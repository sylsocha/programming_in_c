#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    char figury[3][10] = {"kamień", "papier", "nożyce"};
    int rundy;
    int wyniki = 3;
    
    printf("Ile rund chcesz rozegrać? ");
    scanf("%d", &rundy);
    
    int *tab_wyniki = malloc(rundy * sizeof(int));
    
    srand(time(NULL));
    
    for(int i=0;i<rundy;i++){
        char los = rand();
        printf("%d\n", los);
    }
    
    return 0;
}
