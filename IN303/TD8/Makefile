run: main
	./main

main: arbre.o main.o
	gcc -Wall -g -o main main.o arbre.o

main.o: main.c
	gcc -c -g main.c

arbre.o: arbre.c arbre.h
	gcc -c -g arbre.c
clean:
	rm -f *.o main
