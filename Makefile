all: myBank

myBank: main.o libmyBank.a
	gcc -Wall -o myBank main.o libmyBank.a

libmyBank.a: myBank.o
	ar rcs -o libmyBank.a myBank.o

main.o: main.c myBank.h
	gcc -Wall -c -o main.o main.c -I.

myBank.o: myBank.c myBank.h
	gcc -Wall -fPIC -c -o myBank.o myBank.c -I.

clean:
	rm -f *.o *.a *.so mains mainds
