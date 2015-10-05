#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

int main(int argc, char **argv)
{
    int fd;
    int destfd;
    const int LEN = 1024;
    int ret;
    char buffer[LEN];

    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
    {
        perror("OpenSource");
        return(-1);
    }

    destfd = open(argv[2], O_CREAT | O_WRONLY, 0644);
    if(destfd == -1)
    {
        perror("OpenDest");
        return(-1);
    }

    while ((ret = read(fd, buffer, LEN)) != 0)
    {
        if (ret == -1)
        {
            if (errno == EINTR)
                continue;
            perror("Read");
            break;
        }

        if(write(destfd, buffer, ret) == -1)
        {
            perror("Write");
            break;
        }
    }


    if(close(fd) == -1)
    {
        perror("Close");
    }
    if(close(destfd) == -1)
    {
        perror("Close");
    }
    return (0);
}
