#include <stdio.h>
#include <stdlib.h>

int matrix_size()
{
    int N=0;
    char continue_char;
    do
    {
        if (N==1)
            printf("\n\tMatrix 1x1 has only one value in it. How do you expect me to find bigger value out of only one?\t");
        else if (N>14)
        {
            do
            {
                printf("\n\tMight not fit windows terminal properly. Continue?\tY/N\t");
                scanf(" %c", &continue_char);
            }
            while (continue_char!='y' && continue_char!='Y' && continue_char!='n' && continue_char!='N');
            if (continue_char=='y' || continue_char=='Y')
                break;
        }
        if (N==0 || continue_char=='n' || continue_char=='N')
            printf("\tHow large your quadratic matrix should be?\t");
        scanf(" %d", &N);
    }
    while (N<=1 || N>14); // a double-check if you want to fill only the terminal
    return N;
}

int** matrix_make (int N)
{
    int** A = (int**) malloc (N* sizeof(int*));
    for (int i=0; i<N; i++)
        A[i] = (int*) malloc (N* sizeof(int));
    if (A==NULL)
        printf("\n\t\tMemory allocation failed");
    return A;
}

void matrix_clear (int** A, int N)
{
    for (int i=0; i<N; i++)
        free (A[i]);
    free (A);
}

void matrix_print (const int** A, int N)
{
    printf("Here's what you're getting:\n");
    for (int i=0; i<N; i++)
    {
        if (i==0)
        {
            for (int j=0; j<N+1; j++)
            {
                if (j==0)
                    printf("#");
                else
                    printf("\t%d", j);
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
}

