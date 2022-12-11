#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double funcx(double);
double** create_array(int);
void free_array(double**, int);
void write_files(const double**, int, FILE*, FILE*, char[], char[]);
void fill_array(double**, int, double, double);
void binary_print(FILE*);

int main()
{
    char group[100]={0}, name[100]={0};
    double x1=0, x2=0, delta=0;
    int N=0;
    FILE* fp = fopen ("Input.txt", "r");
    FILE* fp_out = fopen ("Output.txt", "w");
    FILE* fp_bin = fopen ("Binary.bin", "w+b");
    if (fp==NULL || fp_out==NULL || fp_bin==NULL) printf("Error, one of the files don't exist");
    else
    {
        fscanf(fp, "%lf %lf %d %lf %s %s", &x1, &x2, &N, &delta, group, name);
        fclose(fp);
        if (delta==0 && N==0)
        {
            printf("Please re-evaluate your values");
            fclose(fp_out);
            fclose(fp_bin);
            return 0;
        }
        else if (N==0) N = ((x2-x1)/delta)+1; else if (delta == 0) delta=(x2-x1)/(N-1);
        double** A = create_array(N);
        if (A==NULL) printf("\n\tMemory has not been allocated");
        else
        {
        printf("%s, %s", name, group);
        fill_array(A, N, x1, delta);
        write_files(A, N, fp_out, fp_bin, group, name);
        free_array(A, N);
        binary_print(fp_bin);
        }
    }
    return 0;
}

double funcx(double x)
{
    return 0.25*pow(x-25,2)+pow(x+25,3)/100+1;
}

double** create_array(int N)
{
    double** A = (double**) malloc(N* sizeof(double*));
    for(int i=0; i<N; i++) A[i] = (double*) malloc(3*sizeof(double));
    return A;
}

void fill_array(double** A, int N, double x, double delta)
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

void write_files(const double** A, int N, FILE* fp_out, FILE* fp_bin, char group[100], char name[100])
{
    fprintf(fp_out, "N\tx\tf(x)\n");
    fwrite(&N, sizeof(int), 1, fp_bin);
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<3; j++)
        {
            if(j==2) fprintf(fp_out, "%g", A[i][j]); else fprintf(fp_out, "%g\t", A[i][j]);
            if(j!=0 && j<=2) fwrite(&A[i][j], sizeof(double), 1, fp_bin);
        }
        fprintf(fp_out, "\n");
    }
    fprintf(fp_out, "%s, %s", group, name);
    fclose(fp_out);
    fclose(fp_bin);
}

void free_array(double** A, int N)
{
    for(int i=0; i<N; i++) free(A[i]);
    free(A);
}

void binary_print(FILE* fp_bin)
{
    int N=0;
    double temp=0;
    fp_bin = fopen("Binary.bin", "r+b");
    if (fp_bin==NULL) printf("Error, the binary file don't exist");
    else
    {
        printf("\nN\tx\tf(x)\n");
        fread(&N, sizeof(int), 1, fp_bin);
        for(int i=0; i<N; i++)
        {
            if(i%10==0 && i!=0) system("pause");
            int k = 1;
            k+=i;
            printf("%d", k);
            for (int j = 1; j < 3; j++)
            {
                fread(&temp, sizeof(double), 1, fp_bin);
                if(j==3) printf("%g", temp); else printf("\t%g", temp);
            }
            printf("\n");
        }
        fclose(fp_bin);
    }
}
