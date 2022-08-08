#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <time.h>
#define PORT "4444"
#define BUF_SIZE 1024

void error_handling(char *msg);
int main(int argc, char *argv[])
{
	// variables
	int server_sock;
	char message[BUF_SIZE];
	int str_len;
	socklen_t client_addr_len;

	struct sockaddr_in my_addr, your_addr;

	server_sock = socket(PF_INET, SOCK_DGRAM, 0);
	if (server_sock == -1)
	{
		error_handling("Socket creating error");
	}
	memset(&my_addr, 0, sizeof(my_addr));
	my_addr.sin_family = AF_INET;
	my_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	my_addr.sin_port = htons(atoi(PORT));
	if (bind(server_sock, (struct sockaddr *)&my_addr, sizeof(my_addr)) == -1)
	{
		error_handling("socket binding error");
	}
	else
	{
		printf("socket binding......\n");
	}

	for(int i =0;i<3;i++){
		sleep(5);

		client_addr_len = sizeof(your_addr);
		str_len = recvfrom(server_sock,message,BUF_SIZE,0,(struct sockaddr*)&your_addr,(socklen_t*)&client_addr_len);
		printf("%s",message);
	}
	close(server_sock);

	return 0;
}
void error_handling(char *msg){
	printf("%s",msg);
	exit(0);
}