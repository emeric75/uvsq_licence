visu: stat.pdf
	evince stat.pdf &


stat.pdf: tri_bulle tri_fusion stat.gplt test_tri_bulle.data test_tri_fusion.data
	gnuplot stat.gplt

test_tri_bulle.data: tri_bulle
	time ./tri_bulle

test_tri_fusion.data: tri_fusion
	time ./tri_fusion

# Tri fusion
tri_fusion: tri_fusion.o tabint.o
	gcc -Wall -o tri_fusion tri_fusion.o tabint.o

tri_fusion.o: tri_fusion.c tabint.h stat.h
	gcc -Wall -c tri_fusion.c


# Le tri à bulles

tri_bulle: tri_bulle.o tabint.o
	gcc -Wall -o tri_bulle tri_bulle.o tabint.o

tri_bulle.o: tri_bulle.c tabint.h stat.h
	gcc -Wall -c tri_bulle.c


# La bibliothèque de manipulation de tableaux
tabint.o: tabint.c tabint.h
	gcc -Wall -c tabint.c

clean:
	rm -f tabint.o
	rm -f tri_bulle.o tri_bulle
	rm -f stat.pdf
	rm -f test_tri_bulle.data
	rm -f tri_fusion tri_fusion.o
	rm -f test_tri_fusion.data
	ls -l

ZIPNAME=IN301_TD5_TRI_INT
zip:
	rm -rf ${ZIPNAME}
	mkdir ${ZIPNAME}
	cp *.c ${ZIPNAME}
	cp *.h ${ZIPNAME}
	cp Makefile ${ZIPNAME}
	cp *.gplt ${ZIPNAME}
	zip -r $(ZIPNAME).zip $(ZIPNAME)
##	rm -rf ${ZIPNAME}
	ls -l ${ZIPNAME}*














