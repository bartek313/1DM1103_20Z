#ifndef studenci_h     
#define studenci_h

typedef struct _student {
    char imie[25];
    char nazwisko[50];
    char nr_albumu[10];
    char kod_przed[10];
    char nazwa_przed[255];
    float ocena;
    int ects;
} student, *pstudent;

int wczytaj(student dane[100], char *fnazwa);

void wypisz(student dane[100], int n);

int znajdz(char *szukany_nr, char kod_przedmiotu[100][10], int n);

int znajdz_studentow(char nr_albumow[100][10], student dane[100], int n);

int znajdz_przedmiot(char kod_przed[100][10], student dane[100], int n);

#endif