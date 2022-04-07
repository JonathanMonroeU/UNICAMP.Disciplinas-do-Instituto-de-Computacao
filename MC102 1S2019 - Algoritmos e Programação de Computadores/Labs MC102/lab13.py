#Lindon Jonathan Sanley dos Santos Pereira Monroe RA 220407

ordem=input()         #Ordem matriz vizinhança
ixj=ordem.split()
i=int(ixj[0])
j=int(ixj[1])

iteracoes=int(input())      #Quantidade de dias
viz=[[0 for c in range(j+2)] for l in range(i+2)]        #Criação de matriz de zeros com duas linhas e colunas adicionais
vizaux=[[0 for c in range(j+2)] for l in range(i+2)]	#Criação de matriz para consultar o dia anterior


for l in range(1,i+1):	      #Pra cada linha da quantidade de linhas
	linha=input()
	linha=linha.split()			#Separa a linha digitada em termos de uma lista
	for c in range(1,j+1):			#Pra cada termo da lista
		viz[l][c]=int(linha[c-1])		#Adiciona à linha em formato de inteiro
			
print("iteracao 0")					
for l in range(1,i+1):			#Pra cada linha
	for c in range(1,j+1):			#Pra cada elemento nela
		if c==j:						# Se for o último elemento imprime e vai pra linha de baixo
			print(viz[l][c])
		else:							#Se não for, imprime e continua na mesma
			print(viz[l][c],end="")
			
for l in range(i+2):			#Criando matriz de consulta do dia de modo que não se modifique enquanto calcula o próximo dia
	for c in range(j+2):
		vizaux[l][c]=viz[l][c]
		
for s in range(1,iteracoes+1):			#Pra cada dia
	for l in range(1,i+1):				#Pra cada elemento de cada linha
		for c in range(1,j+1):
			humanos=0					#Contagem de humanos e zumbis em volta começa em zero
			zumbis=0
			
			if vizaux[l-1][c-1]==1:			#Se o elemento em volta da posição for 1, conta como um humano
				humanos=humanos+1
			if vizaux[l-1][c-1]==2:			#Se for 2, conta como um zumbi
				zumbis=zumbis+1
				
			if vizaux[l-1][c]==1:
				humanos=humanos+1
			if vizaux[l-1][c]==2:
				zumbis=zumbis+1
		
			if vizaux[l-1][c+1]==1:
				humanos=humanos+1
			if vizaux[l-1][c+1]==2:
				zumbis=zumbis+1
		
			if vizaux[l][c-1]==1:
				humanos=humanos+1
			if vizaux[l][c-1]==2:
				zumbis=zumbis+1
		
			if vizaux[l][c+1]==1:
				humanos=humanos+1
			if vizaux[l][c+1]==2:
				zumbis=zumbis+1
		
			if vizaux[l+1][c-1]==1:
				humanos=humanos+1
			if vizaux[l+1][c-1]==2:
				zumbis=zumbis+1
		
			if vizaux[l+1][c]==1:
				humanos=humanos+1
			if vizaux[l+1][c]==2:
				zumbis=zumbis+1
		
			if vizaux[l+1][c+1]==1:
				humanos=humanos+1
			if vizaux[l+1][c+1]==2:
				zumbis=zumbis+1
				
			
			if vizaux[l][c]==0:			#Se o elemento do centro, que estamos destacando for vazio
				if humanos==2:			#Se houver exatamente dois humanos em volta
					viz[l][c]=1			#Vira um humano
		
			elif vizaux[l][c]==1:		#Se for um humano
				if zumbis>=1:			#Se tiver algum zumbi em volta
					viz[l][c]=2			#Vira um zumbi
	
			elif vizaux[l][c]==2:		#Se for zumbi
				if humanos==0:			#Se não  houver nenhum humano em volta
					viz[l][c]=0			#Fica vazio
				elif humanos>=2:		#Se houver mais de dois humanos
					viz[l][c]=0			#Fica vazio
					
	print("iteracao",s)					#Imprimir o dia passado
	for l in range(1,i+1):				#Pra cada linha e coluna
		for c in range(1,j+1):			#Imprimir os elementos, pular linha se for o ultimo da linha
			if c==j:
				print(viz[l][c])
			else:
				print(viz[l][c],end="")
	for l in range(i+2):				#Criar uma matriz de consulta pra ver como será o próximo dia sem modificar ela
		for c in range(j+2):
			vizaux[l][c]=viz[l][c]