#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "wczytywanie.h"

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
    m3->tab = (float**) malloc(sizeof(float*) * m3->r);
    for(i = 0; i < m3->r; i++)
    {
        m3->tab[i] = (float*) malloc(sizeof(float) * m3->c);
    }

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
    m3->tab = (float**) malloc(sizeof(float*) * m3->r);
    for(i = 0; i < m3->r; i++)
    {
        m3->tab[i] = (float*) malloc(sizeof(float) * m3->c);
    }

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
    
    m3->tab = (float**) malloc(sizeof(float*) * m3->r);
    for(i = 0; i < m3->r; i++)
    {
        m3->tab[i] = (float*) malloc(sizeof(float) * m3->c);
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
    m3->tab = (float**) malloc(sizeof(float*) * m3->r);
    for(i = 0; i < m3->r; i++)
    {
        m3->tab[i] = (float*) malloc(sizeof(float) * m3->c);
    }

    for (i = 0; i < m3->r; i++) {
        for (j=0; j < m3->c; j++) {
          m3->tab[i][j] = a * m1.tab[i][j];
        }
    }
}