/*
Task 4
Try task 4, making the main process not wait for the thread to complete its execution.
What is your observation?
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
    //pthread_join(thread, NULL);

    printf("Inside main after thread execution...\n");
    for(int i = 0; i < 20; i+=2){
        printf("%d\t", i);
        fflush(stdout);
        sleep(1);
    }
    printf("\n");

    return 0;
}