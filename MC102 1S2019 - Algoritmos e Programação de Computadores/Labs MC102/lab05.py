t=int(input())
c=int(input())
acu=0
suficiente=False
x=input()
y=x.split(" ") 
for i in range (len(y)):
  aux=int(y[i])
  acu=acu+aux
  if acu>=c:
    suficiente=True
    a=i+1
    break
if suficiente:
  print("sim")
  print(a)
else:
  print("nao")
  print(t+1)


#invalid literal for int() with base 10: ''