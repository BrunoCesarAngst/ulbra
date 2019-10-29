Algoritmo "aula05ex01"
// Disciplina  :  [Algoritmos e Programação I] 
// Professor   : Adriana Bueno 
// Descrição   : Faça um algoritmo para ler um número e informar se ele está na faixa de números entre 100(inclusive) e 1000(inclusive).
// Autor(a)    : Bruno C. Angst
// Data atual  : 19/09/2018
Var
// Seção de Declarações das variáveis
 
nq: real

Inicio
// Seção de Comandos, procedimento, funções, operadores, etc... 

	Escreva ("Digite um numero qualquer: ")
	Leia(nq)
	se (nq <= 999) entao
		Escreva ("Este numero esta na faixa das centas!")
	senao
		se (nq > 999) e (nq < 9999) entao
			Escreva("Este numero esta na faixa dos milhares!")
		senao
			Escreva ("Este numero faz parte de faixas superiores!")
		Fimse
	Fimse

Fimalgoritmo