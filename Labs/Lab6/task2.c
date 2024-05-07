/*
Task 2
Write a program to run another program by the current running process child process
by replacing its image with the program that printed 20 odd numbers and replacing
the current running program process image (parent) with the program of ps command.
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void){
    int process_id = fork();
    switch(process_id){
        case -1:
            printf("Error, not able to fork a child properly");
            break;
        case 0:
            printf("child....\n");
            printf("Before replacing the image of the current running process....%d\n", getpid());
            execl("odd", "./odd", NULL);
            printf("After replacing image of the current running process....%d\n", getpid());
            break;
        default:
            printf("parent....\n");
            printf("Before replacing the image of the current running process....%d\n", getpid());
            execl("/bin/ps", "ps", NULL);
            printf("After replacing image of the current running process....%d\n", getpid());
    }
    sleep(1);
    printf("\n");
    return 0;
}