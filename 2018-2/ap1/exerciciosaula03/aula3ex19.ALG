Algoritmo "ex19"

Var

   cod1, cod2: inteiro
   quan1, quan2, vl1, vl2, vtc1, vtc2, vt: real

Inicio

   escreva("Qual eh o codigo da primeira peca? ")
   leia(cod1)
   //escreva("Qual é o codigo da segunda peca? ")
   leia(cod2)

   escreva("Sao quantas pecas do produto",cod1,"? ")
   leia(quan1)
   escreva("Sao quantas pecas do produto",cod2,"? ")
   leia(quan2)

   escreva("Qual eh o valor do produto",cod1,"? ")
   leia(vl1)
   escreva("Qual eh o valor do produto",cod2,"? ")
   leia(vl2)

   vtc1 <- quan1 * vl1
   vtc2 <- quan2 * vl2
   vt <- vtc1 + vtc2

   escrevaL("Voce comprou",quan1," unidades do produtos codigo",cod1," no valor de R$",vl1," e",quan2," unidades do produtos codigo",cod2," no valor de R$",vl2,".")

   escrevaL("Dando um total de R$",vt,".")

Fimalgoritmo
