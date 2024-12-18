import numpy as np
import matplotlib.pyplot as plt

x = np.array([1,2,3,4,5,6,9,17,26,63,100,174,247,321,396,428,582])
y = np.array([3.3,4.1,5.3,6.5,7.5,8.5,13,21.7,33,77,120,208,295,382,471.5,508,690])

prom_x = x.mean()
prom_y = y.mean()
sum_numerator = 0
sum_denominator = 0
for i,j in zip(x,y):
    sum_numerator += i*(j-prom_y)
    sum_denominator += i*(i-prom_x)

m = sum_numerator/sum_denominator
b = prom_y -m*prom_x
print(f"y = {m:.8f}x + {b:.8f}")

idx_orden = np.argsort(x)
plt.plot(sorted(x),y[idx_orden],"o")
y = m*(np.linspace(1,600)) + b
plt.plot(np.linspace(1,600),y)
plt.title("Trend Line")
plt.ylabel("Milliamps Reference Instrument")
plt.xlabel("ADC read from Microcontroller")
plt.legend(["Dispersed points",f"Equation of the line found : y = {m:.4f}x + {b:.4f}"])
plt.show()
