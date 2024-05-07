//prints 20 numbers

#include <stdio.h>
#include <unistd.h>

int main(void){
    printf("Printing odd numbers....%d\n", getpid());
    for(int i = 1; i <= 40; i += 2) printf("%d\t", i);
    printf("\n");
    return 0;
}