#include <stdio.h>
#include <stdlib.h>

void sum_count ()
{
    int N=1;
    double sum=0, a=0, value_too_high=1;
    do
    {
        do
        {
            printf("\nEnter N\t");
            scanf(" %d", &N);
        }
        while (N<1);
        printf("Enter a\t");
        scanf("%lf", &a);
        value_too_high=1;
        for (int i=0; i<N; i++)
        {
            value_too_high*=a;
            if (value_too_high>1e+308)
            {
                printf("\tSorry, this combination is just too much to handle. Try again?\n");
                break;
            }
        }
    }
    while (value_too_high>1e+308);
    for (int n=1; n<=N; n++)
    {
        int first=1, n_temp = n-1;
        if (n_temp!=0) first = (n_temp%2==0 ? 1:-1);
        double div = (double) a + first * n;
        if (div!=0 && a!=0)
        {
            double temp_a=1;
            for (int i=0; i<n; i++) temp_a*=a;
            sum += (double) first * temp_a / div;
        }
    }
    sum++;
    printf("\n\tsum = %g", sum);
}
