// Code to check if the program can access a file or not...


#include <unistd.h>
#include <errno.h>

void main(){

// Checks if a file exists or not....
    access("/home/student/rajesh/sys1.c",W_OK);
    perror("access");

}
