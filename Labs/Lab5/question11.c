/*
Question 11:
Write a program in which you make a call to fork() system call and print a
message "Operating System Lab\n". What will be the output, and what is the PID of parent
and child processes? Explain the reason for getting such output.
How many processes are created?
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(void){
    printf("Current PID (our question11.c program): %d\n", getpid());
    printf("Current PPID (bas or terminal): %d\n", getppid());

    int pid = fork();

    printf("Operating System Class....%d\n", pid);
}