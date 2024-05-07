/*
Task-05
C program to copy the content of one existing file to another file.
Note: You will not know what is in the file; if anything is there, it should be copied entirely.
*/
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(void){
    int fdin = open("task2.c", O_RDONLY); // if the file exists
    int fdout = open("out_task5.txt", O_CREAT|O_WRONLY|O_APPEND, 0754); // if the file doesn't exist, specifies access
    int bytesRead = 0;
    char buffer[60];

    //loop: How long -> until you reach the end of the file
    while((bytesRead = read(fdin, buffer, 50))){
        write(fdout, buffer, bytesRead);
    }
    close(fdin);
    close(fdout);
    return 0;
}