run: main
	./main

main: liste.o main.o
	gcc -Wall -o main main.o liste.o

liste.o: liste.c liste.h
	gcc -Wall -c liste.c liste.h
main.o: main.c
	gcc -Wall -c main.c
clean:
	rm -f main.o liste.o main
