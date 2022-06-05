#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <unistd.h>
#include <time.h>

typedef unsigned int dns_rr_ttl;
typedef unsigned short dns_rr_type;
typedef unsigned short dns_rr_class;
typedef unsigned short dns_rdata_len;
typedef unsigned short dns_rr_count;
typedef unsigned short dns_query_id;
typedef unsigned short dns_flags;

#define TEMP_BUF_LEN	1024
#define BUFFER_MAX	1024
#define CNAME_TYPE 0x05
#define RESPONSE_BUFFER_SIZE 512
#define PRINT_ALL 1

typedef struct {
	char *name;
	dns_rr_type type;
	dns_rr_class class;
	dns_rr_ttl ttl;
	dns_rdata_len rdata_len;
	unsigned char *rdata;
} dns_rr;

void print_bytes(unsigned char *bytes, int byteslen) {
	int i, j, byteslen_adjusted;

	if (byteslen % 8) {
		byteslen_adjusted = ((byteslen / 8) + 1) * 8;
	} else {
		byteslen_adjusted = byteslen;
	}
	for (i = 0; i < byteslen_adjusted + 1; i++) {
		if (!(i % 8)) {
			if (i > 0) {
				for (j = i - 8; j < i; j++) {
					if (j >= byteslen_adjusted) {
						printf("  ");
					} else if (j >= byteslen) {
						printf("  ");
					} else if (bytes[j] >= '!' && bytes[j] <= '~') {
						printf(" %c", bytes[j]);
					} else {
						printf(" .");
					}
				}
			}
			if (i < byteslen_adjusted) {
				printf("\n%02X: ", i);
			}
		} else if (!(i % 4)) {
			printf(" ");
		}
		if (i >= byteslen_adjusted) {
			continue;
		} else if (i >= byteslen) {
			printf("   ");
		} else {
			printf("%02X ", bytes[i]);
		}
	}
	printf("\n");
}

void canonicalize_name(char *name) {
	/*
	 * Canonicalize name in place.  Change all upper-case characters to
	 * lower case and remove the trailing dot if there is any.  If the name
	 * passed is a single dot, "." (representing the root zone), then it
	 * should stay the same.
	 *
	 * INPUT:  name: the domain name that should be canonicalized in place
	 */

	int namelen, i;

	// leave the root zone alone
	if (strcmp(name, ".") == 0) {
		return;
	}

	namelen = strlen(name);
	// remove the trailing dot, if any
	if (name[namelen - 1] == '.') {
		name[namelen - 1] = '\0';
	}

	// make all upper-case letters lower case
	for (i = 0; i < namelen; i++) {
		if (name[i] >= 'A' && name[i] <= 'Z') {
			name[i] += 32;
		}
	}
}

int name_ascii_to_wire(char *name, unsigned char *wire) {
/*
 * Convert a DNS name from string representation (dot-separated labels)
 * to DNS wire format, using the provided byte array (wire).  Return
 * the number of bytes used by the name in wire format.
 *
 * INPUT:  name: the string containing the domain name
 * INPUT:  wire: a pointer to the array of bytes where the
 *              wire-formatted name should be constructed
 * OUTPUT: the length of the wire-formatted name.
 */

  // Set initial locations
  unsigned char* current = wire;
  unsigned char* current_count = wire;
  // The first item is the count for the first word.
  *current_count = 0x00;
  current++;
  // Iterate through and construct wire
  while (*name != 0) {
    if (*name != '.') {
      // Current location in name is letter
      *current = *name;
      (*current_count)++;
    } else {
      // Replace period with count.
      current_count = current;
    }
    // Increment pointers.
    current++;
    name++;
  }
  // Pad the last character.
  *current = 0x00;
  return strlen(wire);
}

