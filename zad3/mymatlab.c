#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Macierz
{
    int r;
    int c;
    float tab[200][200];
};

//deklaracje funkcji
char * zwrocArg(int nr, int argc, char *argv[]);
void wczytaj(FILE * fin, struct Macierz *m);
void zapisz(char nazwa[], struct Macierz m);
void wypisz(struct Macierz m);

void suma(struct Macierz m1, struct Macierz m2, struct Macierz *m3);
void substract(struct Macierz m1, struct Macierz m2, struct Macierz *m3);
float prodSkalarny(struct Macierz m1, struct Macierz m2);
void prodWektorowy(struct Macierz m1, struct Macierz m2, struct Macierz *m3);
void multiply(struct Macierz m1, float a, struct Macierz *m3);
float norm(struct Macierz m1);

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

void wczytaj(FILE * fin, struct Macierz *m) {
    int i,j;
    fscanf(fin, "%d", &(*m).r);
    fscanf(fin, "%d", &(*m).c);

    for (i=0; i < (*m).r; i++) {
        for (j=0; j < (*m).c; j++) {
            fscanf(fin, "%f", &(*m).tab[i][j]);
        }
    }
}

void zapisz(char nazwa[], struct Macierz m) {
    FILE * fout = fopen(nazwa, "w");
    int i,j;

    fprintf(fout, "%d\n%d\n", m.r, m.c);
    for (i = 0; i < m.r; i++) {
        for (j=0; j < m.c; j++) {
            fprintf(fout, "%f\n", m.tab[i][j]);
        }
    }

    fclose(fout);
}

void wypisz(struct Macierz m) {
    int i, j;
    printf("[ ");
    for (i = 0; i < m.r; i++) {
        for (j=0; j < m.c; j++) {
            printf("%5.1f ", m.tab[i][j]);
        }
        if (i < (m.r-1))
            printf("\n  ");
    }
    printf("]\n");
}

float norm(struct Macierz m) {
    float s = 0;
    int i,j;

    for (i = 0; i < m.r; i++) {
        for (j=0; j < m.c; j++) {
            s += m.tab[i][j] * m.tab[i][j];
        }
    }
    return sqrt(s);
}

void suma(struct Macierz m1, struct Macierz m2, struct Macierz *m3) {
    int i,j;
    if (m1.c != m2.c || m1.r != m2.r)
    {
      printf("Złe rozmiary macierzy przy dodawaniu!\n");
      exit(0);
    }

    m3->r = m1.r;
    m3->c = m1.c;
    for (i = 0; i < m3->r; i++) {
        for (j=0; j < m3->c; j++) {
          m3->tab[i][j] = m1.tab[i][j] + m2.tab[i][j];
        }
    }
}

void substract(struct Macierz m1, struct Macierz m2, struct Macierz *m3) {
    int i,j;

    if (m1.c != m2.c || m1.r != m2.r)
    {
      printf("Złe rozmiary macierzy przy odejmowaniu!\n");
      exit(0);
    }

    m3->r = m1.r;
    m3->c = m1.c;
    for (i = 0; i < m3->r; i++) {
        for (j=0; j < m3->c; j++) {
          m3->tab[i][j] = m1.tab[i][j] - m2.tab[i][j];
        }
    }
}

float prodSkalarny(struct Macierz m1, struct Macierz m2) {
    float s = 0;
    int i,j;

    if (m1.c != m2.c || m1.r != m2.r)
    {
      printf("Złe rozmiary macierzy w iloczynie skalarnym!\n");
      exit(0);
    }

    for (i = 0; i < m2.r; i++) {
        for (j=0; j < m2.c; j++) {
          s += m1.tab[i][j] * m2.tab[i][j];
        }
    }
}

void prodWektorowy(struct Macierz m1, struct Macierz m2, struct Macierz *m3) {
    float s = 0;
    int i,j,k;
    m3->r = m1.r;
    m3->c = m2.c;
    if (m1.c != m2.r)
    {
      printf("Złe rozmiary macierzy w iloczynie wektorowym!\n");
      exit(0);
    }
    //najpierw inicjalizacja macierzy wynikowej
    for (i = 0; i < m3->r; i++) {
        for (j=0; j < m3->c; j++) {
          m3->tab[i][j] = 0.0;
        }
    }
    for (i = 0; i < m3->r; i++) {
        for (j=0; j < m3->c; j++) {
            for (k=0; k < m2.c; k++){
              m3->tab[i][j] += m1.tab[i][k] * m2.tab[k][j];
            }
        }
    }
}

void multiply(struct Macierz m1, float a, struct Macierz *m3){
    int i,j;

    m3->r = m1.r;
    m3->c = m1.c;
    for (i = 0; i < m3->r; i++) {
        for (j=0; j < m3->c; j++) {
          m3->tab[i][j] = a * m1.tab[i][j];
        }
    }
}