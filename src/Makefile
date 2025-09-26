CC = gcc
CFLAGS = -Wall -g
OBJ = main.o tokenizer.o

all: main

main: $(OBJ)
	$(CC) $(CFLAGS) -o main $(OBJ)

main.o: main.c tokenizer.h
tokenizer.o: tokenizer.c tokenizer.h

clean:
	rm -f $(OBJ) main
