// Program to show condition variables in conjuction with mutex..
// Here one thread will decrement the count and 
// Other thread will only increment when count > 5//


#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<stdlib.h>


// Variables for counter, mutex and condiction variables
int count = 10;
pthread_mutex_t mutex;
pthread_cond_t c = PTHREAD_COND_INITIALIZER; // Initializes condition variable 'c'
					     // pthread_cond_init() could also be used.
					     // Check the documentation for the function

void *thread1()
{
	while(1)
	{
	sleep(5);
	pthread_mutex_lock(&mutex); // locking mutex
	printf("Inside the thread1 and count is %d;will decrement count\n",count);
	count--;
	printf("Count is now %d\n",count);
	pthread_cond_signal(&c);	// Will unlock / wake the thread blocked based on a condition 
	pthread_mutex_unlock(&mutex); // Unlocking mutex
	}
}


void *thread2()
{
	while(1)
	{
	sleep(5);
	pthread_mutex_lock(&mutex); // locking mutex
	printf("\n Thread2 woke up\n");
	while(count>5)
		pthread_cond_wait(&c, &mutex); // Here the thread will be blocked / sleep state based on the 							condition variable and mutex will be released
	printf("Inside the thread2 and count is %d ;will increment count\n",count);
	count++;
	printf("Count is now %d\n",count);
	pthread_mutex_unlock(&mutex);
	}
}



int main()
{
	int result;
	pthread_t th1, th2;
	void *thret;

	result = pthread_mutex_init(&mutex, NULL); // initializition of mutex

	if(result != 0){
		printf("Mutex initialization failed");
		exit(1);
	}	
	
	pthread_create(&th1, NULL, thread1, NULL);

	pthread_create(&th2, NULL,thread2, NULL);

	result = pthread_join(th2, NULL);

	result = pthread_join(th1, NULL);

	pthread_mutex_destroy(&mutex); // tidies up mutex 
	pthread_cond_destroy(&c);
	exit(0);
}

