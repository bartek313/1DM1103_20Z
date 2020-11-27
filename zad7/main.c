#include "wczytywanie.h"
#include "operacje_matematyczne.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

char * zwrocArg(int nr, int argc, char *argv[]);

int main(int argc, char *argv[])
{
  char *opNazwa;
  FILE * fin;
  struct Macierz m1, m2, m3;
  int opPoz = 0; // opPoz > 0 oznacza żądanie wypisania macierzy i jednocześnie podaje pozycje nazwy pliku wynikowe na liście argumentów
  char *nazwaOpt = 0;
  opNazwa = zwrocArg(1, argc, argv);
  if (opNazwa == 0)
    exit(0);

  char *nazwa1 = zwrocArg(2, argc, argv);
  if (nazwa1 == 0)
    exit(0);

  fin = fopen(nazwa1, "r");
  wczytaj(fin, &m1);

  if (!strcmp(opNazwa, "sum"))
  {
    char *nazwa2 = zwrocArg(3, argc, argv);
    if (nazwa2 == 0)
      exit(0);

    fin = fopen(nazwa2, "r");
    wczytaj(fin, &m2);

    suma(m1, m2, &m3);

    opPoz = 4;
  }
  else if (!strcmp(opNazwa, "substract"))
  {
    char *nazwa2 = zwrocArg(3, argc, argv);
    if (nazwa2 == 0)
      exit(0);

    fin = fopen(nazwa2, "r");
    wczytaj(fin, &m2);

    substract(m1, m2, &m3);

    opPoz = 4;
  }
  else if (!strcmp(opNazwa, "prod"))
  {
    char *nazwa2 = zwrocArg(3, argc, argv);
    if (nazwa2 == 0)
      exit(0);

    fin = fopen(nazwa2, "r");
    wczytaj(fin, &m2);

    prodWektorowy(m1, m2, &m3);

    opPoz = 4;
  }
  else if (!strcmp(opNazwa, "multiply"))
  {
    char *number = zwrocArg(3, argc, argv);
    multiply(m1, atof(number), &m3);
    opPoz = 4;
  }
  else if (!strcmp(opNazwa, "norm"))
  {
      printf( "Norma macierzy = %f\n", norm(m1));
      //opPoz = 0; - nie trzeba tego robić, bo opPoz jest zainicjowane zerem
  }
  else
  {
    printf("Nieznana operacja!\n");
    exit(0);
  }

  if (opPoz > 0) //oznacza żądanie wypisania macierzy
  {
    char *nazwaOpt = zwrocArg(opPoz, argc, argv);
    if (nazwaOpt == 0)
    {
      wypisz(m3); //na ekran, gdy nie ma podanego pliku wyjściowe
    }
    else
    {
      zapisz(nazwaOpt, m3); //do pliku wyjściowego
    }
  }

  return 0;
}
//definicje funkcji
char * zwrocArg(int nr, int argc, char *argv[])
{
  char *arg = 0;
  if (nr < argc)
  {
    arg = (char*) malloc(strlen(argv[nr])); //pamiec zarezerwona globalnie
    if (arg != 0)
      strcpy(arg, argv[nr]);
  }

  return arg; //zwraca wartość wskaźnika
}
