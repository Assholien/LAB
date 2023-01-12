#include <stdio.h>
#include <stdlib.h>
#include "prototypes.h"

double x_in_a_power_of_y (const double x, const double y)
{
    double result=1;
    for (int i=0; i<y; i++)
        result*=x;
    return result;
}

double funcx (const double x)
{
    return 0.25*x_in_a_power_of_y(x-25,2)+x_in_a_power_of_y(x+25,3)/100+1;
}

double** create_array (const int N)
{
    double** A = (double**) malloc(N* sizeof(double*));
    for(int i=0; i<N; i++) A[i] = (double*) malloc(3*sizeof(double));
    return A;
}

void fill_array (double** A, const int N, double x, const double delta)
{
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<3; j++)
        {
            A[i][0] = (double)i+1;
            A[i][1] = x;
            A[i][2] = funcx(x);
        }
    x+=delta;
    }
}

void free_array (double** A, const int N)
{
    for(int i=0; i<N; i++) free(A[i]);
    free(A);
}
