section .text

%define  SYS_CALL(x)    0x2000000 | x
%define  WRITE          0x4
%define  END            0x1

extern _ft_putstr
extern _ft_strlen
extern _ft_puts
extern _ft_bzero
global _start

_start:

	mov		rdi, string
	mov		qword [rdi], 'qqqq'
	mov		byte [rdi + 4], 0xa
    call    _ft_puts

    mov		rdi, string
    inc		rdi
    mov		rsi, 3
    call	_ft_bzero

    mov		rdi, string
    call	_ft_puts

    mov     rax, SYS_CALL(END)
    mov     rbx, 0x0
    syscall

section .data

msg     db "Hello!", 0xa, 0x0
len     equ $ - msg

section .bss

string	resb 30