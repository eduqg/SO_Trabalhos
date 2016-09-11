CC := gcc
CFLAGS := -W -Wall -pedantic -ansi -lpthread -std=c99

all:
	$(CC) main.c thread.c -o prog $(CFLAGS)
	$(CC) main_analise.c -o prog_analise $(CFLAGS)
run:

	./prog 5 4 3 2 1 5

clean:

	rm -rf prog prog_analise

