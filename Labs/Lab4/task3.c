/*
Task-03
Write a C program to open an existing file (file1.txt with some content typed already in it)
that has some content using the open() system call, read the content up to some bytes,
and print the read bytes of content on the screen using the read() and write() system call.
*/
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(void){
    int fd = open("file1.txt", O_RDONLY);
    char buffer[50];
    int bytesRead = read(fd, buffer, 17);
    write(1, buffer, bytesRead);
    close(fd);
    printf("\n");
    return 0;
}