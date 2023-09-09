section .data
    num1:       equ 100
    num2:       equ 50
    msgRight    db  "Sum is correct\n"
    msgWrong    db  "Sum is incorrect\n"

section .text
    global _start

_start:
    mov         rax, num1
    mov         rbx, num2
    add         rax, rbx
    cmp         rax, 150
    jne         .wrongSum
    jmp         .rightSum

.rightSum:
    mov         rax, 1
    mov         rdi, 1
    mov         rsi, msgRight
    mov         rdx, 15
    syscall
    jmp         .exit

.wrongSum:
    mov         rax, 1
    mov         rdi, 1
    mov         rsi, msgWrong
    mov         rdx, 17
    syscall
    jmp         .exit

.exit:
    mov         rax, 60
    xor         rdi, rdi
    syscall