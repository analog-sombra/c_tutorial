#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

// O_CREAT
// create a file if it's not exist

// O_TRUNC
// overwrite the data

// O_APPEND
// and the new data

// O_RDONLY
// readonly file

// O_WRONLY
// write only

// O_RDWR
// read and write

// writing data to afile

int main(void)
{
	// fd is file descriptor
	int fd;
	char buf[] = "Hello everyone who i am do you know\n";
	fd = open("data.txt", O_CREAT | O_WRONLY | O_TRUNC);
	if (fd == -1)
	{
		printf("open() error!\n");
	}

	if (write(fd, buf, sizeof(buf)) == -1)
	{
		printf("write() error!\n");
	}

	close(fd);
	return 0;
}