Algoritmo "ex18"

Var

   vq, tp, vd: real
   qws: inteiro

Inicio

   escreva("Quanto custa o quilowatt? ")
   leia(vq)

   escreva("Quantos quilowatts foram consumodos? ")
   leia(qws)

   tp <- qws * vq
   vd <- tp - (tp * 15/100)

   escreva("Atraves do comsumo de ",qws,"kws, com um custo de R$",vq," Chegamos a um total de R$ ",tp," mas como o senhor é um bom consumidor tera 15 % de desconto pagando somente: R$ ", vd)

Fimalgoritmo
