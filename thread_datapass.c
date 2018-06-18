
#include<pthread.h>
#include<stdio.h>
void *fun1(void *data)
{
int *a,b;
a = data;
b = *a;
    printf("Inside thread and data is 1  %d\n",b);
   pthread_exit((void*)&b);
printf("\ndilla\n");     // exit the thread after execution of the statements
}
void *fun2(void *data)
{
int *a,b;
a = data;
b = *a;
    printf("\nInside thread and data is  2 %d\n",b);
    pthread_exit((void*) &b);
printf("\nrajesh");     // exit the thread after execution of the statements
}
int main()
{
pthread_t thread_id;
void  *retval;
int a = 10,b=30;
    printf("Creating thread\n");
    pthread_create(&thread_id,NULL,&fun1,(void*)&a);
       pthread_create(&thread_id,NULL,&fun2,(void*)&b);
  pthread_join(thread_id,&retval);
 printf("The data returned from thread is %d\n",*(int*)retval);

  pthread_exit(NULL);	// Called to keep thread till end
    printf("\n main exits..\n");
}
