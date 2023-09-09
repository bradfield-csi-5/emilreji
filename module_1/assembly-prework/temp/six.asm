section .text
global _start
_start:
    mov     rax, 1234    ; rsp is 0xe0b0
    push    rax          ; rsp is 0xe0a8 ; seems to have decremented by 8
    pop     rax          ; rsp is 0xe0b0 ; seems to have incremented by 8
    ret
