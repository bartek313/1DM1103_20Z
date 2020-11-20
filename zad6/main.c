#include "dziekanat.h"
#include "studenci.h"


int main(int argc, char ** argv) 
{
    student dane[100];
    int ile;
    // dane == &dane[0]
    ile = wczytaj(dane, argv[1]);
    wypisz(dane, ile);
    najlepszy_student(dane,ile);
    najtrudniejszy_przedmiot(dane,ile);
    najlatwiejszy_przedmiot(dane,ile);
    return 0;
}