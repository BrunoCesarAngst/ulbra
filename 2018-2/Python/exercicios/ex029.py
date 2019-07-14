n = str(input('Qual é o seu nome? '))
v = float(input('Em qual velocidade você estava? '))
k = 80
if v > k:
    print('{}, você acaba de ser multado!'.format(n))
    dv = v - k
    vm = dv * 7
    print('A multa é de R$ 7,00/Km, acima dos 80K/h, por tanto, pagaras um valor de R${:.2f}'.format(vm))
else:
    print('Muito bem {}, você é um motorista que dirige pela vida!'.format(n))

