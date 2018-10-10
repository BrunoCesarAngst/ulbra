Algoritmo "ex14"

Var

	no: caracter
	sal, ns: real

Inicio

	escreva("Ola, qual he o seu nome? ")
	leia(no)

	escreva(no," me informe seu salario: ")
	leia(sal)

	escreval(no," seu salario de",sal," tem uma gratificação de 5%, e tem uma desconto de impostos de 7%.")

	ns <- (sal + (sal * 5 / 100)) - (sal * 7 / 100);

	escreva("Seu salario final he de R$ ", ns)

Fimalgoritmo
