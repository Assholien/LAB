#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int** memory_allocation(int, int);
void clearMemory(int**, int);
void max_min(const int **, int, int**, int, int, char[]);
void transpose_b(const int**, int, int);
void fill_int_array(int**, int, int, char[]);
void print_int_array(const int**, int, int);
void mult_a_b (const int**, int**, int, int);

int main()
{
    char qa0[100] = {0};
    char qa_y[100] = "y";
    char qa_n[100] = "n";
    int qrc, rows, cols;
    while(
            strcasecmp(qa0,"exit")!=0 &&
            strcasecmp(qa0,"quit")!=0 &&
            strcasecmp(qa0,"halt")!=0
            )
    {
        char qa1[100] = "n";
        while(strcasecmp(qa1,qa_n)==0)
        {
            char qa[100] = "n";
            while(strcasecmp(qa,qa_n)==0)
            {
                do
                {
                    printf("\n\tEnter your quadratic 2D array dimensions:\n");
                    scanf("%d", &qrc);
                } while(qrc>15); //15 just so it could fit terminal
                do
                {
                    printf("\t\tSure?\n\t\t\tY/N?");
                    scanf("%s", qa);
                } while(
                        strcasecmp(qa,qa_y)!=0 &&
                        strcasecmp(qa,qa_n)!=0
                        );
            }
            do
            {
                printf("\n\tYour second array dimensions must be uneven.\n");
                printf("\t\tEnter them:\n");
                scanf("%d %d", &rows, &cols);
            } while(rows==cols || rows>15 || cols>15); //15 just so it could fit terminal
            if (qrc!=rows)
            {
                do
                {
                    printf("\t\tYou sure? Rows must match for multiplication. You won't be able to do it.\n\t\t\tY/N?\n");
                    scanf("%s", qa1);
                } while(
                        strcasecmp(qa1,qa_y)!=0 &&
                        strcasecmp(qa1,qa_n)!=0
                        );
            }
            else break;
        }
        int** A = memory_allocation(qrc,qrc);
        int** B = memory_allocation(rows,cols);
            if (A==NULL || B==NULL)
            {
                printf("\n\tMemory has not been allocated");
                exit(0);
            }
        char qa2[100];
        if(qrc*qrc>20 || rows*cols>20)
        {
            do
            {
            printf("\t\tLots of values you've got. Really wanna bother typing them all?\n\t\t\tY/N?");
            scanf("%s", qa2);
            } while (
                    strcasecmp(qa2,qa_y)!=0 &&
                    strcasecmp(qa2,qa_n)!=0
                    );
        }
        else
        {
            do
            {
            printf("\t\tWanna type values by hand?\n\t\t\tY/N?");
            scanf("%s", qa2);
            } while (
                    strcasecmp(qa2,qa_y)!=0 &&
                    strcasecmp(qa2,qa_n)!=0
                    );
        }
        fill_int_array(A, qrc, qrc, qa2);
        fill_int_array(B, rows, cols, qa2);
        system("cls");
        printf("\tYour arrays:\n");
        print_int_array(A, qrc, qrc);
        print_int_array(B, rows, cols);
        char qa0[100]={0};
        while(
                strcasecmp(qa0,"other")!=0 &&
                strcasecmp(qa0,"another")!=0 &&
                strcasecmp(qa0,"different")!=0 &&
                strcasecmp(qa0,"arrays")!=0 &&
                strcasecmp(qa0,"change")!=0 &&
                strcasecmp(qa0,"exit")!=0 &&
                strcasecmp(qa0,"quit")!=0 &&
                strcasecmp(qa0,"halt")!=0
                )
        {
            do
            {
            printf("\n\tSo, what do you wanna do with them?");
            printf("\n\t\tFind min");
            printf("\n\t\tFind max");
            printf("\n\t\tTranspose B");
            if(strcmp(qa1,qa_n)==0)
            printf("\n\t\tMultiply AxB");
            printf("\n\t\tDifferent arrays");
            printf("\n\t\tExit\n");
            scanf("%s", qa0);
            } while(
                    strcasecmp(qa0,"max")!=0 &&
                    strcasecmp(qa0,"maximum")!=0 &&
                    strcasecmp(qa0,"min")!=0 &&
                    strcasecmp(qa0,"minimum")!=0 &&
                    strcasecmp(qa0,"transpose")!=0 &&
                    strcasecmp(qa0,"multiply")!=0 &&
                    strcasecmp(qa0,"mult")!=0 &&
                    strcasecmp(qa0,"times")!=0 &&
                    strcasecmp(qa0,"axb")!=0 &&
                    strcasecmp(qa0,"other")!=0 &&
                    strcasecmp(qa0,"another")!=0 &&
                    strcasecmp(qa0,"different")!=0 &&
                    strcasecmp(qa0,"arrays")!=0 &&
                    strcasecmp(qa0,"change")!=0 &&
                    strcasecmp(qa0,"exit")!=0 &&
                    strcasecmp(qa0,"quit")!=0 &&
                    strcasecmp(qa0,"halt")!=0
                    );
            if(
                strcasecmp(qa0,"max")==0 ||
                strcasecmp(qa0,"maxmimum")==0
                ) max_min(A, qrc, B, rows, cols, qa0);
            else if (
                    strcasecmp(qa0,"min")==0 ||
                    strcasecmp(qa0,"minimum")==0
                    ) max_min(A, qrc, B, rows, cols, qa0);
            else if(
                    strcasecmp(qa0,"transpose")==0 //||
                    ) transpose_b(B, rows, cols);
            else if (
                    strcasecmp(qa0,"multiply")==0 ||
                    strcasecmp(qa0,"mult")==0 ||
                    strcasecmp(qa0,"times")==0 ||
                    strcasecmp(qa0,"axb")==0
                    ) mult_a_b(A, B, rows, cols);
            else if (
                    strcasecmp(qa0,"other")==0 ||
                    strcasecmp(qa0,"another")==0 ||
                    strcasecmp(qa0,"different")==0 ||
                    strcasecmp(qa0,"arrays")==0 ||
                    strcasecmp(qa0,"change")==0
                    )
            {
                system("cls");
                break;
            }
            else if(
                    strcasecmp(qa0,"exit")==0 ||
                    strcasecmp(qa0,"quit")==0 ||
                    strcasecmp(qa0,"halt")==0
                    )
            {
                clearMemory(A, qrc);
                clearMemory(B, rows);
                return 0;
            }
        }
    }
    return 0;
}

