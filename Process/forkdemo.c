// Program to show fork() system call;

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(){

// Variable declarations; fork returns a value of pid_t type
pid_t pid;
char *message;
int i,l;
	printf(" Calling fork \n");
	pid = fork(); // create a new process by calling fork(), and it returns PID of child process.
	switch(pid)
	{
		case -1:
			perror("fork failed\n");
			exit(1);
		case 0:
			message = "Child process";
			i = 3;
			break;
		default:
			message = "Parent process";
			i = 2;
			break;
	}
	for (l=i;l>0;--l){
		puts(message);
		sleep(5);
	}
	exit(0);
}
