#include <stdio.h>

typedef struct
{
    char * imie;
    double ocena;

} Student;

Student* bubblesort(Student* stud, int rozmiar)
{
    for(int i = 0; i<rozmiar-1; i++)
    {
        for(int j = 0; j<rozmiar-1; j++)
        {
            if(stud[i].ocena>=stud[i+1].ocena)
            {
                Student tymczas = stud[i];
                stud[i] = stud[i+1];
                stud[i+1] = tymczas;
            }
        }
    }
    return stud;
}


int main()
{
    Student tabStudentow[100];

    tabStudentow[0].imie = "Piotr";
    tabStudentow[0].ocena = 5;
    tabStudentow[1].imie = "Damian";
    tabStudentow[1].ocena = 4.5;
    tabStudentow[2].imie = "Marcin";
    tabStudentow[2].ocena = 4;
    tabStudentow[3].imie = "Adam";
    tabStudentow[3].ocena = 4;
    tabStudentow[4].imie = "Dominika";
    tabStudentow[4].ocena = 5;
    tabStudentow[5].imie = "Martyna";
    tabStudentow[5].ocena = 3;
    tabStudentow[6].imie = "Robert";
    tabStudentow[6].ocena = 3.5;
    tabStudentow[7].imie = "Łukasz";
    tabStudentow[7].ocena = 3;
    tabStudentow[8].imie = "Paweł";
    tabStudentow[8].ocena = 4;
    tabStudentow[9].imie = "Jan";
    tabStudentow[9].ocena = 2;
    tabStudentow[10].imie = "Patrycja";
    tabStudentow[10].ocena = 4;
    tabStudentow[11].imie = "Piotr";
    tabStudentow[11].ocena = 3.5;
    tabStudentow[12].imie = "Jakub";
    tabStudentow[12].ocena = 4.5;
    tabStudentow[13].imie = "Piotr";
    tabStudentow[13].ocena = 5;
    tabStudentow[14].imie = "Mateusz";
    tabStudentow[14].ocena = 5;
    tabStudentow[15].imie = "Damian";
    tabStudentow[15].ocena = 4.5;
    tabStudentow[16].imie = "Andrzej";
    tabStudentow[16].ocena = 4;
    tabStudentow[17].imie = "Anna";
    tabStudentow[17].ocena = 2;
    tabStudentow[18].imie = "Mateusz";
    tabStudentow[18].ocena = 3;
    tabStudentow[19].imie = "Adam";
    tabStudentow[19].ocena = 4.5;
    tabStudentow[20].imie = "Izabela";
    tabStudentow[20].ocena = 4.5;
    tabStudentow[21].imie = "Izabela";
    tabStudentow[21].ocena = 5;
    tabStudentow[22].imie = "Dorota";
    tabStudentow[22].ocena = 3.5;
    tabStudentow[23].imie = "Krzysztof";
    tabStudentow[23].ocena = 5;
    tabStudentow[24].imie = "Magdalena";
    tabStudentow[24].ocena = 3.5;
    tabStudentow[25].imie = "Tomasz";
    tabStudentow[25].ocena = 2;
    tabStudentow[26].imie = "Monika";
    tabStudentow[26].ocena = 2;
    tabStudentow[27].imie = "Robert";
    tabStudentow[27].ocena = 5;
    tabStudentow[28].imie = "Adam";
    tabStudentow[28].ocena = 3;
    tabStudentow[29].imie = "Marek";
    tabStudentow[29].ocena = 2;
    tabStudentow[30].imie = "Barbara";
    tabStudentow[30].ocena = 3.5;
    tabStudentow[31].imie = "Tomasz";
    tabStudentow[31].ocena = 4;
    tabStudentow[32].imie = "Bartosz";
    tabStudentow[32].ocena = 4;
    tabStudentow[33].imie = "Bartosz";
    tabStudentow[33].ocena = 5;
    tabStudentow[34].imie = "Barbara";
    tabStudentow[34].ocena = 3;
    tabStudentow[35].imie = "Michał";
    tabStudentow[35].ocena = 3;
    tabStudentow[36].imie = "Magdalena";
    tabStudentow[36].ocena = 2;
    tabStudentow[37].imie = "Martyna";
    tabStudentow[37].ocena = 4;
    tabStudentow[38].imie = "Andrzej";
    tabStudentow[38].ocena = 5;
    tabStudentow[39].imie = "Barbara";
    tabStudentow[39].ocena = 5;
    tabStudentow[40].imie = "Marek";
    tabStudentow[40].ocena = 4.5;
    tabStudentow[41].imie = "Szymon";
    tabStudentow[41].ocena = 3;
    tabStudentow[42].imie = "Joanna";
    tabStudentow[42].ocena = 5;
    tabStudentow[43].imie = "Justyna";
    tabStudentow[43].ocena = 4;
    tabStudentow[44].imie = "Gabriela";
    tabStudentow[44].ocena = 4.5;
    tabStudentow[45].imie = "Izabela";
    tabStudentow[45].ocena = 5;
    tabStudentow[46].imie = "Ewa";
    tabStudentow[46].ocena = 4.5;
    tabStudentow[47].imie = "Dominika";
    tabStudentow[47].ocena = 5;
    tabStudentow[48].imie = "Karolina";
    tabStudentow[48].ocena = 2;
    tabStudentow[49].imie = "Łukasz";
    tabStudentow[49].ocena = 3;
    tabStudentow[50].imie = "Damian";
    tabStudentow[50].ocena = 5;
    tabStudentow[51].imie = "Aneta";
    tabStudentow[51].ocena = 2;
    tabStudentow[52].imie = "Mateusz";
    tabStudentow[52].ocena = 3.5;
    tabStudentow[53].imie = "Damian";
    tabStudentow[53].ocena = 3;
    tabStudentow[54].imie = "Jakub";
    tabStudentow[54].ocena = 2;
    tabStudentow[55].imie = "Michał";
    tabStudentow[55].ocena = 4.5;
    tabStudentow[56].imie = "Jan";
    tabStudentow[56].ocena = 2;
    tabStudentow[57].imie = "Weronika";
    tabStudentow[57].ocena = 5;
    tabStudentow[58].imie = "Emilia";
    tabStudentow[58].ocena = 5;
    tabStudentow[59].imie = "Izabela";
    tabStudentow[59].ocena = 2;
    tabStudentow[60].imie = "Robert";
    tabStudentow[60].ocena = 3;
    tabStudentow[61].imie = "Katarzyna";
    tabStudentow[61].ocena = 3.5;
    tabStudentow[62].imie = "Katarzyna";
    tabStudentow[62].ocena = 3.5;
    tabStudentow[63].imie = "Weronika";
    tabStudentow[63].ocena = 3;
    tabStudentow[64].imie = "Mateusz";
    tabStudentow[64].ocena = 4.5;
    tabStudentow[65].imie = "Krzysztof";
    tabStudentow[65].ocena = 3;
    tabStudentow[66].imie = "Barbara";
    tabStudentow[66].ocena = 4.5;
    tabStudentow[67].imie = "Aneta";
    tabStudentow[67].ocena = 4;
    tabStudentow[68].imie = "Martyna";
    tabStudentow[68].ocena = 4;
    tabStudentow[69].imie = "Monika";
    tabStudentow[69].ocena = 4;
    tabStudentow[70].imie = "Paweł";
    tabStudentow[70].ocena = 2;
    tabStudentow[71].imie = "Łukasz";
    tabStudentow[71].ocena = 3.5;
    tabStudentow[72].imie = "Dominika";
    tabStudentow[72].ocena = 5;
    tabStudentow[73].imie = "Beata";
    tabStudentow[73].ocena = 3.5;
    tabStudentow[74].imie = "Emilia";
    tabStudentow[74].ocena = 5;
    tabStudentow[75].imie = "Gabriela";
    tabStudentow[75].ocena = 4;
    tabStudentow[76].imie = "Karol";
    tabStudentow[76].ocena = 4;
    tabStudentow[77].imie = "Maria";
    tabStudentow[77].ocena = 3;
    tabStudentow[78].imie = "Olga";
    tabStudentow[78].ocena = 3.5;
    tabStudentow[79].imie = "Piotr";
    tabStudentow[79].ocena = 2;
    tabStudentow[80].imie = "Dominika";
    tabStudentow[80].ocena = 2;
    tabStudentow[81].imie = "Paweł";
    tabStudentow[81].ocena = 5;
    tabStudentow[82].imie = "Adam";
    tabStudentow[82].ocena = 3.5;
    tabStudentow[83].imie = "Robert";
    tabStudentow[83].ocena = 4;
    tabStudentow[84].imie = "Dorota";
    tabStudentow[84].ocena = 3;
    tabStudentow[85].imie = "Olga";
    tabStudentow[85].ocena = 4;
    tabStudentow[86].imie = "Aleksandra";
    tabStudentow[86].ocena = 2;
    tabStudentow[87].imie = "Marcin";
    tabStudentow[87].ocena = 3.5;
    tabStudentow[88].imie = "Patrycja";
    tabStudentow[88].ocena = 4;
    tabStudentow[89].imie = "Marek";
    tabStudentow[89].ocena = 3;
    tabStudentow[90].imie = "Joanna";
    tabStudentow[90].ocena = 3;
    tabStudentow[91].imie = "Kinga";
    tabStudentow[91].ocena = 4;
    tabStudentow[92].imie = "Marcin";
    tabStudentow[92].ocena = 4;
    tabStudentow[93].imie = "Szymon";
    tabStudentow[93].ocena = 3.5;
    tabStudentow[94].imie = "Paweł";
    tabStudentow[94].ocena = 2;
    tabStudentow[95].imie = "Krzysztof";
    tabStudentow[95].ocena = 3.5;
    tabStudentow[96].imie = "Jan";
    tabStudentow[96].ocena = 3;
    tabStudentow[97].imie = "Weronika";
    tabStudentow[97].ocena = 4;
    tabStudentow[98].imie = "Kamila";
    tabStudentow[98].ocena = 3.5;
    tabStudentow[99].imie = "Marcin";
    tabStudentow[99].ocena = 3.5;

    int rozmiar = sizeof(tabStudentow)/sizeof(tabStudentow[0]);
    Student* nowaTabStud = bubblesort(tabStudentow, rozmiar);

    for(int i = 0; i<100; i++){
        printf("%s: %.1f\n", nowaTabStud[i].imie, nowaTabStud[i].ocena);
    }

    return 0;
}
