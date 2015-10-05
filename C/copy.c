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

    //Opening source file as read only.
    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
    {
        perror("OpenSource");
        return(-1);
    }

    //Opening the destination file, if it does not exist, it will be created
    destfd = open(argv[2], O_CREAT | O_WRONLY, 0644);
    if(destfd == -1)
    {
        perror("OpenDest");
        return(-1);
    }

    //While there is something to read, it will write it to dest file.
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

    //Ensure that all data has been written from buffed onto disk.
    if(fsync(fd) == -1 | fsync(destfd) == -1)
    {
        perror("Fsync");
    }

    //Close the files so that other prosesses can reach them.
    if(close(fd) == -1 | close(destfd) == -1)
    {
        perror("Close");
    }

    return (0);
}
