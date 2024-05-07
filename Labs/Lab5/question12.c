/*
Question 12:
Include two calls to fork() system call and print a message "Operating System Lab\n".
What will be the output? Explain the reason behind it.

Now, include one more call to fork() system call (total three calls) and print a message
"Operating System Lab\n". What will be the output? Explain the reason behind it.

How many processes are created in each case?
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(void){
    fork(); //2 processes -> parent and child
    fork(); //earlier 2 + new 2 -> from parent - one child; from 1st child - another child
    fork(); //2^n processes - n = fork system calls; 2^3 = 8

    printf("Operating Systems Class....\n");
    sleep(1);
    return 0;
}