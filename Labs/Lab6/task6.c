/*
Task 6
Write a program that creates 10 threads (array of threads).
Have each thread execute the same function and pass each thread index as a parameter.
Each thread should print "thread #: Hello World" message on the output screen for five times,
where # is the thread number (index passed to function).
Your program should not terminate until all the threads complete their execution.
*/

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void *printMessage(void *a){
    int p = *((int*)a);
    //int process = *p;
    for(int i = 0; i < 5; i++) printf("Thread %d.%d: Hello World\n", p, i);
    printf("\n");
    return NULL;
}

int main(void){
    pthread_t threads[10];
    printf("Inside main...\n");
    for(int i = 0; i < 10; i++){
        pthread_create(&(threads[i]), NULL, printMessage, &i);
        pthread_join(threads[i], NULL);
    }
    //for(int i = 0; i < 10; i++) pthread_join(threads[i], NULL);
    
    printf("Inside main after...\n");
    return 0;
}