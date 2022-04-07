#Lindon Jonathan Sanley dos S P Monroe RA 220407

#Formando a base de dados:

N=int(input())
base=[[] for k in range (400)]   #Primeiro criei uma lista de tamanho suficiente  pra alocar os multiplicadores 
for i in range(N):                      #de cada espécie em uma lista diferente dentro da lista base de dados
	info=input()                      
	infolista=[int(j) for j in info.split( )]    
	I=infolista[0]               #Pra cada informação digitada foi separado o número da espécie
	M=infolista[2]/infolista[1]      #O multiplicador é PCf/PCa
	base[I].append(M)                 #Foi alocado o multiplicador no espaço para a espécie
	
#Consultas:

consulta=input()
consultalista=[int (l) for l in consulta.split( )]
I=consultalista[0]                   #Cada espécie consultada teve seu número da espécie separado do PCa
PCa=consultalista[1]
Mm=base[I]                            #O multiplicador for tirado da lista base na posição da espécie consultada
média=0
quant=0
if I!=0 or PCa!=0:
	for o in Mm:                     #Pra cada espécie consultada foi feito a média entre os multiplicadores
		média=média+o
		quant=quant+1
	média=média/quant

	resultado=PCa*média                   #O resultado é a média dos multiplicadores vezes o PCa
	resulteste=resultado*10
	if resulteste%10==0:                  #Testei se era um número redondo, se não for, tem que ir para o próximo
		print(resultado)
	if resulteste%10!=0:                      #Arredondamento para o topo
		resultado=int(resultado)+1
		print(resultado)
while I!=0 or PCa!=0:                          #Continuar consultando até o input 0 0
	consulta=input()
	consultalista=[int(l) for l in consulta.split( )]
	I=consultalista[0]
	PCa=consultalista[1]
	Mm=base[I]
	média=0
	quant=0
	if I!=0 or PCa!=0:
		for o in Mm:
			média=média+o
			quant=quant+1
		média=média/quant
	
		resultado=PCa*média
		resulteste=resultado*10
		if resulteste%10==0:
			print(resultado)
		if resulteste%10!=0:
			resultado=int(resultado)+1
			print(resultado)