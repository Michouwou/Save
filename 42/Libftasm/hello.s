global start

extern _malloc, _free

section .text

; Prend en argument sur la pile deux chaines de caracteres,
; copy la premiere a la fin de la deuxieme et renvoie le
; resultat dans eax
ft_strcat:
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

ft_memalloc:
    push    ebp
    mov     ebp, esp

    mov     edi, [esp + 8]
    call    _malloc
    add     esp, 0x4

    leave
    ret

; ft_strdup:
;     push    ebp,
;     mov     ebp, esp

;     mov     edi, [esp + 8]

;     xor     ecx, ecx
;     toen:
;         cmp     byte[edi + ecx], 0x0
;         je      duplicate
;         inc     ecx
;         jmp     toen



_putnbr:
    push    ebp
    mov     ebp, esp

    mov     ebx, [esp + 8] ; argument
    mov     eax, 0x1 ; on va donner a eax la valeur de la puissance de 10 juste en dessous du nombre a afficher
    mov     ecx, 0xa ; 10, pour la multiplication, on ne peut multiplier et diviser que les registres entre eux
    
    ten_pow:
        mul     ecx ; on multiplie eax par 10
        cmp     eax, ebx ; on regarde s'il est plus petit que le nombre
        jl      ten_pow ; si oui on continue

    ; vu qu'ici eax a en fait un puissance de 10 de trop, il faut le diviser
    xor     edx, edx ; on met edx a 0
    div     ecx ; on divise eax par 10
    mov     ecx, eax ; on met eax dans ecx (for later use)

    while: ; boucle pour afficher
        xor     edx, edx ; on met edx a 0
        mov     eax, ebx ; on met notre nombre dans eax
        div     ecx ; on divise par notre puissance de 10
        
        push    edx ; on sauvegarde les donnees
        push    eax
        call    _printnum ; on affiche le chiffre le plus a droite
        pop     eax
        pop     edx ; on recupere les donnees
        mov     ebx, edx ; on tej la partie du nombre qu'on a deja affiche (ex: 255 --> 55 ; 4637 --> 637 ...)

        mov     eax, ecx ; Il faut maintenant diviser ecx par 10 pour descendre d'une puissance de 10
        mov     ecx, 0xa ; on met 10 dans ecx, notre puissance est dans eax
        xor     edx, edx ; on met edx a 0
        div     ecx ; on divise
        mov     ecx, eax ; on remet notre puissance dans ecx

        cmp     ecx, 0x0 ; Si ecx vaut 0 c'est fini
        jne     while

    leave
    ret

_new_line:
    push    ebp
    mov     ebp, esp

    push    0x1
    push    nl
    call    _print

    leave
    ret

; To print a number (a single one) one screen.
; arguement has to be one the stack
_printnum:
    push    ebp
    mov     ebp, esp

    mov     eax, [esp + 8]
    add     eax, 0x30
    mov     byte [nb], al
    push    0x1
    push    nb
    call    _print
    add     esp, 8
    leave
    ret

; Function to print a string to
; the standard output.
; Arguments (to push on the stack in this same order):
; - length of the said string
; - string itself
_print:
    push    ebp
    mov     ebp, esp ; saving stack state

    mov     eax, [esp + 12]
    mov     ebx, [esp + 8] ; getting args
    push    eax ; len
    push    ebx ; msg
    push    0x1 ; fd
    mov     eax, 0x4 ; syscall
    sub     esp, 0x4 ; additional space
    int     0x80 ; interrupt

    add     esp, 16
; Here there's no need to clean the stack since it is a "function"
; and so with the two next instructions will leave the stack in the
; state it is before the call
    leave
    ret ; returning

start:
    ;push    len ; length of the string to write
    ;push    msg ; message to print

    
    ; mov     dword [string1], "plop"
    ; mov     dword [string2], "tutu"

    ; push    string1
    ; push    string2

    ; call    ft_strcat
    ; push    0x8
    ; push    eax
    ; call    _print

    ; add     esp, 0x10
    push    0x10
    call    ft_memalloc
    mov     dword [eax], "plop"
    push    0x4
    push    eax
    call    _print
    add     esp, 0xc

    push    0x0 ; exit status
    mov     eax, 0x1 ; sys_call = exit
    sub     esp, 0x4 ; additional space
    int     0x80 ; kernel

section .data

msg    db      "Hello, world!", 0xa
len   equ     $ - msg
nl      db     0xa

section .bss

nb      resb    0x1
string1 resb    0x14
string2 resb    0x14
