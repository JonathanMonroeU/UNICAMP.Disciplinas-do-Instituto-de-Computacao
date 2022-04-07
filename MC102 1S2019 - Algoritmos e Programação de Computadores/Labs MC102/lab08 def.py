def tipodegolpe():
	golpe=int(input())
	if golpe<0:
		golpe=-golpe
	d=0
	for i in range (1,golpe):
		if golpe%i==0:
			d=d+i
			if d==golpe:
				golpe=golpe*3
				return golpe
			if d>golpe:
				break
	d=0
	for i in range (1,golpe):
		d=d+i
		if d==golpe:
			golpe=golpe*2
			return golpe
		if d>golpe:
			break

golpe=tipodegolpe()
print(golpe)
x=golpe+50
print("x:",x)



