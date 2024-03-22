#include <stdio.h>

int main()
{
    int x = 2;
    int * pX = &x;

    *pX *= 10;

    printf("Bezposrednio: %d\n", x);
    printf("Posrednio przez wskaznik: %d", *pX);

    return 0;
}
