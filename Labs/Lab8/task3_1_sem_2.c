/*
Task 3_1_sem_2
Examine the same with and without pthread mutex by assigning to more than two threads.
*/

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

int len = 10;
int glob = 0;

//create variable of type semaphore
sem_t semaphore;

void *function(void *a){
    for(int i = 0; i < 10000; i++){
        sem_wait(&semaphore);
        glob++;
        sem_post(&semaphore);
    }
    return NULL;
}

int main(void){
    pthread_t threads[len];

    sem_init(&semaphore, 0, 1);

    for(int i = 0; i < len; i++) pthread_create(&(threads[i]), NULL, function, NULL);

    for(int i = 0; i < len; i++) pthread_join((threads[i]), NULL);

    sem_destroy(&semaphore);

    printf("Global variable after threads: %d\n", glob);
    return 0;
}