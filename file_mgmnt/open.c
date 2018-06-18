// Program to show open() and write() system calls.

#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<errno.h>
#include<stdio.h>


void main(){

char message[6] = "Hello";

int fd;

	fd = open("/home/vlsi52/Desktop/ESDM100/Linux/file_mgmnt/file1.txt",O_CREAT|O_WRONLY,00666);
	perror("File_open");
	printf("\n File descriptor returned is %d\n",fd);

	// If file open is success, then write a test message,,
	if(fd != -1)
		write(1,message,sizeof(message) - 1);
}



