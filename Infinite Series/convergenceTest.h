#include <stdio.h>
#include <math.h>
#define SIZE 100000000000
#define CON(X) (1/(1-X))

double integralTest(double n)
{
    double p = 0;
    printf("When p = %lf, test = %lf\t integralTest = %d\n", p, (1/(pow(n,p))), 1);
    p = 1;
    printf("When p = %lf, test = %lf\t integralTest = %lf\n", p, (1/(pow(n,p))), log(n/(n-1)));
    p = 0.5;
    printf("When p = %lf, test = %lf\t integralTest = %lf\n", p, (1/(pow(n,p))), p * pow(n,p) - p * pow(n-1,p));
}
void easy(size_t *i, double *a, double *b, double *ta, double *tb){
    *ta += pow(*a,*i);
    *tb += pow(*b,*i);
    printf("At %lu\t A's convergence is %lf\t B's convergence is %lf\n",*i,*ta,*tb);
}
double convergeSpeedTest(double a,double b)
{
    printf("A's convergence is: %lf\nB's convergence is: %lf\n",CON(a),CON(b));
    double sumA = 0, sumB = 0;
    for(size_t i = 0; i < SIZE; i++){
        switch(i){
            case 10:
                easy(&i,&a,&b,&sumA,&sumB);
                break;
            case 100:
                easy(&i,&a,&b,&sumA,&sumB);
                break;
            case 1000:
                easy(&i,&a,&b,&sumA,&sumB);
                break;
            default: 
                sumA += pow(a,i);
                sumB += pow(b,i);
                break;
        }
    }
}
