#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void top_eight_letters_in_file()
{
    FILE* text_file = fopen("text.txt", "r");
    if (text_file==NULL)
    {
        printf("File doesn't exist in current directory. Please, create text.txt and put something in.");
        exit(0);
    }
    const char number_of_letters = 26;
    unsigned int N=0, d=NULL, C[2][number_of_letters*2];
    while (d!=EOF) // getting the number of characters in file, before it reaches the End Of File
    {
        d = getc(text_file);
        N++;
        if (d==10) // for some reason, if the character is LF (10), it won't increment N. But at the same time, it's somehow stored inside the array... Even though array's suppose to be smaller. \o/
            N++;
    }
    N--;
    rewind (text_file);
    char A[N];
    for (int i=0; i<N; i++) // writing all the characters into array, using info from previous run. Efficient? No
        A[i] = getc(text_file);
    fclose (text_file);
    char printing_text_choice='u';
    do
    {
        printf("Do you want to see your text in console as well?\tY/N\t");
        scanf(" %c", &printing_text_choice);
    }
    while (printing_text_choice!='y' && printing_text_choice!='Y' && printing_text_choice!='n' && printing_text_choice!='N');
    switch (printing_text_choice)
    {
        case 89:
        case 121:
            for (int i=0; i<N; i++) // printing all the text, dunno why...
            {
            if (A[i]!=10)
                printf("%c", A[i]);
            else
                getchar();
            }
            break;
        case 78:
        case 110:
            break;
    }
    printf("\n\nYour text is %u symbols long\n\n", N);
    for (int i=0; i<number_of_letters; i++) // filling a look-up array with ASCII symbols and 0es
    {
        C[0][i] = 65 + i;
        C[0][i+number_of_letters] = 97 + i;
        C[1][i] = 0;
        C[1][i+number_of_letters] = 0;
    }
    for (int i=0; i<N; i++) // comparing look-up array to text-array. If letter is matched - great!
        for (int j=0; j<number_of_letters*2; j++)
            if (A[i]==C[0][j])
                C[1][j]+=1;
    for (int i=0; i<number_of_letters*2; i++) // sorting lookup array in the most inefficient way possible.
        for (int j=1, temp=0; j<number_of_letters*2; j++)
            if (C[1][j]>C[1][j-1])
            {
                temp = C[1][j];
                C[1][j] = C[1][j-1];
                C[1][j-1] = temp;
                temp = C[0][j];
                C[0][j] = C[0][j-1];
                C[0][j-1] = temp;
            }
    int choice=0;
    do // printing all this mess in 1/2 ways.
    {
        printf("What do you want, exactly?\n\t1.TOP 8 Letters in your file.\n\t2.Letter frequency of your file.\n");
        scanf(" %d", &choice);
    }
    while (choice!=1 && choice!=2 && choice!=8 && choice!=52 && choice!=26);
    switch (choice)
    {
        case 1:
        case 8:
            for (int i = 0; i<8; i++)
            {
                if (C[1][0]==0)
                {
                    printf("Your file doesn't have any latin character");
                    break;
                }
                else if (i==0)
                    printf("\nTOP 8 Letters in your file:\n");
                if (C[1][i]>2)
                    printf("Letter #%d: %c, it's been here %u times.\n", i+1, C[0][i], C[1][i]);
                else if (C[1][i]==2)
                    printf("Letter #%d: %c, it's been here twice.\n", i+1, C[0][i]);
                else if (C[1][i]==1)
                    printf("Letter #%d: %c, it's been here only once.\n", i+1, C[0][i]);
                else if (C[1][i]==0)
                    {
                        printf("Couldn't find any other letter.");
                        break;
                    }
            }
            break;
        case 2:
        case 52:
        case 26:
            for (int i = 0; i<number_of_letters*2; i++)
            {
                if (C[1][0]==0)
                {
                    printf("Your file doesn't have any latin character");
                    break;
                }
                else if (i==0)
                    printf("\nLetter frequency of your file:\n");
                if (C[1][i]>2)
                    printf("Letter #%d: %c, it's been here %u times.\n", i+1, C[0][i], C[1][i]);
                else if (C[1][i]==2)
                    printf("Letter #%d: %c, it's been here twice.\n", i+1, C[0][i]);
                else if (C[1][i]==1)
                    printf("Letter #%d: %c, it's been here only once.\n", i+1, C[0][i]);
                else if (C[1][i]==0)
                    {
                        printf("Couldn't find any other letter.");
                        break;
                    }
                if ((i+1)%13==0 && i!=0 && i+1!=number_of_letters*2)
                    system("pause");
            }
            break;
    }
}
