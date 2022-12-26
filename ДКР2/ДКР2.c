#include <stdio.h>
#include <stdlib.h>

int matrix_size();
int** matrix_make (int);
void matrix_autofill (int**, int);
void matrix_manualfill (int**, int);
void matrix_print (const int**, int);
void matrix_find_bigger_values_below_main_diagonal (int**, int, int*, int*, int*, int*);
void matrix_print_bigger_values (int**, int, int*, int*, int*, int*);
void matrix_clear (int**, int);

int main()
{
    int N = matrix_size();
    int** A = matrix_make (N);
    char auto_fill;
    do
    {
        printf("\n\t\tTo auto-fill, or not?\tY/N\t");
        scanf(" %c", &auto_fill);
    }
    while (auto_fill!='y' && auto_fill!='Y' && auto_fill!='n' && auto_fill!='N');
    // filling matrix with stuff
    if (auto_fill=='y' || auto_fill=='Y')
        matrix_autofill (A, N);
    else if (auto_fill=='n' || auto_fill=='N')
        matrix_manualfill (A, N);
    system("cls");
    matrix_print (A, N); // printing matrix
    int increment = 1, max=0, i=0, j=0;
    matrix_find_bigger_values_below_main_diagonal (A, N, &increment, &max, &i, &j); // looking for bigger numbers on and below main diagonal
    matrix_print_bigger_values (A, N, &increment, &max, &i, &j); // actually printing out all the numbers based on info from the last function
    matrix_clear (A, N);
    return 0;
}

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
    {
        printf("\n\t\tMemory allocation failed");
        exit(0);
    }
    return A;
}

void matrix_autofill (int**A, int N)
{
    for (int i=0; i<N; i++)
        for (int j=0; j<N; j++)
            A[i][j] = rand()%9999999; // dunno why this, can make any value work tbh
}

void matrix_manualfill (int** A, int N)
{
    printf("\n\n\tEnter your array values.\n");
    for (int i=0; i<N; i++)
        for (int j=0; j<N; j++)
        {
            int matrix_value;
            printf("\t\tEnter your value for [%d][%d]\t", i+1, j+1);
            scanf(" %d", &matrix_value);
            A[i][j] = matrix_value;
        }
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
        printf("\nMax Value: [%d][%d] %d", *i_pointer+1, *j_pointer+1, *max);
    else if (*increment>1)
    {
        for (int i=0; i<search_value; i++)
        {
            for (int j=0; j<search_value; j++)
            {
                if (A[i][j]==*max)
                {
                    printf("\nMax Value #%d: [%d][%d] %d", k, i+1, j+1, *max);
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

void matrix_clear (int** A, int N)
{
    for (int i=0; i<N; i++)
        free (A[i]);
    free (A);
}
