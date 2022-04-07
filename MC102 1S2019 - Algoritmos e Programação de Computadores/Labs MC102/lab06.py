C=int(input())
capacidaderestante=C
x=[]
veiculo=1
while veiculo>=-5 and veiculo<=5 and veiculo!=0:
  veiculo=int(input())
  x.append(veiculo)
for i in range(len(x)):
  if x[i]>0:
    if capacidaderestante>=x[i]:
      capacidaderestante=capacidaderestante-x[i]
      print("Seja bem-vindo! Capacidade restante:", capacidaderestante)
    else:
      print("Veiculo muito grande! Capacidade restante:", capacidaderestante)
  if x[i]<0:
    capacidaderestante=capacidaderestante-x[i]
    print("Volte sempre! Capacidade restante:", capacidaderestante)
 