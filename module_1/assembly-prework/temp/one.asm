section .text
global _start
_start:
    mov         rax, 1
    mov         rdi, 1
    mov         rsi, msg
    mov         rdx, 14
    syscall
    mov         rax, 60
    xor         rdi, rdi    ; more efficient way of doing: mov    rdi, 0
    syscall
    ret
section .data
    msg db      "hello, world!",10