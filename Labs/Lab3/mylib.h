//file name: mylib.h
#include <time.h> // for clock_t, clock(), CLOCKS_PER_SEC 
#include <unistd.h> // for sleep()
//returns the amount of time taken by the underlying operating system to run the proc ess
//It returns the clock_t type, which stores the total number of clock ticks.
double funtime_virtual_cpu(int task_load){
int i;
    double time_spent = 0.0;
    clock_t begin = clock(); //returns the amount of time taken by the underlying operating system to run the process
    for(i = 0; i < task_load; i++){
        // do some stuff here
        sleep(3); 
    }
    clock_t end = clock();
    // calculate elapsed time by finding difference (end - begin) and // dividing the difference by CLOCKS_PER_SEC to convert to seconds
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    return time_spent;
}