#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>

int main()
{
	int ret;

	ret = truncate ("../truncate_test.txt", 45);
	if (ret == -1)
	{
		perror ("truncate");
		return -1;
	}
	return 0;
}
