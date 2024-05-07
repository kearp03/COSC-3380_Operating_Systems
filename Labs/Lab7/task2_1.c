/*
Task 2_1:
Update a variable value in the child process and don't update it in the parent process block of code.
Try to print the variable in the common block, which both the parent and child processes can execute.
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(){
	int value = 111;
	printf("Before forking...%d\n", getpid());
	pid_t cpid = fork(); //child process created with same image
	switch(cpid){
		case -1:
			printf("Error: unable to create child process");
			break;
		case 0:
			//child
			printf("Child process: %d", getpid());
			printf("Current process' child pid: %d\n", cpid);
			value = 555;
			break;
		default:
			printf("Parent process: %d", getpid());
			printf("Current process' child pid: %d\n", cpid);
			//parent
	}
	//Common area: executed by both process
	printf("Value = %d\n", value);
	return 0;
}