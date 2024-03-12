#include <stdio.h>
#include <malloc.h>

void Pascal(int N){
    int **tablica = (int **)malloc(N * sizeof(int *));

    for(int i = 0; i < N; i++)
    {
        tablica[i] = (int *) malloc((i+1) * sizeof(int)); // kolejny wiersz z trójkącie Pascala
        for(int j = 0; j<=i; j++)
        {
            if(j == 0 || j == i)  //elementy zewnętrzne (bok pionowy i przeciwprostokątna)
            {
                tablica[i][j] = 1;
            }
            else
            {
                tablica[i][j] = tablica[i-1][j-1] + tablica[i-1][j];  //każdy element wewnętrzny jest sumą dwóch będących nad nim
            }
            printf("%d ", tablica[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int N;

    printf("Podaj wysokosc trojata Pascala:");
    scanf("%d", &N);
    Pascal(N);
    return 0;
}
