/*
Task 3_1_mutex_1
Implement a function that increments the shared variable (declare it as global) 10 times.
Print the final variable value in the main function after assigning the implemented function
to two threads. In each execution or run, keep increasing the number of times you increment
the shared variable by multiples of 10. Apply pthread mutex lock and unlock to avoid race
condition and examine the output by increasing the number of times you increment the shared variable.
*/

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

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
    pthread_t thread1, thread2;

    pthread_mutex_init(&mutex, NULL);

    pthread_create(&thread1, NULL, function, NULL);
    pthread_create(&thread2, NULL, function, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    pthread_mutex_destroy(&mutex);

    printf("Global variable after threads: %d\n", glob);
    return 0;
}