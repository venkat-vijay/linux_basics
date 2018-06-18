//Program to show Pipe between parent and child process

#include <stdlib.h>
#include <stdio.h> 	/* for printf */
#include <string.h>	/* for strlen */

int main()
{
int n,pid;
int fd[2];
char buf[1025];
char *data;
pipe(fd); // Create a pipe
pid = fork();   // Fork a child process
switch(pid)
{
    case -1:
        perror("fork failed\n");
	exit(1);
    case 0:
	if ((n = read(fd[0], buf, 1024)) >= 0) {
	buf[n] = 0;	/* terminate the string */
	printf(" In child and read %d bytes from the pipe: \"%s\"\n", n, buf);
	}	
    else
        perror("read");
	break;
default:
	data = "Hello...child process, message from parent";
	write(fd[1], data, strlen(data)); // Write data to write end fd[1] by parent process
    break;
	}

	 return 0;
}
