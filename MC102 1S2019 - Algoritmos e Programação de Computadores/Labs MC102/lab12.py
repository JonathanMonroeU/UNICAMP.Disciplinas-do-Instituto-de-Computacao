#Lindon Jonathan Sanley dos Santos Pereira Monroe RA 220407 

#Direção:
#mercurio = N 
#venus = NE
#terra = L
#marte = SE
#jupiter = S
#saturno = SO
#urano = O
#netuno = NO

#Elevação do canhão:
#verde = 30
#amarelo = 45
#vermelho = 60


publicação=(input())                                #Guarda a mensagem digitada
publi=publicação.lower()							#Converte em caixa baixa para não haver discrepância
pub=publi.split()									#Separa as palavras em termos de uma lista
c=""												#Cria strings vazias para guardar as coordenadas se a palavra aparece na mensagem
d=""

for i in pub:
	if i=="mercurio":
		c=c+" N"
	if i=="venus":	
		c=c+" NE"
	if i=="terra":
		c=c+" L"
	if i=="marte":
		c=c+" SE"
	if i=="jupiter":
		c=c+" S"
	if i=="saturno":
		c=c+" SO"
	if i=="urano":
		c=c+" O"
	if i=="netuno":
		c=c+" NO"

	if i=="verde":
		d=d+" 30"
	if i=="amarelo":
		d=d+" 45"
	if i=="vermelho":
		d=d+" 60"

c=c.split()                        #Separa as palavras em termos de uma lista           
d=d.split()
		
for i in range (len(c)):		   #Para as palavras dentro de cada lista
	print(c[i],"-",d[i])                #imprime a direção e o ângulo correspondentes
	
