extern _ft_strlen
global _ft_strcat

section .text

_ft_strcat:
	push	rbp
	mov		rbp, rsp

	test	rdi, rdi
	jz		null_dst

	test	rsi, rsi
	jz		null_src

	push	rdi
    push    rsi
	call	_ft_strlen
    add     rdi, rax
	mov		rdx, rdi
	mov		rdi, rsi
	call	_ft_strlen
	mov		rcx, rax
	mov		rdi, rdx
	rep		movsb
	mov		byte [rdi], 0x0
    pop     rsi
	pop		rax
	jmp		end

	null_dst:
		mov		rax, 0x0
		jmp		end

	null_src:
		mov		rax, rdi

	end:
		leave
		ret