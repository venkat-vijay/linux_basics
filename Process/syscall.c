// program to show system();

#include <stdlib.h>
#include <stdio.h>
int main()
{
int ret;
	ret = system("ls -l"); // running a shell command with system function
	printf("Execution completed with return value : %d\n",ret);
	printf("\n Current process id is : %d\n",getpid());
	printf("\n Current process parent id is:  %d\n",getppid());
 	return ret;
}
