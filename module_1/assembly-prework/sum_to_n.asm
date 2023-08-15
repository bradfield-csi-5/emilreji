section   .text
global    _start

_start:
    mov       rdi, n		; n value
	xor 	  rax, rax		; setting rax to 0
.loop:
	add		  rax, rdi		; accumulates sum to rax
	dec		  rdi			; decrements rdi aka n val
	jg 		  .loop
print:		
	mov 	  rdi, 1		; these 4 steps for printing
	mov 	  rsi, rax
	mov       rdx, 8
	syscall
	mov       rax, 60       ; system call for exit
    xor       rdi, rdi      ; exit code 0
    syscall                 ; invoke operating system to exit

n  	equ       5