#include "baza.h"
	
    Przedmiot * wczytaj_przedmioty(FILE *fin)
    {
        char bufor[255];
	    int n, i;
	    char *p;
	    Przedmiot *last_przedmiot = NULL;
	    Przedmiot *glowa = NULL;
	    fgets(bufor, 254, fin);
	    sscanf(bufor, "%d", &n);

         for (i=0; i<n; i++) {
	        Przedmiot *przedm = (Przedmiot*) malloc(sizeof(Przedmiot));
	        przedm->nast = NULL;
	
	        if (last_przedmiot == NULL)
            {
	            glowa = przedm;
            }
	        else
            {
	            last_przedmiot->nast = przedm;
            }
	        last_przedmiot = przedm;

	        fgets(bufor, 254, fin);
	        p = strtok(bufor, ";");
	        przedm->kod_przedmiotu = (char*) malloc( sizeof(char) * (strlen(p) + 1));
	        strcpy(przedm->kod_przedmiotu, p);
	
	        p = strtok(NULL, ";");
	        przedm->nazwa = (char*) malloc( sizeof(char) * (strlen(p) + 1));
	        strcpy(przedm->nazwa, p);
	
	        p = strtok(NULL, ";");
            usun_znak_nowej_linii(p, strlen(p));
	        przedm->semestr = (char*) malloc( sizeof(char) * (strlen(p) + 1));
	        strcpy(przedm->semestr, p);
	    }
	
	    return glowa;
	}
dodaj_ocene(SBaza * baza, char * nr_albumu, char * kod_przedmiotu, float ocena, char * komentarz)
{
    Ocena * oc = (Ocena*) malloc(sizeof(Ocena));

    oc->nr_albumu = (char*) malloc( sizeof(char) * (strlen(nr_albumu) + 1));
    strcpy(oc->nr_albumu, nr_albumu);

    oc->kod_przedmiotu = (char*) malloc( sizeof(char) * (strlen(kod_przedmiotu) + 1));
    strcpy(oc->kod_przedmiotu, kod_przedmiotu);

    oc->ocena = ocena;

    if(komentarz != NULL)
    {
        oc->komentarz = (char*) malloc( sizeof(char) * (strlen(komentarz) + 1));
        strcpy(oc->komentarz, komentarz);
    }
    
    oc->nast = baza->lista_ocen;
    baza->lista_ocen = oc;
}

dodaj_przedmiot(SBaza * baza, char * kod_przedmiotu, char * nazwa, char * semestr)
{
    Przedmiot * przedm = (Przedmiot*) malloc(sizeof(Przedmiot));

    przedm->kod_przedmiotu = (char*) malloc( sizeof(char) * (strlen(kod_przedmiotu) + 1));
    strcpy(przedm->kod_przedmiotu, kod_przedmiotu);

    przedm->nazwa = (char*) malloc( sizeof(char) * (strlen(nazwa) + 1));
    strcpy(przedm->nazwa, nazwa);

    przedm->semestr = (char*) malloc( sizeof(char) * (strlen(semestr) + 1));
    strcpy(przedm->semestr, semestr);

    przedm->nast = baza->lista_przedmiotow;
    baza->lista_przedmiotow = przedm;
}

