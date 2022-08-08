#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define BUf_SIZE 1024
#define PORT 4444


void error_handling(char *message);

int main(int argc, char *argv[]){
	//variables
	int server_sock,client_sock;
	char message[BUf_SIZE];
	int str_len,i;

	struct sockaddr_in server_addr;
	struct sockaddr_in client_addr;
	socklen_t client_addr_size;

	
	
	//creating sockets
	server_sock = socket(PF_INET,SOCK_STREAM,0);
	if(server_sock==-1){
		error_handling("socket creation error");
	}

	memset(&server_addr,0,sizeof(server_addr));
	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr=htonl(INADDR_ANY);
	server_addr.sin_port = htons(PORT);

	//binding socket
	if(bind(server_sock,(struct sockaddr*)&server_addr,sizeof(server_addr))==-1){
		error_handling("socket binding error");
	}

	//listening
	if(listen(server_sock,5)==-1){
		error_handling("listen() error");
	}

	client_addr_size =  sizeof(client_addr);
	for(i =0;i<5;i++){
		client_sock = accept(server_sock,(struct sockaddr*)&client_addr,(socklen_t*)&client_addr_size);
		if(client_sock==-1){
			error_handling("accept() errpr");
		}else{
			printf("Connected cllient %d\n",i+1);
		}
		while ((str_len= read(client_sock,message,BUf_SIZE))!=0)
		{
			write(client_sock,message,str_len);
		}
		close(client_sock);
	}
	close(client_sock);
	return 0;
}

void error_handling(char *msg){
	printf("%s",msg);
	exit(1);
}