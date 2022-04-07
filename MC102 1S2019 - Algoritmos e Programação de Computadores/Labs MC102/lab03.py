d=float(input())
h=float(input())
a=float(input())
b=float(input())
c=float(input())
r=d/2
V=float(3.14*r**2*h*1000)
if a<=V:
  print("posto A foi abastecido")
  if b<=V-a:
    print("posto B foi abastecido")
    if c<=V-a-b:
      print("posto C foi abastecido")
    elif c>V-a-b:
      print("posto C nao foi abastecido")
  elif b>V-a:
    print("posto B nao foi abastecido")
    if c<=V-a:
      print("posto C foi abastecido")
    elif c>V-a:
      print("posto C nao foi abastecido") 
elif a>V:
  print("posto A nao foi abastecido")
  if b<=V:
    print("posto B foi abastecido")
    if c<=V-b:
      print("posto C foi abastecido")
    elif c>V-b:
      print("posto C nao foi abastecido")
  if b>V:
    print("posto B nao foi abastecido")
    if c<=V:
      print("posto C foi abastecido")
    elif c>V:
      print("posto C nao foi abastecido")

