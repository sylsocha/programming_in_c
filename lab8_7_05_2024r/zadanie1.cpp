#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
#include <utility>

class Wers{
public:
    std::string line;
    int digits[2]{};

public:
    explicit Wers(std::string ln) {
        line = std::move(ln);
    }
};

int cyfra(const std::string& lit, int poz){   //funkcja zwracająca 1. i ostatnią cyfrę z danej linii
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

    int wynik = 0;
    int wynik2 = 0;
    Wers * tab_wers[1000];
    int count = 0;

    // Otwarcie pliku
    try {
        const char* path = R"(C:\Users\no.2\Desktop\schools_are_for_fools\studies\ue\sem4\c v cpp\ccpp\lab7_16_04_2024r\zad_1_dane.txt)";
        std::ifstream file(path);
        if (!file) throw std::runtime_error("Nie mozna otowrzyc pliku");

        std::string line;
        for(int i = 0; i<1000; i++){
            if(std::getline(file, line)){
                tab_wers[i] = new Wers(line);
                std::cout<<tab_wers[i]->line<<std::endl;

                for (int j = 0; tab_wers[i]->line[j] != '\0'; j++) {
                    if (isdigit(tab_wers[i]->line[j])) {
                        tab_wers[i]->digits[0] = tab_wers[i]->line[j] - '0';
                        break;
                    }
                }

                for (int j = 0; tab_wers[i]->line[j] != '\0'; j++) {
                    if (isdigit(tab_wers[i]->line[j])) {
                        tab_wers[i]->digits[1] = tab_wers[i]->line[j] - '0';
                    }
                }

                wynik += tab_wers[i]->digits[0] * 10 + tab_wers[i]->digits[1];

                std::cout<<"wynik czesci pierwszej: "<<wynik<<std::endl;

                //CZĘŚC DRUGA ZADANIA

                tab_wers[i]->digits[0] = cyfra(tab_wers[i]->line, 0);
                tab_wers[i]->digits[1] = cyfra(tab_wers[i]->line, 1);

                wynik2 += tab_wers[i]->digits[0] * 10 + tab_wers[i]->digits[1];

                std::cout<<"wynik czesci drugiej: "<<wynik2<<std::endl;

                count++;
            }
            else {
                break;
            }
        }
        
        for (int i = 0; i < count; i++) {
            delete tab_wers[i];
        }
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }

  return 0;
}
