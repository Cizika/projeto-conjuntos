all:  Main set.o
	gcc -g main.o set.o -o Conjuntos -std=c99 -pedantic-errors -Wall -lm

run: 
	./Conjuntos

test: 
	valgrind --leak-check=full --show-leak-kinds=all ./Conjuntos < ./Tests/Teste1.in

set.o:
	gcc -g -c ./TAD_Conjunto/Set.c -o set.o

Main:
	gcc -g -c main.c -I ./TAD_Conjunto

clean:
	rm *.o Conjuntos