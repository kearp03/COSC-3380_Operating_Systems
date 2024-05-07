/*
Task 2_2:
Allow two threads to execute two separate functions.
One function updates the global variable, and another will not.
Print the variable value in both functions after calling the sleep( ) function with some seconds delay.
*/

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

int glob = 20;

void *function1(void *a){
	glob = 10;
	sleep(2);
	printf("The global variable is: %d\n", glob);
	return NULL;
}

void *function2(void *a){
	sleep(2);
	printf("The global variable is: %d\n", glob);
	return NULL;
}

int main(void){
	pthread_t thread1, thread2;

	pthread_create(&thread1, NULL, function1, NULL);
	pthread_create(&thread2, NULL, function2, NULL);

	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	return 0;
}