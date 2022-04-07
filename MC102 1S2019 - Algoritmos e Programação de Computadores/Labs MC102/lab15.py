#!/usr/bin/env python3
#*******************************************************************************
# Funcao: atualizaTabela
#
# Parametros:
#   tabela: uma matriz com os dados da tabela do campeonato
#   jogo: string contendo as informações de um jogo no formato especificado no lab.
#
# Descrição:
#   Deve inserir as informações do parametro 'jogo' na tabela.
#   OBSERVAÇÃO: nesse momento não é necessário ordenar a tabela, apenas inserir as informações.

#Lindon Jonathan Sanley dos Santos Pereira Monroe RA 220407 
def atualizaTabela(tabela, jogo):
	jogo=jogo.split()                  #Transforma os dados do jogo numa lista
	if int(jogo[1])==int(jogo[3]):       #Se empatar, muda os dados da tabela de acordo
		for i in range(len(tabela)): 
			if tabela[i][0]==jogo[0]: 
				tabela[i][1]+=1
				tabela[i][4]+=int(jogo[1])
			if tabela[i][0]==jogo[4]:
				tabela[i][1]+=1
				tabela[i][4]+=int(jogo[3])
				
	if int(jogo[1])>int(jogo[3]):		#Se o time da esquerda ganhar, muda os dados da tabela de acordo
		for i in range(len(tabela)):
			if tabela[i][0]==jogo[0]:
				tabela[i][1]+=3
				tabela[i][2]+=1
				tabela[i][3]+=int(jogo[1])
				tabela[i][3]-=int(jogo[3])
				tabela[i][4]+=int(jogo[1])
			if tabela[i][0]==jogo[4]:
				tabela[i][3]+=int(jogo[3])
				tabela[i][3]-=int(jogo[1])
				tabela[i][4]+=int(jogo[3])
	
	if int(jogo[3])>int(jogo[1]):	#Se o time da direita ganhar, muda os dados da tabela de acordo
		for i in range(len(tabela)):
			if tabela[i][0]==jogo[0]:
				tabela[i][3]+=int(jogo[1])
				tabela[i][3]-=int(jogo[3])
				tabela[i][4]+=int(jogo[1])
			if tabela[i][0]==jogo[4]:
				tabela[i][1]+=3
				tabela[i][2]+=1
				tabela[i][3]+=int(jogo[3])
				tabela[i][3]-=int(jogo[1])
				tabela[i][4]+=int(jogo[3])
#*******************************************************************************

#*******************************************************************************
# Funcao: comparaTimes
#
# Parametros:
#   time1: informações de um time
#   time2: informações de um time
#
# Descricão:
#   retorna 1, se o time1>time2, retorna -1, se time1<time2, e retorna 0, se time1=time2
#   Observe que time1>time2=true significa que o time1 deve estar em uma posição melhor do que o time2 na tabela.
def comparaTimes(time1, time2):
	for k in range(1,5):			#Compara dos dados de dois em dois times na tabela, na ordem de importância dos pontos
		if time1[k]>time2[k]:
			return 1
		if time1[k]<time2[k]:
			return -1
	return 0		
#*******************************************************************************


#*******************************************************************************
# Funcao: ordenaTabela
#
# Parametros:
#   tabela: uma matriz com os dados da tabela do campeonato.
#
# Descricão:
#   Deve ordenar a tabela com campeonato de acordo com as especificaçoes do lab.
#
def ordenaTabela(tabela):			#Selection Sort, se time1<time2, tem que inverter, pro maior ficar mais no começo da lista
	for i in range (len(tabela)-1):
		max=i
		for j in range(i,len(tabela)):
			time1=tabela[max]
			time2=tabela[j]
			c=comparaTimes(time1,time2)
			if c==-1:
				max=j
		tabela[i],tabela[max]=tabela[max],tabela[i]
	
#*******************************************************************************


#*******************************************************************************
# Funcao: imprimeTabela
#
# Parametros:
#   tabela: uma matriz com os dados da tabela do campeonato.
#
# Descrição:
#   Deve imprimir a tabela do campeonato de acordo com as especificações do lab.
def imprimeTabela(tabela):
	for l in range(len(tabela)):				#Pra cada linha e coluna
		for c in range(5):			#Imprimir os elementos, pular linha se for o ultimo da linha
			if c==4:
				print(tabela[l][c])
			else:
				print(tabela[l][c],end=", ")
#*******************************************************************************