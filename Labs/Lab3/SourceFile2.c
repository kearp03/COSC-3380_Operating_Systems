//file name: sourceFile2.c
#include <stdio.h>
#include "mylib.h"

int main(){
    double cpu_status=0;
    int task_load;
    printf("Start.......\n");
    task_load = 5;
    cpu_status = funtime_virtual_cpu(task_load);
    printf("%d tasks completed in %f time in seconds\n", task_load,cpu_status);
    return 0;
}