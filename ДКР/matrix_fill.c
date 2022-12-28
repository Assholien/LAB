#include <stdio.h>
#include <stdlib.h>

void matrix_autofill (int**A, int N)
{
    for (int i=0; i<N; i++)
        for (int j=0; j<N; j++)
            A[i][j] = rand()%9999999; // dunno why this, can make any value work tbh
}

void matrix_manualfill (int** A, int N)
{
    printf("\tEnter your array values.\n");
    for (int i=0; i<N; i++)
        for (int j=0; j<N; j++)
        {
            int matrix_value;
            printf("\t\tEnter your value for [%d][%d]\t", i+1, j+1);
            scanf(" %d", &matrix_value);
            A[i][j] = matrix_value;
        }
}
