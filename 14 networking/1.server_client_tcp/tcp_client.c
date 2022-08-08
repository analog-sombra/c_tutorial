#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>

int main(){
	//variables
	int serverFd;
	struct sockaddr_in serverAddres;

	//socket createion
	serverFd = socket(AF_INET,SOCK_STREAM,0);
	if(serverFd == -1){
		printf("failed to creat a socket\n");
		exit(1);
	}else{
		printf("Socket : %d \n",serverFd);
	}

	//connect
	 
	bzero(&serverAddres,sizeof(serverAddres));
	serverAddres.sin_family = AF_INET;
	serverAddres.sin_addr.s_addr = inet_addr("127.0.0.1");
	serverAddres.sin_port = htons(4567);

	if(connect(serverFd,(struct sockaddr*)&serverAddres,sizeof(serverAddres)) != 0){
		printf("connection failed\n");
		exit(1);
	}else{
		printf("Connected\n");
	}


	

	//reading (communicationg)
	char buf[1024];
	read(serverFd,buf,1024);
	printf("received: %s\n",buf);


	
	//close
	close(serverFd);
	printf("connection end\n");
	return 0;

}