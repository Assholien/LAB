#include <stdio.h>
#include <stdlib.h>

void fill_int_array( unsigned int * uiptr, unsigned int size_of_array );
void fill_float_array( float * fptr, unsigned int size_of_array );
void print_int_array( const unsigned int * uiptr, unsigned int size_of_array );
void print_float_array( const float * fptr, unsigned int size_of_array);
unsigned int sum ( const unsigned int * uiptr, unsigned int size_of_array );
double product( const float * fptr, unsigned int size_of_array );
double mean_value (const unsigned int, unsigned int);
unsigned int find_min(const unsigned int*, unsigned int);
float find_max(const float*, unsigned int);

int main()
{
    unsigned int * A;
    float * B;
    unsigned int Size;
    unsigned int amount;
    double mult;
    double average_value;
    unsigned int min_value;
    float max_value;
    printf("Enter size of array: ");
    scanf("%u", &Size);
    A = (unsigned int *) calloc (Size, sizeof(unsigned int) );
    B = (float *) malloc (Size * sizeof(float) );
    if( A == NULL || B == NULL ){
    printf("Memory has not been allocated");
    exit(0);
    }

    fill_int_array( A, Size );
    fill_float_array( B, Size );
    print_int_array( A, Size );
    print_float_array( B, Size );
    amount = sum( A, Size );
    mult = product( B, Size );
    average_value = mean_value(amount, Size);
    min_value = find_min(A, Size);
    max_value = find_max(B, Size);
    printf("\n\nSum = %u", amount);
    printf("\nProduct = %.3lf", mult);
    printf("\nAverage = %.1f", average_value);
    printf("\nMinimum = %u", min_value);
    printf("\nMaximum = %.f", max_value);
    free(A);
    free(B);
    return 0;
}

void fill_int_array( unsigned int * A, unsigned int Size )
{
    unsigned int temp;
    printf("\n\nEnter values of UNSIGNED INT elements of array.\n");
    for(unsigned int j = 0; j <= Size-1; j++ ){

    printf("A[%u]= ", j);
    scanf("%u", &temp);
    A[j] = temp;

    //Why would you even want that? A[j] = Size - (j+1);
    }
}

void fill_float_array( float * B, unsigned int Size )
{

    float temp;
    printf("\n\nEnter values of FLOAT elements of array.\n");

    for(unsigned int j = 0; j <= Size-1; j++ ){

    printf("B[%u]= ", j);
    scanf("%f", &temp);
    B[j] = temp;

    //I did it... but at what cost? B[j] = 5.*j+5.;
    }
}

void print_int_array( const unsigned int * A, unsigned int Size )
{
    printf("\n\nArray of UNSIGNED INT values:\n");
    for(unsigned int j = 0; j < Size; j++ )
    printf("%5d", A[j] );
}

void print_float_array( const float * B, unsigned int Size )
{
    printf("\n\nArray of FLOAT values:\n");
    for(unsigned int j = 0; j < Size; j++ )
    printf("%7.2f", B[j] );
}

unsigned int sum (const unsigned int * A, unsigned int Size )
{
    unsigned int S = 0;

    for(unsigned int j = 0; j < Size; j++ )
    S += A[j];
    return S;
}

double product(const float * B, unsigned int Size )
{
    double M = 1.0;

    for(unsigned int j = 0; j < Size; j++ )
    M *= B[j];
    return M;
}

double mean_value (const unsigned int A, unsigned int Size)
{
    double average;
    double temp = A;
    average = (double) temp/Size;
    return average;
}

unsigned int find_min(const unsigned int *A, unsigned int Size)
{
    unsigned int value = A[0];
    for(int j=1; j<Size; j++) value = (value<A[j] ? value:A[j]);
    return value;
}

float find_max (const float* B, unsigned int Size)
{
    float value = B[0];
    for(int j=1; j<Size; j++) value = (value>B[j] ? value:B[j]);
    return value;
}
