#Importing numpy, scipy, mpmath and pyplot
import numpy as np
import matplotlib.pyplot as plt
import scipy

x = np.linspace(0,1000,1000)#points on the x axis
x1 = np.linspace(-10,10,250)
simlen = int(1e4) #number of samples
err = [] #declaring probability list
randvar = np.loadtxt('Y.dat',dtype='double')
# x = np.loadtxt('equiprobable.dat',dtype='double')

for i in range(0,50): 
    err_ind = np.nonzero(randvar < x[i]) #checking probability condition
    err_n = np.size(err_ind) #computing the probability
    err.append(err_n/simlen) #storing the probability values in a list

ber = np.loadtxt('ber.dat', dtype='double')
gauss = np.loadtxt('Y.dat', dtype='double')
sig = 5*ber + gauss
x = np.linspace(0, 1, int(1e6))
plt.plot(x, sig, '.')
plt.xlabel('n ($\\times 10^3$)')
plt.ylabel('y')

plt.savefig('Y_scatter.png')
# plt.show() #opening the plot window