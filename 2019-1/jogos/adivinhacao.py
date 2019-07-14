#!/bin/bash python3

import random

def jogar():
    print('******************')
    print('Bem vindo ao jogo!')
    print('******************')

    numero_secreto = random.randrange(1, 101)
    total_de_tentativas = 0
    pontos = 1000
#rodada = 1

    print('Qual é o nível de dificuldade desejas?')
    print('(1) Fácil (2) Médio (3) Difícil')

    nivel = int(input('Defina o nível: '))

    if(nivel == 1):
        total_de_tentativas = 20
    elif(nivel == 2):
        total_de_tentativas = 10
    else:
        total_de_tentativas = 5

# while(rodada <= total_de_tentativas):
    for rodada in range(1, total_de_tentativas + 1):
        print('tentativa: {} de {}' .format(rodada, total_de_tentativas))
        chute_str = input('Digite um número entre 1 e 100: ')
        print('Você digitou ', chute_str)
        chute = int(chute_str)

        if(chute < 1 or chute > 100):
            print('O número deve ser entre 1 e 100!!')
            continue

        acertou = numero_secreto == chute
        maior = chute > numero_secreto
        menor = chute < numero_secreto

        if(acertou):
            print('Você acertou e fez {} pontos!' .format(pontos))
            break
        else:
            if(maior):
                print('Você errou, o chute foi alto!')
            elif(menor):
                print('Você errou, o chute foi baixo!')
            pontos_perdidos = abs(numero_secreto - chute)
            pontos = pontos - pontos_perdidos

        rodada = rodada + 1

    print('Fim do jogo!!')

if(__name__ == "__main__"):
    jogar()
