#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
#include <utility>

class Wers{
public:
    std::string line;
    int sets_count{};
    int * red{};      //czerwone kostki w każdym secie
    int * green{};    //zielone kostki w każdym secie
    int * blue{};     //niebieskie kostki w każdym secie
    int * max[3]{};


public:
    explicit Wers(std::string ln) {
        line = std::move(ln);
        sets_count = 0;
    }

    void sets(){
        for(int j = 0; line[j] != '\0'; j++){
            if(line[j] == ';'){    //poszczególne sety
                sets_count++;
            }
        }
        sets_count++;
    }

    void rgb_in_set(){
        int j = 0;
        for(int i = 0; line[i] != '\0'; i++){
            if(isdigit(line[i]) && isdigit(line[i+1])){   //gdy liczba kostek jest dwucyfrowa
                switch (line[i+3]){  //litera od której zaczyna się słowo po danej liczbie
                    case 'r':
                        red[j] = (line[i] - '0')*10 + (line[i+1] - '0');
                        i++;
                        break;
                    case 'g':
                        green[j] = (line[i] - '0')*10 + (line[i+1]  - '0');
                        i++;
                        break;
                    case 'b':
                        blue[j] = (line[i] - '0')*10 + (line[i+1]  - '0');
                        i++;
                        break;
                }
            }
            else if(isdigit(line[i])){   //gdy liczba kostek jest jednocyfrowa
                switch (line[i+2]){  //litera od której zaczyna się słowo po danej cyfrze
                    case 'r':
                        red[j] = line[i] - '0';
                        break;
                    case 'g':
                        green[j] = line[i] - '0';
                        break;
                    case 'b':
                        blue[j] = line[i] - '0';
                        break;
                }
            }
            if(line[i] == ';'){  //przejście do następnego seta
                j++;
            }
        }
    }

    void maxes(){
        for(int j = 1; j < sets_count; j++){
            if(red[j] > *max[0]){
                max[0] = &red[j];
            }
            if(green[j] > *max[1]){
                max[1] = &green[j];
            }
            if(blue[j] > *max[2]){
                max[2] = &blue[j];
            }
        }
    }
};




int main(){

    int liczba_gier = 100;
    int wynik = 0;
    Wers * tab_wers[liczba_gier];
    int moc = 0;

    int czerw = 12;
    int ziel = 13;
    int nieb = 14;
    int mozliwe_gry[liczba_gier];

    try {
        const char *path = R"(C:\Users\no.2\Desktop\schools_are_for_fools\studies\ue\sem4\c v cpp\ccpp\lab7_16_04_2024r\zad_2_dane.txt)";
        std::ifstream file(path);
        if (!file) throw std::runtime_error("Nie mozna otowrzyc pliku");

        std::string line;
        for (int i = 0; i < liczba_gier; i++) {
            if (std::getline(file, line)) {
                tab_wers[i] = new Wers(line);

                tab_wers[i]->sets();

                tab_wers[i]->red = new int[tab_wers[i]->sets_count];
                tab_wers[i]->green = new int[tab_wers[i]->sets_count];
                tab_wers[i]->blue = new int[tab_wers[i]->sets_count];

                for(int j = 0; j < tab_wers[i]->sets_count; j++){
                    tab_wers[i]->red[j] = 0;
                    tab_wers[i]->green[j] = 0;
                    tab_wers[i]->blue[j] = 0;
                }

                tab_wers[i]->rgb_in_set();

                mozliwe_gry[i] = i+1;

                for(int j = 0; j < tab_wers[i]->sets_count; j++){
                    if(tab_wers[i]->red[j] > czerw || tab_wers[i]->green[j] > ziel || tab_wers[i]->blue[j] > nieb){
                        mozliwe_gry[i] = -1;
                    }
                }

                if(mozliwe_gry[i] != -1){
                    wynik += mozliwe_gry[i];
                }

                //CZĘŚC DRUGA ZADANIA

                tab_wers[i]->max[0] = &tab_wers[i]->red[0];
                tab_wers[i]->max[1] = &tab_wers[i]->green[0];
                tab_wers[i]->max[2] = &tab_wers[i]->blue[0];

                tab_wers[i]->maxes();

                moc += *tab_wers[i]->max[0] * *tab_wers[i]->max[1] * *tab_wers[i]->max[2];
            }
            else {
                break;
            }
        }

        for (int i = 0; i < liczba_gier; i++) {
            delete tab_wers[i];
        }
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout<<"Suma numerow dopuszczalnych gier: "<<wynik<<std::endl;

    std::cout<<"Moc wszytskich minimalnych zestawow to: "<<moc<<std::endl;

    return 0;
    //wynik_part1 = 3035
    //wynik_part2= 66027
}

