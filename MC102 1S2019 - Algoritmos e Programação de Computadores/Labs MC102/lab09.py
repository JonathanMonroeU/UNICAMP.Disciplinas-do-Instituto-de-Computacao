#Lindon Jonathan Sanley dos S P Monroe RA 220407
n=int(input())
asteriscos=0
for i in range(1,n+1):
	for j in range(1,n+1):
		if i%j== 0 or j%i==0:
			asteriscos=asteriscos+1
			print("*",end="")
		else:
			print("-",end="")
		if j==n:
			print()
print(asteriscos)
		
			