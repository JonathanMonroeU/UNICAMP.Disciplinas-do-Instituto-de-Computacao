#!/usr/bin/env python3

import math

# Laboratorio 17 - Banco de Dados Geografico
# Nome: Lindon Jonathan Sanley dos Santos Pereira Monroe
# RA: 220407

class Ponto:
    def __init__(self, x, y):
        self.x = x
        self.y = y

class Cidade:
    def __init__(self, coordenadas, inicioCEP, fimCEP, numHabitantes):
        self.coordenadas = coordenadas
        self.inicioCEP = inicioCEP
        self.fimCEP = fimCEP
        self.numHabitantes = numHabitantes

#
# Funcao: distancia
#
# Parametros:
#   a, b: pontos
#
# Retorno:
#   A distancia euclidiana entre a e b.
#
def distancia(c1, c2):
    return int(100 * math.sqrt((c1.x - c2.x)**2 + (c1.y - c2.y)**2)) / 100.0

# Funcao: consulta_cidade_por_cep
#
# Parametros:
#   cidades: lista de cidades (base de dados) 
#       cep: CEP desejado 
# 
# Retorno:
#   O indice da cidade que contem o CEP desejado ou None caso não haja tal cidade.   
#
def consulta_cidade_por_cep(cidades, cep):
    # Implementar a funcao e trocar o valor de retorno 
	for i in range (len(cidades)):					#Pra cada posição na lista de cidades
		a=cidades[i]								#Igualo o que está na posição a uma variável
		if cep>a.inicioCEP and cep<a.fimCEP:		#Vejo se está entre o primeiro e último CEP
			return i
		if cep==a.inicioCEP:						#Vejo se é igual o primeiro ou o último
			return i
		if cep==a.fimCEP:
			return i								#Retorno a posição se houver correspondência
	return None

# Funcao: consulta_cidades_por_raio
#
# Parametros:
#            cidades: lista de cidades (base de dados) 
#   cidadeReferencia: indice da cidade referencia (centro da circunferencia)
#               raio: raio da busca
#
# Retorno:
#   Lista dos indices das cidades que estao contidas no raio de busca (incluindo
#   a cidade referencia) *ordenados pelas respectivas distancias da cidade referencia*.
#
def consulta_cidades_por_raio(cidades, cidadeReferencia, raio):
    # Implementar a funcao e trocar o valor de retorno
	a=cidades[cidadeReferencia]											
	listac=[]															#Crio listas auxiliiares vazias
	listad=[]
	listades=[1234567890 for m in range (len(cidades))]
	for i in range (len(cidades)):		
		b=cidades[i]
		d=distancia(a.coordenadas,b.coordenadas)						#Uso a função de distancia para encontrar a distancia entre a cidade referência e cada outra
		if d<=raio:														#Se a distancia for menor ou igual ao raio, guardo numa lista
			listad.append(d)											#Guardo a distância na posição original numa lista auxiliar
			listades[i]=d
				
	listad.sort()														#Ordeno a lista de distancias
	for i in range(len(listad)):										#Na ordem crescente, pra cada distância eu coloco a posição original numa lista auxiliar para retornar 
		for j in range(len(listades)):
			if listad[i]==listades[j]:
				listac.append(j)
	
	if listac!=[]:
		return listac
	return None

# Funcao: populacao_total
#
# Parametros:
#            cidades: lista de cidades (base de dados) 
#   cidadeReferencia: indice da cidade referencia (centro da circunferencia)
#               raio: raio da busca
#          
# Retorno:
#   O numero de habitantes das cidades que estao contidas no raio de busca
#
def populacao_total(cidades, cidadeReferencia, raio):
    # Implementar a funcao e trocar o valor de retorno 
	a=cidades[cidadeReferencia]								#Mesmo procedimento da função anterior
	listac=[]
	listad=[]
	for i in range (len(cidades)):
		b=cidades[i]
		d=distancia(a.coordenadas,b.coordenadas)
		if d<=raio:											#Adiciono na lista a posição das cidades dentro do raio
			listac.append(i)
	
	populacao=0												#População inicial 
	for i in listac:										#Pra cada cidade na listac, somo o seu número de habitantes para retornar
		e=cidades[i]
		populacao=populacao+e.numHabitantes
		
	if listac!=[]:
		return populacao
	return None

# Funcao: mediana_da_populacao
#
# Parametros:
#            cidades: lista de cidades (base de dados) 
#   cidadeReferencia: indice da cidade referencia (centro da circunferencia)
#               raio: raio da busca
#
# Retorno:
#   Mediana do numero de habitantes das cidades que estao contidas no raio de busca
#
def mediana_da_populacao(cidades, cidadeReferencia, raio):
    # Implementar a funcao e trocar o valor de retorno
	a=cidades[cidadeReferencia]								#Mesmo inicio das funções anteriores
	listac=[]
	for i in range (len(cidades)):
		b=cidades[i]
		d=distancia(a.coordenadas,b.coordenadas)
		if d<=raio:
			listac.append(b.numHabitantes)					#Adiciono numa lista o numero de habitantes de cada cidade
	listac.sort()
	if listac!=[]:
		if len(listac)%2==0:								#Se o comprimento da lista for par, faz a média entre os dois do meio da lista ordenada e retorna
			x=(len(listac)//2)-1
			y=x+1
			z=(listac[x]+listac[y])/2
			return z
		else:												#Se for ímpar, retorna o número do meio da lista ordenada
			x=(len(listac)//2)
			z=listac[x]
			return z
	return None


