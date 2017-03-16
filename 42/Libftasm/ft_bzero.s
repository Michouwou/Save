global _ft_bzero

section .text

; Function to zero-pad a whole string given as
; a parameter up to a certain index.
; Arguments :
; - string (rdi)
; - length to zero-pad (rsi)
_ft_bzero:
	push	rbp
	mov		rbp, rsp

	xor		rcx, rcx
	push	rdx
	push	rsi
	mov		rdx, rdi

	to_end:
		cmp		rcx, rsi
		je		end
		mov		byte [rdx + rcx], byte 0x0
		inc		rcx
		jmp		to_end

	end:
		pop		rsi
		pop		rdx
		mov		rax, rcx
		xor		rcx, rcx

	leave
	ret