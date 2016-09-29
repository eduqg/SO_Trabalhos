CC := gcc
CFLAGS := -W -Wall -pedantic -ansi -lm -Werror

all:
	$(CC) -c -fpic primo.c -o build/primo.o $(CFLAGS)
	gcc -shared -o build/libprimo.so build/primo.o
	gcc -L./build -Wl,-rpath=build -o main.run main.c -lprimo $(CFLAGS)

clean:

	rm main.run build/*

run:

	./main.run
