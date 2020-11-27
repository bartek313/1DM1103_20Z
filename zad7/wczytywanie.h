#ifndef wczytywanie.h
#define wczytywanie.h
#include <stdio.h>
#include <stdlib.h>

struct Macierz
{
    int r;
    int c;
    float **tab;
};

void zwolnij(struct Macierz *m);
void wczytaj(FILE * fin, struct Macierz *m);
void zapisz(char nazwa[], struct Macierz m);
void wypisz(struct Macierz m);

#endif