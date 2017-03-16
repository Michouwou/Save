global _ft_puts
extern _ft_putstr

section .text

_ft_puts:
	push	rbp
	mov		rbp, rsp

	cmp		rdi, 0x0
	je		null
	call	_ft_putstr

	jmp		no

	null:
		mov		rdi, null_str
		call	_ft_putstr

	no:
		mov		rax, 0xa

	leave
	ret

section .data
null_str	db "(null)", 0xa