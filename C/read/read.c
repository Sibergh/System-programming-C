#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
	int creat (const char *name, mode_t mode);
	int fd;
	
	fd = creat ("home/documents/c/creat/test", 0644);
	if (fd == -1)
	{
		printf("An error has occured during creat()");
	}


	ssize_t read (int fd, void *buf, size_t len);	

	unsigned long word;
	ssize_t nr;

	nr = read (fd, &word, sizeof (unsigned long));
	if (nr == -1)
	{
		printf("An error has occured during read()");
	}
	/*
	int len;
	char buf;	
	ssize_t ret;
	
	while (len != 0 && (ret = read (fd, buf, len)) != 0)
	{
		if (ret == -1)
		{
			if (errno == EINTR)
				continue;
			perror ("read");
			break;		
		}
		
		len -= ret;
		buf += ret;

	}	
	*/
}
