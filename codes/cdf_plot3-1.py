#Importing numpy, scipy, mpmath and pyplot
import numpy as np
import matplotlib.pyplot as plt
import scipy

x = np.linspace(-10,10,50)#points on the x axis
x1 = np.linspace(-10,10,250)
simlen = int(1e6) #number of samples
err = [] #declaring probability list
randvar = np.loadtxt('log.dat',dtype='double')

for i in range(0,50):
	err_ind = np.nonzero(randvar < x[i]) #checking probability condition
	err_n = np.size(err_ind) #computing the probability
	err.append(err_n/simlen) #storing the probability values in a list

def Cdf(x):
	if x< 0:
		x=0 
	return  1 - np.exp(-x/2)

vec_cdf_v = scipy.vectorize(Cdf)

plt.plot(x[0:50].T,err,'o')#plotting the CDF
plt.plot(x1,vec_cdf_v(x1))
plt.grid() #creating the grid
plt.xlabel('$v$')
plt.ylabel('$F_V(v)$')
plt.legend(["Numerical", "Theory"])

plt.savefig('V_cdf.png')
# plt.show() #opening the plot window