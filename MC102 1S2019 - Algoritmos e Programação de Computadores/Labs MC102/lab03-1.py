d=float(input())
h=float(input())
a=float(input())
b=float(input())
c=float(input())
r=d/2
V=float(3.14*r**2*h*1000)
if a<=V:
  print("posto A foi reabastecido")
else:  
  print("posto A nao foi reabastecido")
if a<=V and b<=V-a:
  print("posto B foi reabastecido")
  if c<=V-a-b:
    print("posto C foi reabastecido")
if a>V and b<=V:
  print("posto B foi reabastecido")
    if c<=V-b:
    print("posto C foi reabastecido")
		
		
	  
  

 


