// Program to change the permission of a file...

//#include<sys/stat.h>
#include<errno.h>
#include<unistd.h>
#include<stdio.h>


void main(){

int a;
// checks if the current program can write to a file or not
    a = access("/home/vlsi52/Desktop/ESDM100/Linux/file_mgmnt/cmd",W_OK);
    perror("access");
    if(a != -1)
	chmod("/home/vlsi52/Desktop/ESDM100/Linux/file_mgmnt/cmd",0444);

    access("/home/vlsi52/Desktop/ESDM100/Linux/file_mgmnt/cmd",W_OK);
    perror("access");


}
