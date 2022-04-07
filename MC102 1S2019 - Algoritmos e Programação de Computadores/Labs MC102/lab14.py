#Lindon Jonathan Sanley dos Santos Pereira Monroe RA 220407
def imprimir(turma):							#Função para imprimir a lista de RA
	for t in range(len(turma)):					
		if t==len(turma)-1:						#Se for o último da linha printa e pula
			print(turma[t],"")
		else:									#Se não for o último printa e continua na mesma linha
			print(turma[t],end=" ")

def igualar():									#Função para associar a lista auxiliar à lista da turma
	turma=[0 for i in range(len(turmaaux))]
	for j in range(len(turmaaux)):
		turma[j]=turmaaux[j]					#Iguala cada elemento de cada lista
	return turma

turma=input()									#Digita os RA da turma
turma=turma.split()								#Transforma a string em uma lista
for i in range(len(turma)):
	turma[i]=int(turma[i])						#Transforma cada elemento da lista em int
operacao="a"									#Coloca letra aleatória para operação inicialmente


ordem=0
while operacao!="s":							#Enquanto a operação não for finalizar
	operacao=input()							#Digite a operação
	turmaaux=[]									#Turma auxiliar e vazia inicialmente
	
	if operacao=="p":	#Se operação for p, imprime a lista de RA
		if turma!=[]:
			imprimir(turma)
		
	if operacao=="c":							#Se operação for c, organiza a lista em ordem crescente
		ordem=1
		if turma!=[]:
			turma.sort()
		
	if operacao=="d":	#Se operação for d, organiza a lista em ordem crescente
		ordem=2
		if turma!=[]:
			turma.sort()
			for i in range(len(turma)-1,-1,-1):		#Depois coloca na turma auxiliar em ordem decrescente
				turmaaux.append(turma[i])
			turma=igualar()							#Então associa a turma auxiliar à turma
		
	
	
	if operacao[0]=="b":								#Se o primeiro caractere da operação for b, usa os de 2 a 7 pra formar o RA e transforma em int
		ra_busca=int(operacao[2]+operacao[3]+operacao[4]+operacao[5]+operacao[6]+operacao[7])
		if turma==[]:									#Se e lista estiver vazia 
			print("%d nao esta na lista!"%(ra_busca))
			continue
		if len(turma)==1:								#Se tiver um carctere vê se ele é o procurado
			if turma[0]==ra_busca:
				pos=0
				print(pos)
				print("%d esta na posicao: %d"%(ra_busca, pos))
			else:
				print("%d nao esta na lista!"%(ra_busca))
			continue
		ordenadoc=True									#Inicialmente, tanto ordenado crescente e decrescente são verdadeiros, até se testar
		ordenadod=True
		for m in range(len(turma)-1):					#Pros valores até o penúltimo
			if turma[0]<turma[1]:						#Se o primeiro for menor que o segundo
				ordenadod=False							#Não é decrescente
				if turma[m]>turma[m+1]:					#Mas se um for decrescente
					ordenadoc=False						#Então não é crescente
			if turma[0]>turma[1]:						#Se o primeiro for maior que o segundo
				ordenadoc=False							#Então não é crescente
				if turma[m]<turma[m+1]:					#Mas se um for crescente
					ordenadod=False						#Então não é decrescente
					
		if ordenadoc==False and ordenadod==False:		#Se depois de testar, não for crescente nem decrescente
			print("Vetor nao ordenado!")				#Então não está ordenado
			continue
		
		
		if ordenadoc:									#Se for crescente
			ini=0										#Início é 0 e fim é o últimmo
			fim=len(turma)-1
			meios=""									#Lista de meios é vazia, inicialmente
			achado=False								#Por enquanto não foi encontrado
			while ini<=fim:								#Busca Binária normal
				meio=(ini+fim)//2
				if turma[meio]==ra_busca:
					pos=meio
					achado=True
					meios=meios+str(meio)+" "			#Se for achado a posiçao é adicionada na lista de meios e quebra o ciclo
					break
				elif turma[meio]>ra_busca:				#Se não ajusta o intervalo de procura pra mais ou menos que o meio
					fim=meio-1
				else:
					ini=meio+1
				meios=meios+str(meio)+" "				#Adiciona os meios na lista
		if ordenadod:									#Se for decrescente é simplesmente tudo ao contrário
			fim=0										#Começo e fim ao contrário
			ini=len(turma)-1
			meios=""
			achado=False
			while ini>=fim:								#Busca Binária invertida
				meio=(ini+fim)//2
				if turma[meio]==ra_busca:
					pos=meio
					achado=True
					meios=meios+str(meio)+" "
					break
				elif turma[meio]>ra_busca:
					fim=meio+1
				else:
					ini=meio-1
				meios=meios+str(meio)+" "
			
		if achado:
			print(meios)
			print("%d esta na posicao: %d"%(ra_busca, pos))

		if achado==False:
			print(meios)
			print("%d nao esta na lista!"%(ra_busca))
		
		
	
	if operacao[0]=="i":								#Se o primeiro caractere da operação for i, pega os de 2 a 7 pra formar o RA e transforma em int
		ra_insercao=int(operacao[2]+operacao[3]+operacao[4]+operacao[5]+operacao[6]+operacao[7])
		if len(turma)>=150:								#Se tiver 150 alunos ou mais:
			print("Limite de vagas excedido!")
			continue
		for k in turma:									#Se tiver um RA igual já na lista
			if k==ra_insercao:
				print("Aluno ja matriculado na turma!")
				continue
		
		if turma==[]:									#Se a turma estiver vazia, adiciona o RA nela
			turma.append(ra_insercao)
			continue
		
		if len(turma)==1:								#Se tiver um só RA, testa qual o maior e depois adiciona no lugar
			if turma[0]>ra_insercao and ordem!=0:
				turma.append(turma[0])
				turma[0]=ra_insercao
				continue
			else:
				turma.append(ra_insercao)
				continue
				
		
		inserido=False												#O valor ter sido inserido por enquanto é falso
		if ordem==1:												#Se for crescente
			for n in range(len(turma)):
				if inserido or turma[n]<ra_insercao:				#Se o RA_insercao já foi inserido ou se o valor da turma é menor que o RA_insercao
					turmaaux.append(turma[n])						#Insere o valor da turma na turma auxiliar
					if inserido==False and n==len(turma)-1:				#Se Ra_insercao ainda não foi inserido e esse for o último da turma 
						turmaaux.append(ra_insercao)					#insere o RA_insercao no final				
				if inserido==False and turma[n]>ra_insercao:		#Se RA_insercao não foi inserido e o valor da turma for maior que ele
					turmaaux.append(ra_insercao)					#Insere o RA_insecao e em seguida o valor da turma
					turmaaux.append(turma[n])
					inserido=True									#Confirma que foi inserido
			turma=igualar()
			continue
			
		if ordem==2:												#Se for decresente
			for n in range(len(turma)):
				if inserido or turma[n]>ra_insercao:				#Tudo ao contrário
					turmaaux.append(turma[n])
					if inserido==False and n==len(turma)-1:
						turmaaux.append(ra_insercao)		
				if inserido==False and turma[n]<ra_insercao:
					turmaaux.append(ra_insercao)
					turmaaux.append(turma[n])
					inserido=True	
			turma=igualar()	
			continue
			
		if ordem==0:					#Se não estiver ordenado
			turma.append(ra_insercao)								#Coloca o RA no final da lista
		
	
	if operacao[0]=="r":					#Se o primeiro caractere da operacão for r, pega os de 2 a 7 para formar o RA a ser removido e transforma em int
		ra_remocao=int(operacao[2]+operacao[3]+operacao[4]+operacao[5]+operacao[6]+operacao[7])
		if turma==[]:						#Se a turma não tiver ninguém
			print("Nao ha alunos cadastrados na turma!")
			continue
		matriculado=False					#O aluno a ser removido não está matriculado antes de se ver
		for y in range(len(turma)):			
			if turma[y]!=ra_remocao:		#Se o RA for diferente, apenas insira na turma auxiliar na ordem
				turmaaux.append(turma[y])
			else:
				matriculado=True			#Se houver um RA igual o a ser removido, só ateste que há
		turma=igualar()						#Associa a turma auxiliar à turma
		if matriculado==False:				#Se depois da procura ainda não estiver matriculado realmente
			print("Aluno nao matriculado na turma!")