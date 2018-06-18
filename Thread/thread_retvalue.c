#include<pthread.h>
#include<stdio.h>

int b;
void *fun1(void *data)
{
int *a;
a = data;
b = *a;

    printf("Inside thread and data is  %d\n",b);
    b = b + 10;
    return((void*)&b);
    pthread_exit("addthread exit");

}


int main()
{
pthread_t thread_id;
int a = 10;
int val;
void *retval;

    printf("Creating thread\n");
    pthread_create(&thread_id,NULL,&fun1,(void*)&a);
    pthread_join(thread_id,&retval);			// join with thread
    printf("The data returned from thread is %d\n",*(int*)retval);

}
