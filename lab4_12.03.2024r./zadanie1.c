#include <stdio.h>

int factorial(int x){

    if(x == 1){
        return x;
    }
    else if(x>1){
        return x * factorial(x-1);
    }
    return 0;
}

int main(){

    int x = 5;
    printf("silnia 5 == %d", factorial(x));

    return 0;
}
