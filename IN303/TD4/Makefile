run: main
	./main

main: main.o file.o file_prio.o
	gcc -o main main.o file.o file_prio.o

main.o: main.c
	gcc -c main.c

file.o: file.c file.h
	gcc -c file.c
file_prio.o: file_prio.c file_prio.h
	gcc -c file_prio.c
clean:
	rm -f main *.o
	ls -l
