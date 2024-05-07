/*
Task 3
Write a program to create a thread and assign a job to print the
"I am thread" message on the output screen.
Print a custom message like "inside main" in the main program before
creating a thread and after creating a thread.
*/
#include <stdio.h>
#include <pthread.h>

void *printSomething(void *a){
    printf("I am thread....\n");
    return NULL;
}

int main(void){
    printf("Before creating thread and assigning task to it....\n");

    //create and assign the task to thread
    pthread_t thread;
    pthread_create(&thread, NULL, printSomething, NULL);

    pthread_join(thread, NULL);

    printf("In main after executing thread....\n");
    return 0;
}