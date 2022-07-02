#Importing numpy, scipy, mpmath and pyplot
import numpy as np
import matplotlib.pyplot as plt
import scipy
import math

x = np.linspace(0,10,100)#points on the x axis
simlen = int(1e6) #number of samples
err = [] #declaring probability list
randvar1 = np.random.normal(0,1,simlen)
randvar2= np.random.normal (0,1,simlen)
sr=[]

for g in range(simlen):
  sr.append(math.sqrt(randvar1[g]**2 +randvar2[g]**2))

for i in range(0,100):
	err_ind = np.nonzero(sr < x[i]) #checking probability condition
	err_n = np.size(err_ind) #computing the probability
	err.append(err_n/simlen) #storing the probability values in a list

def chi_cdf(x):
  return 1-math.exp(-(x**2)/2)

vec_chi=scipy.vectorize(chi_cdf)	
plt.plot(x,vec_chi(x))
plt.plot(x.T, err,'o')#plotting the CDF
plt.grid() #creating the grid
plt.xlabel('$x$')
plt.ylabel('$F_A(x)$')
plt.legend(["Theory","Numerical"])

plt.savefig('6.3_cdf.png')
# plt.show() #opening the plot window