Algoritmo "aula05ex07"
// Disciplina  :  [Algoritmos e Programação I]
// Professor   : Adriana Bueno
// Descrição   : Faça um algoritmo para ler: número da conta do cliente, saldo, débito e crédito. Após, calcular e escrever o saldo atual (saldo atual = saldo - débito + crédito). Também testar se saldo atual for maior ou igual a zero escrever a mensagem 'Saldo Positivo', senão escrever a mensagem 'Saldo Negativo'. 
// Autor(a)    : Bruno C. Angst
// Data atual  : 23/09/2018
Var
   // Seção de Declarações das variáveis

   con: inteiro
   sal, deb, cre, sala: inteiro

Inicio
   // Seção de Comandos, procedimento, funções, operadores, etc...

   Escreva ("Numero da sua conta: ")
   Leia(con)
   Escreva ("Qual eh o seu saldo? ")
   Leia(sal)
   Escreva ("Qual eh o valor de dehbitos para esse mehs? ")
   Leia(deb)
   Escreva ("Qual eh o seu credito? ")
   Leia(cre)

   sala <- sal - deb + cre

   Se (sala < 0) entao
      Escreva("Seu saldo atual e de R$",sala," -SALDO NEGATIVO-")
   Senao
      Escreva ("Seu saldo atual e de R$",sala," -SALDO POSITIVO-")
   Fimse


Fimalgoritmo