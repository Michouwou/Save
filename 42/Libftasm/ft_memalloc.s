global _ft_memalloc

extern _malloc

section .text

_ft_memalloc:
    push    ebp
    mov     ebp, esp

    push    eax
    call    _malloc
    add     esp, 0x4

    leave
    ret