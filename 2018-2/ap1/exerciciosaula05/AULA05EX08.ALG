Algoritmo "aula05ex07"
// Disciplina  :  [Algoritmos e Programação I]
// Professor   : Adriana Bueno
// Descrição   : Fazer um algoritmo que leia o percurso em quilômetros, o tipo do carro e informe o consumo estimado de combustível, sabendo-se que um carro tipo C faz 12 Km com um litro de gasolina, um tipo B faz 9 Km e o tipo A, 8 Km por litro.
// Autor(a)    : Bruno C. Angst
// Data atual  : 19/09/2018
Var
   // Seção de Declarações das variáveis

   carro: caractere
   km, a, b, c: real

Inicio
   // Seção de Comandos, procedimento, funções, operadores, etc...

   Escreva ("Quantos quilometros iremos rodar? ")
   Leia(km)
   Escreva ("Com que tipo de carro iremos(A, B ou C)? ")
   Leia(carro)

   a <- km / 8
   b <- km / 9
   c <- km / 12

   Escolha carro
      caso "A"
      Escreva ("vamos precisar de ",a," litros.")
      caso "B"
      Escreva ("vamos precisar de ",b," litros.")
      caso "C"
      Escreva ("vamos precisar de ",c," litros.")
   Fimescolha

Fimalgoritmo