#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>


int main(void)
{
	unsigned long int i = 1;

	while (1) {
		printf("Lazo, iteración #%02ld ...\n", i++);
		(void)sleep(1);
	}

	exit(EXIT_SUCCESS);
}