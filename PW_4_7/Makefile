CC = gcc
CFLAGS = -Wall -Wextra

all: environ

environ: main.o environ.o
	$(CC) $(CFLAGS) -o environ main.o environ.o

main.o: main.c environ.h
	$(CC) $(CFLAGS) -c main.c

environ.o: environ.c environ.h
	$(CC) $(CFLAGS) -c environ.c

clean:
	rm -f *.o environ
