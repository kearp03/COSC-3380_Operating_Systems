/*
Question 13:
Program to print the first 20 odd numbers from the child and the next 20 even numbers from the parent.

How to assign task to each process
parent - task1 i.e. first 20 even numbers
child - task2 i.e. first 20 odd numbers
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(void){
    printf("\nbefore forking\n");
    pid_t p1_id = fork(); //returns new process id to parent, or 0 to child process
    switch (p1_id)
    {
    case -1:
        printf("Error: unable to fork a child process..\n");
        break;
    case 0: //child process, task2: generate 20 odd numbers
        printf("child...\n");
        for(int i = 0; i < 20; i++) printf("%d\n", 2*i+1);
        break;
    default: //parent process, task1: generate 20 even numbers
        printf("parent...\n");
        for(int i = 0; i < 20; i++) printf("%d\n", 2*i);
        break;
    }
    printf("Executed by parent and child\n");
    sleep(1);
    return 0;
}