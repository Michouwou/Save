section .text

global _ft_strlen

; Calculates the length of the string from
; the first character to the ending '\0'.
; Arguments :
; - string which length we want to calculate (rdi)
_ft_strlen:
	push	rbp
	mov		rbp, rsp

	push	rdi
	xor		rcx, rcx
	not		rcx
	mov		rax, 0x0
	cld
	repne	scasb
	not		rcx
	dec		rcx

	end:
		mov		rax, rcx
		xor		rcx, rcx

	pop		rdi
	leave
	ret