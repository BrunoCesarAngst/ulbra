Algoritmo "aula05ex13"
// Disciplina  :  [Algoritmos e Programação I]
// Professor   : Adriana Bueno
// Descrição   : Construa um algoritmo que leia um número inteiro de 1 a 7 e informe o dia da semana correspondente, sendo domingo o dia de número 1. Se o número não corresponder a um dia da semana, mostre uma mensagem de erro.
// Autor(a)    : Bruno C. Angst
// Data atual  : 23/09/2018
Var
   // Seção de Declarações das variáveis

   op: inteiro

Inicio
   // Seção de Comandos, procedimento, funções, operadores, etc...

   Escreva ("Digite um nuhmero de 1 ah 7: ")
   Leia(op)

   Se(op > 7)entao
      Escreva("!!ERRO!!")
   Fimse

   Escolha op
      caso 1
         Escreva("Esse nuhmero corresponde a Domingo")
      caso 2
         Escreva("Esse nuhmero corresponde a Segunda")
      caso 3
         Escreva("Esse nuhmero corresponde a Terca")
      caso 4
         Escreva("Esse nuhmero corresponde a Quarta")
      caso 5
         Escreva("Esse nuhmero corresponde a Quinta")
      caso 6
         Escreva("Esse nuhmero corresponde a Sexta")
      caso 7
         Escreva("Esse nuhmero corresponde a Sabado")
   FimEscolha

Fimalgoritmo