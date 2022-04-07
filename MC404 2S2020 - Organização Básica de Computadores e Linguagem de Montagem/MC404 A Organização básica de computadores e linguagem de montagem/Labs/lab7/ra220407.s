#x, y = ler_linha() 	// Le a primeira linha com os valores de xi, yi
#ler_linha() 		// Linha ‘P2’ deve ser ignorada
#L, C = ler_linha()	// Le a linha com os valores de L e C
#CMAX = ler_linha() 	// Le a linha com o valor de CMAX
#ler_linha() 		// Ignora a primeira linha (y=0)

#while(y < L-1)
#	sensores = ler_linha()	// Lê uma linha com os valores dos sensores
#	dir = decidir(sensores) // Decide se vai para esquerda, direita ou 
#// mantém-se no centro. Decidir retorna -1       
#// (esquerda), 1 (direita) ou 0 (centro)
#	y = y+1			// Incrementa y em 1
#	x = x+dir			// Incrementa x com -1, 0 ou 1
#	imprimir_pos(x, y)	// Imprime a nova posição


### REGISTRADORES:###
#a5 vai guardar x
#não será guardado
#a6 vai guardar L (numero de linhas)

###  MEMÓRIA: ###
# 0 vai receber o byte que está sendo lido
#na parte de impressão: 0 a 14 vão receber os caracteres pra printar

.text
  .align 1
  .globl _start
