Algoritmo "aula05ex03"
// Disciplina  :  [Algoritmos e Programação I] 
// Professor   : Adriana Bueno 
// Descrição   : Faça um algoritmo para ler um número e se ele for maior do que 30, então exibir metade do número, caso contrário, imprimir o dobro do número. 
// Autor(a)    : Bruno C. Angst
// Data atual  : 19/09/2018
Var
// Seção de Declarações das variáveis
 
nu: real
me, do: real

Inicio
// Seção de Comandos, procedimento, funções, operadores, etc... 

	Escreva ("Digite um numero: ")
	Leia(nu)

	me <- nu / 2
	do <- nu * 2
	
	Se (nu > 29) entao
		Escreva ("A metatade do numero",nu," eh:",me)
	Senao
		Se (nu <= 29) entao
			Escreva ("O dobro do numero",nu," eh:",do)
		Fimse
	Fimse

Fimalgoritmo