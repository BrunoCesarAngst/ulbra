import random
num = random.randint(0, 5)
escolha = int(input('Escolha um numero de 0 a 5: '))
if escolha == num:
    print('Parabéns você acertou! ')
else:
    print('Tente novamente! ')
