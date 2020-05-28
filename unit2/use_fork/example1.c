//Calculate number of times hello is printed
#include <stdio.h> 
#include <sys/types.h> 
int main() 
{ 
    fork(); 
    fork(); 
    fork(); 
    printf("hello\n"); 
    return 0; 
} 
