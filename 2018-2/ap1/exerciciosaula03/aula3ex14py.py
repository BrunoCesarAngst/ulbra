no = input('Olá, qual é o seu nome? ')

sal = float(input('{}, me informe seu salário: '.format(no)))

print('{}, seu salário de {} tem uma gratificação de 5%, e tem uma desconto de impostos de 7%.'.format(no, sal))

ns = (sal + (sal * 5 / 100)) - (sal * 7 / 100)

print('Seu salário final é de R${:.2f}.'.format(ns))
