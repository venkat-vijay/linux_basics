#include<pthread.h>
#include<stdio.h>
void *display_name(void *a)
{
printf("\nTHREAD Operation:%d\n",pthread_self());
pthread_exit((void*)&a);
}
void main()
{
int i=0;
void *retval;
pthread_t t;
for(i=0;i<5;i++)
{
pthread_create(&t,NULL,&display_name,NULL);
pthread_join(t,&retval);
}
//printf("\nMAIN FUNCTION:%d\n",*(int*)retval);
}
