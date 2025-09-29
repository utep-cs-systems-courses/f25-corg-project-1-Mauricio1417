CC = gcc
CFLAGS = -Wall -g
OBJ = main.o tokenizer.o history.o

all: main

main: $(OBJ)
	$(CC) $(CFLAGS) -o main $(OBJ)

main.o: main.c tokenizer.h history.h
tokenizer.o: tokenizer.c tokenizer.h
history.o: history.c history.c

clean:
	rm -f $(OBJ) main
