/*
Task 3_1_mutex_2
Examine the same with and without pthread mutex by assigning to more than two threads.
*/

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

int len = 10;
int glob = 0;

//create variable of type mutex
pthread_mutex_t mutex;

void *function(void *a){
    for(int i = 0; i < 10000; i++){
        pthread_mutex_lock(&mutex);
        glob++;
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

int main(void){
    pthread_t threads[len];

    pthread_mutex_init(&mutex, NULL);

    for(int i = 0; i < len; i++) pthread_create(&(threads[i]), NULL, function, NULL);

    for(int i = 0; i < len; i++) pthread_join((threads[i]), NULL);

    pthread_mutex_destroy(&mutex);

    printf("Global variable after threads: %d\n", glob);
    return 0;
}