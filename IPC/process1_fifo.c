#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main()
{
    int fd;

    /* create the FIFO (named pipe) */
    mkfifo("myfifo", 0666);
    /* write message to the FIFO */
    fd = open("myfifo", O_WRONLY);
    write(fd, "Fifo example for ESDM100 students", sizeof("Fifo example for ESDM100 students"));
    close(fd);
    /* remove the FIFO */
    unlink("myfifo");

    return 0;
}




