/*
Task 3_2
Implement two functions that update the shared variable (declare it as global so it
will be available for the entire program and initialize it to 1).
One function increments the shared variable by one, and another decrement
the shared variable by one. In the main function assigns these two functions to
two threads and, at last, print the value of the shared variable.
The final value will be either 0 or 2, and why?

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

int glob = 1;

void *inc(void *a){
    int local = glob;
    printf("Local value before incrementing: %d\n", local);
    local++;
    printf("Local value after incrementing: %d\n", local);
    sleep(2);
    glob = local;
    printf("Global value after incrementing: %d\n", glob);
    return NULL;
}

void *dec(void *a){
    int local = glob;
    printf("Local value before decrementing: %d\n", local);
    local--;
    printf("Local value after decrementing: %d\n", local);
    sleep(2);
    glob = local;
    printf("Global value after decrementing: %d\n", glob);
    return NULL;
}

int main(void){
    pthread_t thread1, thread2;

    pthread_create(&thread1, NULL, inc, NULL);
    pthread_create(&thread2, NULL, dec, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("Global variable after threads: %d\n", glob);
    return 0;
}