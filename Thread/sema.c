#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<pthread.h>
#include<semaphore.h>

#define BUFFER_SIZE 1024

sem_t sem; // semaphore variable 

char buffer[BUFFER_SIZE];

void *read_thread(void *arg) {
	while(strncmp("stop",buffer,4) != 0){
		printf("Enter text: ");
		fgets(buffer, BUFFER_SIZE, stdin);
		sem_post(&sem); // automatically increases the value of the semaphore by 1.( unlock )
	}
	pthread_exit("read_thread exit successful");
}

void *convert_thread() {
	int i;
	sem_wait(&sem);//automatically decreases the value of the semaphore by 1 (lock)
	while(strncmp("stop", buffer, 4) != 0) {
		printf("Converted text: ");
		for(i=0;i<strlen(buffer);i++)
			printf("%c",toupper(buffer[i]));
		sem_wait(&sem);
	}
	pthread_exit("convert_thread exit successful");
}


int main()
{
	int result;
	pthread_t rthread,cthread;
	void *thread_result;
	
	/* Initialize a semaphore object and set the initial value of
	   the semaphore to 0 */
	result = sem_init(&sem, 0, 0);  

	if(result != 0){
		printf("Semaphore initialization failed");
		exit(1);
	}

	printf("Enter text, the program will convert it into upper case, To stop enter 'stop'\n");
	
	result = pthread_create(&cthread, NULL, convert_thread, NULL);
	if(result != 0){
		printf("convert_thread creation failed");
		exit(1);
	}

	result = pthread_create(&rthread, NULL, read_thread, NULL);
	if(result != 0){
		printf("read_thread creation failed");
		exit(1);
	}

	result = pthread_join(rthread, &thread_result);
	if(result != 0){
		printf("read_thread join failed");
		exit(1);
	}
	printf("read_thread joined, %s\n",(char *)thread_result);

	result = pthread_join(cthread, &thread_result);
	if(result != 0){
		printf("convert_thread join failed");
		exit(1);
	}
	printf("convert_thread joined, %s\n",(char *)thread_result);
	
	sem_destroy(&sem);  // tidies up the semaphore
	exit(0);
}



