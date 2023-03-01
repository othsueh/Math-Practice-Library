#include "convergenceTest.h"


int main()
{
    int option = 0;
    double a =0, b = 0;
    while(scanf("%d",&option) != 0){
        switch(option)
        {
            case 1:
                printf("Who's the faster\n");
                scanf("%lf %lf", &a, &b);
                convergeSpeedTest(a,b);
                break;

            case 2:
                printf("Integral test\n");
                scanf("%lf", &a);
                integralTest(a);
                break;
            default:
                break;
        }
    }
}