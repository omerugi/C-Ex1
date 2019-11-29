CC = gcc
CFLAG = -I.
OBJ = myBank.o
DEPS = myBank.h


all: myBank

myBank: main.o libmyBank.a
	$(CC) -Wall -o $@ $^

libmyBank.a: $(OBJ)
	ar rcs -o $@ $^

main.o: main.c $(DEPS)
	$(CC) -Wall -c -o $@ $< $(CFLAG)

myBank.o: myBank.c $(DEPS)
	$(CC) -Wall -fPIC -c -o $(OBJ) $< $(CFLAG)

.PHONY: all myBank clean

clean:
	rm -f *.o *.a *.so myBank
