#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    double x, y;

    printf("Enter x\n");
    scanf("%lf", &x);
    if (-5.2<=x && x<0) y=exp(-x)+1;
    else if (0<=x && x<8) y=exp(x)-1;
    else if (8<=x && x<15) y=sqrt(2*x-7)/sqrt(pow(x,2)-25)+2*pow(x,exp(1));
    else y=0;
    printf("x=%lf\ny=%lf",x,y);
    return 0;
}
