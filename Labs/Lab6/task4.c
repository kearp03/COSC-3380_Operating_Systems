/*
Task 4
Write a program to create a thread to print 10 odd numbers with 1 second delay
and 10 even numbers through the current running process (main) with 1 second delay.
Make the main process to wait for the thread to finish its job so that the main process
can wait and terminate later.
*/
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void* printOdd(void *a){
    for(int i = 1; i < 20; i+=2){
        printf("%d\t", i);
        fflush(stdout);
        sleep(1);
    }
    printf("\n");
    return NULL;
}

int main(void){
    pthread_t thread;
    printf("Inside main before thread execution...\n");
    //Creating first thread
    pthread_create(&thread, NULL, printOdd, NULL);
    pthread_join(thread, NULL);

    printf("Inside main after thread execution...\n");
    for(int i = 0; i < 20; i+=2){
        printf("%d\t", i);
        fflush(stdout);
        sleep(1);
    }
    printf("\n");

    return 0;
}