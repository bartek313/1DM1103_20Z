all:
		cc baza.c main.c -o mydb -Wall --pedantic
	
	test: all
		./mydb baza.csv list_students
	
	test-ile: all
		./mydb baza.csv count_students
	
	test-od-konca: all
		./mydb baza.csv list_students_from_end

	test-sortuj-malejaco: all
		./mydb baza.csv sort_descending

	test-add: all
		./mydb "baza.csv" add_grade "1111111" "22222" "3.0"
		./mydb "baza.csv" add_course "1111111" "ukfuewrbw@sudhceiu" "sem2"
		./mydb "baza.csv" add_student "Robert" "W" "1111111" "nic@nic"
	
	test-memory: all
		valgrind ./mydb baza.csv count_students
    
	


