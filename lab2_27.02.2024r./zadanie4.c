#include <stdio.h>

typedef struct
{
    char * imie;
    double ocena;

} Student;

float quicksort()
{
    return 0;
}

int main()
{
    Student tabStudentow[100];
    for(int i = 0; i<100; i++)
    {
        tabStudentow[i].imie = "Anna";
        tabStudentow[i].ocena = 3.5;
    }

    printf("%s", tabStudentow[0].imie);

    return 0;
}
