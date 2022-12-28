#include <stdio.h>
#include <stdlib.h>

void matrix_find_bigger_values_below_main_diagonal (int** A, int N, int* increment, int* max, int* pointer_i, int* pointer_j)
{
    int increment_temp=0, decrement = N-1, max_temp=0, temp_i=0, temp_j=0;
    for (int i=decrement; i>=0; i--)
    {
        for (int j=decrement; j>=0; j--)
        {
            if (max_temp==A[i][j])
                increment_temp++;
            else if (max_temp<A[i][j])
            {
                max_temp=A[i][j];
                increment_temp=1;
                temp_i = i;
                temp_j = j;
            }
        }
        decrement--;

    }
    *increment = increment_temp;
    *max = max_temp;
    *pointer_i = temp_i;
    *pointer_j = temp_j;
}

void matrix_print_bigger_values (int** A, int N, int* increment, int* max, int* i_pointer, int* j_pointer)
{
    int search_value = 1, k = 1;
    if (*increment==1)
        printf("Max Value: [%d][%d] %d", *i_pointer+1, *j_pointer+1, *max);
    else if (*increment>1)
    {
        for (int i=0; i<search_value; i++)
        {
            for (int j=0; j<search_value; j++)
            {
                if (A[i][j]==*max)
                {
                    printf("Max Value #%d: [%d][%d] %d", k, i+1, j+1, *max);
                    if (*increment!=1)
                        printf("\n");
                    if (*increment==0)
                        break;
                    --*increment;
                    k++;
                }
            }
            if (*increment==0 || search_value==N)
                break;
            search_value++;
        }
    }
}
