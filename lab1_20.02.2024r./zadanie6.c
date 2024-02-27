#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    char figury[3][7] = {"kamień", "papier", "nożyce"};
    int rundy;
    int wyniki = 3;
    char komputer;
    char gracz[7];
    
    printf("Ile rund chcesz rozegrać? ");
    scanf("%d", &rundy);
    
    int *tab_wyniki = malloc(rundy * sizeof(int));
    
    srand(time(NULL));
    
    for(int i=0;i<rundy;i++){
        unsigned char los = rand();
        printf("%d\n", los%3);
        komputer = los%3;
        
        printf("Podaj swoją figurę: ");
        scanf("%s", gracz);
        
        switch(gracz)
        {
            case 
        }
    }
    
    return 0;
}
