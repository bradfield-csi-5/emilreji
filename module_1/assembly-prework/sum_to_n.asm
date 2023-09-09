section   .text
global    sum_to_n

sum_to_n:
	xor 	  rax, rax		; setting rax to 0
.loop:
	add		  rax, rdi		; accumulates sum to rax
	dec		  rdi			; decrements rdi aka n val
	jg 		  .loop			; jg is jump if greater; jumps as long as rdi is greater than 0
	ret