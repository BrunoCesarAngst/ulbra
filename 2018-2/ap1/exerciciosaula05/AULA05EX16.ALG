Algoritmo "aula05ex13"
// Disciplina  :  [Algoritmos e Programação I]
// Professor   : Adriana Bueno
// Descrição   : Crie um algoritmo que solicita ao usuário para digitar um número e mostra-o por extenso. Este número deve variar entre 1 e 10. Se o usuário introduzir um número que não está neste intervalo, mostre: "Número inválido".
// Autor(a)    : Bruno C. Angst
// Data atual  : 23/09/2018
Var
   // Seção de Declarações das variáveis

   op: inteiro

Inicio
   // Seção de Comandos, procedimento, funções, operadores, etc...

   Escreva ("Digite um nuhmero de 1 ah 10: ")
   Leia(op)

   Se(op > 10)entao
      Escreva("!!INVAHLIDO!!")
   Fimse

   Escolha op
      caso 1
         Escreva("Esse nuhmero por extenso eh HUM")
      caso 2
         Escreva("Esse nuhmero por extenso eh DOIS")
      caso 3
         Escreva("Esse nuhmero por extenso eh TRES")
      caso 4
         Escreva("Esse nuhmero por extenso eh QUATRO")
      caso 5
         Escreva("Esse nuhmero por extenso eh CINCO")
      caso 6
         Escreva("Esse nuhmero por extenso eh SEIS")
      caso 7
         Escreva("Esse nuhmero por extenso eh SETE")
      caso 8
         Escreva("Esse nuhmero por extenso eh OITO")
      caso 9
         Escreva("Esse nuhmero por extenso eh NOVE")
      caso 10
         Escreva("Esse nuhmero por extenso eh DEZ")
   FimEscolha

Fimalgoritmo