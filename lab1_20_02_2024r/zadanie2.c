#include <stdio.h>

int main()
{
    char grades[2][5] = {{2,5,3,4,6},{1,3,2,1,4}};
    float maths;
    float physics;
    
    for(int i = 0; i < 5; i++)
    {
        maths += grades[0][i];
        physics += grades[1][i];
    }
    
    maths/= 5;
    physics/=5;
    
    printf("Średnia z matematyki: %.2f, średnia z fizyki: %.2f", maths, physics);

    return 0;
}
