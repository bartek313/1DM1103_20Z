#ifndef _BAZA_H
	#define _BAZA_H
	
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	
	typedef struct _Student {
	    char * imie;
	    char * nazwisko;
	    char * nr_albumu;
	    char * email;
	
	    struct _Student *nast;
	} Student;
	
	 typedef struct _Przedmiot {
	     char * kod_przedmiotu;
	     char * nazwa;
	     char * semestr;
	
	     struct _Przedmiot *nast;
	 } Przedmiot;
	
	 typedef struct _Ocena {
	     char * nr_albumu;
	     char * kod_przedmiotu;
	
	     float ocena;
	     char * komentarz;
	
	     struct _Ocena *nast;
	 } Ocena;
	
	
	typedef struct _SBaza {
	    Student *lista_studentow; /* GĹ‚owa listy! */
        Przedmiot *lista_przedmiotow; 
        Ocena *lista_ocen;
	} SBaza;
	
	SBaza * wczytaj_baze(char *nazwa_pliku);
	SBaza * zapisz_baze(char *nazwa_pliku, SBaza * baza);
	void listuj_studentow(SBaza *baza);
	void zwolnij(SBaza *baza);
	int ile_studentow(SBaza *baza);
    void listuj_przedmioty(SBaza *baza);
    void listuj_oceny(SBaza *baza);
    int ile_przedmiotow(SBaza * baza);
    int ile_ocen(SBaza * baza);
    dodaj_studenta(SBaza * baza, char * imie, char * nazwisko, char * nr_albumu, char * email);
    dodaj_przedmiot(SBaza * baza, char * kod_przedmiotu, char * nazwa, char * semestr);
    dodaj_ocene(SBaza * baza, char * nr_albumu, char * kod_przedmiotu, float ocena, char * komentarz);

	void wypisz_liste_ocen(Ocena * oc);
    Ocena * filtruj(Ocena * glowa, char *kod_przedmiotu, char pole_do_filtrowania);
    void listuj_studentow_od_konca(SBaza *baza);

	Student * sortuj_studentow_przez_wybieranie(Student *glowa, int kolejnosc);
    Przedmiot * sortuj_przedmioty_przez_wybieranie1(Przedmiot *glowa, int kolejnosc);
    Przedmiot * sortuj_przedmioty_przez_wybieranie2(Przedmiot *glowa, int kolejnosc);
    
	#endif
