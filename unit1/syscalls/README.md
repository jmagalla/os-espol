# System Calls
- A system call changes the processor state from user mode to kernel mode, so that the CPU can access protected kernel memory.
- The set of system calls is fixed. Each system call is identified by a unique number (This numbering scheme is not normally visible to programs, which identify system calls by name).
- Each system call may have a set of arguments that specify information to be transferred from user space (i.e., the process’s virtual address space) to kernel space and viceversa.

On Linux/x86-32, execve() is system call number 11 ( __NR_execve ). Thus, in the sys_call_table vector, entry 11 contains the address of sys_execve(), the service routine for this system call. (On Linux, system call service routines typically have names of the form sys_xyz(), where xyz() is the system call in question.)

## Handling system call errors
The manual page for each system call documents the possible return values of the call, showing which value(s) indicate an error. Usually, an error is indicated by a return of –1. Thus, a system call can be checked with code such as the following:

```bash
fd = open(pathname, flags, mode);
if (fd == -1) {
    /* Code to handle the error */
}
...
if (close(fd) == -1) {
    /* Code to handle the error */
}
```
When a system call fails, it sets the global integer variable errno to a positive value that identifies the specific error. Including the <errno.h> header file provides a declaration of errno, as well as a set of constants for the various error numbers. All of these symbolic names commence with E. The section headed ERRORS in each manual page provides a list of possible errno values that can be returned by each system call. Here is a simple example of the use of errno to diagnose a system call error:
```bash
cnt = read(fd, buf, numbytes);
if (cnt == -1) {
    if (errno == EINTR)
        fprintf(stderr, "read was interrupted by a signal\n");
    else {
        /* Some other error occurred */
   }
}
```

