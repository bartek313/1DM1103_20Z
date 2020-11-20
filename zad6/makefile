DEPS= dziekanat.c main.c studenci.c dziekanat.h studenci.h
#DEPS= dziekanat.o main.o studenci.o

p6_3: $(DEPS)
	gcc $^ -o $@ -Wall --pedantic

%.o:%.c
	gcc -c $^ -o $@

clean:
	rm -f main
	rn -f *.o
