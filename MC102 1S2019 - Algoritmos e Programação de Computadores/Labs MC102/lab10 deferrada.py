def arredondar():
	inteiro=int(M*10000)
	inteiromais1casa=int(M*100000)
	umacasadepoisdavirgula=inteiromais1casa/10
	diferença=umacasadepoisdavirgula-inteiro
	if diferença>=0.5:
		inteiro=(inteiro+1)/10000
		return inteiro
	else:
		inteiro=inteiro/10000
		return inteiro