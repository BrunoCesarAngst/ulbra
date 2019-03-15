Algoritmo "sp ex 1"
// Disciplina  :  [Agoritmos e Programação] 
// Professora   : Adriana Bueno da Silva 

// Data atual  : 05/09/2018

Var

	nome: caracter
    idade: inteiro
    
Inicio

	Escreva("Qual eh o seu nome? ")
	Leia(nome)
	Escreva("Quantos anos voce tem? ")
	Leia(idade)

	Se(idade >= 5) e (idade <= 10) entao
		EscrevaL(nome, ", voce eh da categoria Infantil.")

	Senao
         se(idade >= 11) e (idade <= 17) entao
                  EscrevaL(nome, ", voce eh da categoria Juvenil.")
         Senao
              se(idade >= 18) entao
                       EscrevaL(nome, ", voce eh da categoria Adulto.")
              FimSe
         FimSe
	FimSe

Fimalgoritmo