section .text
global _start
;https://codereview.stackexchange.com/questions/244968/printing-a-number-from-memory-in-assembly
_start:
    mov  rcx, rsp
    sub  rsp, 16        ; Room for at most 10 digits (keep ESP dword-aligned)
    mov  rax, [12]
    mov  rbx, 10        ; CONST

.loop:
    xor  rdx, rdx
    div  rbx            ; Divide EDX:EAX by 10
    dec  rcx
    add  rdx, '0'       ; From remainder [0,9] to character ['0','9']
    mov  [rcx], dl
    test rax, rax       ; Is quotient zero?
    jnz  .loop

    mov  rax, 4         ; Write system call
    mov  rbx, 1         ; STDOUT
    lea  rdx, [rsp+16]
    sub  rdx, rcx
    int  0x80
    add  rsp, 16        ; Clean-up

    mov rax, 1
    mov rdi, 1
    mov rsi, rbx
    mov rdx, 8
    syscall
    mov rax, 60
    xor rdi, rdi
    syscall
    ret
