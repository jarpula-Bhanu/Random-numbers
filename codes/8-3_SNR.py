#Importing numpy, scipy, mpmath and pyplot
import numpy as np
import mpmath as mp
import matplotlib.pyplot as plt

def Q(x):
    return mp.erfc(x/mp.sqrt(2))/2

snr_size = 10
snr_dB = np.linspace(0, 9, 10)
simlen = int(1e5)

err = []
ber = []

n1 = np.random.normal(0, 1, simlen)
n2 = np.random.normal(0, 1, simlen)

for i in range(0, snr_size):
    snr = 10**(0.1*snr_dB[i])
    y1 = mp.sqrt(2*snr) + n1
    y2 = n2

    err_n = np.size(np.nonzero(y1 < y2))
    err.append(err_n/simlen)
    ber.append(Q(mp.sqrt(snr)))

plt.semilogy(snr_dB.T, ber, label = 'Analysis')
plt.semilogy(snr_dB.T, err, 'o',  label = 'Simulated')
plt.xlabel('SNR $\\left(\\frac{A}{\\sqrt{2}}\\right)$')
plt.ylabel('$P_e$')
plt.legend()
plt.grid()

plt.savefig('8.3_snr.png')
# plt.show() #opening the plot window