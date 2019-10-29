#!/usr/bin/env python

n1 = float(input('Qual é o seu salário? R$'))
acrec = n1 + (n1 * 15 / 100)
ns = n1 + acrec
print('Com 15 porcento de acrécimo fica por R${:.2f}'.format(ns))
