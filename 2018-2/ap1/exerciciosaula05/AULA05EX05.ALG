Algoritmo "aula05ex05"
// Disciplina  :  [Algoritmos e Programação I] 
// Professor   : Adriana Bueno 
// Descrição   : Construa um algoritmo que leia dois números e efetue a adição. Caso o valor somado seja maior que 20, este deverá ser apresentado somando e a ele mais 8; caso o valor somado seja menor ou igual a 20, este deverá ser apresentado subtraindo-se 5
.
// Autor(a)    : Bruno C. Angst
// Data atual  : 19/09/2018
Var
// Seção de Declarações das variáveis
 
n1, n2: real
re, cs1, cs2: real

Inicio
// Seção de Comandos, procedimento, funções, operadores, etc... 

	Escreva ("Digite um numero: ")
	Leia(n1)
	Escreva ("Digite um segundo numero: ")
	Leia(n2)

	re <- n1 + n2
	cs1 <- re + 8
	cs2 <- re - 5
	
	Se (re > 20) entao
		Escreva ("A soma dos numeros informados eh",cs1,".")
	Senao
		Escreva ("A soma dos numeros informados eh",cs2,".")		
	Fimse

Fimalgoritmo