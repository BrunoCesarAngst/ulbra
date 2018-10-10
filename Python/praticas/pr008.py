#import math
#num = int(input('Digite um número: '))
#raiz = math.sqrt(num)
#print('A raiz de um {} é igual a {}'.format(num,raiz)) - normal
#print('A raiz de um {} é igual a {}'.format(num, math.ceil(raiz))) - arredondado para cima
#print('A raiz de um {} é igual a {}'.format(num, math.floor(raiz)))

from math import sqrt, floor, ceil

num = int(input("Digite um número: "))
raiz = sqrt(num)
print('A raiz de um {} é igual a {}'.format(num, raiz))
print('A raiz de um {} é igual a {}'.format(num, ceil(raiz)))
print('A raiz de um {} é igual a {}'.format(num, floor(raiz)))
