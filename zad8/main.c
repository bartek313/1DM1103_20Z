#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include "baza.h"
	
	int main(int argc, char ** argv) {
        
	    SBaza *baza;
	    baza = wczytaj_baze(argv[1]);

       if (strcmp("list_students", argv[2]) == 0) 
        {
	        listuj_studentow(baza);
        }
        else if (strcmp("list_courses", argv[2]) == 0) 
        {
	        listuj_przedmioty(baza);
        }
        else if (strcmp("list_grades", argv[2]) == 0) 
        {
	        listuj_oceny(baza);
        }
        else if (strcmp("add_student", argv[2]) == 0)
        {
            if(argc == 7)
            {
                dodaj_studenta(baza, argv[3], argv[4], argv[5], argv[6]);
            }
	    } 
        else if(strcmp("add_grade", argv[2]) == 0)
        {
            if(argc == 7)
            {
                dodaj_ocene(baza, argv[3], argv[4], atof(argv[5]), argv[6]);
            }
            else if(argc == 6)
            {
                dodaj_ocene(baza, argv[3], argv[4], atof(argv[5]), NULL);
            }
            else if(argc == 5)
            {
                dodaj_ocene(baza, argv[3], argv[4], 0, NULL);
            } 

        }
        else if(strcmp("add_student_to_course", argv[2]) == 0)
        {
            dodaj_ocene(baza, argv[3], argv[4], 0, NULL);
        }
        else if(strcmp("add_course", argv[2]) == 0)
        {
            if(argc == 6)
            {
                dodaj_przedmiot(baza, argv[3], argv[4], argv[5]);
            }
        }
        else if (strcmp("count_students", argv[2]) == 0) 
        {
	        printf("Liczba studentów: %d\n", ile_studentow(baza)); 
	    } else if (strcmp("count_courses", argv[2]) == 0) 
        {
           printf("Liczba przedmiotów : %d\n", ile_przedmiotow(baza));
        } else if (strcmp("count_grades", argv[2]) == 0) 
        {
            printf("Liczba ocen : %d\n", ile_ocen(baza));
        } 
	    zapisz_baze(argv[1], baza);
	    zwolnij(baza);
	    return 0;
	}
