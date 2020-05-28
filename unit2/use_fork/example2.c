//Predict the Output of the following program
#include <stdio.h> 
#include <sys/types.h> 
#include <unistd.h> 
  
int main() 
{ 
    int x = 1; 
  
    if (fork() == 0) 
        printf("Child has x = %d\n", ++x); 
    else
        printf("Parent has x = %d\n", --x);

    return 0; 
} 