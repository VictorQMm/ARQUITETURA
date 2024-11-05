.data 
    texto: .asciz "Hello World\n"

.texto.global _start

_start:
    movl $texto, %eax       
    pushl %eax
    call printf
    addl $4, %esp          
    call exit

