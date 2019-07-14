#!/bin/bash python3

import forca
import adivinhacao 

def escolher_jogo():
    print('******************')
    print('Escolha o seu jogo!')
    print('******************')

    print('(1) Forca (2) Adivinhação')

    jogo = int(input('Qual é o jogo? '))

    if(jogo == 1):
        print('jogando Forca')
        forca.jogar()
    elif(jogo == 2):
        print('jogando Adivinhação')
        adivinhacao.jogar()

    print('Fim do jogo!!')


if(__name__ == "__main__"):
    jogar()
