global _ft_putnbr

extern ft_putstr

section .text

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

_ft_putnbr:
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