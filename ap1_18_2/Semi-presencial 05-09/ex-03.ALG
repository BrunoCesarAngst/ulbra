Algoritmo "sp ex 3"
// Disciplina  :  [Agoritmos e Programação]
// Professora   : Adriana Bueno da Silva

// Data atual  : 05/09/2018

Var

   numa, numb: inteiro
   cal: inteiro

Inicio

   Escreva("Digite um numero: ")
   Leia(numa)
   Escreva("Digite outro numero: ")
   Leia(numb)
   
   se (numa > numb) entao
      cal <- numa div numb
   senao
      cal <- numb div numa
   fimse

   Se(cal % 2 = 0) entao
      Escreva("O resultado da divisao",numa, " por" ,numb, " eh" ,cal," 'PAR'")
   Senao
      Escreva("O resultado da divisao",numa, " por" ,numb, " eh" ,cal," 'IMPAR'")
   FimSe

Fimalgoritmo