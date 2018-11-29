vq = float(input('Quanto custa o quilowatt? '))
qws = float(input('Quantos quilowatts foram consumodos? '))

tp = qws * vq
vd = tp - (tp * 15/100)

print("Atraves do comsumo de {:.0f} kws, com um custo de R$ {:.2f} Chegamos a um total de R$ {:.2f} mas como o senhor é um bom consumidor tera 15 % de desconto pagando somente R$ {:.2f}.\n".format(qws, vq, tp, vd))