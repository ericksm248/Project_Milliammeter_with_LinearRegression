import numpy as np
import matplotlib.pyplot as plt

x = np.array([1,2,3,4,5,6,9,17,26,63,100,174,247,321,396,428,582])
y = np.array([3.3,4.1,5.3,6.5,7.5,8.5,13,21.7,33,77,120,208,295,382,471.5,508,690])

prom_x = x.mean()
prom_y = y.mean()
n = len(x)
a=(n*(sum(x*y))-sum(x)*sum(y))/(n*(sum(x**2))-(sum(x)**2))
b = prom_y -a*prom_x

print(f"y = {a:.8f}x + {b:.8f}")

idx_orden = np.argsort(x)
plt.plot(sorted(x),y[idx_orden],"o")
y = a*(np.linspace(1,600)) + b
plt.plot(np.linspace(1,600),y)
plt.title("Trend Line")
plt.ylabel("Milliamps Standar Instrument")
plt.xlabel("ADC read from PIC")
plt.legend(["Dispersed points",f"straight line found : y = {a:.4f}x + {b:.4f}"])
plt.show()
