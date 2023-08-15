	global   _start
	section	 .text
_start:
    mov       rdi, n		; n value
	mov		  rax, 0
loop:
	add		  rax, rdi
	dec		  rdi
	cmp		  rdi, 0
	jne		  loop
rest:
	ret
n  	equ       5