dodaj_studenta(SBaza * baza, char * imie, char * nazwisko, char * nr_albumu, char * email)
{
    Student *stud = (Student*) malloc(sizeof(Student));
    
    stud->imie = (char*) malloc( sizeof(char) * (strlen(imie) + 1));
    strcpy(stud->imie, imie);

    stud->nazwisko = (char*) malloc( sizeof(char) * (strlen(nazwisko) + 1));
    strcpy(stud->nazwisko, nazwisko);

    stud->nr_albumu = (char*) malloc( sizeof(char) * (strlen(nr_albumu) + 1));
    strcpy(stud->nr_albumu, nr_albumu);

    stud->email = (char*) malloc( sizeof(char) * (strlen(email) + 1));
    strcpy(stud->email, email);
    
    stud->nast = baza->lista_studentow;
    baza->lista_studentow = stud;
}
	
 Ocena * wczytaj_oceny(FILE *fin)
    {
        char bufor[255];
	    int n, i;
	    char *o;
	    Ocena *last_ocena = NULL;
	    Ocena *glowa = NULL;
	    fgets(bufor, 254, fin);
	    sscanf(bufor, "%d", &n);

         for (i=0; i<n; i++) {

	        Ocena *oc = (Ocena*) malloc(sizeof(Ocena));
	        oc->nast = NULL;
	
	        if (last_ocena == NULL)
	            glowa = oc;
	        else
	            last_ocena->nast = oc;
	        last_ocena = oc;
	
	        fgets(bufor, 254, fin);
	        o = strtok(bufor, ";");
	        oc->nr_albumu = (char*) malloc( sizeof(char) * (strlen(o) + 1));
	        strcpy(oc->nr_albumu, o);
	
	        o = strtok(NULL, ";");
	        oc->kod_przedmiotu = (char*) malloc( sizeof(char) * (strlen(o) + 1));
	        strcpy(oc->kod_przedmiotu, o);
	
            o = strtok(NULL, ";");
            oc->ocena = atof(o);

	        o = strtok(NULL, ";");
            if (o != NULL) {
                usun_znak_nowej_linii(o, strlen(o));
                oc->komentarz = (char*) malloc( sizeof(char) * (strlen(o) + 1));
                strcpy(oc->komentarz, o);
            }
	    }
	
	    return glowa;
	}
	
 



	Student * wczytaj_studentow(FILE *fin) {
	    char bufor[255];
	    int n, i;
	    char *s;
	    Student *last_student = NULL;
	    Student *glowa = NULL;
	    fgets(bufor, 254, fin);
	    sscanf(bufor, "%d", &n);
	
	    for (i=0; i<n; i++) {
	        Student *stud = (Student*) malloc(sizeof(Student));
	        stud->nast = NULL;
	
	        if (last_student == NULL)
	            glowa = stud;
	        else
	            last_student->nast = stud;
	        last_student = stud;
	
	        fgets(bufor, 254, fin);
	        s = strtok(bufor, ";");
	        stud->imie = (char*) malloc( sizeof(char) * (strlen(s) + 1));
	        strcpy(stud->imie, s);
	
	        s = strtok(NULL, ";");
	        stud->nazwisko = (char*) malloc( sizeof(char) * (strlen(s) + 1));
	        strcpy(stud->nazwisko, s);
	
	        s = strtok(NULL, ";");
	        stud->nr_albumu = (char*) malloc( sizeof(char) * (strlen(s) + 1));
	        strcpy(stud->nr_albumu, s);
	
	        s = strtok(NULL, "\n");
            usun_znak_nowej_linii(s, strlen(s));
	        stud->email = (char*) malloc( sizeof(char) * (strlen(s) + 1));
	        strcpy(stud->email, s);
	    }
	
	    return glowa;
	}
	
	SBaza * wczytaj_baze(char *nazwa_pliku) {
	    FILE *fin = fopen(nazwa_pliku, "r");
	    if (fin == NULL) {
	        printf("BŁĄD! Nie moge otworzyc pliku: %s.\n", nazwa_pliku);
	        exit(-1);
	    }

	    SBaza *baza = (SBaza*) malloc( sizeof(SBaza) );
	    baza->lista_studentow = wczytaj_studentow(fin);
        baza->lista_przedmiotow = wczytaj_przedmioty(fin);
        
        baza->lista_ocen = wczytaj_oceny(fin);


	    fclose(fin);
	    return baza;
	}
	
    void usun_znak_nowej_linii(char* s, int dlugosc) {
        if (dlugosc > 0 && s[dlugosc-1] == '\n') {
            s[dlugosc-1] = 0;
        }
    }

	SBaza * zapisz_baze(char *nazwa_pliku, SBaza * baza) 
    {
        FILE * fout = fopen(nazwa_pliku, "w+");
        zapisz_studentow(fout, baza);
        zapisz_przedmioty(fout, baza);
        zapisz_oceny(fout, baza);
	    return baza;
	}

    zapisz_studentow(FILE *fout, SBaza *baza)
    {
        fprintf(fout, "%d\n", ile_studentow(baza));
        Student * stud = baza->lista_studentow;
	    while (stud != NULL) 
        {
	        fprintf(fout, "%s;%s;%s;%s\n", stud->imie, stud->nazwisko, stud->nr_albumu, stud->email);
	        stud = stud->nast;
        }
    }

    zapisz_przedmioty(FILE *fout, SBaza *baza)
    {
        fprintf(fout, "%d\n", ile_przedmiotow(baza));
        Przedmiot * przedm = baza->lista_przedmiotow;
	    while (przedm != NULL) 
        {
	        fprintf(fout, "%s;%s;%s\n", przedm->kod_przedmiotu, przedm->nazwa, przedm->semestr);
	        przedm = przedm->nast;
        }
    }

    zapisz_oceny(FILE *fout, SBaza *baza)
    {
        fprintf(fout, "%d\n", ile_ocen(baza));
	    Ocena * oc = baza->lista_ocen;
	    while (oc != NULL) 
        {
            char * komentarz_do_zapisu = "";
            if(oc->komentarz != NULL)
            {
                komentarz_do_zapisu = oc->komentarz;
            }
            if(oc->ocena == 0.0)
            {
                fprintf(fout, "%s;%s;;%s\n", oc->kod_przedmiotu, oc->nr_albumu, komentarz_do_zapisu);
            }
            else
            {
                fprintf(fout, "%s;%s;%f;%s\n", oc->kod_przedmiotu, oc->nr_albumu, oc->ocena, komentarz_do_zapisu);
            }
	        oc = oc->nast;
	    }
    }
	
	int ile_studentow(SBaza *baza) {
	    int n = 0;
	    Student * stud = baza->lista_studentow;
	    while (stud != NULL) {
	        n++;
	        stud = stud->nast;
	    }
	    return n;
	}

    int ile_przedmiotow(SBaza *baza) {
	    int n = 0;
	    Przedmiot * przedm = baza->lista_przedmiotow;
	    while (przedm != NULL) {
	        n++;
	        przedm = przedm->nast;
	    }
	    return n;
	}

    int ile_ocen(SBaza *baza) {
	    int n = 0;
	    Ocena * oc = baza->lista_ocen;
	    while (oc != NULL) {
	        n++;
	        oc = oc->nast;
	    }
	    return n;
	}

	void listuj_studentow(SBaza *baza) {
	    Student * stud = baza->lista_studentow;
	    while (stud != NULL) {
	        printf("%s %s %s %s\n", stud->imie, stud->nazwisko, stud->nr_albumu, stud->email);
	        stud = stud->nast;
	    }
	}

    void listuj_przedmioty(SBaza *baza) {
	    Przedmiot * przedm = baza->lista_przedmiotow;
	    while (przedm != NULL) {
	        printf("%s %s %s\n", przedm->kod_przedmiotu, przedm->nazwa, przedm->semestr);
	        przedm = przedm->nast;
	    }
	}

    void listuj_oceny(SBaza *baza) {
	    Ocena * oc = baza->lista_ocen;
	    while (oc != NULL) {
	        printf("%s %s %f %s\n", oc->kod_przedmiotu, oc->nr_albumu, oc->ocena, oc->komentarz);
	        oc = oc->nast;
	    }
	}
	
	void zwolnij_student(Student *s) {
	    free(s->imie);
	    free(s->nazwisko);
	    free(s->nr_albumu);
	    free(s->email);
	    free(s);
	}
	
	void zwolnij_liste_studentow(Student *s) {
	    Student *n;
	    while (s != NULL) 
        {
	        n = s->nast;
	        zwolnij_student(s);
	        s = n;
	    }
	}

    void zwolnij_przedmiot(Przedmiot *p)
    {
        free(p->kod_przedmiotu);
        free(p->nazwa);
        free(p->semestr);
        free(p);
    }

    void zwolnij_ocene(Ocena *o)
    {
        free(o->kod_przedmiotu);
        free(o->nr_albumu);
        //free(o->ocena);
        free(o->komentarz);
        free(o);
    }

    void zwolnij_liste_przedmiotow(Przedmiot *p)
    {
        Przedmiot *n;
        while(p != NULL)
        {
            n = p->nast;
            zwolnij_przedmiot(p);
            p = n;
        }
    }

    void zwolnij_liste_ocen(Ocena *o)
    {
        Ocena *n;
        while(o != NULL)
        {
            n = o->nast;
            zwolnij_ocene(o);
            o = n;
        }
    }
	
	void zwolnij(SBaza *baza) 
    {
	    zwolnij_liste_studentow(baza->lista_studentow);
        zwolnij_liste_przedmiotow(baza->lista_przedmiotow);
        zwolnij_liste_ocen(baza->lista_ocen);
	    free(baza);
	}



