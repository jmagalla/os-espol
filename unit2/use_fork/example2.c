//Predict the Output of the following program
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    int x = 1;

    if (fork() == 0)
        printf("Child has x = %d, %p\n", ++x, &x);
    else
        printf("Parent has x = %d, %p\n", --x, &x);

    return 0;
}