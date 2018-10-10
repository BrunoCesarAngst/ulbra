Algoritmo "sp ex 4"
// Disciplina  :  [Agoritmos e Programação]
// Professora   : Adriana Bueno da Silva
// Data atual  : 05/09/2018

Var
   nFim,nota1,nota2,nota3,exercicios:real
   matricula: caracter

Inicio
   EscrevaL("Entre com a Matricula:")
   Leia(matricula)

   EscrevaL("Entre com a nota 1:")
   Leia(nota1)

   EscrevaL("Entre com a nota 2:")
   Leia(nota2)

   EscrevaL("Entre com a nota 3:")
   Leia(nota3)

   EscrevaL("Entre com a Media dos Exercicios")
   Leia(exercicios)

   nFim<- (nota1+2*nota2+3*nota3+exercicios) / 7

   EscrevaL("Matricula : ",matricula)
   EscrevaL("Sua nota final eh: ",nFim:4:2)


   se(nFim>=9)entao
      EscrevaL("Conceito A, voce foi aprovado!")
   fimse

   se((nFim>=7.5) e (nFim<9))entao
   EscrevaL("Conceito B, voce foi aprovado!")
   fimse

   se((nFim>=6) e (nFim<7.5))entao
   EscrevaL("Conceito C, voce foi aprovado!")
   fimse

   se(nFim>=4) e (nFim<6)entao
   EscrevaL("Conceito D, tera prova de substituicao!")
   fimse

   se(nFim<4)entao
   EscrevaL("Conceito E, voce foi reprovado!")
   fimse      
Fimalgoritmo