int name_ascii_from_wire(unsigned char *wire, int *indexp, char* name) {
	/*
	 * Extract the wire-formatted DNS name at the offset specified by
	 * *indexp in the array of bytes provided (wire) and return its string
	 * representation (dot-separated labels) in a char array allocated for
	 * that purpose.  Update the value pointed to by indexp to the next
	 * value beyond the name.
	 *
	 * INPUT:  wire: a pointer to an array of bytes
	 * INPUT:  indexp, a pointer to the index in the wire where the
	 *              wire-formatted name begins
	 * OUTPUT: the length of the original wire-formatted name.
	 */
  int length = 1;
  int current_pos = *indexp;
  unsigned char current_size = wire[current_pos++];
  // Iterate through each chunk and decode
  while(current_size) {
    if((current_size & 0xC0) == 0xC0) {
			// Sub-phrase encountered
      int new_pos = wire[current_pos];
      name += name_ascii_from_wire(wire, &new_pos, name);
      // Increment pointers
      current_size = wire[++current_pos];
      length++;
    } else {
	    for(int current_item = 0; current_item < current_size; current_item++) {
				// Copy over current
	      *name = wire[current_pos+current_item];
	      length++;
	      name++;
	    }
      // Increment pointers that correspond to name length, pos.
			current_pos += current_size;
			current_size = wire[current_pos++];
	    if(current_size) {
				// Period encountered
	      *name = '.';
	      length++;
	      name++;
	    }
		}
  }
	// Pad last with zero
  *name = 0x00;
  return length;
}

dns_rr parse_compressed(unsigned char **answer_rr_ptr, char* owner_name) {
  // The name is compressed
  dns_rr output;
  output.name = owner_name;
  // Yeah I definately found an online source that walked through this process
  output.type = ((*answer_rr_ptr)[2] << 8) | (*answer_rr_ptr)[3];
  output.class = ((*answer_rr_ptr)[4] << 8) | (*answer_rr_ptr)[5];
  output.ttl = ((*answer_rr_ptr)[6] << 24) | ((*answer_rr_ptr)[7] << 16) | ((*answer_rr_ptr)[8] << 8) | ((*answer_rr_ptr)[9]);
  output.rdata_len = ((*answer_rr_ptr)[10] << 8) | (*answer_rr_ptr)[11];
  output.rdata = &((*answer_rr_ptr)[12]);
  (*answer_rr_ptr) += (output.rdata_len + 12);
  // Struct created, output.
  return output;
}

dns_rr parse_uncompressed(unsigned char **answer_rr_ptr, char* owner_name, int name_length) {
  // The name isn't compressed
  dns_rr output;
  output.name = owner_name;
  output.type = ((*answer_rr_ptr)[name_length] << 8) | (*answer_rr_ptr)[name_length + 1];
  output.class = ((*answer_rr_ptr)[name_length + 2] << 8) | (*answer_rr_ptr)[name_length + 3];
  output.ttl = ((*answer_rr_ptr)[name_length + 4] << 24) | ((*answer_rr_ptr)[name_length + 5] << 16) | ((*answer_rr_ptr)[name_length + 6] << 8) | ((*answer_rr_ptr)[name_length + 7]);
  output.rdata_len = ((*answer_rr_ptr)[name_length + 8] << 8) | (*answer_rr_ptr)[name_length + 9];
  output.rdata = (*answer_rr_ptr) + name_length + 10;
  (*answer_rr_ptr) += (name_length + output.rdata_len + 10);
  // Struct created, output.
  return output;
}

dns_rr rr_from_wire(unsigned char* query_start, unsigned char **answer_rr_ptr, int query_only) {
	/*
	 * Extract the wire-formatted resource record at the offset specified by
	 * *indexp in the array of bytes provided (wire) and return a
	 * dns_rr (struct) populated with its contents. Update the value
	 * pointed to by indexp to the next value beyond the resource record.
	 *
	 * INPUT:  wire: a pointer to an array of bytes
	 * INPUT:  indexp: a pointer to the index in the wire where the
	 *              wire-formatted resource record begins
	 * INPUT:  query_only: a boolean value (1 or 0) which indicates whether
	 *              we are extracting a full resource record or only a
	 *              query (i.e., in the question section of the DNS
	 *              message).  In the case of the latter, the ttl,
	 *              rdata_len, and rdata are skipped.
	 * OUTPUT: the resource record (struct)
	 */

  // Allocate required segments
  char* owner_name = malloc(BUFFER_MAX);
  // Construct pointer based on whether response is compressed
  unsigned indexp = ((**answer_rr_ptr & 0xC0) == 0xC0) ? (*answer_rr_ptr)[1] : (*answer_rr_ptr) - query_start;
  // Access name length
  int name_length = name_ascii_from_wire(query_start, &indexp, owner_name);
  // Parse response
  return ((**answer_rr_ptr & 0xC0) == 0xC0) ? parse_compressed(answer_rr_ptr, owner_name) : parse_uncompressed(answer_rr_ptr, owner_name, name_length);
}

