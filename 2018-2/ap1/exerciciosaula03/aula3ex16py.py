Kgsra = float(input('Quantos quilos de ração você comprou? '))

gt1 = float(input('Quantos gramas por dia o gato 01 come? '))

gt2 = float(input('Quantos gramas por dia o gato 02 come? '))

pordia = gt1 + gt2

em5dia = Kgsra - (pordia * 5)

print('No quinto dia termos somente {} gramas de ração'.format(em5dia))
