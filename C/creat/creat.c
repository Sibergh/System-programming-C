#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


int main()
{
	int creat (const char *name, mode_t mode);
	int fd;
	
	fd = creat ("home/documents/c/creat/test", 0644);
	if (fd == -1)
		printf("An error has occured");

}