_start:  

  #PRIMEIRA LINHA----------------------------------------------------------------------------------
  jal ler_linha
  #nesse ponto t1 tem a quantidade de caracteres na linha
  li t3, 1 #em qual numero o programa está, começa do final
  addi sp, sp, 1   #começa voltando uma posição pra sair do \n
  addi t1, t1, -1   #quantidade de caracteres na heap diminui 1
  
  numeros1:   #identifica os numeros na linha 1
  beq t1, zero, fimn1   #percorre agora a linha salva na heap do fim ao começo
    li t2, 0 #Quantidade de caracteres formando o numero
    mesmonum:
      li t4, ' '
      lb t5, 0(sp)
      beq t5, t4, qualnum  #quando achar um espaço, verifica que por qual numero passou
      li t4, '\n'
      beq t5,t4, qualnum  #quando chega no fim da linha, verifica por qual numero passou
      addi t2, t2, 1
      sb t5, 0(t2)

      addi sp, sp, 1   
      addi t1, t1, -1   #quantidade de caracteres na heap diminui 1
      j mesmonum

    qualnum:
      addi sp, sp, 1   
      addi t1, t1, -1   #quantidade de caracteres na heap diminui 1

      li t4, 1
      beq t2, t4, menosde10
      li t4, 2
      beq t2, t4, menosde100
      li t4, 3
      beq t2, t4, menosde255

      menosde10:
        li t4, 1
        lb a0, 0(t4)
        jal descobrir_numero

        j xouy
      menosde100:
        li t4, 2
        lb a0, 0(t4)
        jal descobrir_numero
        li t4, 10
        mul a2, a0, t4

        li t4, 1
        lb a0, 0(t4)
        jal descobrir_numero
        add a0, a0, a2
        #AQUI a0 CONTEM O NUMERO
        j xouy
      menosde255:
        li t4, 3
        lb a0, 0(t4)
        jal descobrir_numero
        li t4, 100
        mul a2, a0, t4
        
        li t4, 2
        lb a0, 0(t4)
        jal descobrir_numero
        li t4, 10
        mul a0, a0, t4
        add a2, a0, a2

        li t4, 1
        lb a0, 0(t4)
        jal descobrir_numero
        add a0, a0, a2
        #AQUI a0 CONTEM O NUMERO
        j xouy

    xouy:
      li t4, 1
      beq t3, t4, y
      li t4, 2
      beq t3, t4, x
      x:
        mv a5, a0
        j numeros1
      y:
        #mv a6, a0
        addi t3, t3, 1
        j numeros1
    
    j numeros1
  fimn1: 
 
  add sp, sp, t1  #retorna o apontador do heap para a posição inicial

  #SEGUNDA LINHA----------------------------------------------------------------------------------
  jal ler_linha
  add sp, sp, t1
  li t1, 0

  #TERCEIRA LINHA----------------------------------------------------------------------------------
  jal ler_linha
  #t1 tem a quantidade de caracteres na linha
  
  addi sp, sp, +1   #começa voltando uma posição pra sair do \n
  addi t1, t1, -1   #quantidade de caracteres na heap diminui 1
  numeros3:   #identifica os numeros na linha 1
  beq t1, zero, fimn3   #percorre agora a linha salva na heap do fim ao começo
    li t3, 1 #em qual numero o programa está, começa do final
    li t2, 0 #Quantidade de caracteres formando o numero
    mesmonum3:
      
      li t4, ' '
      lb t5, 0(sp)
      beq t5, t4, qualnum3  #quando achar um espaço, verifica que por qual numero passou
      li t4, '\n'
      beq t5,t4, qualnum3 #quando chega no fim da linha, verifica por qual numero passou
      addi t2, t2, 1
      sb t5, 0(t2)

      addi sp, sp, +1   
      addi t1, t1, -1   #quantidade de caracteres na heap diminui 1
      j mesmonum3

    qualnum3:
      addi sp, sp, 1   
      addi t1, t1, -1   #quantidade de caracteres na heap diminui 1

      li t4, 1
      beq t2, t4, menosde10_3
      li t4, 2
      beq t2, t4, menosde100_3
      li t4, 3
      beq t2, t4, menosde255_3

      menosde10_3:
        li t4, 1
        lb a0, 0(t4)
        jal descobrir_numero

        j coul
      menosde100_3:
        li t4, 2
        lb a0, 0(t4)
        jal descobrir_numero
        li t4, 10
        mul a2, a0, t4

        li t4, 1
        lb a0, 0(t4)
        jal descobrir_numero
        add a0, a0, a2
        #AQUI a0 CONTEM O NUMERO
        j coul
      menosde255_3:
        li t4, 3
        lb a0, 0(t4)
        jal descobrir_numero
        li t4, 100
        mul a2, a0, t4

        li t4, 1
        lb a0, 0(t4)
        jal descobrir_numero
        li t4, 10
        mul a0, a0, t4
        add a2, a0, a2

        li t4, 1
        lb a0, 0(t4)
        jal descobrir_numero
        add a0, a0, a2
        #AQUI a0 CONTEM O NUMERO
        j coul

    coul:
      li t4, 1
      beq t3, t4, l
      li t4, 2
      beq t3,t4,c
      c:
        j numeros3
      l:
        mv a6, a0
        addi t3, t3, 1
        j fimn3
    
    j numeros3
  fimn3: 
 
  add sp, sp, t1  #retorna o apontador do heap para a posição inicial
  
  #QUARTA LINHA----------------------------------------------------------------------------------
  jal ler_linha
  add sp, sp, t1  #retorna o apontador do heap para a posição inicial
  li t1,0


  #QUINTA LINHA----------------------------------------------------------------------------------
  jal ler_linha
  add sp, sp, t1  #retorna o apontador do heap para a posição inicial
  li t1, 0


  #LINHAS QUE FORMAM A IMAGEM-----------------------------------------------------------------------------
  #0 B 2 C 4 B 6 7\n    t6=8-a5-1=8-3-1=4

  li t3, 1
  linhas:
    beq t3, a6, final
    jal ler_linha
    li t6, 63
    sub t6, t6, a5 #t6=64-posição do carro-1, que é igual a qtd de espaços brancos da posição do carro ao final da linha

    addi sp, sp, +1   #começa voltando uma posição pra sair do \n
    addi t1, t1, -1   #quantidade de caracteres na heap diminui 1
    #vai voltando salvando as posições dos espaços em branco até chegar no carro
    numerosL:   #identifica os numeros na linha L
    beq t6, zero, fimnL   #percorre agora a linha até a posição do carro
    li t2, 0 #Quantidade de caracteres formando o numero
    mesmonumL:
      li t4, ' '
      lb t5, 0(sp)
      beq t5, t4, qualnumL  #quando achar um espaço, verifica que por qual numero passou
      addi t2, t2, 1

      addi sp, sp, +1   #começa voltando uma posição pra sair do \n
      addi t1, t1, -1   #quantidade de caracteres na heap diminui 1
      j mesmonumL

    qualnumL:
      addi sp, sp, 1   
      addi t1, t1, -1   #quantidade de caracteres na heap diminui 1

      addi t6, t6, -1
      li t4, 3
      beq t2, t4, menosde255L
      j numerosL

      menosde255L:
        mv a1, t6
        j numerosL
     fimnL: 
 
    

    #vai voltando a partir do carro até chegar no primeiro valor maior que 99
    li t6, -1
    numerosL2:   #identifica os numeros na linha L
    #beq S  #percorre da posição do carro até achar uma borda
    li t2, 0 #Quantidade de caracteres formando o numero
    mesmonumL2:
      li t4, ' '
      lb t5, 0(sp)
      beq t5, t4, qualnumL2  #quando achar um espaço, verifica que por qual numero passou
      addi t2, t2, 1
      
      addi sp, sp, +1       
      addi t1, t1, -1   #quantidade de caracteres na heap diminui 1
      j mesmonumL2
    qualnumL2:
      addi sp, sp, +1       
      addi t1, t1, -1   #quantidade de caracteres na heap diminui 1

      addi t6, t6, 1
      li t4, 3
      beq t2, t4, menosde255L2
      j numerosL2

      menosde255L2:
        mv a0, t6
        j fimnL2
     fimnL2: 
 


    add sp, sp, t1  #retorna o apontador do heap para a posição inicial
    jal edc #verifica qual a maior distância pra borda da pista

    add a5, a5, a0 #soma pra qual direção vai


    impressao:
      li a0, 'P'
      sb a0, 0(zero)
      li a0, 'O'
      sb a0, 1(zero)
      li a0, 'S'
      sb a0, 2(zero)
      li a0, ':'
      sb a0, 3(zero)
      li a0, ' '
      sb a0, 4(zero)


      mv a3, a5
      #imprime a coluna atual
      li a1, 4
      jal asci_numero
      sb a0, 5(zero) 

      li a1, 3
      jal asci_numero
      sb a0, 6(zero) 

      li a1, 2
      jal asci_numero
      sb a0, 7(zero)

      li a1, 1
      jal asci_numero
      sb a0, 8(zero)
  
      li a0, ' '
      sb a0, 9(zero)

      mv a3, t3
      #imprime a linha atual t3
      li a1, 4
      jal asci_numero
      sb a0, 10(zero) 

      li a1, 3
      jal asci_numero
      sb a0, 11(zero) 

      li a1, 2
      jal asci_numero
      sb a0, 12(zero)

      li a1, 1
      jal asci_numero
      sb a0, 13(zero)

      li a0, '\n'
      sb a0, 14(zero)

       addi t3, t3, 1

      #impressão final:
      li a0, 1 # file descriptor = 1 (stdout)
      li a1, 0
      li a2, 15 # size
      li a7, 64 # syscall write (64)
      ecall

   
    j linhas

