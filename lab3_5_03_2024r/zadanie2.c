#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

int main()
{
    int wiersze, kolumny;
    printf("Podaj liczbe wierszy");
    scanf("%d", &wiersze);
    printf("Podaj liczbe kolumn");
    scanf("%d", &kolumny);

    int **macierz = (int **) malloc(wiersze * sizeof(int *));

    for(int i = 0; i <wiersze; i++)
    {
        macierz[i] = (int *) malloc(kolumny * sizeof(int));
        for(int j = 0; j<kolumny; j++)
        {
           macierz[i][j] = rand();
        }
    }

    for(int i = 0; i <wiersze; i++)
    {
        for(int j = 0; j<kolumny; j++)
        {
            printf("%d ", macierz[i][j]);
        }
        printf("\n");
    }

    free(macierz);
    return 0;
}
