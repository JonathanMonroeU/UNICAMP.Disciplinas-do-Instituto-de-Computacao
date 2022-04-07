#Lindon Jonathan Sanley dos Santos Pereira Monroe RA 220407

ordem=(input())
ixj=ordem.split()
i=int(ixj[0])
j=int(ixj[1])

viz=[[0 for c in range(j+2)] for l in range(i+2)]
iteracoes=(int(input())

for l in range(1,i+1):	
		linha=input()
		linha=linha.split()
		for v in range(len(linha)):
			viz[l][v]=int(linha[v])
			
print("iteracao 0")
for l in range(1,i+1):
	for c in range(1,j+1):
		if c==j+1:
			print(viz[i][j])
		else:
			print(viz[i][j],end="")

for i in range(1,iteracoes+1):			
	for l in range(1,i+1):
		for c in range(1,j+1):
			nada=0;humanos=0;zumbis=0
			if[i-1][j-1]==0:
				nada=nada+1
			if[i-1][j-1]==1:
				humanos=humanos+1
			if[i-1][j-1]==2:
				zumbis==zumbis+1
				
			if[i-1][j]==0:
				nada=nada+1
			if[i-1][j]==1:
				humanos=humanos+1
			if[i-1][j]==2:
				zumbis=zumbis+1
		
			if[i-1][j+1]==0:
				nada=nada+1
			if[i-1][j+1]==1:
				humanos=humanos+1
			if[i-1][j+1]==2:
				zumbis=zumbis+1
		
			if[i][j-1]==0:
				nada=nada+1
			if[i][j-1]==1:
				humanos=humanos+1
			if[i][j-1]==2:
				zumbis=zumbis+1
		
			if[i][j+1]==0:
				nada=nada+1
			if[i][j+1]==1:
				humanos=humanos+1
			if[i][j+1]==2:
				zumbis=zumbis+1
		
			if[i+1][j-1]==0:
				nada=nada+1
			if[i+1][j-1]==1:
				humanos=humanos+1
			if[i+1][j-1]==2:
				zumbis=zumbis+1
		
			if[i+1][j]==0:
				nada=nada+1
			if[i+1][j]==1:
				humanos=humanos+1
			if[i+1][j]==2:
				zumbis=zumbis+1
		
			if[i+1][j+1]==0:
				nada=nada+1
			if[i+1][j+1]==1:
				humanos=humanos+1
			if[i+1][j+1]==2:
				zumbis=zumbis+1
		
		
			if viz[i][j]==0:
				if humanos==2:
					viz[i][j]=1
		
			elif viz[i][j]==1:
				if zumbis>=1:
					viz[i][j]=2
	
			elif viz[i][j]==2:
				if humanos==0:
					viz[i][j]=0
				elif humanos>=2:
					viz[i][j]=0
	print("iteracao",i)
	for l in range(1,i+1):
		for c in range(1,j+1):
			if l==j+1:
				print(viz[i][j])
			else:
				print(viz[i][j],end="")
	
	
			

	