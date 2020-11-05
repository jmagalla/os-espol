#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

#define NTHREADS 3
#define TIMING 5
void *worker(void *argv)
{
    long datanum = (long) argv;
    printf("Worker thread #%ld running ...\n", datanum);
    sleep(5);
    printf("#%ld: work done, exiting now\n", datanum);
    pthread_exit((void *)0); /* Terminate with success: status value 0.
	                            * The join will pick this up. */
}
int main()
{
    long i;
    pthread_t tid[NTHREADS];
    pthread_attr_t attr;

    /* Init the thread attribute structure to defaults */
	pthread_attr_init(&attr);

    int status, ret;
    
    // Thread creation loop
	for (i = 0; i < NTHREADS; i++) {
        ret = pthread_create(&tid[i], &attr, worker, (void *) i);
        if (ret != 0)
            exit(ret);

    }
    pthread_attr_destroy(&attr);
    
    // Thread join loop
	for (i = 0; i < NTHREADS; i++) {
        ret = pthread_join(tid[i], (void **) &status);
        if (ret != 0)
            exit(ret);
        else
            printf("Thread #%ld successfully joined; it terminated with status=%d\n", i, status);
    }
    
    printf("\nmain: now done... Goodbye!\n");
	pthread_exit(NULL);
}