n1 = int(input('Primeiro número: '))
n2 = int(input('Segundo numero: '))
# Ordem de precedência
# Primeiro de dentro para fora o que estiver em parenteses.
# Segundo as potências
print(n1 ** n2)
# Terceiro o que aparecer primeiro na sequencia abaixo.
print(n1 * n2)
print(n1 / n2)
print(n1 // n2)
print(n1 % n2)
# Quarto e último. (binários)
print(n1 + n2)
print(n1 - n2)
