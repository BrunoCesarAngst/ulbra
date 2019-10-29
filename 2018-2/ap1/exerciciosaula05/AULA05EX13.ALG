Algoritmo "aula05ex13"
// Disciplina  :  [Algoritmos e Programação I]
// Professor   : Adriana Bueno
// Descrição   : Faça um algoritmo para ler: quantidade atual em estoque, quantidade máxima em estoque e quantidade mínima em estoque de um produto. Calcular e escrever a quantidade média ((quantidade média = quantidade máxima + quantidade mínima)/2). Se a quantidade em estoque for maior ou igual a quantidade média escrever a mensagem 'Não efetuar compra', senão escrever a mensagem 'Efetuar compra'.
 
// Autor(a)    : Bruno C. Angst
// Data atual  : 23/09/2018
Var
   // Seção de Declarações das variáveis

   quan_es, quan_mah, quan_mih: inteiro
   quan_meh: real

Inicio
   // Seção de Comandos, procedimento, funções, operadores, etc...

   Escreva ("Quantidade em estoque: ")
   Leia(quan_es)
   Escreva ("Quantidade mahxima? ")
   Leia(quan_mah)
   Escreva ("Quantidade mihnima? ")
   Leia(quan_mih)

   quan_meh <- (quan_mah + quan_mih) / 2

   Se (quan_es > quan_meh) entao
      Escreva("Não fazer compras!")
   Senao
      Escreva ("Fazer compras!")
   Fimse


Fimalgoritmo