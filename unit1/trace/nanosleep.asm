section .data
	hello:     db 'Hello world!',10    ; 'Hello world!' plus a linefeed character
	helloLen:  equ $-hello             ; Length of the 'Hello world!' string
	                                   ; (I'll explain soon)
	timeval:
		tv_sec  dd 0
		tv_usec dd 0

section .text
	global _start

_start:
	; Sleep for 2.5 seconds, 2 secs and 500000000 nsec
	mov dword [tv_sec], 2
	mov dword [tv_usec], 500000000
	mov eax, 162 		 ; The system call for nanosleep
	mov ebx, timeval
	mov ecx, 0
	int 80h

	mov eax,4            ; The system call for write (sys_write)
	mov ebx,1            ; File descriptor 1 - standard output
	mov ecx,hello        ; Put the offset of hello in ecx
	mov edx,helloLen     ; helloLen is a constant, so we don't need to say
	                     ;  mov edx,[helloLen] to get it's actual value
	int 80h              ; Call the kernel

	mov eax,1            ; The system call for exit (sys_exit)
	mov ebx,0            ; Exit with return code of 0 (no error)
	int 80h
