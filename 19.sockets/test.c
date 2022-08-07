#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
int main (int argc, char *argv[])
{
    int fd;
    char *buf = "This is realy very awesome";
    fd = open("data",O_CREAT|O_WRONLY|O_TRUNC);
    write(fd,buf,sizeof(buf));
    printf("%d\n",fd);
    return 0;
}
