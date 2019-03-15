zAlgoritmo "aula05ex02"
// Disciplina  :  [Algoritmos e Programação I] 
// Professor   : Adriana Bueno 
// Descrição   : Faça um algoritmo para reajustar o salário de acordo com a função. Se for técnico, aumentar o salário 50%, se for gerente, aumentar 30% e se for outro cargo, aumentar 20%
// Autor(a)    : Bruno C. Angst
// Data atual  : 19/09/2018
Var
// Seção de Declarações das variáveis
 
no: caracter
op: inteiro
result: real

Inicio
// Seção de Comandos, procedimento, funções, operadores, etc... 

	Escreva ("Qual eh o seu nome? ")
	Leia(no)
	EscrevaL ("O salario minimo eh de R$ 1.196,47.")

	Escreva ("Voce foi promovido a 1 - Tecnico 2 - Gerente 3 - Outros: ")
	Leia(op)
	Escolha op
		Caso 1
			result <- 1196.47 + (1196.47 * (50/100))
		Caso 2
			result <- 1196.47 + (1196.47 * (30/100))
		Caso 3
			result <- 1196.47 + (1196.47 * (20/100))
		Outrocaso
			EscrevaL("!Escolha invalida!")
	Fimescolha
 Escreva("Sr(a) ",no,", seu salario serah de R$",result)

Fimalgoritmo