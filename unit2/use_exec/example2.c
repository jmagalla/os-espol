// C program to illustrate  use of fork() and
// exec() system call for process creation

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/wait.h>

int main()
{
    pid_t pid;
    int status;
    pid = fork();

    if (pid == -1)
    {
        printf("can't fork, error occured\n");
        exit(EXIT_FAILURE);
    }
    else if (pid == 0) // child process 
    {
        printf("- child process, pid = %u\n", getpid());
        printf("- parent of child process, pid = %u\n", getppid());

        // the argv list first argument should point to filename associated with file being executed
        // the array pointer must be terminated by NULL pointer
        char *argv_list[] = { "ls", "-lart", "/home", NULL };
        
        // the execv() only return if error occured. The return value is -1
        execvp("/bin/ls", argv_list);
        exit(0);
    }
    else // pid > 0 then Parent process
    {
        printf("* parent of parent process, pid = %u\n", getppid());
        printf("* parent process, pid = %u\n", getpid());

        if (waitpid(pid, &status, 0) > 0)
            printf("program execution successful\n");
        else
            printf("waitpid() failed\n");

        exit(0);
    }
    return 0;
}