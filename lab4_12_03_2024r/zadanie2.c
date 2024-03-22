#include <stdio.h>

int bin(int* tab, int szukaj, int poczatek, int koniec){
    int x = (poczatek + koniec)/2;

    if(szukaj<tab[poczatek] || szukaj>tab[koniec-1]){
        return -1;
    }
    else if(szukaj == tab[x]){
        return x;
    }
    else if(szukaj > tab[x]){
        return bin(tab, szukaj, x, koniec);
    } else
        return bin(tab, szukaj, poczatek, x);
}

int main(){
    int tab[10];
    for(int i = 0; i<10; i++){
        tab[i] = i*i;
    }
    int szukaj = 9;
    printf("%d", bin(tab, szukaj, 0, sizeof(tab)/sizeof(tab[0])));
    return 0;
}
