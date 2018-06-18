#include <sys/types.h> 
#include <sys/ipc.h> 
#include <sys/shm.h> 
#include <stdio.h> 
#include <stdlib.h>

#define SHMSZ 27 
main() { 
char c; 
int shmid; 
key_t key; 
char *shm, *s; 
	key = 5678; // We'll name our shared memory segment * "5678". 
	 if ((shmid = shmget (key, SHMSZ, IPC_CREAT | 0666)) < 0) { 
		perror("shmget"); 
		exit(1); 
	}

// Now we attach the segment to our program address space. 
	if ((shm = shmat (shmid, NULL, 0)) == (char *) -1) { 
			perror("shmat"); 
			exit(1); 
	} 

//Now put some data into the memory for the other process to read. 
		 s = shm; 
		for (c = 'a'; c <= 'z'; c++) 
			*s++ = c; 
		*s = NULL;
		while (*shm != '*') 
/*  Finally, we wait until the other process changes the first character of our memory to '*', indicating that it has read what we put there. */
		sleep(1); 
		shmdt(shm);
		shmctl(shmid, IPC_RMID,0);
		exit(0); 
	}
