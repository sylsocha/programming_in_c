#include <stdio.h>

int main(){

    int tab[10];

    for(int i = 0; i<10; i++){
        tab[i] = i;
    }

    for( int *i = &tab[0]; i<=&tab[9]; i++){
        printf("address: %x,  value: %d\n", i, *i);
    }

    return 0;
}
