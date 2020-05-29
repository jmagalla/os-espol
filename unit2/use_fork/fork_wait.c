// C program to demonstrate working of wait()
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main()
{
    if (fork() == 0) 
    {
        printf("HC: hello from child\n");
        exit(0);
    }
    else
    {
        printf("HP: hello from parent\n");
        wait(NULL); // after calling wait(), parent process has to be in wait state if no child terminates.
        printf("CT: child has terminated\n");
        exit(0);
    }

    printf("Bye\n");
    return 0;
}