final:
li a0, 0 # exit code
  li a7, 93 # syscall exit
  _end:
  ecall



###################################################################################################################################



#FUNÇÕES:----------------------------------------------------------------------------------

ler_linha:
  li t0, '\n'
  li t1, 0 #contador de char adicionados na heap
  addi sp, sp, -1
  sb t0, 0(sp)
  addi t1, t1, 1 #aumenta 1 no contador de char na heap

  li t0, 1 #valor qualquer
  linha1:     #lê a linha e salva no heap
    li t4, '\n'
    beq t0, t4, fiml1
    li a0, 0 #  0=stdin
    li a1, 0 # endereço onde será guardado as informações lidas
    li a2, 1 # quantos bytes serão lidos
    li a7, 63 # syscall read (63)
    ecall  
  
    lb t0, 0(zero)
    addi sp, sp, -1
    sb t0, 0(sp)
    addi t1, t1, 1 #aumenta 1 no contador de char na heap
    
    j linha1

  fiml1: #fim da leitura da linha
  ret


descobrir_numero:
  li a4, '0'
  beq a0, a4, a0zero
  li a4, '1'
  beq a0, a4, a0um
  li a4, '2'
  beq a0, a4, a0dois
  li a4, '3'
  beq a0, a4, a0tres
  li a4, '4'
  beq a0, a4, a0quatro
  li a4, '5'
  beq a0, a4, a0cinco
  li a4, '6'
  beq a0, a4, a0seis
  li a4, '7'
  beq a0, a4, a0sete
  li a4, '8'
  beq a0, a4, a0oito
  li a4, '9'
  beq a0, a4, a0nove
  
  a0zero:
    li a0, 0
    j retornar_descobrir
  a0um:
    li a0, 1
    j retornar_descobrir
  a0dois:
    li a0, 2
    j retornar_descobrir
  a0tres:
    li a0, 3
    j retornar_descobrir
  a0quatro:
    li a0, 4
    j retornar_descobrir
  a0cinco:
    li a0, 5
    j retornar_descobrir
  a0seis:
    li a0, 6
    j retornar_descobrir
  a0sete:
    li a0, 7
    j retornar_descobrir
  a0oito:
    li a0, 8
    j retornar_descobrir
  a0nove:
    li a0, 9
    j retornar_descobrir

  retornar_descobrir:
  ret

