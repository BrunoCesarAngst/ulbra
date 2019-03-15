cod1 = int(input('Qual é o código da primeira peça? '))
cod2 = int(input('Qual é o código da segunda peça? '))

quan1 = int(input('São quantas peças do produto {}? '.format(cod1)))
quan2 = int(input('São quantas peças do produto {}? '.format(cod2)))

vl1 = float(input('Qual é o valor do produto {}? '.format(cod1)))
vl2 = float(input('Qual é o valor do produto {}? '.format(cod2)))

vtc1 = quan1 * vl1
vtc2 = quan2 * vl2
vt = vtc1 + vtc2

print('Você comprou {} unidades do produtos codigo {} no valor de R$ {:.2f} e {} unidades do produtos codigo {} no valor de R$ {:.2f}\n'.format(quan1, cod1, vl1, quan2, cod2, vl2))
print('Dando um total de R$ {:.2f}.'.format(vt))
