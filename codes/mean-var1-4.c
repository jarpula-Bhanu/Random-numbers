#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "coeffs.h"

int main(){

//Mean of uniform
printf("The mean of U is %lf\n",mean("uni.dat"));

//variance of uniform
printf("The varience of U is %lf\n",variance("uni.dat"));

    return 0;
}

/* OUTPUT:
The mean of U is 0.500007
The varience of U is 0.083301
*/
