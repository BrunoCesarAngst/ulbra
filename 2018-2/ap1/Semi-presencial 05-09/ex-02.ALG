Algoritmo "sp ex 2"
// Disciplina  :  [Agoritmos e Programação]
// Professora   : Adriana Bueno da Silva

// Data atual  : 05/09/2018

Var

   nome: caracter
   sal, tov, cmu, cmd, cmt: real

Inicio

   Escreva("Qual eh o seu nome? ")
   Leia(nome)
   EscrevaL(nome,", eh muito bom te ter como funcionario dessa loja!")
   Escreva("Escreva seu salario fixo: ")
   Leia(sal)
   Escreva("Qual eh o valor total de sua vendas deese mes? ")
   Leia(tov)

   cmu <- sal + (tov * 25/100)
   cmd <- sal + (tov * 18/100)
   cmt <- sal + (tov * 7/100)

   Se(tov < 4999.99) entao
      EscrevaL(nome, ", com sua venda de " ,tov, "R$, voce ganhara uma comissão de 7% mais" ,sal, "R$; voce recebera no total " ,cmt, "R$.")
   Senao
      Se(tov >= 5000.00) e (tov <= 14999.99) entao
         Escreva(nome, ", com sua venda de " ,tov, "R$, voce ganhara uma comissão de 18% mais" ,sal, "R$; voce recebera no total " ,cmd, "R$.")
      Senao
         Se(tov >= 15000.00) entao
            Escreva(nome, ", com sua venda de " ,tov, "R$, voce ganhara uma comissão de 25% mais" ,sal, "R$; voce recebera no total " ,cmu, "R$.")
         FimSe
      FimSe
   FimSe

Fimalgoritmo