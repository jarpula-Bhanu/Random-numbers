//Function declaration
double **createMat(int m,int n);
void readMat(double **p, int m,int n);
void print(double **p,int m,int n);
double **loadtxt(char *str,int m,int n);
double linalg_norm(double **a, int m);
double **linalg_sub(double **a, double **b, int m, int n);
double **linalg_inv(double **mat, int m);
double **matmul(double **a, double **b, int m, int n, int p);
double **transpose(double **a,  int m, int n);
void uniform(char *str, int len);
void gaussian(char *str, int len);
double mean(char *str);
double variance(char *str);
void V(char *str,char *read);
//End function declaration


//Defining the function for matrix creation
double **createMat(int m,int n)
{
 int i;
 double **a;
 
 //Allocate memory to the pointer
a = (double **)malloc(m * sizeof( *a));
    for (i=0; i<m; i++)
         a[i] = (double *)malloc(n * sizeof( *a[i]));

 return a;
}
//End function for matrix creation


//Defining the function for reading matrix 
void readMat(double **p, int m,int n)
{
 int i,j;
 for(i=0;i<m;i++)
 {
  for(j=0;j<n;j++)
  {
   scanf("%lf",&p[i][j]);
  }
 }
}
//End function for reading matrix

//Read  matrix from file
double **loadtxt(char *str,int m,int n)
{
FILE *fp;
double **a;
int i,j;


a = createMat(m,n);
fp = fopen(str, "r");

 for(i=0;i<m;i++)
 {
  for(j=0;j<n;j++)
  {
   fscanf(fp,"%lf",&a[i][j]);
  }
 }
//End function for reading matrix from file

fclose(fp);
 return a;

}


//Defining the function for printing
void print(double **p, int m,int n)
{
 int i,j;

 for(i=0;i<m;i++)
 {
  for(j=0;j<n;j++)
  printf("%lf ",p[i][j]);
 printf("\n");
 }
}
//End function for printing

//Defining the function for norm

double linalg_norm(double **a, int m)
{
int i;
double norm=0.0;

 for(i=0;i<m;i++)
 {
norm = norm + a[i][0]*a[i][0];
}
return sqrt(norm);

}
//End function for norm

//Defining the function for difference of matrices

double **linalg_sub(double **a, double **b, int m, int n)
{
int i, j;
double **c;
c = createMat(m,n);

 for(i=0;i<m;i++)
 {
  for(j=0;j<n;j++)
  {
c[i][j]= a[i][j]-b[i][j];
  }
 }
return c;

}
//End function for difference of matrices

//Defining the function for inverse of 2x2 matrix


double **linalg_inv(double **mat, int m)
{
double **c, det;
c = createMat(m,m);

det = mat[0][0]*mat[1][1]-mat[0][1]*mat[1][0];

c[0][0] = mat[1][1]/det;
c[0][1] = -mat[1][0]/det;
c[1][0] = -mat[0][1]/det;
c[1][1] = mat[0][0]/det;

return c;

}
// End  function for inverse of 2x2 matrix


//Defining the function for difference of matrices

double **matmul(double **a, double **b, int m, int n, int p)
{
int i, j, k;
double **c, temp =0;
c = createMat(m,p);

 for(i=0;i<m;i++)
 {
  for(k=0;k<p;k++)
  {
    for(j=0;j<n;j++)
    {
	temp= temp+a[i][j]*b[j][k];
    }
	c[i][k]=temp;
	temp = 0;
  }
 }
return c;

}
//End function for difference of matrices

//Defining the function for transpose of matrix

double **transpose(double **a,  int m, int n)
{
int i, j;
double **c;
//printf("I am here");
c = createMat(n,m);

 for(i=0;i<n;i++)
 {
  for(j=0;j<m;j++)
  {
c[i][j]= a[j][i];
//  printf("%lf ",c[i][j]);
  }
 }
return c;

}
//End function for transpose of matrix

//Defining the function for generating uniform random numbers
void uniform(char *str, int len)
{
int i;
FILE *fp;

fp = fopen(str,"w");
//Generate numbers
for (i = 0; i < len; i++)
{
fprintf(fp,"%lf\n",(double)rand()/RAND_MAX);
}
fclose(fp);

}
//End function for generating uniform random numbers

//Defining the function for generating equiprobable numbers
void equiprobable(char *str, int len)
{
int i;
FILE *fp;

fp = fopen(str,"w");
//Generate numbers
for (i = 0; i < len; i++)
{
  double a=(double)rand()/RAND_MAX;
  if(a>0.5) a = 1;
  else a=-1;
fprintf(fp,"%lf\n",a);
}
fclose(fp);

}
//End function for generating equiprobable  numbers

