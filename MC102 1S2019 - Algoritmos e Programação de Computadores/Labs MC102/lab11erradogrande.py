d=int(input())

um=[0 for i in range (d)]
dois=[0 for i in range (d)]
três=[0 for i in range (d)]
quatro=[0 for i in range (d)]

lucro1=0;lucro2=0;lucro3=0;lucro4=0
lucro1def=0;lucro2def=0;lucro3def=0;lucro4def=0
umc=False;doisc=False;trêsc=False;quatroc=False
pricv=[100];segcv=[100];tercv=[100]
compra1=0;compra2=0;compra3=0;compra4=0

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
		if lucroum>lucro1 and i<j:
			lucro1=lucroum
			compra1=i
			venda1=j
		lucrodois=dois[j]-dois[i]
		if lucrodois>lucro2 and i<j:
			lucro2=lucrodois
			compra2=i
			venda2=j
		lucrotrês=três[j]-três[i]
		if lucrotrês>lucro3 and i<j:
			lucro3=lucrotrês
			compra3=i
			venda3=j
		lucroquatro=quatro[j]-quatro[i]
		if lucroquatro>lucro4 and i<j:
			lucro4=lucroquatro
			compra4=i 
			venda4=j
if lucro1>lucro2 and lucro1>lucro3 and lucro1>lucro4:
	umc=True
	lucro1def=lucro1
	compra1def=compra1+1
	venda1def=venda1+1
	pricv=[i for i in range(compra1,venda1+1)]
elif lucro2>lucro1 and lucro2>lucro3 and lucro2>lucro4:
	doisc=True
	lucro2def=lucro2
	compra2def=compra2+1
	venda2def=venda2+1
	pricv=[i for i in range(compra2,venda2+1)]
elif lucro3>lucro1 and lucro3>lucro2 and lucro3>lucro4:
	trêsc=True
	lucro3def=lucro3
	compra3def=compra3+1
	venda3def=venda3+1
	pricv=[i for i in range(compra3,venda3+1)]
elif lucro4>lucro1 and lucro4>lucro2 and lucro4>lucro3:
	quatroc=True
	lucro4def=lucro4
	compra4def=compra4+1
	venda4def=venda4+1
	pricv=[i for i in range(compra4,venda4+1)]
elif lucro1==lucro2 or lucro1==lucro3 or lucro1==lucro4 or lucro2==lucro3 or lucro2==lucro4 or lucro3==lucro4:
	if compra1<compra2 and compra1<compra3 and compra1<compra4:
		umc=True
		lucro1def=lucro1
		compra1def=compra1+1
		venda1def=venda1+1
		pricv=[i for i in range(compra1,venda1+1)]
	if compra2<compra1 and compra2<compra3 and compra2<compra4:
		doisc=True
		lucro2def=lucro2
		compra2def=compra2+1
		venda2def=venda2+1
		pricv=[i for i in range(compra2,venda2+1)]
	if compra3<compra1 and compra3<compra2 and compra3<compra4:
		trêsc=True
		lucro3def=lucro3
		compra3def=compra3+1
		venda3def=venda3+1
		pricv=[i for i in range(compra3,venda3+1)]
	if compra4<compra1 and compra4<compra2 and compra4<compra3:
		quatroc=True
		lucro4def=lucro4
		compra4def=compra4+1
		venda4def=venda4+1
		pricv=[i for i in range(compra4,venda4+1)]
	
	
	


	
lucro1=0;lucro2=0;lucro3=0;lucro4=0

for i in range(d):
	for j in range(d):
		emcomumpri=0
		tempo=[k for k in range(i,j+1)]
		for m in pricv:
			for n in tempo:
				if m==n:
					emcomumpri=emcomumpri+1
		
		lucroum=um[j]-um[i]
		if lucroum>lucro1 and i<j and umc==False and emcomumpri<2:
			lucro1=lucroum
			compra1=i
			venda1=j
		lucrodois=dois[j]-dois[i]
		if lucrodois>lucro2 and i<j and doisc==False and emcomumpri<2:
			lucro2=lucrodois
			compra2=i
			venda2=j
		lucrotrês=três[j]-três[i]
		if lucrotrês>lucro3 and i<j and trêsc==False and emcomumpri<2:
			lucro3=lucrotrês
			compra3=i
			venda3=j
		lucroquatro=quatro[j]-quatro[i]
		if lucroquatro>lucro4 and i<j and quatroc==False and emcomumpri<2:
			lucro4=lucroquatro
			compra4=i 
			venda4=j
if lucro1>lucro2 and lucro1>lucro3 and lucro1>lucro4 and umc==False:
	umc=True
	lucro1def=lucro1
	compra1def=compra1+1
	venda1def=venda1+1
	segcv=[i for i in range(compra1,venda1+1)]
