#include<pthread.h>
#include<stdio.h>


void *fun1(void* data)
{

int* a,b;
a = data;
b = *a;
    printf("Inside thread and data is  %d\n",b);
    pthread_exit(NULL);     // exit the thread after execution of the statements
}


int main()
{
pthread_t thread_id;
int a = 10;
    printf("Creating thread\n");
    pthread_create(&thread_id,NULL,&fun1,(void*)&a);
   // pthread_exit(NULL);			// Called to keep thread till end
    printf("\n main exits..\n");
}
