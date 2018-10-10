Algoritmo "ex13"

Var

	vp, desc, vdesc: real

Inicio

	escreva("Qual he o valor do produto? ")
	leia(vp)

	escreva("Informe o percentual de desconto: ")
	leia(desc)

	vdesc <- vp - (vp * desc / 100)

	escreva("O produto de R$ ",vp," com o desconto de ",desc,"%, saira por R$ ", vdesc)

Fimalgoritmo
