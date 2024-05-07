/*
Task 3_2
Implement two functions that update the shared variable (declare it as global so it
will be available for the entire program and initialize it to 1).
One function increments the shared variable by one, and another decrement
the shared variable by one. In the main function assigns these two functions to
two threads and, at last, print the value of the shared variable.
The final value will be either 0 or 2. Apply semaphore sem_wait() and sem_post() to
avoid race condition and examine the output.

The general algorithm in both functions:
Step1: Copy the shared variable value to the local variable of the function
Step 2: Print the value of the local variable
Step 3: Increment or decrement the function's local variable by one 
(increment in one function and decrement in another)
Step 4: Print the local variable
Step 5: Call sleep() function for some seconds delay
Step 6: Copy the local variable value to the shared variable Step 7: Print the shared variable value
*/
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

int glob = 1;

//create variable of type semaphore
sem_t semaphore;

void *inc(void *a){
    sem_wait(&semaphore);
    int local = glob;
    printf("Local value before incrementing: %d\n", local);
    local++;
    printf("Local value after incrementing: %d\n", local);
    sleep(2);
    glob = local;
    printf("Global value after incrementing: %d\n", glob);
    sem_post(&semaphore);
    return NULL;
}

void *dec(void *a){
    sem_wait(&semaphore);
    int local = glob;
    printf("Local value before decrementing: %d\n", local);
    local--;
    printf("Local value after decrementing: %d\n", local);
    sleep(2);
    glob = local;
    printf("Global value after decrementing: %d\n", glob);
    sem_post(&semaphore);
    return NULL;
}

int main(void){
    pthread_t thread1, thread2;

    sem_init(&semaphore, 0, 1);

    pthread_create(&thread1, NULL, inc, NULL);
    pthread_create(&thread2, NULL, dec, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    sem_destroy(&semaphore);

    printf("Global variable after threads: %d\n", glob);
    return 0;
}