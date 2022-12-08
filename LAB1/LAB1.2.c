#include <stdio.h>//link directive
#include <stdlib.h>
#include <Windows.h>
//double delta// global declaration, because not inside int
int main()//main function
{
    // ініціалізація declarations
    double delta, fx, x1, x2;
    unsigned int N, v;
    int i=1;
    //declarations
    // зміна кодової сторінки на UTF-8
    SetConsoleCP (65001);
    SetConsoleOutputCP (65001);

    printf("Оберіть варіант дій (введіть 1 або 2)\n1 означає вибір кількості стовпців.\n2 означає вибір кроку від x1 до x2.\n");
    scanf("%d",&v);

    // Якщо введенне значення не дорівнює 1 чи 2, опитати знову (scanf)
    while(v!= 1  &&  v!= 2) //while iteration operator
        {
        printf("Помилка. Спробуйте знову:");
        scanf("%d",&v);
        }

    if(v == 1)//operator
        {
    printf("\nВведіть x1: ");//function (instruction)
    scanf("%lf",&x1);
    printf("\nВведіть x2: ");
    scanf("%lf",&x2);
    printf("\nВведіть  N: ");
    scanf("%u",&N);
    while(x1>=x2 || N<=0)
    {
        printf("Помилка. Спробуйте знову:");
        printf("\nВведіть x1: ");//function (instruction)
        scanf("%lf",&x1);
        printf("\nВведіть x2: ");
        scanf("%lf",&x2);
        printf("\nВведіть  N: ");
        scanf("%u",&N);
    }

    printf("\n|*****|*******************|********************|");
    printf("\n|    N|\t\t\t X|\t\t   F(X)|");
    printf("\n|*****|*******************|********************|");

    delta=(x2-x1)/(N-1);
    for(i;i<=N;i++)//for iteration cycle operator
    {
    fx=0.25*x1*x1-0.25*25*2*x1+0.25*25*25+0.01*x1*x1*x1+0.01*3*x1*x1*25+0.01*3*x1*25*25+0.01*25*25*25+1;
    printf("\n|%5.0d|%19.2lf|%20.2lf|",i,x1,fx);
    x1=x1+delta;
    if(i%10==0)
    {
        printf("\n");
        system("pause");
        //getchar();
    }
    }
        }

    if(v == 2)
        {
    printf("\nВведіть x1: ");
    scanf("%lf",&x1);
    printf("\nВведіть x2: ");
    scanf("%lf",&x2);
    printf("\nВведіть крок(delta):");
    scanf("%lf",&delta);
    while(x1>=x2 && delta==x1 && delta==x2)
    {
        printf("Помилка. Спробуйте знову:");
        printf("\nВведіть x1: ");
        scanf("%lf",&x1);
        printf("\nВведіть x2: ");
        scanf("%lf",&x2);
        printf("\nВведіть крок(delta):");
        scanf("%lf",&delta);
    }

    printf("\n|*****|*******************|********************|");
    printf("\n|    N|\t\t\t X|\t\t   F(X)|");
    printf("\n|*****|*******************|********************|");
    while(x1<=x2)
    {
    fx=0.25*x1*x1-0.25*25*2*x1+0.25*25*25+0.01*x1*x1*x1+0.01*3*x1*x1*25+0.01*3*x1*25*25+0.01*25*25*25+1;
    printf("\n|%5.0d|%19.2lf|%20.2lf|",i,x1,fx);
    if(i%10==0)
    {
        printf("\n");
        system("pause");
        //getchar();
    }
    x1=x1+delta;
    i++;
    }
        }
    return 0;
}
