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

	push	rdi
	push	rsi

	to_end:
		cmp		rcx, rsi
		je		end
		mov		byte [rdi], byte 0x0
		inc		rdi
		inc		rcx
		jmp		to_end

	end:
		pop		rsi
		pop		rdi
		xor		rcx, rcx

	leave
	ret