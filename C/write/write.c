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
	int close (int fd);
	
	fd = creat ("Home/Documents/C/test", 0644);
	if (fd == -1)
		perror("creat");
		return -1;


	ssize_t read (int fd, void *buf, size_t len);	

	unsigned long word = 1720;
	ssize_t nr;

	nr = read (fd, &word, sizeof (unsigned long));
	if (nr == -1)
		perror("read");
		return -1;
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

	ssize_t write (int fd, const void *buf, size_t count);
/*	const char *buf = "This is a test!";

	nr = write (fd, buf, strlen (buf));
	if (nr == -1)
	{
		printf("An error has occured during write()");
	}
*/
	size_t count;

	count = sizeof (word);
	nr = write (fd, &word, count);
	if (nr == -1)
		perror("write");
		return -1;
	

	close(fd);
	if (close (fd) == -1 )
		perror ("close");

}
