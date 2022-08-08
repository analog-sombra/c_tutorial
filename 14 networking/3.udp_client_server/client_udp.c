#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUF_SIZE 30
#define PORT "4444"
#define IP "127.0.0.1"
void error_handling(char *message);
int main(void){
	//variables
	int server_sock;
	// char message[BUF_SIZE];
	int str_len;
	socklen_t socket_addr_len;

	struct sockaddr_in server_addr,from_addr;

	server_sock = socket(PF_INET,SOCK_DGRAM,0);
	if(server_sock ==-1){
		error_handling("Socket creating error");
	}
	memset(&server_addr,0,sizeof(server_addr));
	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr =inet_addr(IP);
	server_addr.sin_port = htons(atoi(PORT));

	
	printf("sending client to server using UDP");
	char *message = "hello sombra";
	sendto(server_sock,message,strlen(message),0,(struct sockaddr*)&server_addr,sizeof(server_addr));

	close(server_sock);



	//
	return 0;
}
void error_handling(char *message){
	printf("%s\n",message);
	exit(1);
}