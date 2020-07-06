/***
This program creates two threads, each of which executes the same function. 
The function executes a loop that repeatedly increments a global variable, glob, 
by copying glob into the local variable loc, incrementing loc, and copying loc back to glob. 
(Since loc is an automatic variable allocated on the per-thread stack, each thread has its own copy of this variable.)
The number of iterations of the loop is determined by the command-line argument
supplied to the program, or by a default value, if no argument is supplied
****/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <errno.h>

static volatile int glob = 0;  /* "volatile" prevents compiler optimizations of arithmetic operations on 'glob' */
static pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;

/* Loop 'arg' times incrementing 'glob' */
static void * threadFunc(void *arg)
{
    int loops = *((int *)arg);
    int loc, j, s;
    for (j = 0; j < loops; j++)
    {
        pthread_mutex_lock(&mtx); //Entering the critical section
        
        loc = glob;
        loc++;
        glob = loc;
        
        pthread_mutex_unlock(&mtx); //Leaving the critical section
    }
    return NULL;
}

int main(int argc, char *argv[])
{
    pthread_t t1, t2;
    int loops, s;

    if (argc > 1) 
        loops = atoi(argv[1]);
    else
        loops = 10000000;
    
    pthread_create(&t1, NULL, threadFunc, &loops);
    pthread_create(&t2, NULL, threadFunc, &loops);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    
    printf("glob = %d\n", glob);
    exit(EXIT_SUCCESS);
}