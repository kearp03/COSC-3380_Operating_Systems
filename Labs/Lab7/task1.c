/*
Task 1: 
Program to check whether two threads are running sequentially or parallelly.
Implement a function that is assigned to two threads for execution.
In the function, use the sleep( ) function call with some seconds
delay between two message printing statements.
*/

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void *testFunction(){
	printf("Operating System\n");
	sleep(2);
	printf("lab\n");
	return NULL;
}

int main(){
	pthread_t t_1, t_2;
	pthread_create(&t_1, NULL, testFunction, NULL);
	pthread_create(&t_2, NULL, testFunction, NULL);
	pthread_join(t_1, NULL);
	pthread_join(t_2, NULL);
	return 0;
}