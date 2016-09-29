CC := gcc
CFLAGS := -W -Wall -pedantic -ansi -lm

all:
	#referencia: http://mindbending.org/pt/bibliotecas-estaticas-simples
	rm build/*
	$(CC)  -c lib/primo.c -o build/primo.o
	ar rcs build/libprimo.a build/primo.o
	ar -t build/libprimo.a
	nm -s build/libprimo.a
	cp lib/primo.h build/primo.h
	$(CC) -static src/main.c -L./build -I./build -lprimo -o build/main.run $(CFLAGS)
	./build/main.run


clean:

	rm build/*.o build/main.run

run:

	./build/main.run
