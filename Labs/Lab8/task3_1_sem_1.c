/*
Task 3_1_sem_1
Implement a function that increments the shared variable (declare it as global) 10 times.
Print the final variable value in the main function after assigning the implemented function
to two threads. In each execution or run, keep increasing the number of times you increment
the shared variable by multiples of 10. Apply semaphore sem_wait() and sem_post() to avoid
race condition and examine the output by increasinging the number of times you increment
the shared variable.
*/

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

int glob = 0;

//Declare semaphore variable
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
    pthread_t thread1, thread2;

    //Initialize semaphore variable
    sem_init(&semaphore, 0, 1);

    pthread_create(&thread1, NULL, function, NULL);
    pthread_create(&thread2, NULL, function, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    sem_destroy(&semaphore);

    printf("Global variable after threads: %d\n", glob);
    return 0;
}