elif lucro2>lucro1 and lucro2>lucro3 and lucro2>lucro4 and doisc==False:
	doisc=True
	lucro2def=lucro2
	compra2def=compra2+1
	venda2def=venda2+1
	segcv=[i for i in range(compra2,venda2+1)]
elif lucro3>lucro1 and lucro3>lucro2 and lucro3>lucro4 and trêsc==False:
	trêsc=True
	lucro3def=lucro3
	compra3def=compra3+1
	venda3def=venda3+1
	segcv=[i for i in range(compra3,venda3+1)]
elif lucro4>lucro1 and lucro4>lucro2 and lucro4>lucro3 and quatroc==False:
	quatroc=True
	lucro4def=lucro4
	compra4def=compra4+1
	venda4def=venda4+1
	segcv=[i for i in range(compra4,venda4+1)]
elif lucro1==lucro2 or lucro1==lucro3 or lucro1==lucro4 or lucro2==lucro3 or lucro2==lucro4 or lucro3==lucro4:
	if compra1<compra2 and compra1<compra3 and compra1<compra4:
		umc=True
		lucro1def=lucro1
		compra1def=compra1+1
		venda1def=venda1+1
		segcv=[i for i in range(compra1,venda1+1)]
	if compra2<compra1 and compra2<compra3 and compra2<compra4:
		doisc=True
		lucro2def=lucro2
		compra2def=compra2+1
		venda2def=venda2+1
		segcv=[i for i in range(compra2,venda2+1)]
	if compra3<compra1 and compra3<compra2 and compra3<compra4:
		trêsc=True
		lucro3def=lucro3
		compra3def=compra3+1
		venda3def=venda3+1
		segcv=[i for i in range(compra3,venda3+1)]
	if compra4<compra1 and compra4<compra2 and compra4<compra3:
		quatroc=True
		lucro4def=lucro4
		compra4def=compra4+1
		venda4def=venda4+1
		segcv=[i for i in range(compra4,venda4+1)]


lucro1=0;lucro2=0;lucro3=0;lucro4=0

for i in range(d):
	for j in range(d):
		emcomumpri=0
		emcomumseg=0
		tempo=[k for k in range(i,j+1)]
		for m in pricv:
			for n in tempo:
				if m==n:
					emcomumpri=emcomumpri+1
		for m in segcv:
			for n in tempo:
				if m==n:
					emcomumseg=emcomumseg+1
				
		lucroum=um[j]-um[i]
		if lucroum>lucro1 and i<j and umc==False and emcomumpri<2 and emcomumseg<2:
			lucro1=lucroum
			compra1=i
			venda1=j
		lucrodois=dois[j]-dois[i]
		if lucrodois>lucro2 and i<j and doisc==False and emcomumpri<2 and emcomumseg<2:
			lucro2=lucrodois
			compra2=i
			venda2=j
		lucrotrês=três[j]-três[i]
		if lucrotrês>lucro3 and i<j and trêsc==False and emcomumpri<2 and emcomumseg<2:
			lucro3=lucrotrês
			compra3=i
			venda3=j
		lucroquatro=quatro[j]-quatro[i]
		if lucroquatro>lucro4 and i<j and quatroc==False and emcomumpri<2 and emcomumseg<2:
			lucro4=lucroquatro
			compra4=i 
			venda4=j
if lucro1>lucro2 and lucro1>lucro3 and lucro1>lucro4 and umc==False:
	umc=True
	lucro1def=lucro1
	compra1def=compra1+1
	venda1def=venda1+1
	tercv=[i for i in range(compra1,venda1+1)]
elif lucro2>lucro1 and lucro2>lucro3 and lucro2>lucro4 and doisc==False:
	doisc=True
	lucro2def=lucro2
	compra2def=compra2+1
	venda2def=venda2+1
	tercv=[i for i in range(compra2,venda2+1)]
elif lucro3>lucro1 and lucro3>lucro2 and lucro3>lucro4 and trêsc==False:
	trêsc=True
	lucro3def=lucro3
	compra3def=compra3+1
	venda3def=venda3+1
	tercv=[i for i in range(compra3,venda3+1)]
elif lucro4>lucro1 and lucro4>lucro2 and lucro4>lucro3 and quatroc==False:
	quatroc=True
	lucro4def=lucro4
	compra4def=compra4+1
	venda4def=venda4+1
	tercv=[i for i in range(compra4,venda4+1)]
