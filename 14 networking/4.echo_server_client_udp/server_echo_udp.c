#include <sys/socket.h>
#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUF_SIZE 30
#define PORT "4444"
void error_handling(char *message);
int main(void)
{
	// variables
	int server_sock;
	char message[BUF_SIZE];
	int str_len;
	socklen_t client_addr_len;

	struct sockaddr_in server_addr, client_addr;

	server_sock = socket(PF_INET, SOCK_DGRAM, 0);
	if (server_sock == -1)
	{
		error_handling("Socket creating error");
	}
	memset(&server_addr, 0, sizeof(server_addr));
	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	server_addr.sin_port = htons(atoi(PORT));
	if (bind(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1)
	{
		error_handling("socket binding error");
	}
	else
	{
		printf("socket binding......");
	}

	while (1)
	{
		client_addr_len = sizeof(client_addr);
		str_len = recvfrom(server_sock, message, BUF_SIZE, 0, (struct sockaddr *)&client_addr, (socklen_t *)&client_addr_len);
		sendto(server_sock, message, str_len, 0, (struct sockaddr *)&client_addr, client_addr_len);
	}

	close(server_sock);

	return 0;
}
void error_handling(char *message)
{
	printf("%s\n", message);
	exit(1);
}