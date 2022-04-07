.text
  .align 1
  .globl _start

_start:  
  # Converte angulo inteiro para radianos e coloca em f0
  jal funcao_pegar_angulo
  # Utilizado para calcular a série
  jal funcao_calcula_serie
  # Transforma um PF para inteiro, onde a0 contem o sinal, a1 a parte inteira e a2 a parte fracionaria (truncada com 3 casas decimais)
  jal funcao_float_para_inteiro
  # Imprime o resultado de a0, a1 e a2 na tela
  jal funcao_imprime
  
  li a0, 0 # exit code
  li a7, 93 # syscall exit
  ecall
  
funcao_calcula_serie:
  addi sp, sp, -8
  sw ra, 0(sp)
  sw s0, 4(sp)
  addi s0, sp, 8
  
  # Neste ponto o registrador f0 contem o valor de angle em radianos
  # *********************************************
  # ** INSIRA AQUI SEU CÓDIGO PARA CÁLCULO DA SERIE **
  #f1 contém pi

  li t0, 2
  fcvt.s.w f7, t0  #f7=2.0
  li t0, 3
  fcvt.s.w f6, t0  #f6=3.0

  fdiv.s f8, f1, f7   #f8=pi/2
  fmul.s f9, f1, f7   #f9=2pi
  fmul.s f10, f1, f6 
  fdiv.s f10, f10, f7  #f10=3pi/2

  fle.s t0, f0, f8 
    bne t0, zero, menorigual90
  fle.s t0, f0, f1
    bne t0, zero, menorigual180
  fle.s t0, f0, f10
    bne t0, zero, menorigual270
  fle.s t0, f0, f9
    bne t0, zero, menorigual360  

  menorigual90:
    li t5, 1
    j continue
  menorigual180:
    fsub.s f0, f1, f0
    li t5, 1
    j continue
  menorigual270: 
    fsub.s f0, f0, f1 
    li t5, 0
    j continue
  menorigual360:
    fsub.s f0, f9, f0
    li t5, 0 
    j continue

  continue:
  #variáveis
  li t0, 0  #guarda o número n da iteração atual
  li t2,0
  fcvt.s.w f1, t2    #f1 vai guardar a soma da sequência

  #constantes:
  li t1, 11 #guarda o valor que faz sair do for
  li t3, 2
  li t4, 1
  fcvt.s.w f6, t2  #f6=0.0

  for:
    bge t0, t1, cont    #se n for >=11 sai do for
    mv t2, t0  #guarda o valor n da iteração atual em t2 
    mul t2, t3, t2    # t2=2*n
    addi t2, t2, 1    # t2=2*n+1 

    fadd.s f3, f0, f6   # f3=xfcvt.s.w f6, t0
    for2:
      ble t2, t4, cont2     #se for <=1 sai do for2
      fmul.s f3, f3, f0
      fcvt.s.w f2, t2
      fdiv.s f3, f3, f2
      addi t2, t2, -1
      j for2
    
    cont2:    
    rem t6, t0, t3    # t6=resto de n%2
    li t4, 1
    
    addi t0, t0, 1
    
    beq t6, t4, impar
    #par:
      fadd.s f1, f1, f3
      j for
    impar:
      fsub.s f1, f1, f3
      j for
    
  cont:
    fadd.s f0, f1, f6
    fle.s t0, f0, f6    #1 se negativo, 0 se positivo

  vaila:

  # *********************************************
  
  lw ra, 0(sp)
  lw s0, 4(sp)
  addi sp, sp, 8
  jr ra


