/*
https://www.classes.cs.uchicago.edu/archive/2018/spring/12300-1/lab6.html

This code demonstrates:

How to create a thread
How to pass an argument to a thread
How to force C to accept an int into the generic void* parameter, by casting
How to return a result from a thread
How to use casting to work between the generic and the specific again here
How to wait for a thread to complete, and get its return value

*/

#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

void* func(void* x) {
    int xi = (int)x;

    printf("Inside thread; x = %d\n", xi);

    return (void*)(xi + 123);
}

int main(int argc, char** argv) {
    pthread_t th;
    pthread_create(&th, NULL, func, (void*)100);

    void* ret_from_thread;
    int ri;
    pthread_join(th, &ret_from_thread);
    ri = (int)ret_from_thread;

    printf("Outside thread, which returned %d\n", ri);
    return 0;
}
