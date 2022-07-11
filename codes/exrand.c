#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "coeffs.h"

int  main(void) //main function begins
{
 
//Uniform random numbers
uniform("uni.dat", 1000000);

//Gaussian random numbers
gaussian("gau.dat", 1000000);

//Generating sample of V = -2ln(1-U)
V("log.dat","uni.dat");

//Generating triangular distribution
triangular("T.dat",1000000);

//Generating equiprobable distribution
equiprobable("equiprobable.dat",1000000);

//Generating sample of Y = AX+N
Y("Y1.dat","equiprobable.dat","gau.dat");

//Generating sample of Y = AX+N
bernoulli("ber.dat", 1000000);
gauss("Y.dat", 1, 1000000);

ral("ral.dat", 1000000);

return 0;
}