#include <stdio.h>

int main()
{
    int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    
    int silnie[10];
    silnie[0] = array[0];
    printf("silnia %d to %d\n", array[0], silnie[0]);
    
    for(int i = 1; i<10; i++)
    {
        silnie[i] = array[i-1]*array[i];
        printf("silnia %d to %d\n", array[i], silnie[i]);
    }
    
    return 0;
}
