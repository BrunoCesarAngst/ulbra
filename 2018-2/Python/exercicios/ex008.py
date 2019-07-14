#n1 = int(input('Quantos metros são? '))
n1 = float(input('Quantos metros? '))
km = n1 / 1000
hm = n1 / 100
dam = n1 / 10
m = n1
dm = n1 * 10
cm = n1 * 100
mm = n1 * 1000
print('Portanto,\n {}km \n {}hm \n {}dam \n {}m \n {}dm \n {}cm \n {}mm'.format(km, hm, dam, m, dm, cm, mm))
