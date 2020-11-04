/* Another resource to see in https://www.geeksforgeeks.org/errors-in-cc/ */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>  /* Prototypes for many system calls */
#include <fcntl.h>  /* Prototypes for file control options */
#include <errno.h>  /* Prototypes for handle errors */
#include <string.h>  /* Prototypes for handle errors */

int main(int argc, char** argv) {
    if (argc != 2) {
        fprintf(stderr, "Error of use: ./mysyscall filename\n"); /* write to standart error */
        exit(EXIT_FAILURE);
    }
    
    int fd;
    /* Usually, an error is indicated by a return of –1 */
    fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        /*Code to handle the error*/
        printf("Value of the errno: %d\n", errno);
        //fprintf(stderr, "The error messages is %s\n", strerror(errno));
        perror("Error in open");
        exit(EXIT_FAILURE);
    }
    else
    {
        /*Code success*/
        close(fd);
        printf("Success.\n");
    }
    
    exit(EXIT_SUCCESS);
}