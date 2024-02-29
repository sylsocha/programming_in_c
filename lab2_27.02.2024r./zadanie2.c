#include <stdio.h>
#include <stdlib.h>

float doubled(float *x)
{
    return 2**x;
}

int main()
{
    float x = 3.1415;
    printf("2x = %f", doubled(&x));
    
  return 0;
}
