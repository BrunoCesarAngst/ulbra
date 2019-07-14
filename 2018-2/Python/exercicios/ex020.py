import random
a1 = str(input('Primero aluno nome: '))
a2 = str(input('Segundo aluno nome: '))
a3 = str(input('Terceiro aluno nome: '))
a4 = str(input('Quarto aluno nome: '))
lista = [a1, a2, a3, a4]
random.shuffle(lista)
print('Será nessa ordem:')
print(lista)
