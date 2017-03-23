section .text

%define  SYS_CALL(x)    0x2000000 | x
%define  WRITE          0x4
%define  END            0x1

extern _ft_putstr
extern _ft_strlen
extern _ft_puts
extern _ft_bzero
extern _ft_strcat
global _start

_start:

    mov		rdi, dat
    mov		rsi, msg
    call	_ft_strcat

    mov		rdi, rax
    mov		rsi, msg
    call 	_ft_strcat

    mov		rdi, dat
    call	_ft_putstr

    mov     rax, SYS_CALL(END)
    mov     rbx, 0x0
    syscall

section .data

msg     db "Hello!", 0xa, 0x0
len     equ $ - msg

section .bss
dat resb 30