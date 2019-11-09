run: main
	./main
main: main.o tas.o
	gcc -o main main.o tas.o
main.o: main.c
	gcc -c main.c
tas.o: tas.c tas.h
	gcc -c tas.c

clean:
	rm -f *.o main
