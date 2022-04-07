#Convolução
#Lindon Jonathan Sanley dos Santos Pereira Monroe
#RA 220407

import sys

larq1=[]                      #Criação de listas auxiliares
larq2=[]


arq1=open(sys.argv[1],"r")    	#Abertura da imagem.pgm
while True:						#Loop até quebrar quando acaba o arquivo
	a1=arq1.readline()			#Lê cada linha e divide cada linha de número em uma lista, então joga na lista auxiliar 1
	if a1=="":
		arq1.close()
		break
	a1=a1.split()
	for a in range(len(a1)):
		if a1[a]!="P2":
			a1[a]=int(a1[a])
	larq1.append(a1)
	
mcolunas=larq1[1][0]			#Pega o número de linhas e colunas na segunda linha da lista auxiliar 1
nlinhas=larq1[1][1]
del larq1[0]					#Deleta as informações iniciais desnecessárias agora
del larq1[0]
del larq1[0]

arq2=open(sys.argv[2],"r")		#Abre o arquivo matriz.txt
while True:						#Loop até quebrar quando acabar o arquivo
	r2=arq2.readline()
	if r2=="":
		arq2.close()
		break
	r2=r2.split()				#Faz split em cada linha e adiciona na lista auxiliar 2
	for r in range(len(r2)):
		r2[r]=int(r2[r])
	larq2.append(r2)
	
D=larq2[0][0]					#Relaciona o divisor e as letras de a à i  aos seus valores da matriz
a=larq2[1][0]
b=larq2[1][1]
c=larq2[1][2]
d=larq2[2][0]
e=larq2[2][1]
f=larq2[2][2]
g=larq2[3][0]
h=larq2[3][1]	
i=larq2[3][2]

larq3=[[0 for m in range(mcolunas)]for n in range(nlinhas)]			#Cria lista 3 auxiliar do tamanho da matriz imagem

for k in range(nlinhas):											#Faz da lista 3 uma cópia da lista 1, mas mantém elas independentes
	for l in range(mcolunas):
		larq3[k][l]=larq1[k][l]

for l in range(nlinhas):
	for j in range(mcolunas):
		if l!=0 and l!=nlinhas-1 and j!=0 and j!=mcolunas-1:		#Pra cada elemento da matriz 3, exceto os das bordas, faz a conta com o elemento da matriz 1 e coloca naquela posição na 3
			larq3[l][j]=(a*larq1[l-1][j-1]+b*larq1[l-1][j]+c*larq1[l-1][j+1]+d*larq1[l][j-1]+e*larq1[l][j]+f*larq1[l][j+1]+g*larq1[l+1][j-1]+h*larq1[l+1][j]+i*larq1[l+1][j+1])//D
			if larq3[l][j]<0:										#Se der menor que 0 fica 0
				larq3[l][j]=0
			if larq3[l][j]>255:										#Se der maior que 255 fica 255
				larq3[l][j]=255
	

print("P2")															#Printa P2, número de linhas e colunas e 255
print(mcolunas,nlinhas)
print("255")

for i in range(nlinhas):												#Printa a matriz contida na lista auxiliar 3
	for j in range(mcolunas):				
		if j==mcolunas-1:		#Se for o último da linha printa e pula
			print(larq3[i][j]," ")
		else:				#Se não for o último printa e continua na mesma linha
			print(larq3[i][j],end=" ")
