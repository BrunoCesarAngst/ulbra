Algoritmo "aula05ex07"
// Disciplina  :  [Algoritmos e Programação I]
// Professor   : Adriana Bueno
// Descrição   : As maçãs custam R$ 1,30 cada se forem compradas menos de uma dúzia, e R$ 1,00 se forem compradas pelo menos 12. Escreva um algoritmo que leia o número de maçãs compradas, calcule e escreva o custo total da compra.
// Autor(a)    : Bruno C. Angst
// Data atual  : 19/09/2018
Var
   // Seção de Declarações das variáveis

   mc: inteiro
   a, b: real

Inicio
   // Seção de Comandos, procedimento, funções, operadores, etc...

   Escreva ("Quantas macas voceh estah comprando???? ")
   Leia(mc)

   a <- mc * 1.3
   b <- mc * 1

   Se (mc < 12) entao
      Escreva ("A compra custa R$: ",a)
   Senao
      Escreva ("A compra custa R$: ",b)
   Fimse


Fimalgoritmo