#!/bin/bash python3

import random

def jogar():

    imprime_mensagem_abertura()

    arquivo = open('palavras.txt', 'r')
    palavras = []

    for linha in arquivo:
        linha  = linha.strip()
        palavras.append(linha)

    arquivo.close()

    numero = random.randrange(0, len(palavras))
    palavra_secreta = palavras[numero].upper()

    palavra_secreta = 'kiwi'.upper()
    #letra_acertadas = ['_','_','_','_','_','_']

    #for letra in palavra_secreta:
       # letra_acertadas.append('_')
    letra_acertadas = ['_' for letra in palavra_secreta]

    enforcou = False
    acertou = False
    erros = 0

    print(letra_acertadas)

    while(not enforcou and not acertou):

        chute = input('Qual é a letra? ')
        chute = chute.strip().upper()

        if(chute in palavra_secreta):
            index = 0
            for letra in palavra_secreta:
                if(chute == letra):
                    letra_acertadas[index] = letra
                index = index +1
        else:
            erros = erros + 1

        enforcou = erros == 6
        acertou = '_' not in letra_acertadas

        print(letra_acertadas)

    if(acertou):
        print('Você Ganhou!!')
    else:
        print('Você Perdeu!!')

    print('Fim do jogo!!')

if(__name__ == "__main__"):
    jogar()


def imprime_mensagem_abertura():
    print('******************')
    print('Bem vindo ao jogo!')
    print('******************')
