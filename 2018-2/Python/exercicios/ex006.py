n1 = int(input('Digite um número: '))
m = n1 * 2
m3 = n1 * 3
#r = n1 ** (1/2)
r = pow(n1, (1/2))
print('O dobro é {}, seu triplo é {} e a rais quadrada desse número e igual a {:.3f}.'.format(m, m3, r))
