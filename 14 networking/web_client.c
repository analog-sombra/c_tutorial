#include <sys/socket.h>
#include <sys/types.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <stdarg.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/time.h>
#include <sys/ioctl.h>
#include <netdb.h>

// standard HTTP port
#define SERVER_PORT 80

// buffer where data come
#define MAXLINE 4096

#define SA struct sockaddr

void err_n_die(const char *fmt, ...);

int main(int argc, char const *argv[])
{
    int sockfd,n;
    int sendbytes;
    struct sockaddr_in servaddr;
    char sendline[MAXLINE];
    char recvline[MAXLINE];

    

    if(argc !=2){
        err_n_die("usages: %s <server address>",argv[0]);
    }


//creating the socket
    if((sockfd = socket(AF_INET,SOCK_STREAM,0))<0){
        err_n_die("Error while creating the socket!");
    }

    bzero(&servaddr,sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(SERVER_PORT);


    //convert to binary
    if(inet_pton(AF_INET,argv[1],&servaddr.sin_addr) <=0){
        err_n_die("inet_pton error for %s",argv[1]);
    }
    //connect to the address
    if(connect(sockfd,(SA *) &servaddr,sizeof(servaddr))<0){
        err_n_die("Connect failed!");
    }

    //connected.
    sprintf(sendline,"GET / HTTP/1.1\r\n\r\n");
    sendbytes = strlen(sendline);

    if(write(sockfd,sendline,sendbytes) != sendbytes){
        err_n_die("write error");

    }
    memset(recvline , 0 ,MAXLINE);

    while ((n =read(sockfd,recvline,MAXLINE-1))>0)
    {
        printf("%s",recvline);
    }
    if(n<0){
        err_n_die("read error");
    }
    exit(0);
    return 0;
}

void err_n_die(const char *fmt, ...)
{
    int errno_save;
    va_list ap;

    // any system or libary call can set errno , so we need to save it now
    errno_save = errno;

    va_start(ap, fmt);
    vfprintf(stdout, fmt, ap);
    fprintf(stdout, "\n");
    fflush(stdout);

    // print out error message is errno was set.
    if (errno != 0)
    {
        fprintf(stdout, "(errno = %d) : %s\n", errno_save, strerror(errno_save));
    }
    va_end(ap);

    exit(1);
}
