//Predict the Output of the following program with string
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

int main()
{
    char x[64] = {'H', 'e', 'l', 'l', 'o'};

    if (fork() == 0)
    {
        strcat(x, " everyone;");
        printf("Child has x = %s\n", x);
    }
    else
    {
        strcat(x, " everyboby;");
        printf("Parent has x = %s\n", x);
    }
    return 0;
}