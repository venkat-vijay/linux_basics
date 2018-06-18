#include<pthread.h>
#include<stdio.h>


void *print_xs(void *ss)
{
    while(1)
	fputc('x',stdout);  // print X continously
   retrun NULL;
}


int main()
{
pthread_t thread;

    pthread_create(&thread,NULL,&print_xs,NULL); // Create  thread
    while(1)
	fputc('o',stdout); // Print 'o' to screen

return 0;
}
