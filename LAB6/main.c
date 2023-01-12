#include <stdio.h>
#include <stdlib.h>
#include "prototypes.h"

int main()
{
    char group[100], name[100];
    double x1, x2, delta;
    int N;
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
