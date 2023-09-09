section .text
global binary_convert
binary_convert:
	xor rax, rax ; clears out rax to 0 so it can be used

	; rdi is first argument aka the binary num string
loop:
	cmp [rdi], byte 0 	; pulling of first bit and comparing to null
	je return_num		; if null, return with whatever is in rax as result
	xor rbx, rbx
	mov bl, [rdi]		; moving first bit from input into rdi's first byte aka bl
	sub bl, 48			; convert bit character to corresponding number (49 to 1 and 48 to 0)
	add rax, rbx		; bl corresponds to rbx

	jmp loop 			;
return_num:
	ret