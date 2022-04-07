#Lindon Jonathan Sanley dos Santos Pereira Monroe RA 220407

def intervalosdiferentes():        				#função para só validar a possibilidade de compra da empresa
	emcomumpri=0									#se estiver num intervalo diferente da compra anterior
	emcomumseg=0
	emcomumter=0
	tempo=[x for x in range(compra,venda+1)]
	for y in pricv:
		for z in tempo:
			if y==z:
				emcomumpri=emcomumpri+1
	for y in segcv:
		for z in tempo:
			if y==z:
				emcomumseg=emcomumseg+1
	for y in tercv:
		for z in tempo:           
			if y==z:
				emcomumter=emcomumter+1
	if emcomumpri<2 and emcomumseg<2 and emcomumter<2:
		return True
	else:
		return False

lucro1def=0;lucro2def=0;lucro3def=0;lucro4def=0;lucrodef=0          #definindo algumas variáveis para não 
compra1def=0;compra2def=0;compra3def=0;compra4def=0					#haver possibilidade de dar erro no final
venda1def=0;venda2def=0;venda3def=0;venda4def=0
lucro1definitivo=0;lucro2definitivo=0;lucro3definitivo=0;lucro4definitivo=0

d=int(input())							#Guardando os números lidos em uma lista para cada empresa, ao somar com os 0 das listas base
um=[0 for i in range (d)]
dois=[0 for i in range (d)]
três=[0 for i in range (d)]
quatro=[0 for i in range (d)]

for i in range (d):										
	x=float(input())
	um[i]=um[i]+x
for i in range (d):
	x=float(input())
	dois[i]=dois[i]+x
for i in range (d):
	x=float(input())
	três[i]=três[i]+x
for i in range (d):
	x=float(input())
	quatro[i]=quatro[i]+x
	
for j in range(1,d):			#Para cada dia possível de venda e dia de compra antes dele,  para cada empresa
	for i in range(j):
		for l in range(1,d):
				for k in range(l):
					for n in range(1,d):
						for m in range(n):
							for p in range(1,d):
								for o in range(p):
									pricv=[50];segcv=[50];tercv=[50]        #Valores aleatórios para quando entrar na função comparando inntervalos de compra e venda já ocupados, ele não dar erro

									lucroum=um[j]-um[i]       #Lucro é o valor no dia da venda menos o valor no dia da compra
									umc=False                  #Por enquando ela ter sido comprada é falso
									lucro1def=0					#Por enquanto o lucro definitivo da compra dela não existe
									lucro1=lucroum 				#Lucro temporário em relação a essa empresa é igual o lucro calculado acima
									compra=i					#Posição da compra na lista
									venda=j						#Posição da venda na lista
									if i<j and lucro1>0:		#Só para confirmar, se o o dia da compra for antes do de venda e o lucro for positivo
										umc=True				#A empresa foi comprada
										lucro1def=lucro1		#Lucro definitivo=lucro temporário
										compra1def=compra+1		#Compra definitiva da empresa=posição na lista+1, já que a lista começa em 0
										venda1def=venda+1		#Venda definitiva da empresa=posição na lista+1, já que a lista começa em 0
										pricv=[b for b in range(compra,venda+1)]		#Intervalo ocupado pela primeira compra
			
									lucrodois=dois[l]-dois[k]		#Lucro é o valor no dia da venda menos o valor no dia da compra
									doisc=False						#Por enquando ela ter sido comprada é falso
									válido=False					#Por enquanto a empresa não está num intervalo de compra válido
									lucro2=lucrodois				#Lucro temporário em relação a essa empresa é igual o lucro calculado acima
									compra=k						#Posição da compra na lista
									venda=l							#Posição da venda na lista
									lucro2def=0						#Por enquanto o lucro definitivo da compra dela não existe
									válido=intervalosdiferentes()
									if k<l and lucro2>0 and válido:		#Só para confirmar, se o o dia da compra for antes do de venda e o lucro for positivo e estiver num intervalo diferente do da compra anterior
										doisc=True						#A empresa foi comprada
										lucro2def=lucro2				#Lucro definitivo=lucro temporário
										compra2def=compra+1				#Compra definitiva=compra temporária
										venda2def=venda+1				#Venda definitiva=Venda temporária		
										if umc:							#Se a empresa 1 foi comprada
											segcv=[b for b in range(compra,venda+1)]		#Esse é  o segundo intervalo de compra
										else:												#Se empresa 1 não foi comprada
											pricv=[b for b in range(compra,venda+1)]		#Esse é o primerio intervalo de compra
							
									lucrotrês=três[n]-três[m]							#Empresa 3 segue a mesma lógica das anteriores
									trêsc=False
									válido=False
									lucro3=lucrotrês
									compra=m
									venda=n
									lucro3def=0
									válido=intervalosdiferentes()
									if m<n and lucro3>0 and válido:
										trêsc=True
										lucro3def=lucro3
										compra3def=compra+1
										venda3def=venda+1	
										if umc and doisc:
											tercv=[b for b in range(compra,venda+1)]
										elif umc or doisc:
											segcv=[b for b in range(compra,venda+1)]
										if umc==False and doisc==False:
											pricv=[b for b in range(compra,venda+1)]
											
									lucroquatro=quatro[p]-quatro[o]				#Empresa 4 segue a mesma lógica das anteriores
									quatroc=False
									válido=False
									lucro4=lucroquatro
									compra=o 
									venda=p
									lucro4def=0
									válido=intervalosdiferentes()
									if o<p and lucro4>0 and válido:
										quatroc=True
										lucro4def=lucro4
										compra4def=compra+1									
										venda4def=venda+1
														
									lucro=lucro1def+lucro2def+lucro3def+lucro4def		#Lucro temporário=Soma dos lucros defitivos sendo testados
									if lucro>lucrodef:						#Se esse lucro temporário for maior que o lcro definitivo anterior:
										lucrodef=lucro				#O lucro definitivo se torna o valor desse lucro temporário calculado
										lucro1definitivo=lucro1def		#O lucro definitivo final de cada empresa se torna o lucro definitivo dessa tentativa
										lucro2definitivo=lucro2def
										lucro3definitivo=lucro3def
										lucro4definitivo=lucro4def
										compra1definitiva=compra1def	#O dia de compra definitivo final de cada empresa se torna o dia de compra definitivo dessa tentativa
										compra2definitiva=compra2def
										compra3definitiva=compra3def
										compra4definitiva=compra4def
										venda1definitiva=venda1def   #O dia de venda definitivo final de cada empresa se torna o dia de venda definitivo dessa tentativa
										venda2definitiva=venda2def
										venda3definitiva=venda3def
										venda4definitiva=venda4def											
																		
if lucro1definitivo>0:				#Pra cada lucro o teste final é: Se o lucro da empresa for positivo, imprime os dados da compra dessa empresa
	print("acao %d: compra %d, venda %d, lucro %.2f" % (1, compra1definitiva, venda1definitiva, lucro1definitivo))
if lucro2definitivo>0:		
	print("acao %d: compra %d, venda %d, lucro %.2f" % (2, compra2definitiva, venda2definitiva, lucro2definitivo))
if lucro3definitivo>0:		
	print("acao %d: compra %d, venda %d, lucro %.2f" % (3, compra3definitiva, venda3definitiva, lucro3definitivo))
if lucro4definitivo>0:		
	print("acao %d: compra %d, venda %d, lucro %.2f" % (4, compra4definitiva, venda4definitiva, lucro4definitivo))
print("Lucro: %.2f" % (lucrodef))		#Imprime esse lucro definitivo, que é o maior