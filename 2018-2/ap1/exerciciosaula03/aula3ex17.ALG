Algoritmo "ex14"

Var

	alt, ndeg: real
	esp: inteiro

Inicio

	escreva("Qual he a medida dos espelhos da escada? ")
	leia(esp)

	escreva("Qual he a altura da escada? ")
	leia(alt)

	ndeg <- (alt / esp) *100

	escreva("Esta escada tera ",ndeg:2:0," degraus ate o topo.")

Fimalgoritmo
