no = input('Olá, qual é o seu nome? ')

sal = float(input('{}, me informe seu salário: '.format(no)))

print('{}, seu salário de {} terá um reajuste de 25%.'.format(no, sal))

ns = sal + (sal * 25 / 100) 

print('Seu salário passa a se