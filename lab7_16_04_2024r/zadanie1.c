#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct node {
    char * line;
    int digits[2];
    int number;
    struct node * next;
} node_t;

int cyfra(const char * lit, int poz){   //funkcja zwracająca 1. i ostatnią cyfrę z danej linii
    int zwrot = -1;

    for (int i = 0; lit[i] != '\0'; i++) {
        if (isdigit(lit[i])) {
            zwrot = lit[i] - '0';
            if(poz == 0 && zwrot != 0) {
                return zwrot;
            }
        }
        else{
            switch (lit[i]) {
                case 'z':
                    if (lit[i + 1] == 'e' && lit[i + 2] == 'r' && lit[i + 3] == 'o') {
                        zwrot = 0;
                    }
                case 'o':
                    if (lit[i + 1] == 'n' && lit[i + 2] == 'e') {
                        zwrot = 1;
                    }
                case 't':
                    if (lit[i + 1] == 'w' && lit[i + 2] == 'o') {
                        zwrot = 2;
                    } else if (lit[i + 1] == 'h' && lit[i + 2] == 'r' && lit[i + 3] == 'e' && lit[i + 4] == 'e') {
                        zwrot = 3;
                    }
                case 'f':
                    if (lit[i + 1] == 'o' && lit[i + 2] == 'u' && lit[i + 3] == 'r') {
                        zwrot = 4;
                    } else if (lit[i + 1] == 'i' && lit[i + 2] == 'v' && lit[i + 3] == 'e') {
                        zwrot = 5;
                    }
                case 's':
                    if (lit[i + 1] == 'i' && lit[i + 2] == 'x') {
                        zwrot = 6;
                    } else if (lit[i + 1] == 'e' && lit[i + 2] == 'v' && lit[i + 3] == 'e' && lit[i + 4] == 'n') {
                        zwrot = 7;
                    }
                case 'e':
                    if (lit[i + 1] == 'i' && lit[i + 2] == 'g' && lit[i + 3] == 'h' && lit[i + 4] == 't') {
                        zwrot = 8;
                    }
                case 'n':
                    if (lit[i + 1] == 'i' && lit[i + 2] == 'n' && lit[i + 3] == 'e') {
                        zwrot = 9;
                    }
            }
            if(poz == 0 && zwrot != -1) {   //jeśli ma być pierwszą cyfrą z ciągu
                return zwrot;
            }
        }
    }
    return zwrot;   //zwrot ostatniej cyfry w linijce
}

int main(){

    FILE *file;
    int line_count = 0;
    int wynik = 0;


    // Otwarcie pliku
    file = fopen("lab7_16_04_2024r/zad_1_dane.txt", "r");
    if(file == NULL)
    {
        printf("Nie mozna otowrzyc pliku\n");
        return 0;
    }
    else printf("Plik otwarto pomyslnie\n");


    node_t * head = (node_t*)malloc(sizeof(node_t));
    head->line = (char*)malloc(sizeof(char) * 100); // max dlugość linijki == 100 znaków
    head->next = NULL;

    node_t * current = head;
    while(fgets(current->line, 100, file) != NULL){

        line_count++;

        //alokacja pamięci dla kolejnego noda
        current->next = (node_t *)malloc(sizeof(node_t));
        current->next->line = (char *)malloc(sizeof(char) * 100);
        current->next->next = NULL;
        current = current->next;
    }

    current = head; // powrót do 1. noda

    while (current != NULL) {  //zczytanie pierwszej i ostatniej cyfry z każej linijki
        for (int i = 0; current->line[i] != '\0'; i++) {    //nie jest końcem linii, pierwsza cyfra w linii
            if (isdigit(current->line[i])) {
                current->digits[0] = current->line[i] - '0'; //ostatnia cyfra w linii
                break;
            }
        }

        for (int i = 0; current->line[i] != '\0'; i++) {    //nie jest końcem linii
            if (isdigit(current->line[i])) {
                current->digits[1] = current->line[i] - '0'; // konwersja z char na int
            }
        }

        current = current->next;
    }

    current = head;

    while(current != NULL){  //konwersja cyfr na liczbę zgodnie z założeniami zadania
        current->number = current->digits[0] * 10 + current->digits[1];
        current = current->next;
    }

    current = head;

    while(current != NULL){  //suma wszytskich liczb
        wynik += current->number;
        current = current->next;
    }
    printf("wynik czesci pierwszej: %d\n", wynik);

    /*
     * CZĘŚC DRUGA ZADANIA
     */
    wynik = 0;

    current = head; // powrót do 1. noda

    while (current != NULL) {  //zczytanie pierwszej i ostatniej cyfry z każdej linijki
        current->digits[0] = cyfra(current->line, 0);  //pierwsza
        current->digits[1] = cyfra(current->line, 1);  //ostatnia
        current = current->next;
    }

    current = head;

    while(current != NULL){  //konwersja jak w części pierwszej
        current->number = current->digits[0] * 10 + current->digits[1];
        current = current->next;
    }

    current = head;

    while(current != NULL){  //suma jak w części pierwszej
        wynik += current->number;
        current = current->next;
    }
    printf("wynik czesci drugiej: %d\n", wynik);

    return 0;
}
