/*
Task-02
Write a C program to allow the user to provide input from the keyboard up to some
bytes with the help of the read() system call and write the read number of bytes
of content on the screen using the write() system call.
*/
#include <unistd.h>
#include <stdio.h>

int main(void){
    //fd - file descriptor for monitor representing file is 1 and keyboard is 0
    char buffer[50];
    int countRead = read(0, buffer, 50);
    write(1, buffer, countRead);
    return 0;
}