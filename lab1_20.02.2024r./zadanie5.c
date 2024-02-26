#include <stdio.h>

int main()
{
    int max;
    printf("Podaj ograniczenie: ");
    scanf("%d", &max);
    printf("%d", liczby(max));
    
    return 0;
}

int liczby(int max)
{
    int wynik;
    if(max<=0) wynik = 0;
    else
    {
        for(int i = 1; i<max; i++)
        {
            if(i%3==0 && i%5==0) wynik +=i;
            else if(i%5==0) wynik+=i;
            else if(i%3==0) wynik+=i;
        }
    }
    return wynik;
}
