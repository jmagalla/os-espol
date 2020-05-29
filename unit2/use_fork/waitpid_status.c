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
    pid = fork();
    if (pid == -1)
    {
        printf("can't fork, error occured\n");
        exit(EXIT_FAILURE);
    }
    else if (pid == 0) // child process
    {
        printf("- child process, pid = %u\n", getpid());
        exit(0);
    }
    else //parent process
    {
        if (waitpid(pid, &status, 0) > 0) // return pid the process if the call system it's ok
        {
            if (WIFEXITED(status))                                // WIFEXITED(status) child exited normally
                printf("Exit status: %d\n", WEXITSTATUS(status)); //WEXITSTATUS(status): return code when child exits
            else if (WIFSIGNALED(status))                         //child exited because a signal was not caught
                psignal(WTERMSIG(status), "Exit signal");
        }
        else
        {
            printf("waitpid() failed\n");
            exit(-1);
        }
    }
    return 0;
}