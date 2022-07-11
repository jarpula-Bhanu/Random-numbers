
import numpy as np
import mpmath as mp
from matplotlib import pyplot as plt
import scipy

ber = np.loadtxt('ber.dat', dtype='double')
gauss = np.loadtxt('Y.dat', dtype='double')

def error(a):
    Y = a*ber + gauss
    n0 = np.count_nonzero(ber> 0)
    n1 = np.count_nonzero(ber < 0)
    e0 = np.count_nonzero((Y < 0) & (ber > 0)) 
    e1 = np.count_nonzero((Y > 0) & (ber < 0))
    return 0.5*(e0/n0 + e1/n1)

err_vec = scipy.vectorize(error, otypes=['double'])

def qfunc(x):
    return (0.5)*mp.erfc(x/np.sqrt(2))

qfunc_vec = scipy.vectorize(qfunc, otypes=['double'])

A = np.linspace(0, 10, 11)
b = err_vec(A)
plt.semilogy(A, b, 'o')
plt.semilogy(A, qfunc_vec(A))
plt.grid()
plt.xlabel('$A$ in dB')
plt.ylabel('$P_e$')
plt.legend(["Theoretical", "Numerical"])


plt.savefig('5-8_P_e.png')
# plt.show() #opening the plot window