elif lucro1==lucro2 or lucro1==lucro3 or lucro1==lucro4 or lucro2==lucro3 or lucro2==lucro4 or lucro3==lucro4:
	if compra1<compra2 and compra1<compra3 and compra1<compra4:
		umc=True
		lucro1def=lucro1
		compra1def=compra1+1
		venda1def=venda1+1
		tercv=[i for i in range(compra1,venda1+1)]
	if compra2<compra1 and compra2<compra3 and compra2<compra4:
		doisc=True
		lucro2def=lucro2
		compra2def=compra2+1
		venda2def=venda2+1
		tercv=[i for i in range(compra2,venda2+1)]
	if compra3<compra1 and compra3<compra2 and compra3<compra4:
		trêsc=True
		lucro3def=lucro3
		compra3def=compra3+1
		venda3def=venda3+1
		tercv=[i for i in range(compra3,venda3+1)]
	if compra4<compra1 and compra4<compra2 and compra4<compra3:
		quatroc=True
		lucro4def=lucro4
		compra4def=compra4+1
		venda4def=venda4+1
		tercv=[i for i in range(compra4,venda4+1)]
	


lucro1=0;lucro2=0;lucro3=0;lucro4=0


for i in range(d):
	for j in range(d):
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
								
		lucroum=um[j]-um[i]
		if lucroum>lucro1 and i<j and umc==False and emcomumpri<2 and emcomumseg<2 and emcomumter<2:
			lucro1=lucroum
			compra1=i
			venda1=j
		lucrodois=dois[j]-dois[i]
		if lucrodois>lucro2 and i<j and doisc==False and emcomumpri<2 and emcomumseg<2 and emcomumter<2:
			lucro2=lucrodois
			compra2=i
			venda2=j
		lucrotrês=três[j]-três[i]
		if lucrotrês>lucro3 and i<j and trêsc==False and emcomumpri<2 and emcomumseg<2 and emcomumter<2:
			lucro3=lucrotrês
			compra3=i
			venda3=j
		lucroquatro=quatro[j]-quatro[i]
		if lucroquatro>lucro4 and i<j and quatroc==False and emcomumpri<2 and emcomumseg<2 and emcomumter<2:
			lucro4=lucroquatro
			compra4=i 
			venda4=j
if lucro1>lucro2 and lucro1>lucro3 and lucro1>lucro4 and umc==False:
	umc=True
	lucro1def=lucro1
	compra1def=compra1+1
	venda1def=venda1+1
	quacv=[i for i in range(compra1,venda1+1)]
elif lucro2>lucro1 and lucro2>lucro3 and lucro2>lucro4 and doisc==False:
	doisc=True
	lucro2def=lucro2
	compra2def=compra2+1
	venda2def=venda2+1
	quacv=[i for i in range(compra2,venda2+1)]
elif lucro3>lucro1 and lucro3>lucro2 and lucro3>lucro4 and trêsc==False:
	trêsc=True
	lucro3def=lucro3
	compra3def=compra3+1
	venda3def=venda3+1
	quacv=[i for i in range(compra3,venda3+1)]
elif lucro4>lucro1 and lucro4>lucro2 and lucro4>lucro3 and quatroc==False:
	quatroc=True
	lucro4def=lucro4
	compra4def=compra4+1
	venda4def=venda4+1
	quacv=[i for i in range(compra4,venda4+1)]
elif lucro1==lucro2 or lucro1==lucro3 or lucro1==lucro4 or lucro2==lucro3 or lucro2==lucro4 or lucro3==lucro4:
	if compra1<compra2 and compra1<compra3 and compra1<compra4:
		umc=True
		lucro1def=lucro1
		compra1def=compra1+1
		venda1def=venda1+1
		quacv=[i for i in range(compra1,venda1+1)]
	if compra2<compra1 and compra2<compra3 and compra2<compra4:
		doisc=True
		lucro2def=lucro2
		compra2def=compra2+1
		venda2def=venda2+1
		quacv=[i for i in range(compra2,venda2+1)]
	if compra3<compra1 and compra3<compra2 and compra3<compra4:
		trêsc=True
		lucro3def=lucro3
		compra3def=compra3+1
		venda3def=venda3+1
		quacv=[i for i in range(compra3,venda3+1)]
	if compra4<compra1 and compra4<compra2 and compra4<compra3:
		quatroc=True
		lucro4def=lucro4
		compra4def=compra4+1
		venda4def=venda4+1
		quacv=[i for i in range(compra4,venda4+1)]
			

	

if umc:		
	print("acao %d: compra %d, venda %d, lucro %.2f" % (1, compra1def, venda1def, lucro1def))
if doisc:		
	print("acao %d: compra %d, venda %d, lucro %.2f" % (2, compra2def, venda2def, lucro2def))
if trêsc:		
	print("acao %d: compra %d, venda %d, lucro %.2f" % (3, compra3def, venda3def, lucro3def))
if quatroc:		
	print("acao %d: compra %d, venda %d, lucro %.2f" % (4, compra4def, venda4def, lucro4def))

Lucro=lucro1def+lucro2def+lucro3def+lucro4def
print("Lucro: %.2f" % (Lucro))