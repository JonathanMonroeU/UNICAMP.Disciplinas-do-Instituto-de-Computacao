def intervalosdiferentes():
	emcomumpri=0
	emcomumseg=0
	emcomumter=0
	tempo=[k for k in range(i,j+1)]
	
	for m in pricv:
		for n in tempo:
			if m==n:
				emcomumpri=emcomumpri+1
	for m in segcv:
		for n in tempo:
			if m==n:
				emcomumseg=emcomumseg+1
	for m in tercv:
		for n in tempo:
			if m==n:
				emcomumter=emcomumter+1
	if emcomumpri<2 and emcomumseg<2 and emcomumter<2:
		return True
	else:
		return False


d=int(input())

um=[0 for i in range (d)]
dois=[0 for i in range (d)]
três=[0 for i in range (d)]
quatro=[0 for i in range (d)]

lucro1=0;lucro2=0;lucro3=0;lucro4=0
lucro1def=0;lucro2def=0;lucro3def=0;lucro4def=0;lucrodef=0
compra1=-1;compra2=-1;compra3=-1;compra4=-1
compra1def=0;compra2def=0;compra3def=0;compra4def=0
venda1def=0;venda2def=0;venda3def=0;venda4def=0

umc=False;doisc=False;trêsc=False;quatroc=False
pricv=[123456];segcv=[123456];tercv=[123456]



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
		lucroum=um[j]-um[i]
		if i<=j:
			lucro1=lucroum
			compra1=i
			venda1=j
			if i<j:
				umc=True
				lucro1def=lucro1
				compra1def=compra1+1
				venda1def=venda1+1
				pricv=[b for b in range(compra1,venda1+1)]
			for i in range(d):
				for j in range(d):
					válido=intervalosdiferentes()
					if válido:
						lucrodois=dois[j]-dois[i]
						if i<=j:
							lucro2=lucrodois
							compra2=i
							venda2=j
							if i<j:
								doisc=True
								lucro2def=lucro2
								compra2def=compra2+1
								venda2def=venda2+1								
								if umc:
									segcv=[b for b in range(compra2,venda2+1)]
								else:
									pricv=[b for b in range(compra1,venda1+1)]
							for i in range(d):
								for j in range(d):
									válido=intervalosdiferentes()
									if válido:
										lucrotrês=três[j]-três[i]
										if i<=j:
											lucro3=lucrotrês
											compra3=i
											venda3=j
											if i<j:
												trêsc=True
												lucro3def=lucro3
												compra3def=compra3+1
												venda3def=venda3+1
												if umc and doisc:
													tercv=[b for b in range(compra3,venda3+1)]
												elif umc or doisc:
													segcv=[b for b in range(compra2,venda2+1)]
												if umc==False and doisc==False:
													pricv=[b for b in range(compra1,venda1+1)]
											for i in range(d):
												for j in range(d):
													válido=intervalosdiferentes()
													if válido:
														lucroquatro=quatro[j]-quatro[i]
														if i<=j:
															lucro4=lucroquatro
															compra4=i 
															venda4=j
															if i<j:
																quatroc=True
																lucro4def=lucro4
																compra4def=compra4+1									
																venda4def=venda4+1
														
															lucro=lucro1def+lucro2def+lucro3def+lucro4def
															if lucro>lucrodef:
																lucrodef=lucro
																compra1definitiva=compra1def
																compra2definitiva=compra2def
																compra3definitiva=compra3def
																compra4definitiva=compra4def
																venda1definitiva=venda1def
																venda2definitiva=venda2def
																venda3definitiva=venda3def
																venda4definitiva=venda4def
									
											
																			
if umc:		
	print("acao %d: compra %d, venda %d, lucro %.2f" % (1, compra1definitiva, venda1definitiva, lucro1def))
if doisc:		
	print("acao %d: compra %d, venda %d, lucro %.2f" % (2, compra2definitiva, venda2definitiva, lucro2def))
if trêsc:		
	print("acao %d: compra %d, venda %d, lucro %.2f" % (3, compra3definitiva, venda3definitiva, lucro3def))
if quatroc:		
	print("acao %d: compra %d, venda %d, lucro %.2f" % (4, compra4definitiva, venda4definitiva, lucro4def))

lucrodef=lucro1def+lucro2def+lucro3def+lucro4def
print("Lucro: %.2f" % (lucrodef))