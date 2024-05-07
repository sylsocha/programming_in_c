#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct node{    //każda poszczególna gra
    int game_num;
    char * line;
    int sets_count;
    int * red;      //czerwone kostki w każdym secie
    int * green;    //zielone kostki w każdym secie
    int * blue;     //niebieskie kostki w każdym secie
    int * max[3];
    struct node * next;
}node_t;

void rgb_in_set(node_t * n){
    int j = 0;
    for(int i = 0; i< strlen(n->line); i++){
        if(isdigit(n->line[i]) && isdigit(n->line[i+1])){   //gdy liczba kostek jest dwucyfrowa
            switch (n->line[i+3]){  //litera od której zaczyna się słowo po danej liczbie
                case 'r':
                    n->red[j] = (n->line[i] - '0')*10 + (n->line[i+1] - '0');
                    i++;
                    break;
                case 'g':
                    n->green[j] = (n->line[i] - '0')*10 + (n->line[i+1]  - '0');
                    i++;
                    break;
                case 'b':
                    n->blue[j] = (n->line[i] - '0')*10 + (n->line[i+1]  - '0');
                    i++;
                    break;
            }
        }
        else if(isdigit(n->line[i])){   //gdy liczba kostek jest jednocyfrowa
            switch (n->line[i+2]){  //litera od której zaczyna się słowo po danej cyfrze
                case 'r':
                    n->red[j] = n->line[i] - '0';
                    break;
                case 'g':
                    n->green[j] = n->line[i] - '0';
                    break;
                case 'b':
                    n->blue[j] = n->line[i] - '0';
                    break;
            }
        }
        if(n->line[i] == ';'){  //przejście do następnego seta
            j++;
        }
    }
}

int main(){

    FILE * file;
    int liczba_gier = 0;
    int wynik = 0;

    // Otwarcie pliku
    file = fopen("lab7_16_04_2024r/zad_2_dane.txt", "r");
    if(file == NULL)
    {
        printf("Nie mozna otowrzyc pliku\n");
        return -1;
    }
    else printf("Plik otwarto pomyslnie\n");

    node_t * head = (node_t*) malloc(sizeof (node_t));
    head->line = (char*)malloc(sizeof(char) * 200); // max dlugość linijki == 200 znaków
    head->next = NULL;

    node_t * current = head;
    while(fgets(current->line, 200, file) != NULL){
        liczba_gier++;
        //alokacja pamięci dla kolejnego noda
        current->next = (node_t *)malloc(sizeof(node_t));
        current->next->line = (char *)malloc(sizeof(char) * 200);
        current->next->next = NULL;
        current = current->next;
    }

    current = head;

    while(current->next!= NULL){    //wczytanie poszczególnych linii
        current->sets_count = 0;
        for(int i = 0;  i < strlen(current->line); i++){
            if(current->line[i] == ';'){
                current->sets_count++;
            }
        }
        current->sets_count++;
        current = current->next;
    }

    current = head;

    while(current->next != NULL){
        current->red = (int*) malloc(sizeof(int) * current->sets_count);
        current->green = (int*) malloc(sizeof(int) * current->sets_count);
        current->blue = (int*) malloc(sizeof(int) * current->sets_count);

        for(int i = 0; i < current->sets_count; i++){
            current->red[i] = 0;
            current->green[i] = 0;
            current->blue[i] = 0;
        }

        char * line = current->line;

        for(int i = 0; i <= strlen(line); i++){ //odczytanie numeru gry
            if(isdigit(line[5]) && line[8] == ':'){
                current->game_num = (line[5] - '0')*100 + (line[6] - '0')*10 + (line[7] - '0');
            }
            if(isdigit(line[5]) && line[7] == ':'){
                current->game_num = (line[5] - '0')*10 + (line[6] - '0');
            }
            if(isdigit(line[5]) && line[6] == ':'){
                current->game_num = line[5] - '0';
            }
        }
        rgb_in_set(current);    //odczytanie wartości rgb dla każdego setu w grze
        current = current->next;
    }

    int czerw = 12;
    int ziel = 13;
    int nieb = 14;
    int * mozliwe_gry = (int*) malloc(sizeof (int) * liczba_gier);

    current = head;

    for(int j = 0; j < liczba_gier; j++){   //wyznaczenie dopuszczlnych gier
        mozliwe_gry[j] = current->game_num;
        for(int i = 0; i < current->sets_count; i++){
            if(current->red[i] > czerw || current->green[i] > ziel || current->blue[i] > nieb){
                mozliwe_gry[j] = -1;
            }
        }
        if(mozliwe_gry[j] != -1){
            wynik += mozliwe_gry[j];
        }
        current = current->next;
    }

    printf("Suma numerow dopuszczalnych gier: %d\n", wynik);

    /*
     * CZĘŚC DRUGA ZADANIA
     */

    current = head;

    int moc = 0;
    
    while (current->next != NULL){
        current->max[0] = &current->red[0];
        current->max[1] = &current->green[0];
        current->max[2] = &current->blue[0];

        for(int i = 1; i < current->sets_count; i++){
            if(current->red[i] > *current->max[0]){
                current->max[0] = &current->red[i];
            }
            if(current->green[i] > *current->max[1]){
                current->max[1] = &current->green[i];
            }
            if(current->blue[i] > *current->max[2]){
                current->max[2] = &current->blue[i];
            }
        }

        moc += *current->max[0] * *current->max[1] * *current->max[2];

        current = current->next;
    }

    printf("Moc wszytskich minimalnych zestawow to: %d", moc);

    return 0;
}
