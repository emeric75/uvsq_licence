CFLAGS= -Wall -g
CC = gcc

run: clean automate
	./automate 

automate: test.o automate.o ms_list.o
	$(CC) test.o automate.o ms_list.o -o automate

%.o: %.c %.h
	$(CC) -c $< $(CFLAGS) 

valgrind: automate
	valgrind --leak-check=full ./automate

clean: 
	rm -f *.o
	rm -f automate
	rm -f *.aut
