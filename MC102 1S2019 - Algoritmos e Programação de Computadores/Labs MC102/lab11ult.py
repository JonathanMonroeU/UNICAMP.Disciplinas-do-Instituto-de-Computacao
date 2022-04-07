def intervalosdiferentes2():
	emcomumpri=0
	emcomumseg=0
	emcomumter=0
	tempo=[x for x in range(compra2,venda2+1)]
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
		
def intervalosdiferentes3():
	emcomumpri=0
	emcomumseg=0
	emcomumter=0
	tempo=[x for x in range(compra3,venda3+1)]
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
		
def intervalosdiferentes4():
	emcomumpri=0
	emcomumseg=0
	emcomumter=0
	tempo=[x for x in range(compra4,venda4+1)]
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
		


pricv=[123456];segcv=[123456];tercv=[123456]
lucro1=0;lucro2=0;lucro3=0;lucro4=0;lucro1definitivo=0;lucro2definitivo=0;lucro3definitivo=0;lucro4definitivo=0
lucro1def=0;lucro2def=0;lucro3def=0;lucro4def=0;lucrodef=0
compra1=0;compra2=0;compra3=0;compra4=0
compra1def=0;compra2def=0;compra3def=0;compra4def=0;
venda1def=0;venda2def=0;venda3def=0;venda4def=0;
umc=False;doisc=False;trêsc=False;quatroc=False

									
									
d=int(input())

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
	
	
for i in range(d):
	for j in range(d):
		for k in range(d):
				for l in range(d):
					for m in range(d):
						for n in range(d):
							for o in range(d):
								for p in range(d):
									pricv=[123456];segcv=[123456];tercv=[123456]

								
									lucroum=um[j]-um[i]
									umc=False
									lucro1def=0
									
									lucro1=lucroum 
									compra1=i
									venda1=j
									if i<j and lucro1>0:
										umc=True
										lucro1def=lucro1
										compra1def=compra1+1
										venda1def=venda1+1
										pricv=[b for b in range(compra1,venda1+1)]
			
			
									
									lucrodois=dois[l]-dois[k]
									doisc=False
									válido=False
										
									lucro2=lucrodois
									compra2=k
									venda2=l
									lucro2def=0
									válido=intervalosdiferentes2()
									if k<l and lucro2>0 and válido:
										doisc=True
										lucro2def=lucro2
										compra2def=compra2+1
										venda2def=venda2+1								
										if umc:
											segcv=[b for b in range(compra2,venda2+1)]
										else:
											pricv=[b for b in range(compra2,venda2+1)]
							
							
								
									lucrotrês=três[n]-três[m]
									trêsc=False
									válido=False
									
									lucro3=lucrotrês
									compra3=m
									venda3=n
									lucro3def=0
									válido=intervalosdiferentes3()
									if m<n and lucro3>0 and válido:
										trêsc=True
										lucro3def=lucro3
										compra3def=compra3+1
										venda3def=venda3+1	
										if umc and doisc:
											tercv=[b for b in range(compra3,venda3+1)]
										elif umc or doisc:
											segcv=[b for b in range(compra3,venda3+1)]
										if umc==False and doisc==False:
											pricv=[b for b in range(compra3,venda3+1)]
											
											
											
									lucroquatro=quatro[p]-quatro[o]
									quatroc=False
									válido=False
											
									lucro4=lucroquatro
									compra4=o 
									venda4=p
									lucro4def=0
									válido=intervalosdiferentes4()
									if o<p and lucro4>0 and válido:
										quatroc=True
										lucro4def=lucro4
										compra4def=compra4+1									
										venda4def=venda4+1
														
														
									lucro=lucro1def+lucro2def+lucro3def+lucro4def
													
														
									if lucro>lucrodef:
										lucrodef=lucro
										lucro1definitivo=lucro1def
										lucro2definitivo=lucro2def
										lucro3definitivo=lucro3def
										lucro4definitivo=lucro4def
														
										compra1definitiva=compra1def
										compra2definitiva=compra2def
										compra3definitiva=compra3def
										compra4definitiva=compra4def
										venda1definitiva=venda1def
										venda2definitiva=venda2def
										venda3definitiva=venda3def
										venda4definitiva=venda4def
														
														
									
											
if lucro1definitivo>0:
	umc=True
if lucro2definitivo>0:
	doisc=True
if lucro3definitivo>0:
	trêsc=True
if lucro4definitivo>0:
	quatroc=True																		

if umc:		
	print("acao %d: compra %d, venda %d, lucro %.2f" % (1, compra1definitiva, venda1definitiva, lucro1definitivo))
if doisc:		
	print("acao %d: compra %d, venda %d, lucro %.2f" % (2, compra2definitiva, venda2definitiva, lucro2definitivo))
if trêsc:		
	print("acao %d: compra %d, venda %d, lucro %.2f" % (3, compra3definitiva, venda3definitiva, lucro3definitivo))
if quatroc:		
	print("acao %d: compra %d, venda %d, lucro %.2f" % (4, compra4definitiva, venda4definitiva, lucro4definitivo))

print("Lucro: %.2f" % (lucrodef))