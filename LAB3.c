#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

double chord_method (double x1, double x2, double eps, unsigned int iterations_option, unsigned int N);
double div_method (double x1, double x2, double eps, unsigned int iterations_option, unsigned int N);
unsigned int NeXTSTEP(unsigned int N);
double func(double x);

int main()
{
    double x1, x2, eps, timings;
    unsigned int calc_method, iterations_option, N;
    unsigned int last_choice = 1;
    time_t start, end;
    while(last_choice == 1)
    {
        do
        {
            printf("Choose your Calculation Method\n\t1 - Chord Method\n\t2 - Half-Division Method\n");
            scanf("%u", &calc_method);
        } while(calc_method!=1 && calc_method!=2);
        do
        {
            printf("Good. Wanna count number of iterations?\n\t1 - Yes\n\t2 - No\n");
            scanf("%u", &iterations_option);
            if(iterations_option==1)
            {
                do
                {
                    printf("Enter number of iterations: ");
                    scanf("%u", &N);
                } while(N<1);
            } else N=1;
        } while(iterations_option!=1 && iterations_option!=2);
        printf("Now, enter your:\n\tx1 - first point\n\tx2 - second point\n\teps - measurement error\n");
        scanf("%lf %lf %lf", &x1, &x2, &eps);
        while(func(x1)*func(x2)>0 || eps<0.000001)
        {
            if(func(x1)*func(x2)>0)
            {
                printf("No solutions. Try again?\n");
                scanf("%lf %lf", &x1, &x2);
            }
            else if (eps<0.000001)
            {
                printf("Your measurement error threshold is too low, sorry. Would you go a bit higher?\n");
                scanf("%lf", &eps);
            }
        }
        start = clock();
        switch(calc_method)
        {
        case 1:
            printf("\txi = %.15lf\n", chord_method (x1, x2, eps, iterations_option, N));
        break;
        case 2:
            printf("\txi = %.15lf\n", div_method (x1, x2, eps, iterations_option, N));
        break;
        }
        end = clock();
        timings = (end - start);
        if(iterations_option==2) printf("\tTimer: %.lfms\n", timings);
        do
        {
            printf("\nThis is fun! Another one?\n\t1 - More\n\t2 - Enough is enough\n");
            scanf("%u", &last_choice);
        } while(last_choice!=1 && last_choice!=2);
        }
    return 0;
}

double func(double x)
{
    return 0.25*pow(x-25,2)+pow(x+25,3)/100+1;
}

double chord_method (double x1, double x2, double eps, unsigned int iterations_option, unsigned int N)
{
    double xi;
    while(fabs(func(xi)) > eps)
    {
        xi = (func(x2) * x1 - func(x1) * x2)/(func(x2) - func(x1));
        if (func(xi)*func(x1)>0) x1=xi;
        else x2=xi;
        if(iterations_option==1)
        {
            printf("\txi = %.15lf\n", xi);
            unsigned int i;
            i++;
            if(i>=N)
            {
                i=0;
                switch(NeXTSTEP(N))
                {
                case 1:
                break;
                case 2:
                    iterations_option=2;
                break;
                case 3:
                    return xi;
                break;
                }
            }
        }
    }
    return xi;
}

double div_method (double x1, double x2, double eps, unsigned int iterations_option, unsigned int N)
{
    double xi;
    while(fabs(x2-x1) >= eps)
    {
        xi = (x1+x2)/2;
        if(func(xi)==0) break;
        else if(func(xi)*func(x1)>0) x1=xi;
        else x2=xi;
        if(iterations_option==1)
        {
            printf("\txi = %.15lf\n", xi);
            unsigned int i;
            i++;
            if(i>=N)
            {
                i=0;
                switch(NeXTSTEP(N))
                {
                    case 1:
                    break;
                    case 2:
                        iterations_option=2;
                    break;
                    case 3:
                        return xi;
                    break;
                }
            }
        }
    }
    return xi;
}

unsigned int NeXTSTEP(unsigned int N)
{
    unsigned int thingy;
    while(thingy!=1 && thingy!=2 && thingy!=3)
    {
        printf("All iterations complete, but no solution found... Yet\n\t1 - Go on with %u more iterations\n\t2 - Stop only after solution is found\n\t3 - Halt and display results\n", N);
        scanf("%u", &thingy);
    }
    return thingy;
}
