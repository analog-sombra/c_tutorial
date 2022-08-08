#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>

int main(){
	//variables
	int serverSocketFd, clientSocketFd;
	struct sockaddr_in serverAddres, clinetAddress;
	int clientAddressLength;

	//socket createion
	serverSocketFd = socket(AF_INET,SOCK_STREAM,0);
	if(serverSocketFd == -1){
		printf("failed to creat a socket\n");
		exit(1);
	}else{
		printf("Socket : %d \n",serverSocketFd);
	}

	//bind
	bzero(&serverAddres,sizeof(serverAddres));
	serverAddres.sin_family = AF_INET;
	serverAddres.sin_addr.s_addr = htonl(INADDR_ANY);
	serverAddres.sin_port = htons(4567);
	if(bind(serverSocketFd,(struct sockaddr*)&serverAddres,sizeof(serverAddres)) != 0){
		printf("unable to bind the socket\n");
		exit(1);
	}else{
		printf("bind succecfully\n");
	}

	

	//listening
	if(listen(serverSocketFd,1)!=0){
		printf("failed to listen\n");
		exit(0);
	}else{
		printf("listening\n");
	}

	//accepting
	bzero(&clinetAddress,sizeof(clinetAddress));
	clientSocketFd = accept(serverSocketFd,(struct sockaddr*)&clinetAddress,(socklen_t*)&clientAddressLength);
	if(clientSocketFd == -1){
		printf("failed to accept\n");
		exit(1);
	}else{
		printf("accepted\n");
	}

	//writing (communicating)
	char* msg = "hello sombra";
	write(clientSocketFd,msg,strlen(msg));
	printf("sent: \"%s\"\n",msg);
	 



	//close
	close(serverSocketFd);
	printf("server socket closed\n");
	close(clientSocketFd);
	printf("client socket closed\n");
	return 0;

}