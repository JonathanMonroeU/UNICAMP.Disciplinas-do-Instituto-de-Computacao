d=int(input())

um=[0 for i in range (d)]
dois=[0 for i in range (d)]
três=[0 for i in range (d)]
quatro=[0 for i in range (d)]

	
ant=0.0
for i in range (d):
	x=float(input())
	um[i]=um[i]+x
	um[i]=um[i]-ant
	ant=x

ant=0.0
for i in range (d):
	x=float(input())
	dois[i]=dois[i]+x
	dois[i]=dois[i]-ant
	ant=x

ant=0.0
for i in range (d):
	x=float(input())
	três[i]=três[i]+x
	três[i]=três[i]-ant
	ant=x

ant=0.0
for i in range (d):
	x=float(input())
	quatro[i]=quatro[i]+x
	quatro[i]=quatro[i]-ant
	ant=x
		
compra1=20       #valor inexistente
compra2=20
compra3=20
compra4=20
venda1=20
venda2=20
venda3=20
venda4=20
lucro1=0
lucro2=0
lucro3=0
lucro4=0
umc=False
doisc=False
trêsc=False
quatroc=False

for i in range (1,d):
	if um[i]>dois[i] and um[i]>três [i] and um[i]>quatro[i]:
		if compra1==20:
			compra1=i
			venda1=i+1
			lucro1=um[i]
			umc=True
		elif compra1!=20:
			venda1=i+1
			lucro1=lucro1+um[i]
	if dois[i]>um[i] and dois[i]>três [i] and dois[i]>quatro[i]:
		if compra2==20:
			compra2=i
			venda2=i+1
			lucro2=um[i]
			doisc=True
		elif compra2!=20:
			venda2=i+1
			lucro2=lucro2+dois[i]
	if três[i]>um[i] and três[i]>dois [i] and três[i]>quatro[i]:
		if compra3==20:
			compra3=i
			venda3=i+1
			lucro3=três[i]
			trêsc=True
		elif compra3!=20:
			venda3=i+1
			lucro3=lucro3+três[i]
	if quatro[i]>um[i] and quatro[i]>dois [i] and quatro[i]>três[i]:
		if compra4==20:
			compra4=i
			venda4=i+1
			lucro4=três[i]
			quatroc=True
		elif compra4!=20:
			venda4=i+1
			lucro4=lucro4+quatro[i]

	

if umc:		
	print("acao %d: compra %d, venda %d, lucro %.2f" % (1, compra1, venda1, lucro1))
if doisc:		
	print("acao %d: compra %d, venda %d, lucro %.2f" % (2, compra2, venda2, lucro2))
if trêsc:		
	print("acao %d: compra %d, venda %d, lucro %.2f" % (3, compra3, venda3, lucro3))
if quatroc:		
	print("acao %d: compra %d, venda %d, lucro %.2f" % (4, compra4, venda4, lucro4))

Lucro=lucro1+lucro2+lucro3+lucro4
print("Lucro: %.2f" % (Lucro))