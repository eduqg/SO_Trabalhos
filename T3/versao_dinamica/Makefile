CC := gcc
CFLAGS := -W -Wall -pedantic -ansi -lm -lpthread

all:
	gcc -c -fpic primo.c -o build/primo.o
	#$(CC)  -c primo.c -o primo.o
	gcc -shared -o build/libprimo.so build/primo.o
	gcc  -o main.run main.c -lprimo
	cp primo.h build/primo.h
	gcc -L./build -o prog main.c -lprimo
	./prog


clean:

	rm prog build/*

run:

	./prog
