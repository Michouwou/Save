section .text

%define  SYS_CALL(x)    0x2000000 | x
%define  WRITE          0x4
%define  END            0x1

global _ft_putstr
extern _ft_strlen
; Function to print a string to
; the standard output.
; Arguments :
; - string itself (rdi)
_ft_putstr:
    push    rbp
    mov     rbp, rsp ; saving stack state

    call    _ft_strlen
    mov     rdx, rax
    mov     rax, 0x2000004
    mov     rsi, rdi
    mov     rdi, 1
    syscall

    leave
    ret ; returning