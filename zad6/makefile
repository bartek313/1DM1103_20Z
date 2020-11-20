DEPS= dziekanat.c main.c studenci.c dziekanat.h studenci.h
#DEPS=p6_3.o dziekanat.o main.o studenci.o

p6_3: $(DEPS)
	gcc $^ -o $@

%.o:%.c
	gcc -c $^ -o $@

clean:
	rm p6_3