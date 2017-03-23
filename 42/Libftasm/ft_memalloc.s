global _ft_memalloc

extern _malloc

section .text

_ft_memalloc:
    push    rbp
    mov     rbp, rsp

    push    rax
    call    _malloc
    add     rsp, 0x4

    leave
    ret