unsigned short create_dns_query(char *qname, dns_rr_type qtype, unsigned char *wire) {
	/*
	 * Create a wire-formatted DNS (query) message using the provided byte
	 * array (wire).  Create the header and question sections, including
	 * the qname and qtype.
	 *
	 * INPUT:  qname: the string containing the name to be queried
	 * INPUT:  qtype: the integer representation of type of the query (type A == 1)
	 * INPUT:  wire: the pointer to the array of bytes where the DNS wire
	 *               message should be constructed
	 * OUTPUT: the length of the DNS wire message
	 */

   // Zero header
  for(int i = 0; i < BUFFER_MAX; i++) wire[i] = 0;
  // Set random identification
  wire[0] = rand();
  wire[1] = rand();
  // Set RD bit
  wire[2] = 0x01;
  // Set total questions
  wire[5] = 0x01;
  // Set query to question location (location 12)
  int query_bytes = name_ascii_to_wire(qname, &wire[12]);
  // Set type 1 (type A for address)
  wire[12 + query_bytes + 2] = 0x01;
  // Set class 1 (internet)
  wire[12 + query_bytes + 4] = 0x01;
  // Return size of query
  return 12 + query_bytes + 5;
}

char* get_answer_address(char* qname, dns_rr_type qtype, unsigned char* wire, char* answer) {
	/*
	 * Extract the IPv4 address from the answer section, following any
	 * aliases that might be found, and return the string representation of
	 * the IP address.  If no address is found, then return NULL.
	 *
	 * INPUT:  qname: the string containing the name that was queried
	 * INPUT:  qtype: the integer representation of type of the query (type A == 1)
	 * INPUT:  wire: the pointer to the array of bytes representing the DNS wire message
	 * OUTPUT: a string representing the IP address in the answer; or NULL if none is found
	 */

  // I hate doing this but the professor changed the requirements on me.
  char* name_copy = malloc(strlen(qname));
  strncpy(name_copy, qname, strlen(qname));

  // Get details from wire. We only need one thing.
  uint16_t total_answer_rrs = (wire[6] << 8) | wire[7];

  // Initialize pointers and variables
  unsigned char* answer_rr_ptr = &(wire[0]);
  int name_position = 12;
  // Get ascii name
  int query_name_length = name_ascii_from_wire(wire, &name_position, qname);
  answer_rr_ptr += (query_name_length + 17);

  // Iterate through all the RRs.
  for(int answer_index = 0; answer_index < total_answer_rrs; answer_index++) {
    dns_rr rr = rr_from_wire(wire, &answer_rr_ptr, 0);
    // Test whether the name is c-name
    if(strcmp(rr.name, qname) == 0 && rr.type == qtype){
      // Name is normal
      char string_ip[90];
      int ip_length = rr.rdata_len;
      int position = 0;
      char* current_ip = string_ip;
      // Cycle through and create ip.
      while(ip_length){
        // Only seperate IP with '.' and not on either side.
        int chars = sprintf(current_ip, (ip_length == 1) ? "%u" : "%u.", rr.rdata[position]);
        current_ip += chars;
        position++;
        ip_length--;
      }
      // Done with current_ip
      current_ip = 0x00;
      // Copy over answer
      strncpy(answer, string_ip, strlen(string_ip) > strlen(answer) ? strlen(string_ip) : strlen(answer));
      // Valid RR, return answer.
      if (PRINT_ALL) {
        printf("%s => %s\n", qname, answer == NULL ? "NONE" : answer);
      } else {
        free(name_copy);
        return answer;
      }
    } else if(strcmp(rr.name, qname) == 0 && rr.type == CNAME_TYPE){
      // Name is alias
      int name_position = rr.rdata - wire;
      name_ascii_from_wire(wire, &name_position, qname);
      canonicalize_name(qname);
    }
    // free the name: We're done with it.
    free(rr.name);
  }
  if (PRINT_ALL && strlen(answer) == 0) {
    printf("%s => %s\n", name_copy, "NONE");
  } else if (PRINT_ALL) {
    // For some dumb reason this is what the provided code does.
    printf("\n");
  }
  free(name_copy);
  return NULL;
}

