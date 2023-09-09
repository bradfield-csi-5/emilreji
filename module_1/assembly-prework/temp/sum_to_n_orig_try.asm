section   .text
global    _start

_start:
	mov		  rdi, n		; n value
	xor 	  rax, rax		; setting rax to 0
.loop:
	add		  rax, rdi		; accumulates sum to rax
	dec		  rdi			; decrements rdi aka n val
	jg 		  .loop
print: ; there 4 steps for printing; we are calling write syscall with 3 args
	mov 	  rdi, 1		; 3 args are file descriptor of stdout, buffer, and bytes
	mov 	  rsi, rax		; rax is return value
	mov       rdx, 8		; arguments: rdi, rsi, rdx, rcx
	mov       rax, 1		; setting up syscall to be called with 1 for write
	syscall
	mov		  rax, 60       ; system call for exit
	xor		  rdi, rdi      ; exit code 0
	syscall                 ; invoke operating system to exit

section   .data
n  	equ       5
message:  db        "Hello World", 10

;To print integer with write system call, must convert integer to array of characters 
;and then pass a pointer to the array of characters into write's 2nd arg