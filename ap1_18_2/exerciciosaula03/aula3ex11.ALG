Algoritmo "ex11"

Var

	nt1, nt2, nt3, mp: real

Inicio

	escreva("Informe sua nota do primero quadrimestre: ")
	leia(nt1)

	escreval("Esse quadrimestre tem peso 2.")

	escreva("Informe sua nota do segundo quadrimestre: ")
	leia(nt2)

	escreval("Esse quadrimestre tem peso 4.")

	escreva("Informe sua nota do terceiro quadrimestre: ")
	leia(nt3)

	escreval("Esse quadrimestre tem peso 6.")

	mp <- (((nt1*2) + (nt2*4) + (nt3*6))/12)

	escreva("Sua media ponderada he ", mp)

Fimalgoritmo