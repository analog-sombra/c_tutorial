// Internet address representation in c

// syntex
//  unsigned short htons(unsigned short);
//  unsigned short ntohs(unsigned short);
//  unsigned short htonl(unsigned short);
//  unsigned short ntohl(unsigned short);

// h = host
// n = network
// s = short
// l = long

// htons = human to network short
// ntohs = network to human short
// htonl = human to network long
// ntohl = network to human long

#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	// converting ip and port human ordred to network ordered
	unsigned short int host_port = 0x1234;
	unsigned short net_port;
	unsigned long host_address = 0x12345678;
	unsigned long net_address;

	net_port = htons(host_port);
	net_address = htonl(host_address);
	printf("Host ordered port %#x\n", host_port);
	printf("Net ordered port %#x\n", net_port);
	printf("Host ordered address %#lx\n", host_address);
	printf("Network ordered address %#lx\n", net_address);

	puts("***********************************************");
	// conver string ip addres to computer ip address
	// 123.345.23.34 this is wrong ip addres can't be longer then 255
	char *addr = "127.232.124.79";
	struct sockaddr_in addr_inet;

	if (!inet_aton(addr, &addr_inet.sin_addr))
	{
		printf("Conversion error");
		exit(1);
	}
	else
	{
		printf("Network ordered integer addres: %#x \n", addr_inet.sin_addr.s_addr);
	}
	puts("***********************************************");

	// network order ip addres to human readable address
	struct sockaddr_in addr1, addr2;
	char *str_ptr1;
	char *str_ptr2;
	addr1.sin_addr.s_addr = htonl(0x1020304);
	addr2.sin_addr.s_addr = htonl(0x1010101);

	str_ptr1 = inet_ntoa(addr1.sin_addr);
	printf("Dotted_Decimal notation1: %s \n", str_ptr1);
	str_ptr2 = inet_ntoa(addr2.sin_addr);
	printf("Dotted-decimal notation2: %s \n", str_ptr2);

	return 0;
}