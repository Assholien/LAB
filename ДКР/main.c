#include <stdio.h>
#include <stdlib.h>

int main()
{
    int program=0;
    while (program==0 || program==1 || program==2 || program==3)
    {
        do
        {
            printf("\nWhich program to enter?\n\t1.Counting sum\n\t2.Finding bigger value in matrix\n\t3.Looking for frequently used letters in text\n\t4.Exit\n");
            scanf(" %d", &program);
        }
        while (program!=1 && program!=2 && program!=3 && program!=4);
        if (program==1) // Counting Sum (DKR 1)
            sum_count ();
        else if (program==2) // Finding bigger value on and below the main diagonal of quadratic matrix (DKR 2)
        {
            int N = matrix_size();
            int** A = matrix_make (N);
            char auto_fill;
            do
            {
                printf("\t\tTo auto-fill, or not?\tY/N\t");
                scanf(" %c", &auto_fill);
            }
            while (auto_fill!='y' && auto_fill!='Y' && auto_fill!='n' && auto_fill!='N');
            // filling matrix with stuff
            if (auto_fill=='y' || auto_fill=='Y')
                matrix_autofill (A, N);
            else if (auto_fill=='n' || auto_fill=='N')
                matrix_manualfill (A, N);
            //system("cls");
            matrix_print (A, N); // printing matrix
            int increment = 1, max=0, i=0, j=0;
            matrix_find_bigger_values_below_main_diagonal (A, N, &increment, &max, &i, &j); // looking for bigger numbers on and below main diagonal
            matrix_print_bigger_values (A, N, &increment, &max, &i, &j); // actually printing out all the numbers based on info from the last function
            matrix_clear (A, N);
        }
        else if (program==3) // Listing TOP 8 letters in a file
            top_eight_letters_in_file();
    }
    return 0;
}
