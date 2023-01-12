#include <stdio.h>
#include <stdlib.h>
#include "prototypes.h"

void write_files(const double** A, const int N, FILE* fp_out, FILE* fp_bin, const char group[100], const char name[100])
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
    return;
}
