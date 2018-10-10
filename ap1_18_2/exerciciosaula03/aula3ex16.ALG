Algoritmo "ex14"

Var

	kgsra, gt1, gt2, pordia, em5dia: real

Inicio

	escreva("Quantos quilos de racao voce comprou? ")
	leia(kgsra)

	escreva("Quantos gramas por dia o gato 01 come? ")
	leia(gt1)

	escreva("Quantos gramas por dia o gato 02 come? ")
	leia(gt2)

	pordia <- gt1 + gt2

	em5dia <- kgsra - (pordia * 5)

	escreva("No quinto dia termos somente ",em5dia," gramas de racao")

Fimalgoritmo
