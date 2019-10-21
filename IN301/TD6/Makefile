run: main
	./main

main: liste.o main.o
	gcc -o main main.o liste.o

liste.o: liste.c liste.h
	gcc -c liste.c liste.h
main.o: main.c
	gcc -c main.c
clean:
	rm -f main.o liste.o main
