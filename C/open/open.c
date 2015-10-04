#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


int main()
{
	int open (const char *name, int flags);
	int open (const char *name, int flags, mode_t mode);
	int fd;

	fd = open("/Home/Documents/C/testdocument.txt", O_RDONLY);
	if (fd == -1)
		printf("An error has occured");

}
