a = input('digite algo: ')
print('O tipo primitivo desse valor é:', type(a))
print('Só tem espaços? ', a.isspace())
print('A informação é letra - {}'.format(a.isalpha()))
print('A informação é número - {}'.format(a.isnumeric()))
print('A informação é alfanumérica - {}'.format(a.isalnum()))
print('Está em maiúsculas? ', a. isupper())
print('Está em minúsculas? ', a.islower())
print('Esta capitalizada? ', a.istitle())
print('A informação é decimal- {}'.format(a.isdecimal()))
print('A informação é dígito- {}'.format(a.isdigit()))
