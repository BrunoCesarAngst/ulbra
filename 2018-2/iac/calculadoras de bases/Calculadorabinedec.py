# Convertor-debioc

# Criei uma função conversor que trabalha com
#  3 informaçãoes
def conversor(número, baseinic, basefim):

	# Declarei valores numéricos para as variáveis
	# trabalhadas dentro da função.
	# Iniciei as variáveis de controle antes do comando.
	resultado = 0
	potência = 0

	# Criei uma condição que usa a variável de controle e
	# se mantenha verdadeira pelo número correto de iterações
	while número > 0:
	# Modifiquei a variável de controle para garantir a terminação e
		resultado += baseinic ** potência * (número % basefim)
		número //= basefim
		potência += 1
	# realizar as computações sucessivas para se chegar a resposta correta
	return (resultado)

número = int(input('Digite um número (binário, octal ou decimal): '))
baseinic = int(input('Digite a base desse número (2, 8 ou 10): '))
basefim = int(input('Digite a base de conversão (2, 8 ou 10): '))

print(conversor(número, baseinic, basefim))
