/**
Mamy mini bazę studentów (tabelę z studentami, przedmiotami i ocenami)
Cel: obliczyć ranking.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _student {
    char imie[25];
    char nazwisko[50];
    char nr_albumu[10];
    char kod_przed[10];
    char nazwa_przed[255];
    float ocena;
    int ects;
} student, *pstudent;

typedef struct _przedmiot {
    char nazwa[255];
    char kod[10];
    float suma_ocen;
    int liczba_ocen;
    float srednia;
} przedmiot, *pprzedmiot;

int wczytaj(student dane[100], char *fnazwa) {
    FILE * fin = fopen(fnazwa, "r");
    int cnt, i;
    char bufor[1024];
    char *w;

    fgets(bufor, 1023, fin);
    sscanf(bufor, "%d", &cnt);
 
    for (i=0; i<cnt; i++) {
        fgets(bufor, 1023, fin);
        // printf("%s", bufor);
        w = strtok(bufor, "|");
        strncpy(dane[i].imie, w, 24);

        w = strtok(NULL, "|");
        strncpy(dane[i].nazwisko, w, 49);
        
        w = strtok(NULL, "|");
        strncpy(dane[i].nr_albumu, w, 9);

        w = strtok(NULL, "|");
        strncpy(dane[i].kod_przed, w, 9);

        w = strtok(NULL, "|");
        strncpy(dane[i].nazwa_przed, w, 254);

        w = strtok(NULL, "|");
        dane[i].ocena = atof(w);

        w = strtok(NULL, "|");
        dane[i].ects = atoi(w);
    }

    fclose(fin);
    return cnt;
}

void wypisz(student dane[100], int n) {
    int i;
    for (i=0; i<n;i++) {
        printf("{ Student: %s - %s %s, z przedmiotu: [%s] %s za ECTS: %d otrzymał %.1f\n",
            dane[i].nr_albumu, dane[i].imie, dane[i].nazwisko,
            dane[i].kod_przed, dane[i].nazwa_przed,
            dane[i].ects, dane[i].ocena
        );
    }
}

int znajdz(char *szukany_nr, char nr_albumow[100][10], int n) {
    int i;
    for (i=0; i<n; i++) {
        if (strcmp(szukany_nr, nr_albumow[i]) == 0)
            return i;
    }
    return -1;
}

int znajdz_studentow(char nr_albumow[100][10], student dane[100], int n) {
    int ile_znalazlem = 0;
    int i;

    for (i=0; i <n; i++) {
        if (znajdz(dane[i].nr_albumu, nr_albumow, ile_znalazlem ) == -1) {
            strncpy(nr_albumow[ile_znalazlem], dane[i].nr_albumu, 9);
            ile_znalazlem++;
        }
    }
    return ile_znalazlem;
}

int znajdz_przedmiot(char *szukany_kod_przedmiotu, przedmiot lista_przedmiotow[50], int n)
{
    int i;
    for (i=0; i<n; i++) {
        if (strcmp(szukany_kod_przedmiotu, lista_przedmiotow[i].kod) == 0)
            return i;
    }
    return -1;
}

void najlepszy_przedmiot(student dane[100], int ile_rekordow)
{
    przedmiot lista_przedmiotow[50];
    int liczba_przedmiotow_na_liscie;
    // funkcja ma przejsc przez wszystkie przedmioty i stworzyc liste przedmiotow
    int i;
    for(i = 0; i < ile_rekordow; i++)
    {
        int indeks_przedmiotu = znajdz_przedmiot(dane[i].kod_przed, lista_przedmiotow, liczba_przedmiotow_na_liscie);

        if(indeks_przedmiotu == -1)
        {
            // jeśli nie ma przedmiotu, musimy go dodać
            przedmiot p;
            strncpy(p.kod, dane[i].kod_przed, 9);
            strncpy(p.nazwa, dane[i].nazwa_przed, 254);
            p.suma_ocen = dane[i].ocena;
            p.liczba_ocen = 1;

            lista_przedmiotow[liczba_przedmiotow_na_liscie++] = p;
        }
        else
        {
            // dodaj oceny do sumy danego przedmiotu
            lista_przedmiotow[indeks_przedmiotu].suma_ocen += dane[i].ocena;
            lista_przedmiotow[indeks_przedmiotu].liczba_ocen++;
        }
    }
    // teraz należy obliczyć średnią dla każdego przedmotu
    // możemy od razu poszukać min i max
    if(liczba_przedmiotow_na_liscie > 0)
    {
        int indeks_max = 0;
        int indeks_min = 0;
        for(i = 0; i < liczba_przedmiotow_na_liscie; i++)
        {
            lista_przedmiotow[i].srednia = lista_przedmiotow[i].suma_ocen / lista_przedmiotow[i].liczba_ocen;
            if(lista_przedmiotow[indeks_max].srednia < lista_przedmiotow[i].srednia)
            {
                indeks_max = i;
            }
            if(lista_przedmiotow[indeks_min].srednia > lista_przedmiotow[i].srednia)
            {
                indeks_min = i;
            }
        }
        //drukujemy wynik
        printf("Najlepsza średnia: %s - %s: %f\n", 
            lista_przedmiotow[indeks_max].kod, 
            lista_przedmiotow[indeks_max].nazwa,
            lista_przedmiotow[indeks_max].srednia);
        
        printf("Najgorsza średnia: %s - %s: %f\n", 
            lista_przedmiotow[indeks_min].kod, 
            lista_przedmiotow[indeks_min].nazwa,
            lista_przedmiotow[indeks_min].srednia);
    }
}



void najlepszy_student(student dane[100], int ile_rekordow) {
    char nr_albumow[100][10];
    int ile_studentow;
    float sumy_wazonych_ocen[100];
    int sumy_ects[100];
    float srednie[100];
    int i;
    int pozycja;
    int najlepsza_pozycja;
    float najlepsza = 0.0f;

    ile_studentow = znajdz_studentow(nr_albumow, dane, ile_rekordow);

    for (i=0; i < ile_rekordow; i++) {
        pozycja = znajdz( dane[i].nr_albumu, nr_albumow, ile_studentow );
        // if (pozycje >= 0)
        sumy_wazonych_ocen[pozycja] += dane[i].ocena * dane[i].ects;
        sumy_ects[pozycja] += dane[i].ects;
    }    

    for (i=0;i<ile_studentow; i++) 
        printf("Student [%d]: %s - %f:%d - %f \n", i+1, nr_albumow[i], 
        sumy_wazonych_ocen[i], sumy_ects[i], sumy_wazonych_ocen[i] / sumy_ects[i]);

    for (i=0; i < ile_studentow; i++) {
        if (najlepsza < sumy_wazonych_ocen[i] / sumy_ects[i]) {
            najlepsza = sumy_wazonych_ocen[i] / sumy_ects[i];
            najlepsza_pozycja = i;
        }
    }

    printf("Najlepszy student: \n");
    printf("Student [%d]: %s - %f \n", 
        najlepsza_pozycja+1, nr_albumow[najlepsza_pozycja],
        sumy_wazonych_ocen[najlepsza_pozycja] / sumy_ects[najlepsza_pozycja]
    );

}

int main(int argc, char ** argv) {
    student dane[100];
    int ile;
    // dane == &dane[0]
    ile = wczytaj(dane, argv[1]);
   // wypisz(dane, ile);

    //najlepszy_student(dane, ile);
    najlepszy_przedmiot(dane, ile);

    return 0;
}