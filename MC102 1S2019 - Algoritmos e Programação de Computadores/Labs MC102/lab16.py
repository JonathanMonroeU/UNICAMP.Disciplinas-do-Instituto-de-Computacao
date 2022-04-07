#Lindon Jonathan Sanley dos Santos Pereira Monroe RA 220407

#!/usr/bin/env python3

# Funcao: pertence
#
# Parametros:
#   conj: vetor contendo o conjunto de entrada
#    num: elemento a ser verificado pertinencia
#
# Retorno:
#   True se num pertence a conj e False caso contrario
#
def pertence(conj, num):
    # Implementar a funcao e trocar o valor de retorno
	if num in conj:
		return True
	else:	
		return False
# Funcao: contido
#
# Parametros:
#   conj1: vetor contendo um conjunto de entrada
#   conj2: vetor contendo um conjunto de entrada
#
# Retorno:
#   True se conj1 esta contido em conj2 e False caso contrario
#
def contido(conj1, conj2):
    # Implementar a funcao e trocar o valor de retorno
	contem=True
	for i in conj1:
		if i not in conj2:
			contem=False
	if contem==True:
		return True
	else:		
		return False

# Funcoes: adicao e subtracao
#
# Parametros:
#   conj: vetor contendo o conjunto que tera incluso ou removido o elemento
#    num: elemento a ser adicionado ou removido
#
def adicao(conj, num):
    # Implementar a funcao
	if num not in conj:
		conj=conj.append(num)
	return 
	

def subtracao(conj, num):
    # Implementar a funcao
	if num in conj:
		conj.remove(num)
		return

# Funcoes: uniao, intersecao e diferenca
#
# Parametros:
#     conj1: vetor contendo o conjunto de entrada do primeiro operando
#     conj2: vetor contendo o conjunto de entrada do segundo operando
#
# Retorno:
#   Vetor contendo o conjunto de saida/resultado da operacao
#
def uniao(conj1, conj2):
    # Implementar a funcao e trocar o valor de retorno
	conjaux=[]
	for i in conj1:
		conjaux.append(i)
	for j in conj2:
		if j not in conj1:
			conjaux.append(j)
	return conjaux

def intersecao(conj1, conj2):
    # Implementar a funcao e trocar o valor de retorno
	conjaux=[]
	for i in conj2:
		if i in conj1:
			conjaux.append(i)
	return conjaux

def diferenca(conj1, conj2):
    # Implementar a funcao e trocar o valor de retorno
	conjaux=[]
	for i in conj1:
		if i not in conj2:
			conjaux.append(i)
	return conjaux

def uniao_disjunta(conj1, conj2):
    # Implementar a funcao e trocar o valor de retorno
	conjaux=[]
	for i in conj1:
		if i not in conj2:
			conjaux.append(i)
	for i in conj2:
		if i not in conj1:
			if i not in conjaux:
				conjaux.append(i)
	return conjaux
