/* client program to demonstrate shared memory. */ 
#include <sys/types.h> 
#include <sys/ipc.h> 
#include <sys/shm.h> 
#include <stdio.h> 
#include <stdlib.h>

#define SHMSZ 27
 
main() { 
int shmid; 
key_t key; 
char *shm, *s; 
key = 5678; 
if ((shmid = shmget(key, SHMSZ, 0)) < 0) { perror("shmget"); 
	exit(1); 
}

if ((shm = shmat(shmid, NULL, 0)) == (char *) -1) { 
		perror("shmat");
	 	exit(1); 
	} // Now we attach the segment to our data space
	for (s = shm; *s != NULL; s++) 
		putchar(*s); // Now read what the server put in the memory. 
	putchar('\n'); 
	*shm = '*'; 
	/* Finally, change the first character of the * segment to '*', indicating we have read * the segment. */ 
	shmdt(shm);
	exit(0); 
} 
