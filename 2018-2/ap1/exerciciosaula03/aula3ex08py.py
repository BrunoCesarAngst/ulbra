pp = float(input('O preço do produto é de R$: '))
qp = float(input('Quantos está levando? '))
vt = pp*qp
print('{} unidades a R$ {}/cada, vai lhe custar um total de R$ {:.2f}.'.format(qp, pp, vt))
