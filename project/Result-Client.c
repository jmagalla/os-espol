/* Linux Headers */
#include <sys/mman.h> 		/* Includes mmap(), unmmap(). */
#include <sys/stat.h>

#include <fcntl.h>		/* Contains O_ constants. */
#include <unistd.h>
#include <semaphore.h>
#include <libgen.h>

/* C Standard Headers */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

/*
 * Provides access to more features to program_invocation_short_name
 * in errno.h and psignal() in signal.h.
 */
#define __GNU_SOURCE		 
#include <signal.h>
#include <errno.h>

int main(int argc, char *argv[]) {
     return 0;
}