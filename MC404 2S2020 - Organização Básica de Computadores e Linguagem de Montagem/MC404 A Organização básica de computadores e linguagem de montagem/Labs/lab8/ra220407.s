.text
  .align 1
  .globl _start
_start:  

    li a0, 1000 # tempo (ms)
    li a1, 1 # frente (1) /trás (-1)
    li a2, -175 # direcao
    li a7, 2100 # syscall write (64)
    ecall

    li a0, 5000 # tempo (ms)
    li a1, 1 # frente (1) /trás (-1)
    li a2, 0 # direcao
    li a7, 2100 # syscall write (64)
    ecall

   
    


    li a0, 0 # exit code
    li a7, 93 # syscall exit
    _end:
    ecall
