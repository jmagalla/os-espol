//Use of execvp for call to exec.c demo program

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main()
{
    //A null terminated array of character
    //pointers
    char *args[] = {"./exec", NULL};
    execvp(args[0], args);

    /*All statements are ignored after execvp() call as this whole  
        process is replaced by another process (EXEC.c) */
    printf("Ending....\n");

    return 0;
}
