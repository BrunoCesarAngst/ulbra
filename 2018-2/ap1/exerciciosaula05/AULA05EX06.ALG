Algoritmo "aula05ex06"
// Disciplina  :  [Algoritmos e Programação I] 
// Professor   : Adriana Bueno 
// Descrição   : Faça um algoritmo para entrar com nome, sexo e idade de uma pessoa. Se a pessoa for do sexo feminino e tiver menos que 25 anos, imprimir nome e mensagem: ACEITA. Caso contrário, imprimir nome e a mensagem: NÃO ACEITA.
// Autor(a)    : Bruno C. Angst
// Data atual  : 19/09/2018
Var
// Seção de Declarações das variáveis
 
no:caracter
sx, id: inteiro

Inicio
// Seção de Comandos, procedimento, funções, operadores, etc... 

	Escreva ("Qual eh o seu nome? ")
	Leia(no)
	Escreva ("Seu sexo; (1 para masculino, 2 para feminino): ")
	Leia(sx)
	Escreva ("Qual eh sua idade? ")
	Leia(id)

	Se (sx = 2) e (id <= 24) entao
		Escreva (no,", voceh foi aceita.")
	Senao
		Escreva (no,", voceh nao foi aceita.")		
	Fimse

Fimalgoritmo