funcao_imprime:
  addi sp, sp, -8
  sw ra, 0(sp)
  sw s0, 4(sp)
  addi s0, sp, 8
  
  # Neste ponto os registradores contem:
  #   a0 -> valor 0 se f0 for negativo e !=0 caso contratio
  #   a1 -> Parte inteira de f0
  #   a2 -> Parte fracionaria de f0 (truncada com 3 casas decimais, i.e. 0 a 999)
  # **************************************
  # ** INSIRA AQUI SEU CÓDIGO PARA IMPRESSÃO **

  mv t0, t5   #ignorei o a0
  mv t1, a1
  mv t2, a2

  #t3:
  li a4, 0
  beq t1, a4, t3zero
  li a4, 1
  beq t1, a4, t3um
  
  t3zero:
    li t3, '0'
    j t4
  t3um:
    li t3, '1'


  t4:
  #t4=primeiro dígito dos três
  li a5, 100
  div t1, t2, a5

  li a4, 0
  beq t1, a4, t4zero
  li a4, 1
  beq t1, a4, t4um
  li a4, 2
  beq t1, a4, t4dois
  li a4, 3
  beq t1, a4, t4tres
  li a4, 4
  beq t1, a4, t4quatro
  li a4, 5
  beq t1, a4, t4cinco
  li a4, 6
  beq t1, a4, t4seis
  li a4, 7
  beq t1, a4, t4sete
  li a4, 8
  beq t1, a4, t4oito
  li a4, 9
  beq t1, a4, t4nove
  
  t4zero:
    li t4, '0'
    j t5
  t4um:
    li t4, '1'
    j t5
  t4dois:
    li t4, '2'
    j t5
  t4tres:
    li t4, '3'
    j t5
  t4quatro:
    li t4, '4'
    j t5
  t4cinco:
    li t4, '5'
    j t5
  t4seis:
    li t4, '6'
    j t5
  t4sete:
    li t4, '7'
    j t5
  t4oito:
    li t4, '8'
    j t5
  t4nove:
    li t4, '9'
    j t5

  t5:
  #t5=segundo dígito dos três
  li a5, 10
  div t1, t2, a5
  rem t1, t1, a5

  li a4, 0
  beq t1, a4, t5zero
  li a4, 1
  beq t1, a4, t5um
  li a4, 2
  beq t1, a4, t5dois
  li a4, 3
  beq t1, a4, t5tres
  li a4, 4
  beq t1, a4, t5quatro
  li a4, 5
  beq t1, a4, t5cinco
  li a4, 6
  beq t1, a4, t5seis
  li a4, 7
  beq t1, a4, t5sete
  li a4, 8
  beq t1, a4, t5oito
  li a4, 9
  beq t1, a4, t5nove
  
  t5zero:
    li t5, '0'
    j t6
  t5um:
    li t5, '1'
    j t6
  t5dois:
    li t5, '2'
    j t6
  t5tres:
    li t5, '3'
    j t6
  t5quatro:
    li t5, '4'
    j t6
  t5cinco:
    li t5, '5'
    j t6
  t5seis:
    li t5, '6'
    j t6
  t5sete:
    li t5, '7'
    j t6
  t5oito:
    li t5, '8'
    j t6
  t5nove:
    li t5, '9'
    j t6

  t6:
  #t6=terceiro dígito dos três
  rem t1, t2, a5
  
  li a4, 0
  beq t1, a4, t6zero
  li a4, 1
  beq t1, a4, t6um
  li a4, 2
  beq t1, a4, t6dois
  li a4, 3
  beq t1, a4, t6tres
  li a4, 4
  beq t1, a4, t6quatro
  li a4, 5
  beq t1, a4, t6cinco
  li a4, 6
  beq t1, a4, t6seis
  li a4, 7
  beq t1, a4, t6sete
  li a4, 8
  beq t1, a4, t6oito
  li a4, 9
  beq t1, a4, t6nove
  
  t6zero:
    li t6, '0'
    j impressao
  t6um:
    li t6, '1'
    j impressao
  t6dois:
    li t6, '2'
    j impressao
  t6tres:
    li t6, '3'
    j impressao
  t6quatro:
    li t6, '4'
    j impressao
  t6cinco:
    li t6, '5'
    j impressao
  t6seis:
    li t6, '6'
    j impressao
  t6sete:
    li t6, '7'
    j impressao
  t6oito:
    li t6, '8'
    j impressao
  t6nove:
    li t6, '9'
    j impressao

  impressao:
  li a0, 'S'
  sb a0, 0(zero)
  li a0, 'E'
  sb a0, 1(zero)
  li a0, 'N'
  sb a0, 2(zero)
  li a0, 'O'
  sb a0, 3(zero)
  li a0, ':'
  sb a0, 4(zero)
  li a0, ' '
  sb a0, 5(zero)

  beq t0, zero, negativo

  #positivo:
  li a0, '+'
  sb a0, 6(zero)
  j aposSinal

  negativo:
  li a0, '-'
  sb a0, 6(zero)
  #j aposSinal

  aposSinal:
  sb t3, 7(zero)
  li a0, '.'
  sb a0, 8(zero)
  sb t4, 9(zero)
  sb t5, 10(zero)
  sb t6, 11(zero)
  li a0, '\n'
  sb a0, 12(zero)

  #impressão final:
  li a0, 1 # file descriptor = 1 (stdout)
  li a1, 0
  li a2, 13 # size
  li a7, 64 # syscall write (64)
  ecall

  li a0, 0 # exit code
  li a7, 93 # syscall exit
  _end:
  ecall

  # **************************************
  
  lw ra, 0(sp)
  lw s0, 4(sp)
  addi sp, sp, 8
  jr ra

  
