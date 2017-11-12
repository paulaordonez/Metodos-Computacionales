import numpy as np
import matplotlib.pyplot as plt

dat= np.genfromtxt("usar.dat")
x= np.linspace(0,0.64,129)

d1=dat[0,:]
d2=dat[1,:]
d3=dat[3000,:]
d4=dat[10000,:]
d5=dat[50000,:]
print len(d1)


plt.plot(x, d1)
plt.plot(x, d2)
plt.plot(x, d3)
plt.plot(x, d4)
plt.plot(x, d5)
plt.savefig("Resultados_hm4.pdf")
