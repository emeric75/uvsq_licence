run: nombres.data nombres-verif.data
	diff nombres.data nombres-verif.data


genere: genere.c constantes.h
	gcc -Wall -o genere genere.c

nombres.data: genere
	./genere



lecture: lecture.c constantes.h
	gcc -Wall -o lecture lecture.c

nombres-verif.data: lecture nombres.data
	./lecture


clean:
	rm -f genere
	rm -f lecture
	rm -f nombres.data
	rm -f nombres-verif.data
	
