Algoritmo "sp ex 4"
// Disciplina  :  [Agoritmos e Programação]
// Professora   : Adriana Bueno da Silva

// Data atual  : 05/09/2018

Var

   op: inteiro
   tc, a: real

Inicio

   Escreva("Qual eh o total da compra? ")
   Leia(tc)
   Escreva("Ecolha uma opcao: 1 - cliente F 2 - cliente E 3 - Cliente C: ")
   Leia(op)
      Escolha(op)
         caso 1
            a <- tc - (tc * 5/100)
         caso 2
            a <- tc - (tc * 10/100)
         caso 3
            a <- tc
      Fimescolha
      Escreva("Como tal cliente só pagara" ,a, "R$")
      
Fimalgoritmo

