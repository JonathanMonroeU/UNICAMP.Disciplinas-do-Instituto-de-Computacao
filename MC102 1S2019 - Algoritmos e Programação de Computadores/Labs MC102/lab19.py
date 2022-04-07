#Lab19-Hierarquia
#Lindon Jonathan Sanley dos Santos Pereira Monroe
#RA 220407

entrada=input()
entrada=entrada.split()
n=int(entrada[0])
f=int(entrada[1])
hi=[]
for m in range(n):
	func=input()
	func=func.split()
	for z in range(len(func)):
		func[z]=int(func[z])
	hi.append(func)

def main():
	resultado=(subord(f))
	resultado.sort()
	if resultado==[]:
		print(f)
	else:
		print(f,end=" ")
	for k in range(len(resultado)):
		if k==len(resultado)-1:
			print(resultado[k])
		else:
			print(resultado[k],end=" ")

def subord(f):
	sub=[]
	for r in range(n):
		if hi[f][r]==1:  
			sub.append(r)
	if sub==[]:
		return sub
	else:
		result=[]
		result+=sub
		for q in sub:
			result+=subord(q)
		return result
			
			
main()
