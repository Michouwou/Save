global _ft_strcat

section .text

; Prend en argument sur la pile deux chaines de caracteres,
; copy la premiere a la fin de la deuxieme et renvoie le
; resultat dans eax
_ft_strcat:
    push    ebp
    mov     ebp, esp

    mov     edi, [esp + 8]
    mov     esi, [esp + 12]
    push    edi

    toend:
        cmp     byte [edi], 0x0
        je      cpy
        inc     edi
        jmp     toend

    cpy:
        mov     al, byte[esi]
        mov     byte [edi], al
        cmp     byte [esi], 0x0
        je      end
        inc     edi
        inc     esi
        jmp     cpy

    end:

    pop     eax
    leave
    ret