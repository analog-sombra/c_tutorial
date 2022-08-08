#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT "4444"
#define IP "127.0.0.1"



void error_handling(char *message);
int main(int argc, char *argv[]){
	//variables
	char msg1[] = "hello sombra\n";
	char msg2[] = "hello sona\n";
	char msg3[] = "hello Ahri\n";
	int sock;
	struct sockaddr_in server_addr, from_addr;
	socklen_t sock_len;

	//creating socket
	sock = socket(PF_INET,SOCK_DGRAM,0);
	if(sock ==-1){
		error_handling("socket creating error");
	}

	memset(&server_addr,0,sizeof(server_addr));
	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr =inet_addr(IP);
	server_addr.sin_port = htons(atoi(PORT));

	//sending messages
	sendto(sock,msg1,sizeof(msg1),0,(struct sockaddr*)&server_addr,sizeof(server_addr));
	sendto(sock,msg2,sizeof(msg2),0,(struct sockaddr*)&server_addr,sizeof(server_addr));
	sendto(sock,msg3,sizeof(msg3),0,(struct sockaddr*)&server_addr,sizeof(server_addr));
	close(sock);

	return 0;
}
void error_handling(char *msg){
	printf("%s",msg);
	exit(1);
}