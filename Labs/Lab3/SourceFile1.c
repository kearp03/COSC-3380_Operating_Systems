//file name: sourceFile1.c
#include <stdio.h>
#include <math.h>

int main(void){
    float var1,  var2=0;
    printf("Start......\n");
    var1 = 20;
    var2 = sqrt(var1);
    printf("%f is the current value in var2...\n", var2); var2 = 30;
    var1 = pow(var2,2);
    printf("%f is the current value in var1...\n", var1); return 0;
}