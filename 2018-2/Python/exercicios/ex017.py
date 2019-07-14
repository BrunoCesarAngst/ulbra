import math
co = float(input('Me informe o valor do Cateto Oposto: '))
ca = float(input('Me informe o valor do cateto Adjacente: '))
print('A partidos valores do CO {} e do CA {} temos o valor da hipotenusa {:.3f}'.format(co, ca,
              math.hypot(co, ca)))