int send_recv_message(unsigned char *request, int request_length, unsigned char *response, char *server, unsigned short port) {
	/*
	 * Send a message (request) over UDP to a server (server) and port
	 * (port) and wait for a response, which is placed in another byte
	 * array (response).  Create a socket, "connect()" it to the
	 * appropriate destination, and then use send() and recv();
	 *
	 * INPUT:  request: a pointer to an array of bytes that should be sent
	 * INPUT:  requestlen: the length of request, in bytes.
	 * INPUT:  response: a pointer to an array of bytes in which the
	 *             response should be received
	 * OUTPUT: the size (bytes) of the response received
	 */

  // Setup socket
  struct sockaddr_in resolver_addr = {
  .sin_family = AF_INET, // Use the internet address family
  .sin_port = htons(53), // DNS port 53
  .sin_addr = inet_addr(server) // Convert dot notation to binary
  };
  // Make call to socket
  int sock = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP);
  if (sock == -1) {
    fprintf(stderr, "Error creating socket\r\n");
    abort();
  }
  // Connect to faciliate future calls.
  if (connect(sock, (struct sockaddr*) &resolver_addr, sizeof(resolver_addr)) == -1) {
    fprintf(stderr, "Error connecting\r\n");
    abort();
  }

  // Send request
  unsigned char* request_buffer = request;
  unsigned char* request_ptr = request_buffer;
  int request_bytes_left = request_length;
  // Iterate through all bytes of request to send
  while (request_bytes_left) {
    // Send as many bytes as possible
    int bytes_sent = send(sock, request_ptr, request_bytes_left, 0);
    if (bytes_sent < 0 && errno == EINTR) {
      continue;
    } else if (bytes_sent <= 0) {
      // An error occured
      fprintf(stderr, "Error sending request to server\r\n");
      abort();
    }
    // Increment pointers
    request_ptr += bytes_sent;
    request_bytes_left -= bytes_sent;
  }

  // Recieve response
  unsigned char* response_ptr = response;
  int response_bytes_left = RESPONSE_BUFFER_SIZE;
  int bytes_read = recv(sock, response_ptr, response_bytes_left, 0);
  // Check for errors
  if (bytes_read < 0 && errno != EINTR) {
    fprintf(stderr, "Error resceiving response from server\r\n");
    abort();
  } else if (bytes_read == 0) {
    // This is an error-case too.
    bytes_read = -1;
  }
  return bytes_read;
}

char* resolve(char* qname, char* server) {
  // Allocate memory
  unsigned char* response = malloc(BUFFER_MAX);
  char* answer = malloc(BUFFER_MAX);
  unsigned char message[BUFFER_MAX];
  // Create query
  int query_bytes = create_dns_query(qname, (dns_rr_type) 0x01, message);
  // Send and recieve message
  int bytes_read = send_recv_message(message, query_bytes, response, server, 53);
  if (bytes_read <= 0) {
    return "NONE";
  }
  // Extract answer
  char* success = get_answer_address(qname, (dns_rr_type) 0x01, response, answer);
  free(response);
  if (!success) {
    return "NONE";
  }
  // Return the IP.
  return answer;
}

int main(int argc, char *argv[]) {
	char *ip;
	if (argc < 3) {
		fprintf(stderr, "Usage: %s <domain name> <server>\n", argv[0]);
		exit(1);
	}
	ip = resolve(argv[1], argv[2]);
	if (!PRINT_ALL) printf("%s => %s\n", argv[1], ip == NULL ? "NONE" : ip);
}