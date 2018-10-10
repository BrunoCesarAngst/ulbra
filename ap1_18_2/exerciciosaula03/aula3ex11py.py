nt1 = float(input('Informe sua nota do primero quadrimestre: '))

print('Esse quadrimestre tem peso 2. \n')

nt2 = float(input('Informe sua nota do segundo quadrimestre: '))

print('Esse quadrimestre tem peso 4. \n')

nt3 = float(input('Informe sua nota do terceiro quadrimestre: '))

print('Esse quadrimestre tem peso 6. \n')

mp = (((nt1*2) + (nt2*4) + (nt3*6))/12)

print('Sua média ponderada é {}.'.format(mp))
