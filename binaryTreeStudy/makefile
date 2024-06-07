all: arvoreBinaria.o
	gcc arvoreBinaria.o main.c -o main

arvoreBinaria.o: arvoreBinaria.h
	gcc -c arvoreBinaria.c

run:
	./main

clean:
	rm -rf *.o