int** memory_allocation(int rows, int cols)
{
    int** matrix = (int**) malloc(rows* sizeof(int*));
    for(int i=0; i<rows; i++) matrix[i] = (int*) malloc(cols*sizeof(int));
    return matrix;
}

void fill_int_array(int** A, int rows, int cols, char qa[100])
{
    int temp=0;
        if(strcasecmp(qa,"y")==0)
        {
        printf("\n\n\tEnter your array values.\n");
        for(int i=0; i<rows; i++)
            for(int j=0; j<cols; j++)
            {
                printf("Enter your value for [%d][%d]\n", i, j);
                scanf("%d", &temp);
                A[i][j] = temp;
            }
        }
        else if (strcasecmp(qa,"n")==0)
        {
            for(int i=0; i<rows; i++)
                for(int j=0; j<cols; j++)
                {
                    A[i][j] = i+j;
                }
        }
}

void print_int_array(const int** A, int rows, int cols)
{
    printf("\n\t\t");
    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<cols; j++)
        {
            printf("%d\t", A[i][j]);
        }
            printf("\n\t\t");
    }
    printf("\n");
}

void clearMemory(int** matrix, int rows)
{
    for(int i=0; i<rows; i++)
        free(matrix[i]);
    free(matrix);
}

void transpose_b(const int** B, int rows, int cols)
{
    int trows=cols;
    int tcols=rows;
    int** transposed = memory_allocation(trows, tcols);
    printf("\n\tTransposed matrix B:\n\t\t");
    for (int i=0; i<rows; i++)
        for(int j=0; j<cols; j++)
            transposed[j][i] = B[i][j];
    print_int_array(transposed, trows, tcols);
    clearMemory(transposed, trows);
}

void mult_a_b (const int** A, int** B, int rows, int cols)
{
    int** mult = memory_allocation(rows, cols);
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            mult[i][j]=0;
            for(int k=0;k<rows;k++)
            {
                mult[i][j]+=A[i][k]*B[k][j];
            }
        }
    }
    printf("\tResult:\n");
    print_int_array(mult, rows, cols);
    clearMemory(mult, rows);
}

void max_min(const int** A, int qrc, int** B, int rows, int cols, char qa0[100])
{
    int A_min_max = A[0][0];
    int B_min_max = B[0][0];
    if(strcasecmp(qa0,"max")==0)
    {
        for(int i=0; i<qrc; i++)
        {
            for(int j=0; j<qrc; j++)
                A_min_max = (A[i][j]>A_min_max ? A[i][j]:A_min_max);
        }
        printf("A_max = %d\t", A_min_max);
        for(int i=0; i<rows; i++)
        {
            for(int j=0; j<cols; j++)
                B_min_max = (B[i][j]>B_min_max ? B[i][j]:B_min_max);
        }
        printf("B_max = %d\t", B_min_max);
    }
    else if(strcasecmp(qa0,"min")==0)
        {
        for(int i=0; i<qrc; i++)
        {
            for(int j=0; j<qrc; j++)
                A_min_max = (A[i][j]<A_min_max ? A[i][j]:A_min_max);
        }
        printf("A_min = %d\t", A_min_max);
        for(int i=0; i<rows; i++)
        {
            for(int j=0; j<cols; j++)
                B_min_max = (B[i][j]<B_min_max ? B[i][j]:B_min_max);
        }
        printf("B_min = %d\t", B_min_max);
    }
}
