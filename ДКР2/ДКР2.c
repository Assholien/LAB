#include <stdio.h>
#include <stdlib.h>

void matrix_func();

int main()
{
    matrix_func();
    return 0;
}

void matrix_func()
{
    int N=1;
    do
    {
        printf("\tHow large your quadratic matrix should be?\t");
        scanf(" %d", &N);
        if (N==1)
        {
            printf("\n\tMatrix 1x1 has only one value in it. How do you expect me to find bigger value out of only one?\t");
            scanf(" %d", &N);
        }
    }
    while (N<=0 || N>14); // yep, just to fit windows terminal
    int** A = (int**) malloc (N* sizeof(int*));
    for (int i=0; i<N; i++)
        A[i] = (int*) malloc (N* sizeof(int));
    if (A==NULL)
    {
        printf("\n\t\tMemory allocation failed");
        exit(0);
    }
    char auto_fill;
    do
    {
        printf("\n\t\t\To auto-fill, or not?\tY/N\t");
        scanf(" %c", &auto_fill);
    }
    while (auto_fill!='y' && auto_fill!='Y' && auto_fill!='n' && auto_fill!='N');
    //filling matrix with stuff
    if (auto_fill=='y' || auto_fill=='Y')
    {
        for (int i=0; i<N; i++)
            for (int j=0; j<N; j++)
                A[i][j] = rand()%9999999;
    }
    else if (auto_fill=='n' || auto_fill=='N')
    {
        printf("\n\n\tEnter your array values.\n");
        for (int i=0; i<N; i++)
            for (int j=0; j<N; j++)
            {
                int matrix_value;
                printf("\t\tEnter your value for [%d][%d]\t", i, j);
                scanf(" %d", &matrix_value);
                A[i][j] = matrix_value;
            }
    }
    system("cls");
    //printing
    printf("Here's what you're getting:\n");
    for (int i=0; i<N; i++)
    {
        if (i==0)
        {
            for (int j=0; j<N+1; j++)
            {
                if (j==0)
                    printf("#\t");
                else
                    printf("%d\t", j);
            }
            printf("\n");
        }
        printf("%d\t", i+1);
        for (int j=0; j<N; j++)
        {
            if (j==0)
                printf("%d", A[i][j]);
            else
                printf("\t%d", A[i][j]);
        }
        printf("\n");
    }
    //looking for bigger numbers under+main diagonal
    int increment=1, decrement = N-1, max_temp=0;
    for (int i=decrement; i>=0; i--)
    {
        for (int j=decrement; j>=0; j--)
        {
            if (max_temp==A[i][j])
                increment++;
            else if (max_temp<A[i][j])
                max_temp=A[i][j];
        }
        decrement--;
    }
    // actually printing out all the numbers based on info from the last cycle
    int k = 1;
    int increment_temp = increment;
    for (int i=0; i<N; i++)
    {
        for (int j=0; j<N; j++)
        {
            if (max_temp==A[i][j] && increment>=0 && increment_temp!=1)
            {
                printf("\nMax Value #%d: [%d][%d] %d", k, i+1, j+1, max_temp);
                if (increment==0)
                    break;
                increment--;
                k++;
            }
            else if (max_temp==A[i][j] && increment_temp==1)
            {
                printf("\nMax Value: [%d][%d] %d", i+1, j+1, max_temp);
                increment_temp--;
                break;
            }
        }
        if (increment==1 && increment_temp==0 || increment==0)
            break;
    }
    for (int i=0; i<N; i++)
        free (A[i]);
    free (A);
}
