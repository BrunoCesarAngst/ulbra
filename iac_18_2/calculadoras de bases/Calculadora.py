# calculadora conversora de base

# variável a recebe o número
a = int(input('Digite um número: '))

print('~' * 40,)
# conversão sem tratamento
print('O binário do número {} é {}.'.format(a, bin(a)))
# conversão com tratamento de "fatiamento"
# print('O binário do número {} é {}.\n'.format(a, bin(a)[2:]))
print('~' * 40,)
print('O octagonal do número {} é {}.'.format(a, oct(a)))
# print('O octagonal do número {} é {}.\n'.format(a, oct(a)[2:]))
print('~' * 40,)
print('O hexagonal do número {} é {}.'.format(a, hex(a)))
# print('O hexagonal do número {} é {}.'.format(a, hex(a)[2:]))