//Defining the function for generating triangular distribution
void triangular(char *str, int len)
{
int i;
FILE *fp;

fp = fopen(str,"w");
//Generate numbers
for (i = 0; i < len; i++)
{
double a=(double)rand()/RAND_MAX;
double b=(double)rand()/RAND_MAX;
fprintf(fp,"%lf\n",a+b);
}
fclose(fp);

}
//End function for generating triangular distribution

//Defining the function for calculating the mean of random numbers
double mean(char *str)
{
int i=0,c;
FILE *fp;
double x, temp=0.0;

fp = fopen(str,"r");
//get numbers from file
while(fscanf(fp,"%lf",&x)!=EOF)
{
//Count numbers in file
i=i+1;
//Add all numbers in file
temp = temp+x;
}
fclose(fp);
temp = temp/(i-1);
return temp;

}
//End function for calculating the mean of random numbers

//Defining the function for calculating the variance of random numbers
double variance(char *str)
{
int i=0,c;
FILE *fp;
double x, temp1=0.0,temp2=0.0;

fp = fopen(str,"r");
//get numbers from file
while(fscanf(fp,"%lf",&x)!=EOF)
{
//Count numbers in file
i=i+1;
//Add square of all numbers in file
temp1 = temp1+pow(x,2);
//Add all numbers in file
temp2 = temp2+x;
}
fclose(fp);
temp1 = temp1/(i-1);
temp2 = temp2/(i-1);
return (temp1-pow(temp2,2));

}
//End function for calculating the variance of random numbers

//Defining the function for generating Gaussian random numbers
void gaussian(char *str, int len)
{
int i,j;
double temp;
FILE *fp;

fp = fopen(str,"w");
//Generate numbers
for (i = 0; i < len; i++)
{
temp = 0;
for (j = 0; j < 12; j++)
{
temp += (double)rand()/RAND_MAX;
}
temp-=6;
fprintf(fp,"%lf\n",temp);
}
fclose(fp);

}
//End function for generating Gaussian random numbers

//Defining the function to generate samples of V
void V(char *str,char *read)
{
int i;
FILE *fp1,*fp2;
double val;

fp1 = fopen(read,"r");
fp2 = fopen(str,"w");
//Generate numbers
while(fscanf(fp1,"%lf",&val)!=EOF)
{
fprintf(fp2,"%lf\n",-2*log(1-val));
}
fclose(fp1);
fclose(fp2);

}
//End function for gentating smaples of V

//Defining the function to generate samples of Y
void Y(char *str,char *read,char *gau)
{
int i;
FILE *fp1,*fp2,*fp3;
double val,N;
 
fp1 = fopen(read,"r");
fp2 = fopen(str,"w");
fp3 = fopen(gau,"r");
//Generate numbers
while(fscanf(fp1,"%lf",&val)!=EOF && fscanf(fp3,"%lf",&N)!=EOF)
{
fprintf(fp2,"%lf\n",val+N);
}
fclose(fp1);
fclose(fp2);
fclose(fp3);

}
//End function for gentating smaples of Y

//Defining the function for generating Gaussian random numbers
void gauss(char *str, int sig, int len)
{
int i,j;
double temp;
FILE *fp;

fp = fopen(str,"w");
//Generate numbers
for (i = 0; i < len; i++)
{
temp = 0;
for (j = 0; j < 12; j++)
{
temp += (double)rand()/RAND_MAX;
}
temp-=6;
fprintf(fp,"%lf\n",sig*temp);
}
fclose(fp);

}
//End function for generating Gaussian random numbers

//Defining the function for generating bernoulli random numbers
void bernoulli(char *str, int len)
{
int i;
FILE *fp;

fp = fopen(str,"w");
//Generate numbers
for (i = 0; i < len; i++)
{
fprintf(fp,"%lf\n",(double)rand()/RAND_MAX < 0.5 ? -1.0 : 1.0);
}
fclose(fp);

}
//End function for generating bernoulli random numbers

//Defining the function for generating rayleigh random numbers
void ral(char *str, int len)
{
int i,j;
double y1, y2;
FILE *fp;

fp = fopen(str,"w");
//Generate numbers
for (i = 0; i < len; i++)
{
y1 = 0, y2 = 0;
for (j = 0; j < 12; j++)
{
y1 += (double)rand()/RAND_MAX;
y2 += (double)rand()/RAND_MAX;
}
y1-=6,y2-=6;
double sig = sqrt(1/2.0);
y1*=sig,y2*=sig;
fprintf(fp,"%lf\n",sqrt(y1*y1 + y2*y2));
}
fclose(fp);

}
//End function for generating rayleigh random numbers