#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main(void){
	int fd;
	char buf[50];
	fd=open("data.txt",O_RDONLY);
	if(fd==-1){
		printf("open() error");
	}
	printf("file descriptor: %d \n",fd);
	if(read(fd,buf,sizeof(buf))==-1){
		printf("read() error!");
	}
	printf("file data: %s",buf);
	close(fd);
	return 0;

}