Algoritmo "aula05ex07"
// Disciplina  :  [Algoritmos e Programação I]
// Professor   : Adriana Bueno
// Descrição   : Faça um algoritmo que verifique a validade de uma senha fornecida pelo usuário. A senha válida é o número 1234.   OBS:   Se a senha informada pelo usuário for inválida, a mensagem "ACESSO NEGADO" deve ser exibida. Se for a correta, a mensagem "ACESSO PERMITIDO"  deverá ser exibida.
// Autor(a)    : Bruno C. Angst
// Data atual  : 19/09/2018
Var
   // Seção de Declarações das variáveis

   senha: inteiro

Inicio
   // Seção de Comandos, procedimento, funções, operadores, etc...

   Escreva ("Qual eh a senha???? ")
   Leia(senha)

   se senha = "1234" entao
      Escreva ("ACESSO PERMITIDO")
   Senao
      Escreva ("ACESSO NEGADO")
   Fimse


Fimalgoritmo