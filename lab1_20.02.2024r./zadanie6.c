#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    char figury[3][7] = {"kamień", "papier", "nożyce"};
    int rundy;
    char komputer;
    int gracz;
    
    printf("Ile rund chcesz rozegrać? ");
    scanf("%d", &rundy);
    
    int *tab_wyniki = malloc(rundy * sizeof(int));
    
    srand(time(NULL));
    
    for(int i=0;i<rundy;i++){
        unsigned char los = rand();
        printf("%d\n", los%3);
        komputer = los%3;
        
        printf("Podaj numer swojej figury\n1 - kamień\n2 - papier\n3 - nożyce: ");
        scanf("%d", &gracz);
        gracz -=1;
        
        switch(gracz)
        {
            case 0:
                switch(komputer)
                {
                    case 0:
                    break;
                }
        }
        
    }
    
    return 0;
}
