Algoritmo "aula05ex13"
// Disciplina  :  [Algoritmos e Programação I]
// Professor   : Adriana Bueno
// Descrição   : Faça um programa que receba o valor da venda, escolha a condição de pagamento no menu e mostre o total da venda final conforme condições a seguir: 1 - Venda a Vista - desconto de 10%; 2 - Venda a Prazo 30 dias - desconto de 5%; 3 - Venda a Prazo 60 dias - mesmo preço; 4 - Venda a Prazo 90 dias - acréscimo de 5%; 5 - Venda com cartão de débito - desconto de 8%; 6 - Venda com cartão de crédito - desconto de 7%.
// Autor(a)    : Bruno C. Angst
// Data atual  : 23/09/2018
Var
   // Seção de Declarações das variáveis

   vv, op1, op2, op3, op4, op5, op6 : real
   op: inteiro

Inicio
   // Seção de Comandos, procedimento, funções, operadores, etc...

   Escreva ("Qual eh o valor de venda do produto X: ")
   Leia(vv)
   EscrevaL("1 - Venda a Vista - desconto de 10%")
   EscrevaL("2 - Venda a Prazo 30 dias - desconto de 5%")
   EscrevaL("3 - Venda a Prazo 60 dias - mesmo preco")
   EscrevaL("4 - Venda a Prazo 90 dias - acrehscimo de 5%")
   EscrevaL("5 - Venda com cartaho de dehbito - desconto de 8%")
   EscrevaL("6 - Venda com cartaho de crehdito - desconto de 7%")
   Escreva("Qual a sua opcao de pagamento: ")
   Leia(op)

   op1 <- vv - (vv * 10/100)
   op2 <- vv - (vv * 5/100)
   op3 <- vv 
   op4 <- vv + (vv * 5/100)
   op5 <- vv - (vv * 8/100)
   op5 <- vv - (vv * 7/100)

   Escolha op
      caso 1
         Escreva("O pagamento de R$",vv:2:2," a vista sai por R$ ",op1:2:2)
      caso 2
         Escreva("O pagamento de R$",vv:2:2," em 30 dias sai por R$ ",op2:2:2)
      caso 3
         Escreva("O pagamento de R$",vv:2:2," em 60 dias sai por R$ ",op3:2:2)
      caso 4
         Escreva("O pagamento de R$",vv:2:2," em 90 dias sai por R$ ",op4:2:2)
      caso 5
         Escreva("O pagamento de R$",vv:2:2," no dehbito sai por R$ ",op5:2:2)
      caso 6
         Escreva("O pagamento de R$",vv:2:2," no crehdito sai por R$ ",op6:2:2)
   FimEscolha

Fimalgoritmo