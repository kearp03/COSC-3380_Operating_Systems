/*
Task 1
Write a program to replace the currently running process image with
another process (executing another program).
*/
#include <stdio.h>
#include <unistd.h>

int main(void){
    printf("Before replacing the image of the current running process....%d\n", getpid());

    execl("odd", "./odd", NULL);

    printf("After replacing image of the current running process....%d\n", getpid());
    return 0;
}