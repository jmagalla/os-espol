/* prod_no_condvar.c
   A simple POSIX threads producer-consumer example that doesn't use a condition variable.
   See also prod_condvar.c.
*/
#include <time.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <errno.h>

static pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;
static pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

static int avail = 0;

void *producer(void *arg)
{
    int cnt = atoi((char *)arg);
    
    for (int j = 0; j < cnt; j++)
    {
        sleep(1); 
        /* Code to produce a unit omitted */
        pthread_mutex_lock(&mtx);
        avail++; /* Let consumer know another unit is available */

        pthread_mutex_unlock(&mtx);
        pthread_cond_signal(&cond); /* Wake sleeping consumer */
    }

    return NULL;
}

int main(int argc, char *argv[])
{
    pthread_t tid;
    int s, j;
    int totRequired; /* Total number of units that all will produce */
    int numConsumed; /* Total units so far consumed */
    short done;
    time_t t;

    t = time(NULL);

    /* Create all threads */
    totRequired = 0;
    for (j = 1; j < argc; j++)
    {
        totRequired += atoi(argv[j]);
        pthread_create(&tid, NULL, producer, argv[j]);
    }

    /* Use a polling loop to check for available units */
    numConsumed = 0;
    done = 0;

for (;;)
{
    pthread_mutex_lock(&mtx);
    //Wait for something to consume
    pthread_cond_wait(&cond, &mtx); //wait for a signal
    while (avail > 0)
    { /* Consume all available units */
        /* Do something with produced unit */
        numConsumed++;
        avail--;
        printf("T=%ld: numConsumed=%d\n", (long)(time(NULL) - t), numConsumed);

        done = (numConsumed >= totRequired);
    }

    pthread_mutex_unlock(&mtx);
    if (done)
        break;

    /* Perhaps do other work here that does not require mutex lock */
}

    exit(EXIT_SUCCESS);
}