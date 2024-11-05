section .data
    texto db "Hello World", 0  

section .text
    global _start 

extern  printf, exit  

_start:
    ; Passando o endereço da string para o printf
    push    texto
    call    printf
    add     esp, 4    
  
    push    0          
    call    exit       