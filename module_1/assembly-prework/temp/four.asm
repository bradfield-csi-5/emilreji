section .data
    msgMatches        db  "Matches",10
    msgDoesntMatch    db  "Doesn't Match",10

global _start

section .text

_start:
    mov     rax, 1
    call    incRax
    cmp     rax, 2
    jne     .doesntMatch
    jmp     .matches

.matches:
    mov         rax, 1
    mov         rdi, 1
    mov         rsi, msgMatches
    mov         rdx, 8
    syscall
    jmp         .exit

.doesntMatch:
    mov         rax, 1
    mov         rdi, 1
    mov         rsi, msgDoesntMatch
    mov         rdx, 14
    syscall
    jmp         .exit

.exit:
    mov         rax, 60
    xor         rdi, rdi
    syscall

incRax:
    inc     rax
    ret