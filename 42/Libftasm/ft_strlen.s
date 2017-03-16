section .text

global _ft_strlen

; Calculates the length of the string from
; the first character to the ending '\0'.
; Arguments :
; - string which length we want to calculate (rdi)
_ft_strlen:
	push	rbp
	mov		rbp, rsp

	xor		rcx, rcx
	push	rdx
	mov		rdx, rdi

	to_end:
		cmp		byte [rdx + rcx], byte 0x0
		je		end
		inc		rcx
		jmp		to_end

	end:
		pop		rdx
		mov		rax, rcx
		xor		rcx, rcx

	leave
	ret