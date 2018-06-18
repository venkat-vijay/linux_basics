#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void problem(int signal)
{
	printf("You can't stop me\n");
}

int main()
{
	/* 
	  sigaction structure, used to define the action to be taken
          on receipt of the signal specified by 1st parameter, defined
          in signal.h 
        */
	struct sigaction s;
	s.sa_handler = problem; // signal handler finction
	
	sigaction(SIGINT, &s, 1); // sets the action for the SIGINT
	while(1){
		i = 0;
		printf("Hello \n %d",i);
		sleep(5);
		i=i+1;
	}
}


