# [SOCA] Sistema Operacional do Carro Autônomo 
.globl _start
.text
.align 4

li t5, 10 #debug
int_handler:
    ###### Tratador de interrupções e syscalls ######
    # <= Implemente o tratamento da sua syscall aqui =>
   
    csrrw sp, mscratch, sp
    addi sp, sp, -8
    sw a3, 0(sp)
    sw a4, 4(sp)
    #sw a2, 8(sp)
    #sw a3, 12(sp)

    #Tratamento:
    li a3, 10
    beq a7, a3, setmotor
    li a3, 11
    beq a7, a3, sethand
    li a3, 12
    beq a7, a3, readsensors
    li a3, 13
    beq a7, a3, sensordis
    li a3, 14
    beq a7, a3, gettime
    li a3, 15
    beq a7, a3, getposition
    li a3, 16
    beq a7, a3, getrotation

    li t5, 11 #debug

    setmotor:
      li t5, 5 #debug
      #0xFFFF0121 - vertical
      li a3, 0xFFFF0121
      sb a0, 0(a3) 
      
      #0xFFFF0120 - horizontal 
      li t5, 6 #debug
      li a3, 0xFFFF0120
      sb a1, 0(a3)

      li a0, 0 #retorno
      li t5, 7 #debug
      j termina
    
    sethand:
      #0xFFFF0122 - 1 ativa
      li a3, 0xFFFF0122
      sb a0, 0(a3)
      lb t6, 0(a3)
      
      j termina
    
    readsensors:
      #0xFFFF0101 - 1 inicia leitura, quando acaba coloca 0
      li a3, 0xFFFF0101
      li a4, 1
      sb a4, 0(a3) #coloca 1 no endereço, dando início

      espera1:
        lb a4, 0(a3)
        beq a4, zero, fimespera1
        j espera1

      fimespera1:

      li t5, 14 #debug
      #0xFFFF0124 - os valores ficam armazenados a partir desse endereço
      li a3, 0xFFFF0124
      #256 vezes
      li t4, 256
      li t2, 0

      loop256:
        beq t2, t4, fimloop 
        lb a4, 0(a3)
        sb a4, 0(a0)

        addi a0, a0, 0x1
        addi a3, a3, 0x1
        addi t2, t2, 1

        j loop256
      
      fimloop:
        li t5, 15 #debug
        j termina
    
    sensordis:
      #0xFFFF0102 - 1 inicia leitura, quando acaba coloca 0
      li a3, 0xFFFF0102
      li a4, 1
      sb a4, 0(a3) #coloca 1 no endereço, dando início

      espera2:
        lb a4, 0(a3)
        beq a4, zero, fimespera2
        j espera2
 
      fimespera2:

      #0xFFFF011C - distancia em cm
      li a3, 0xFFFF011C
      lw a0, 0(a3) #a0 é o retorno
      
      j termina
    
    gettime:
      li t5, 12 #debug
      #0xFFFF0300 - 1 inicia leitura, quando acaba coloca 0
      li a3, 0xFFFF0300
      li a4, 1
      sb a4, 0(a3) #coloca 1 no endereço, dando início

      espera3:
        lb a4, 0(a3)
        beq a4, zero, fimespera3
        j espera3        

      fimespera3:

      #0xFFFF0304 - tempo atual em ms
      li a3, 0xFFFF0304
      lw a0, 0(a3) #a0 é o retorno
      li t5, 13 #debug
      j termina
    
    getposition:
      #0xFFFF0100 - 1 inicia leitura, quando acaba coloca 0
      li a3, 0xFFFF0100
      li a4, 1
      sb a4, 0(a3) #coloca 1 no endereço, dando início

      espera4:
        lb a4, 0(a3)
        beq a4, zero, fimespera4
        j espera4

      fimespera4:


      #0xFFFF0110 - posição x em cm
      li a3, 0xFFFF0110
      lw a4, 0(a3)
      sw a4, 0(a0)
      #0xFFFF0114 - posição y em cm
      li a3, 0xFFFF0114
      lw a4, 0(a3)
      sw a4, 0(a1)
      #0xFFFF0118 - posição z em cm
      li a3, 0xFFFF0118
      lw a4, 0(a3)
      sw a4, 0(a2)

      j termina
    
    getrotation:
      #0xFFFF0100 - 1 inicia leitura, quando acaba coloca 0
      li a3, 0xFFFF0100
      li a4, 1
      sb a4, 0(a3) #coloca 1 no endereço, dando início

      espera5:
        lb a4, 0(a3)
        beq a4, zero, fimespera5
        j espera5

      fimespera5:

      #0xFFFF0104 - ângulo de Euler x
      li a3, 0xFFFF0104
      lw a4, 0(a3)
      sw a4, 0(a0)
      #0xFFFF0108 - ângulo de Euler y
      li a3, 0xFFFF0108
      lw a4, 0(a3)
      sw a4, 0(a1)
      #0xFFFF010C - ângulo de Euler z
      li a3, 0xFFFF010C
      lw a4, 0(a3)
      sw a4, 0(a2)

      j termina
    
    termina:
    li t5, 8 #debug
    #lw a3, 12(sp)
    #lw a2, 8(sp)
    lw a4, 4(sp)
    lw a3, 0(sp)
    addi sp, sp, 8
    csrrw sp, mscratch, sp

    csrr t0, mepc  # carrega endereço de retorno (endereço da instrução que invocou a syscall)
    addi t0, t0, 4 # soma 4 no endereço de retorno (para retornar após a ecall)
    csrw mepc, t0  # armazena endereço de retorno de volta no mepc
    li t5,9 #debug
    mret           # Recuperar o restante do contexto (pc <- mepc)



_start:
    la t0, int_handler  # Carregar o endereço da rotina que tratará as syscalls
    csrw mtvec, t0      # no registrador MTVEC

    li t5,1 #debug
    # Aqui você deve mudar para modo usuário, ajustar a pilha do usuário para
    # 0x7fffffc e saltar para o código de usuário (user_code)
    csrr t1, mstatus # Update the mstatus.MPP
    li t2, ~0x1800 # field (bits 11 and 12)
    and t1, t1, t2 # with value 00 (U-mode)
    csrw mstatus, t1

    li sp, 0x7fffffc

    la t0, user_code # Loads the user software
    csrw mepc, t0 # entry point into mepc
    li t5, 2 #debug
    mret



  loop_infinito:
    j loop_infinito
