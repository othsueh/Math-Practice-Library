#include "infinteSeries.h"

int main()
{
    int option = 0;
    double a = 0, x = 0;

    while(scanf(" %d", &option) != EOF){
        switch(option){
            case 1:
                printf("Multiply Series: \n");
                scanf("%lf %lf", &a,&x);
                multiply_series(a,x);
                break;
            case 2: 
                printf("Derivate Series: \n");
                scanf("%lf %lf", &a,&x);
                derivative_series(a,x);
                break; 
            case 3: 
                printf("Substract Series: \n");
                scanf("%lf %lf", &a,&x);
                substract_series(a,x);
                break; 
            case 4: 
                printf("Logarithm Series: \n");
                scanf("%lf %lf", &a,&x);
                logarithm_series(a,x);
                break; 
            case 5: 
                printf("tanInverse Series: \n");
                scanf("%lf %lf", &a,&x);
                tanInverse_series(a,x);
                break; 
            default:
                break;
        }
    }
}

double multiply_series(double a, double x){
    double sum = 0;
    for(size_t i = 0; i < SIZE; i++){
        sum += pow(x,i);
    }
    sum *= a;
    double ssum = a / (1-x);
    printf("Long: %.9lf Simple: %.9lf\n",sum,ssum);
    return sum;
}

double derivative_series(double a, double x){
    double sum = 0;
    for(size_t i = 1; i < SIZE; i++){
        sum +=  i * pow(x,(i-1)); 
    }
    sum *= a;
    double ssum = a / ((1-x)*(1-x));
    printf("Long: %.9lf Simple: %.9lf\n",sum,ssum);
    return sum;
}

double substract_series(double a, double x){
    double sum = derivative_series(a,x) - multiply_series(a,x);
    double ssum = a * x / ((1-x)*(1-x));
    printf("Long: %.9lf Simple: %.9lf\n",sum,ssum);
}

double logarithm_series(double a, double x)
{
    double sum = 0;
    for(size_t i = 1; i < SIZE; i+= 2){
        sum += (pow(x,i)) / i; 
    }
    sum *= 2 * a;
    double ssum = a * log((1+x)/(1-x));
    printf("Long: %.9lf Simple: %.9lf\n",sum,ssum);
}

double tanInverse_series(double a, double x)
{
    double sum = 0;
    for(int i = 1, j = 1; i < SIZE; i+=2, j *= -1){
        sum += j * pow(x,i) / i; 
    }
    sum *= a;
    double ssum = a * atan(x);
    printf("Long: %.9lf Simple: %.9lf\n",sum,ssum);
}