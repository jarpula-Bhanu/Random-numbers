#Importing numpy, scipy, mpmath and pyplot
import matplotlib.pyplot as plt
import numpy as np

mean = np.array([0, 0])
cov = np.array([[1, 0], [0, 1]])  # diagonal covariance
A = 10
simlen = int(1e6)
n1, n2 = np.random.multivariate_normal(mean, cov, simlen).T
y1 = A + n1
y2 = n2
plt.plot( y1, y2, 'bx')


n1, n2 = np.random.multivariate_normal(mean, cov, simlen).T
y1 = n1
y2 = A + n2
plt.plot(y1, y2, 'rx')
plt.legend(['$\mathbf{x} = \mathbf{s}_0$','$\mathbf{x} = \mathbf{s}_1$'])
plt.xlabel("$y_1$")
plt.ylabel("$y_2$")

plt.savefig('8.1_scatter.png')
# plt.show() #opening the plot window