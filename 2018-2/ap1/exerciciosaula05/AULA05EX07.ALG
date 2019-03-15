Algoritmo "aula05ex07"
// Disciplina  :  [Algoritmos e Programação I]
// Professor   : Adriana Bueno
// Descrição   : Faça um algoritmo para ler a sigla do estado de uma pessoa e imprimir uma das mensagens: Gaúcho, Paulista, Mineiro,  Outros estados
// Autor(a)    : Bruno C. Angst
// Data atual  : 19/09/2018
Var
   // Seção de Declarações das variáveis

   est: caractere

Inicio
   // Seção de Comandos, procedimento, funções, operadores, etc...

   Escreva ("Escreva a sigla do seu estado: ")
   Leia(est)

   Se est = "rs" entao
      Escreva ("Voceh eh Gaucho.")
   Senao
      Se est = "sp" entao
         Escreva ("Voceh eh Paulista.")
      Senao
         Se est = "mg" entao
            Escreva ("Voceh eh Mineiro.")
         Senao
            Escreva ("Voceh eh de outro estado.")
         Fimse
      Fimse
  Fimse

Fimalgoritmo