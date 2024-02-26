#include <stdio.h>
#include <stdlib.h>

int main()
{
    char figury[3][10] = {"kamień", "papier", "nożyce"};
    int n;
    printf("Ile rund chcesz rozegrać?")
    scanf("%d", &n)
    
    float* wyniki = malloc((n+1) * sizeof(*a));
    for(int i=0;i<3;i++){
        printf("%s\n", figury[i]);
    }
    
    return 0;
}
