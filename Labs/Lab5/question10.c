/*
Question 10:
Write a c program to print the PID of the current running program's process and its parent process.
Note: you won't be using fork() in this program.

To monitor the process, you can use the ps command with the -u option, but you may fail to
observe the processes belonging to this program when you execute this program.
It happens so because of fast execution on the CPU.

One solution for it is: before the end of the program, place sleep() library function call
by passing some number of seconds as a parameter to pause and then, in a new terminal,
execute the ps command with the -u option or with -auxf option.

Second solution: At the end of your program, you can execute the same ps command along with
the program execution by passing it as a string constant parameter into the system() library function.
What is the PID of the current process and parent process? What does each process executing?
What does the STAT column indicate in the ps output?
STAT possible status values are D, R, S, T, W, X, Z, and sometimes along with
<, N, L, s, l, +. What is the meaning of these status values for a process?
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(void){
    printf("Current PID (our question10.c program): %d\n", getpid());
    printf("Current PPID (bash or terminal): %d\n", getppid());
    printf("Operating System Class....\n");

    system("ps -u");
    return 0;
}