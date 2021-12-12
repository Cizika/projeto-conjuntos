all:  Main set.o
	gcc -g main.o set.o -o Conjuntos -std=c99 -pedantic-errors -Wall -lm

run: 
	./Conjuntos < ./Tests/Teste2.in > ./Tests/Teste2.out

test: 
	valgrind --leak-check=full --show-leak-kinds=all ./Conjuntos

set.o:
	gcc -g -c ./TAD_Conjunto/Set.c -o set.o

Main:
	gcc -g -c main.c -I ./TAD_Conjunto

clean:
	rm *.o Conjuntos