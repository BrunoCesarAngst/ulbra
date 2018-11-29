nf = int(input('Quantos funcionários são? '))
ht = float(input('Quantas horas eles trabalharam? '))
vh = float(input('Quanto é o vlor por hora? '))
vt = nf * ht * vh
print('seus {} funcionários, vão receber R$ {:.2f}.'.format(nf, vt))
