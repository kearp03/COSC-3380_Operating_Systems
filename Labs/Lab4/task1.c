/*
Task-01
Write a C program to print the "Operating Systems" message on the screen using the write()
system call. Print the number of characters/bytes printed on the screen.
What happens if the third parameter is smaller or bigger than the message string?
*/
#include <unistd.h>
#include <stdio.h>

int main(void){
    //fd - file decriptor for minitor representing file is 1 and keyboard is 0
    int countWritten = 0;
    countWritten = write(1, "Operating Systems", 18);
    printf("\n%d characters/bytes printed to the screen\n", countWritten);
    return 0;
}