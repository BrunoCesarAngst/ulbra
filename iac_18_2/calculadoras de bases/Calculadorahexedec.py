#cal hexdec

# Criei uma função que retira um valor de dentro de uma lista, atribuindo o seu indece.
def __getdecdigito(digito):

	# Criei uma lista com a sequencia do hexagonal.
	digitos = ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F']

	# Para iterar (pegar um número adequado como um alvo para funções e construções) com cada 
	# número com índices de uma sequência na lista criei um for que "lista"-range que devolve 
	# o comprimento-(len'ght') da lista ou seja seu indice e atribui a função digito.
	for x in range(len(digitos)):
		if digito == digitos[x]:
			return x

# Criei outra função que obtem o número e seu indice da função anterior e converte o hexadecimal
#  para decimal.
def hexdec(hexnum):

	# Declarei valores numéricos para as variáveis trabalhadas dentro da função.
	decnum = 0
	potência = 0

	# Através do for criei uma outra interação que levará em consideração o valor informa hexadec
	# criando uma outra 'lista' através do range 
	for digito in range(len(hexnum), 0, -1):
		#
		decnum += 16 ** potência * __getdecdigito(hexnum[digito - 1])
		potência += 1
	print(str(decnum))
hexdec('A')
