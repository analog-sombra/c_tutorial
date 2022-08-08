#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define BUf_SIZE 1024
#define PORT "4444"
#define IP "127.0.0.1"

void error_handling(char *message);

int main(int argc,char *argv[]){
	//variables
	int sock;
	char message[BUf_SIZE];
	int str_len;
	struct sockaddr_in server_addr;



	//creating socket
	sock =  socket(PF_INET,SOCK_STREAM,0);
	if(sock==-1){
		error_handling("socket createing error");
	}

	//connection socket
	memset(&server_addr,0,sizeof(server_addr));
	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = inet_addr(IP);
	server_addr.sin_port = htons(atoi(PORT));
	if(connect(sock,(struct sockaddr*)&server_addr,sizeof(server_addr))==-1){
		error_handling("socket connection error");
	}else{
		printf("socket connected .........");
	}
	while(1){
		fputs("Input message(Q to quit): ",stdout);
		fgets(message,BUf_SIZE,stdin);

		if(!strcmp(message,"q\n") || !strcmp(message,"Q\n")){
			break;
		}
		write(sock,message,strlen(message));
		str_len = read(sock,message,BUf_SIZE-1);
		message[str_len]=0;
		printf("Message from server: %s",message);
	}


	return 0;
}

void error_handling(char *msg){
	printf("%s",msg);
	exit(1);
}