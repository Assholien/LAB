#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#define Name "Денис"
#define LastName "Коваленко"
#define GroupName "РЕ-22"
#define Faculty "РТФ"
#define University "КПІ"
#define Grade "Введіть оцінку за предмет №"

int main()
{
    SetConsoleCP (65001); // зміна кодової сторінки на UTF-8
    SetConsoleOutputCP (65001); // зміна кодової сторінки на UTF-8
    unsigned int age; // оголошення змінної
    // unsinged int age=18; Ініціалізація змінної
    unsigned int semestr;
    double admissionScore;
    double grade1;
    double grade2;
    double grade3;
    double grade4;
    double grade5;
    double averageGrade;

    printf("%s %s, виконайте наступні дії.\n", Name, LastName);
    printf("Введіть номер семестру:");
    scanf("%u", &semestr);
    printf("Введіть свій вступний бал:");
    scanf("%lf", &admissionScore);
    printf("%s1:", Grade);
    scanf("%lf", &grade1);
    printf("%s2:", Grade);
    scanf("%lf", &grade2);
    printf("%s3:", Grade);
    scanf("%lf", &grade3);
    printf("%s4:", Grade);
    scanf("%lf", &grade4);
    printf("%s5:", Grade);
    scanf("%lf", &grade5);
    printf("Введіть свій вік:");
    scanf("%u", &age);
    averageGrade = (double)(grade1 + grade2 + grade3 + grade4 + grade5) / 5;

    system("cls");
    printf("\n***************");
    printf("\n===============");
    printf("\n%s", University);
    printf("\n%s", Faculty);
    printf("\n%s", GroupName);
    printf("\n---------------");
    printf("\nСтудент: %s %s", Name, LastName );
    printf("\nВік: %u", age);
    printf("\nСеместр: %u", semestr);
    printf("\n---------------");
    printf("\nВступний бал: %.1lf", admissionScore);
    printf("\nСередня оцінка = %.2lf", averageGrade);
    printf("\n");
    return 0;
}