asci_numero:
  #a3 contém o número
  li t4, 1
  beq a1, t4, unidade
  li t4, 2
  beq a1, t4, dezena
  li t4, 3
  beq a1, t4, centena
  li t4, 4
  beq a1, t4, milhar

  unidade:
    li t4, 10
    rem a0, a3, t4
    j conversao
    
  dezena:
    li t4, 100
    rem a0, a3, t4
    li t4, 10
    div a0, a0, t4
    j conversao
  
  centena:
    li t4, 1000
    rem a0, a3, t4
    li t4, 100
    div a0, a0, t4
    j conversao

  milhar:
    li t4, 1000
    div a0, a3, t4
    j conversao

  conversao:
  li a4, 0
  beq a0, a4, ascizero
  li a4, 1
  beq a0, a4, ascium
  li a4, 2
  beq a0, a4, ascidois
  li a4, 3
  beq a0, a4, ascitres
  li a4, 4
  beq a0, a4, asciquatro
  li a4, 5
  beq a0, a4, ascicinco
  li a4, 6
  beq a0, a4, asciseis
  li a4, 7
  beq a0, a4, ascisete
  li a4, 8
  beq a0, a4, ascioito
  li a4, 9
  beq a0, a4, ascinove
  
  ascizero:
    li a0, '0'
    j retornar_asci
  ascium:
    li a0, '1'
    j retornar_asci
  ascidois:
    li a0, '2'
    j retornar_asci
  ascitres:
    li a0, '3'
    j retornar_asci
  asciquatro:
    li a0, '4'
    j retornar_asci
  ascicinco:
    li a0, '5'
    j retornar_asci
  asciseis:
    li a0, '6'
    j retornar_asci
  ascisete:
    li a0, '7'
    j retornar_asci
  ascioito:
    li a0, '8'
    j retornar_asci
  ascinove:
    li a0, '9'
    j retornar_asci

  retornar_asci:
  ret

edc: #esquerda, direita ou centro
  #a0 é a distância da esquerda
  #a1 é a distância da direita
  beq a0, a1, centro 
  blt a0, a1, direita #se a distância da esquerda for menor, vai pra direita
  bge a0, a1, esquerda #se a distância da esquerda for maior, vai pra esquerda

  centro:
    li a0, 0
    j retornar_edc
  direita:
    li a0, 1
    j retornar_edc 
  esquerda:
    li a0, -1
    j retornar_edc

  retornar_edc:
  ret

