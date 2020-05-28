// C program to demonstrate working of status from wait.
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main()
{
    pid_t pid;
    int status;
    
    // This status 1 is reported by WEXITSTATUS
    if (fork() == 0)
        exit(1);
    else {
        waitpid(&status);
        if (WIFEXITED(status))
            printf("Exit status: %d\n", WEXITSTATUS(status));
        else if (WIFSIGNALED(status))
            psignal(WTERMSIG(status), "Exit signal");
    }
    return 0;
}