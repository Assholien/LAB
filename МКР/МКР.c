#include <stdio.h>
#include <stdlib.h>

float* allocating_array (float*, const int);
void fill_array (float*, const int);
void print_array (const float*, const int);
float sum_array (const float*, const int);
void clearing_array (float*);
double x_function (int);
double sqrt_of_a_number (const int);

int main()
{
    unsigned int program_choice=13;
    while (program_choice!=0)
    {
        do
        {
            printf("Which program to choose?\n\t0.Exit\n\t10.Find sum in float array.\n\t11.Find product\n\t12.Find x\n");
            scanf(" %d", &program_choice);
        }
        while (program_choice!=10 && program_choice!=11 && program_choice!=12 && program_choice!=0);
        if (program_choice==10)
        {
            int N=4;
            do
            {
                if (N<4)
                    printf("Can't find a sum of non-pair elements of array if it has less than 4 elements in it.\n");
                printf("How large should your array be?\t");
                scanf (" %d", &N);
            }
            while (N<4);
            float* A = allocating_array (A, N);
            if (A==NULL)
            {
                printf("Memory couldn't be allocated.\n");
                continue;
            }
            fill_array (A, N);
            print_array (A, N);
            printf("\nSum = %g\n", sum_array (A, N));
            free(A);
        }
        else if (program_choice==11)
        {
            srand(time(0));
            unsigned int one=rand()%20, two=rand()%20, three=rand()%20, product=1;
            while (one==0 || two==0 || three==0)
                if (one==0)
                    one=rand()%20;
                else if (two==0)
                    two=rand()%20;
                else if (three==0)
                    three=rand()%20;
            product*=one;
            product*=two;
            product*=three;
            printf("Value 1 = %u\nValue 2 = %u\nValue 3 = %u\nProduct = %u\n", one, two, three, product);
        }
        else if (program_choice==12)
        {
            int x;
            printf("Enter your x\t");
            scanf(" %d", &x);
            printf("x = %g\n", x_function(x));
        }
    }
    return 0;
}

float* allocating_array (float* A, const int N)
{
    A = (float*) malloc (N* sizeof(float));
    return A;
}

void fill_array (float* A, const int N)
{
    for (int i=0; i<N; i++)
    {
        printf("Value for [%d] ", i);
        scanf(" %f", &A[i]);
    }
}

void print_array (const float* A, const int N)
{
    for (int i=0; i<2; i++)
        for (int j=0; j<N; j++)
        {
            if (i==0 && j!=N-1)
                printf("%d\t", j);
            else if (i==0 && j==N-1)
            {
                printf("%d\t", j);
                printf("\n\n");
            }
            else if (i!=0)
                printf("%g\t", A[j]);
        }
}

float sum_array (const float* A, const int N)
{
    float sum=0;
    for (int i=0; i<N; i++)
        if (i%2==1)
            sum+=A[i];
    return sum;
}

double x_function (const int x)
{
    double value;
    value = (double)(x>0 ? sqrt_of_a_number(x):value);
    value = (double)(x<0 ? x*x:value);
    value = (double)(x==0 ? -1:value);
    return value;
}

double sqrt_of_a_number (const int x)
{
    double start=0, middle, end=x;
    double value;
    while (start<=end) // first loop. Looking for integer part of sqrt. Mainly for saving resources, cuz next for-loop will give you same results, but since it increments only by 0.1...
    {
        middle = (start+end)/2; // begins with calculating value in-between 0 - N.
        if (middle*middle==x) // if after counting middle in power of 2 it will be equal to N, value = middle and cycle is over.
        {
            value = middle;
            break;
        }
        else if (middle*middle<x) // if m^2 < N - we set the result to start value
        {
            value = start; // in case if after incrementing start it would break out of loop, first writing value of start into our result.
            start = middle+1;
        }
        else if (middle*middle>x) // decrementing end value if middle^2 > N
            end = middle-1;
    }
    double increment=0.1;
    for (int i=0; i<5; i++) // second loop. Counts 5 digits after comma.
    {
        while (value*value<x) // adds an increment to value, untill it would be more than x by 1 increment step
            value+=increment;
        value-=increment; // that's why we subtract that 1 increment step from value
        increment = increment/10; // modifying increment to continue search
    }
    return value;
}
