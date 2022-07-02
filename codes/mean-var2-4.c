#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "coeffs.h"

int main(){

//Mean of uniform
printf("The mean of X is %lf\n",mean("gau.dat"));

//variance of uniform
printf("The varience of X is %lf\n",variance("gau.dat"));

    return 0;
}

/* OUTPUT:
The mean of X is 0.000326
The varience of X is 1.000907
*/