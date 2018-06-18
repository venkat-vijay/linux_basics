#include<pthread.h>
#include<stdio.h>


void *fun1()
{
    printf("Inside thread %u\n",pthread_self());  //pthread_self() returns the thread id
    pthread_exit(NULL);
}


int main()
{
    pthread_t thread_id;
    printf("Creating thread\n");
    pthread_create(&thread_id,NULL,&fun1,NULL);
    printf("Inside main and thread id is %u\n",thread_id);	
    pthread_exit(NULL);			// Called to keep thread till end
}
