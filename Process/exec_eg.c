// Example to show execvp()
//System() is a combination of fork() and execvp()

//The shell program uses a combination of fork() and exec() to work..


#include <stdio.h>
#include <unistd.h>

int main( void ) {
	char *argv[3] = {"ls","-l",NULL};
	int pid = fork();

	if ( pid == 0 ) {
		execvp( "ls",argv);
	}

	/* The Parent process suspends execution and waits for child to return */
	wait();

	printf( "Finished executing the parent process\n"
	        " - the child won't get here--you will only see this once\n" );

	return 0;
}
