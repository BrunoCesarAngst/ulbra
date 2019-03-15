Algoritmo "revg1 ex 1"
// Data atual  : 11/10/2018

Var
g1, g2, med, freq: real
fal: inteiro

Inicio
escreva("informe nota da G1: ")
leia(g1)
escreva("informe nota da G2: ")
leia(g2)
escreva("informe quantos dias de falta: ")
leia(fal)

med <- (g1 + g2 * 2)/3
freq <- (100 *(68 - fal))/68

se (freq < 75) entao
  escreva ("Reprovado por nao atingir frequencia")
senao
  se (freq >= 75) e (med < 6) e ((g1 = 0) ou (g2 = 0)) entao
    escreva ("Reprovado por media baixa")
  senao
    se (freq >= 75) e (med < 6) e ((g1 > 0) ou (g2 > 0)) entao
      escreva ("Voce esta em substituicao de grau!")
        se (g1 < g2) entao
          escreva ("Poderar substituir a G1!")
        senao
          escreva ("Poderar substituir a G2!")
          se (freq >= 75) e (med >= 6) entao
            escreva ("Voce esta aprovado!")
          fimse
        fimse
      fimse
    fimse
  fimse

Fimalgoritmo
