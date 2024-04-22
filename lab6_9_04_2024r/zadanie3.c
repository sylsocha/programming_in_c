#include <stdio.h>
#include <stdlib.h>

int sum(int *a, int *b){
    return (*a + *b);
}

int multi(int *a, int *b){
    return (*a * *b);
}

int sub(int *a, int *b){
    return (*a - *b);
}

int main(){

    int (*act)(int*, int*);
    int num, a, b;
    printf("Podaj numer dzialania, ktore chcesz wykonać:\n1. dodawanie\n2. odejmowanie\n3. mnozenie\n");
    scanf("%d", &num);
    printf("Podaj liczby, na ktorych chcesz dokonac dzialania:\n");
    scanf("%d %d", &a, &b);

    switch (num) {
        case 1:
            act = &sum;
            break;
        case 2:
            act = &sub;
            break;
        case 3:
            act = &multi;
            break;
    }

    printf("Wynik dzialania to: %d", (*act)(&a, &b));

    return 0;
}
