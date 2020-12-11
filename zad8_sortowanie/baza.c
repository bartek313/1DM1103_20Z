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
	        oc->kod_przedmiotu = (char*) malloc( sizeof(char) * (strlen(o) + 1));
	        strcpy(oc->kod_przedmiotu, o);
	        

	        o = strtok(NULL, ";");
	        oc->nr_albumu = (char*) malloc( sizeof(char) * (strlen(o) + 1));
	        strcpy(oc->nr_albumu, o);
	
            o = strtok(NULL, ";");
            oc->ocena = atof(o);

	        o = strtok(NULL, ";");
            if (o != NULL) 
			{
                usun_znak_nowej_linii(o, strlen(o));
                oc->komentarz = (char*) malloc( sizeof(char) * (strlen(o) + 1));
                strcpy(oc->komentarz, o);
            }
			else
			{
				oc->komentarz = NULL;
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

    void listuj_oceny(SBaza *baza) 
	{
		wypisz_liste_ocen(baza->lista_ocen);
	}

	void wypisz_liste_ocen(Ocena * oc) 
	{
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

Ocena * filtruj(Ocena * glowa, char *szukany_tekst, char pole_do_filtrowania)
{
    Ocena * oc = glowa;
    Ocena *last_ocena = NULL;
	Ocena *nowa_glowa = NULL;
	
    while (oc != NULL) 
    {	
		int porownanie;
		switch (pole_do_filtrowania)
		{
		case 'P':
			porownanie = strcmp(szukany_tekst, oc->kod_przedmiotu);
			break;
		case 'A':
			porownanie = strcmp(szukany_tekst, oc->nr_albumu);
			break;
		default:
			return NULL;
		}

        if(porownanie == 0)
        {
            Ocena *noc = (Ocena*) malloc(sizeof(Ocena));
            noc->nast = NULL;

            if (last_ocena == NULL)
            {
                nowa_glowa = noc;
            }
            else
            {
                last_ocena->nast = noc;
            }
                
            last_ocena = noc;
            
            noc->nr_albumu = (char*) malloc( sizeof(char) * (strlen(oc->nr_albumu)));
	        strcpy(noc->nr_albumu, oc->nr_albumu);

            noc->kod_przedmiotu = (char*) malloc( sizeof(char) * (strlen(oc->kod_przedmiotu)));
	        strcpy(noc->kod_przedmiotu, oc->kod_przedmiotu);
	        
			if (oc->komentarz != NULL) {
            	noc->komentarz = (char*) malloc( sizeof(char) * (strlen(oc->komentarz)));
	        	strcpy(noc->komentarz, oc->komentarz);
	    	}
	    	
            noc->ocena = oc->ocena;
         
        }

        oc = oc->nast;
    }
    
    return nowa_glowa;
}



Student * ostatni(Student *glowa) {
    Student *el = glowa;
    if (el != NULL) {
        while (el->nast != NULL)
            el = el->nast;

        return el;
    } else
        return NULL;
}

Student * usun(Student *glowa, Student *el) {
    Student *c = glowa;
    if (glowa == el) {
        glowa = glowa->nast;
    } else {
		Student *poprz = glowa;
        while (c != NULL) {
            if (c == el) {
                poprz->nast = c->nast;
                
                break;
            }
			poprz = c;

            c = c->nast;
        }
    }
    c->nast = NULL;
    return glowa;
}

Student * najwiekszy(Student *el) {
    Student * max = NULL;
    while (el != NULL) {
        if (max == NULL) {
            max = el;
        } else {
            if ( strcmp(el->nazwisko, max->nazwisko) > 0 ) 
                max = el;
        }
        el = el->nast;
    }
    return max;
}

Student * najmniejszy(Student *el) {
    Student * min = NULL;
    while (el != NULL) {
        if (min == NULL) {
            min = el;
        } else {
            if ( strcmp(el->nazwisko, min->nazwisko) < 0 ) 
                min = el;
        }
        el = el->nast;
    }
    return min;
}

// kolejnosc: rosnąca dla 0, malejąca dla 1
Student * sortuj_studentow_przez_wybieranie(Student *glowa, int kolejnosc) {
    Student * nglowa = NULL;
    Student * m;
    Student * o; // = NULL;

    while (glowa != NULL) 
    {
        if(kolejnosc == 0)
        {
            m = najmniejszy(glowa);
        }
        else
        {
            m = najwiekszy(glowa);
        }
        
        glowa = usun(glowa, m);
        
        o = ostatni(nglowa);
        if (o == NULL) {
            nglowa = m;
        } else {
            o->nast = m;
            //m->poprz = o;
        }
        // o = m;

        // printf("Najwiekszy: %s\n", m->nazwisko);
        // wypisz_rekurencyjnie(glowa);
    }

    return nglowa;
}






Przedmiot * ostatni1(Przedmiot *glowa) {
    Przedmiot *el = glowa;
    if (el != NULL) {
        while (el->nast != NULL)
            el = el->nast;

        return el;
    } else
        return NULL;
}

Przedmiot * usun1(Przedmiot *glowa, Przedmiot *el) {
    Przedmiot *c = glowa;
    if (glowa == el) {
        glowa = glowa->nast;
    } else {
		Przedmiot *poprz = glowa;
        while (c != NULL) {
            if (c == el) {
                poprz->nast = c->nast;
                
                break;
            }
			poprz = c;

            c = c->nast;
        }
    }
    c->nast = NULL;
    return glowa;
}

Przedmiot * najwiekszy1(Przedmiot *el) {
    Przedmiot * max = NULL;
    while (el != NULL) {
        if (max == NULL) {
            max = el;
        } else {
            if ( strcmp(el->kod_przedmiotu, max->kod_przedmiotu) > 0 ) 
                max = el;
        }
        el = el->nast;
    }
    return max;
}

Przedmiot * najmniejszy1(Przedmiot *el) {
    Przedmiot * min = NULL;
    while (el != NULL) {
        if (min == NULL) {
            min = el;
        } else {
            if ( strcmp(el->kod_przedmiotu, min->kod_przedmiotu) < 0 ) 
                min = el;
        }
        el = el->nast;
    }
    return min;
}

// kolejnosc: rosnąca dla 0, malejąca dla 1
Przedmiot * sortuj_przedmioty_przez_wybieranie1(Przedmiot *glowa, int kolejnosc) {
    Przedmiot * nglowa = NULL;
    Przedmiot * m;
    Przedmiot * o; // = NULL;

    while (glowa != NULL) 
    {
        if(kolejnosc == 0)
        {
            m = najmniejszy1(glowa);
        }
        else
        {
            m = najwiekszy1(glowa);
        }
        
        glowa = usun1(glowa, m);
        
        o = ostatni1(nglowa);
        if (o == NULL) {
            nglowa = m;
        } else {
            o->nast = m;
            //m->poprz = o;
        }
        // o = m;

        // printf("Najwiekszy: %s\n", m->nazwisko);
        // wypisz_rekurencyjnie(glowa);
    }

    return nglowa;
}





Przedmiot * ostatni2(Przedmiot *glowa) {
    Przedmiot *el = glowa;
    if (el != NULL) {
        while (el->nast != NULL)
            el = el->nast;

        return el;
    } else
        return NULL;
}

Przedmiot * usun2(Przedmiot *glowa, Przedmiot *el) {
    Przedmiot *c = glowa;
    if (glowa == el) {
        glowa = glowa->nast;
    } else {
		Przedmiot *poprz = glowa;
        while (c != NULL) {
            if (c == el) {
                poprz->nast = c->nast;
                
                break;
            }
			poprz = c;

            c = c->nast;
        }
    }
    c->nast = NULL;
    return glowa;
}

Przedmiot * najwiekszy2(Przedmiot *el) {
    Przedmiot * max = NULL;
    while (el != NULL) {
        if (max == NULL) {
            max = el;
        } else {
            if ( strcmp(el->nazwa, max->nazwa) > 0 ) 
                max = el;
        }
        el = el->nast;
    }
    return max;
}

Przedmiot * najmniejszy2(Przedmiot *el) {
    Przedmiot * min = NULL;
    while (el != NULL) {
        if (min == NULL) {
            min = el;
        } else {
            if ( strcmp(el->nazwa, min->nazwa) < 0 ) 
                min = el;
        }
        el = el->nast;
    }
    return min;
}

// kolejnosc: rosnąca dla 0, malejąca dla 1
Przedmiot * sortuj_przedmioty_przez_wybieranie2(Przedmiot *glowa, int kolejnosc) {
    Przedmiot * nglowa = NULL;
    Przedmiot * m;
    Przedmiot * o; // = NULL;

    while (glowa != NULL) 
    {
        if(kolejnosc == 0)
        {
            m = najmniejszy2(glowa);
        }
        else
        {
            m = najwiekszy2(glowa);
        }
        
        glowa = usun2(glowa, m);
        
        o = ostatni2(nglowa);
        if (o == NULL) {
            nglowa = m;
        } else {
            o->nast = m;
            //m->poprz = o;
        }
        // o = m;

        // printf("Najwiekszy: %s\n", m->nazwisko);
        // wypisz_rekurencyjnie(glowa);
    }

    return nglowa;
}