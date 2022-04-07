#Lindon Jonathan Sanley dos Santos Pereira Monroe RA 220407

def tipodegolpe():
	golpe=int(input())
	if golpe>0:
		golpet=golpe
	if golpe<0:
		golpet=-golpe
	d=0
	for i in range (1,golpet):
		if golpet%i==0:
			d=d+i
			if d==golpet:
				golpe=golpe*3
				return golpe
			elif d>golpet:
				break
	d=0
	for i in range (1,golpet+1):
		d=d+i
		if d==golpet:
			golpe=golpe*2
			return golpe
		elif d>golpet:
			return golpe
	

#Round 1

lryu=2000  #vida do Ryu
lken=2000  #vida do Ken
dryu=0   #dano recebido pelo Ryu
dken=0   #dano recebido pelo Ken
kenwin=0   #vezes Ken venceu Roundhnm  
ryuwin=0   #vezes Ryu venceu Round

golpe=tipodegolpe()   #golpe inicial

while lryu>0 and lken>0:   #enquanto ninguém tiver perdido todos os pontos de vida
	if golpe>0:     #se Ryu ataca Ken
		aken=lken
		dken=dken+golpe
		lken=lken-golpe
		if lken>0:
			golpe=tipodegolpe()
			while golpe>0 and lken>0:
				dken=dken+golpe
				lken=lken-golpe
				if lken>0:
					golpe=tipodegolpe()
		print("Ken:",aken,"-",dken,"=",lken)
		dken=0
	if golpe<0:     #se Ken ataca Ryu
		aryu=lryu
		dryu=dryu-golpe
		lryu=lryu+golpe
		if lryu>0:
			golpe=tipodegolpe()
			while golpe<0 and lryu>0:
				dryu=dryu-golpe
				lryu=lryu+golpe
				if lryu>0:
					golpe=tipodegolpe()
		print("Ryu:",aryu,"-",dryu,"=",lryu)
		dryu=0
		
		
if lryu<=0:    #se Ryu está sem vida
	kenwin=1
elif lken<=0:   #se Ken está sem vida
	ryuwin=1
		
  

#Round 2

lryu=2000
lken=2000
dryu=0
dken=0

golpe=tipodegolpe()

while lryu>0 and lken>0:
	if golpe>0:     
		aken=lken
		dken=dken+golpe
		lken=lken-golpe
		if lken>0:
			golpe=tipodegolpe()
			while golpe>0 and lken>0:
				dken=dken+golpe
				lken=lken-golpe
				if lken>0:
					golpe=tipodegolpe()
		print("Ken:",aken,"-",dken,"=",lken)
		dken=0
	if golpe<0:
		aryu=lryu
		dryu=dryu-golpe
		lryu=lryu+golpe
		if lryu>0:
			golpe=tipodegolpe()
			while golpe<0 and lryu>0:
				dryu=dryu-golpe
				lryu=lryu+golpe
				if lryu>0:
					golpe=tipodegolpe()
		print("Ryu:",aryu,"-",dryu,"=",lryu)
		dryu=0
		
if lryu<=0:   #se Ryu está sem vida
	kenwin=kenwin+1
elif lken<=0:   #se Ken está sem vida
	ryuwin=ryuwin+1
			
 
if ryuwin>kenwin:
	print("Ryu venceu")
elif kenwin>ryuwin:
	print("Ken venceu")
elif ryuwin==kenwin:
	print("empatou")