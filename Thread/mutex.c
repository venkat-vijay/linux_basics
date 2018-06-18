// Mutex example..
// One thread will increment the count , while other one will decrement the count.


#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<stdlib.h>


// Count and mutex variable
int count = 10;
pthread_mutex_t mutex;

// This thread will decrement the count
void *thread1()
{
	while(1)
	{
	sleep(5);
	pthread_mutex_lock(&mutex); // locking mutex
	printf("Inside the thread1 and count is %d;will decrement count\n",count);
	count--;
	printf("Count is now %d\n",count);
	pthread_mutex_unlock(&mutex);//unlocking mutex
	}
}


// This thread will increment the count
void *thread2()
{
	while(1)
	{
	sleep(5);
	pthread_mutex_lock(&mutex); // locking mutex
	printf("Inside the thread2 and count is %d ;will increment count\n",count);
	count++;
	printf("Count is now %d\n",count);
	pthread_mutex_unlock(&mutex);//unlocking mutex
	}
}



int main()
{

// Variables for thread and thread return
int result;
pthread_t th1, th2;
void *thret;

	result = pthread_mutex_init(&mutex, NULL); // initializition of mutex

	if(result != 0){
		printf("Mutex initialization failed");
		exit(1);
	}	
	
	pthread_create(&th1, NULL, thread1, NULL); // count decrement thread

	pthread_create(&th2, NULL,thread2, NULL);  // count increment thread

	result = pthread_join(th2, NULL);	// wait for thread2 to return

	result = pthread_join(th1, NULL);	// wait for thread3 to return

	pthread_mutex_destroy(&mutex); // tidies up mutex 
	exit(0);
}

