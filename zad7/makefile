DEPS= wczytywanie.c wczytywanie.h operacje_matematyczne.h operacje_matematyczne.c main.c


main: $(DEPS)
	gcc $^ -o $@ -lm 

%.o:%.c
	gcc -c $^ -o $@

clean:
	rm -f main
	rn -f *.o