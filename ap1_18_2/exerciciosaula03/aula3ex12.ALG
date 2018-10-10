Algoritmo "ex12"

Var

	no: caracter
	sal, ns: real

Inicio

	escreva("Ola, qual he o seu nome? ")
	leia(no)

	escreva(no," me informe seu salario: ")
	leia(sal)

	escreval(no," seu salario de",sal," tera um reajuste de 25%.")

	ns <- sal + (sal * 25 / 100)

	escreva("Seu salario passa a ser de R$ ", ns)

Fimalgoritmo