funcao_pegar_angulo:
  addi sp, sp, -8
  sw ra, 0(sp)
  sw s0, 4(sp)
  addi s0, sp, 8
  
  # load angle value to a0
  lw a0, angle
  # convert angle to float and put in f0
  fcvt.s.w f0, a0
  # load pi address to a0
  la a0, .float_pi
  # load float_pi value (from a0 address) into f1
  flw f1, 0(a0)
  # load value 180 into a0
  li a0, 180
  # convert 180 to float and put in f2
  fcvt.s.w f2, a0

  # f0 -> angle, f1 -> pi, f2 -> 180
  # Now, put angle in radians (angle*pi/180)
  # f0 = angle * pi
  fmul.s f0, f0, f1
  # f0 = f0 / 180
  fdiv.s f0, f0, f2
  
  lw ra, 0(sp)
  lw s0, 4(sp)
  addi sp, sp, 8
  jr ra
  
funcao_float_para_inteiro:
  addi sp, sp, -8
  sw ra, 0(sp)
  sw s0, 4(sp)
  addi s0, sp, 8
  
  # Get signal
  li a0, 0
  fcvt.s.w f1, a0
  flt.s a0, f0, f1
  
  # Drop float signal
  fabs.s f0, f0
  
  # Truncate integer part
  fcvt.s.w f1, a0
  fadd.s f1, f1, f0
  jal funcao_truncar_float
  fcvt.w.s a1, f0
  
  # Truncate float part with 3 decimal places
  fsub.s f1, f1, f0
  li a3, 1000
  fcvt.s.w f2, a3
  fmul.s f0, f1, f2
  jal funcao_truncar_float
  fcvt.w.s a2, f0
  li a3, 1000
  rem a2, a2, a3
  
  lw ra, 0(sp)
  lw s0, 4(sp)
  addi sp, sp, 8
  jr ra
  
funcao_truncar_float:
  addi sp, sp, -8
  sw ra, 0(sp)
  sw s0, 4(sp)
  addi s0, sp, 8
  
  fmv.x.w a5, f0
  li a3, 22
  srai a4, a5,0x17
  andi a4, a4, 255
  addi a4, a4, -127
  addi a2, a5, 0
  blt a3, a4, .funcao_truncar_float_continue
  lui a5, 0x80000
  and a5, a5, a2
  bltz a4, .funcao_truncar_float_continue
  lui a5, 0x800
  addi a5, a5, -1
  sra a5, a5, a4
  not a5, a5
  and a5, a5, a2
.funcao_truncar_float_continue:
  fmv.w.x f0, a5
  
  lw ra, 0(sp)
  lw s0, 4(sp)
  addi sp, sp, 8
  jr ra
  
  
# Additional data variables
.align  4
.data
  angle:
    .word 90
  .float_pi:
    .word 0x40490fdb





