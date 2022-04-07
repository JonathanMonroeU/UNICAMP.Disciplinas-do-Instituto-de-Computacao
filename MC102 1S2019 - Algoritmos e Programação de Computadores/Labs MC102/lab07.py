#Lindon Jonathan Sanley dos Santos Pereira Monroe RA 220407

#Round 1

lryu=50  #vida do Ryu
lken=50  #vida do Ken
dryu=0   #dano recebido pelo Ryu
dken=0   #dano recebido pelo Ken
kenwin=0   #vezes Ken venceu Round
ryuwin=0   #vezes Ryu venceu Round

golpe=int(input())   #golpe inicial

while lryu>0 and lken>0:   #enquanto ninguém tiver perdido todos os pontos de vida
	if golpe>0:     #se Ryu ataca Ken
		aken=lken
		dken=dken+golpe
		lken=lken-golpe
		if lken>0:
			golpe=int(input())
			while golpe>0 and lken>0:
				dken=dken+golpe
				lken=lken-golpe
				if lken>0:
					golpe=int(input())
		print("Ken:",aken,"-",dken,"=",lken)
		dken=0
	if golpe<0:     #se Ken ataca Ryu
		aryu=lryu
		dryu=dryu-golpe
		lryu=lryu+golpe
		if lryu>0:
			golpe=int(input())
			while golpe<0 and lryu>0:
				dryu=dryu-golpe
				lryu=lryu+golpe
				if lryu>0:
					golpe=int(input())
		print("Ryu:",aryu,"-",dryu,"=",lryu)
		dryu=0
		
		
if lryu<=0:    #se Ryu está sem vida
	kenwin=1
elif lken<=0:   #se Ken está sem vida
	ryuwin=1
		
  

#Round 2

lryu=50
lken=50
dryu=0
dken=0

golpe=int(input())

while lryu>0 and lken>0:
	if golpe>0:     
		aken=lken
		dken=dken+golpe
		lken=lken-golpe
		if lken>0:
			golpe=int(input())
			while golpe>0 and lken>0:
				dken=dken+golpe
				lken=lken-golpe
				if lken>0:
					golpe=int(input())
		print("Ken:",aken,"-",dken,"=",lken)
		dken=0
	if golpe<0:
		aryu=lryu
		dryu=dryu-golpe
		lryu=lryu+golpe
		if lryu>0:
			golpe=int(input())
			while golpe<0 and lryu>0:
				dryu=dryu-golpe
				lryu=lryu+golpe
				if lryu>0:
					golpe=int(input())
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
 