#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x = 2;
    int * pX = &x;
    
    *pX *= 10;
    
    printf("Bezpośrednio: %d\n", x);
    printf("Pośrednio przez wskaźnik: %d", *pX);

  return 0;
}
