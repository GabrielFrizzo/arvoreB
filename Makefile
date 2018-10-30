all: saida
	@echo " " 
	@echo "Compilação concluída!!"
	@echo " " 

run: saida
	./saida
	 
saida: src/mainArvoreb.o src/buscaArvoreb.o src/criaArvoreb.o src/insereArvoreb.o src/printArvoreb.o src/removeArvoreb.o
	gcc -o saida src/mainArvoreb.o src/buscaArvoreb.o src/criaArvoreb.o src/insereArvoreb.o src/printArvoreb.o src/removeArvoreb.o

src/mainArvoreb.o: src/mainArvoreb.c
	gcc -o src/mainArvoreb.o -c src/mainArvoreb.c 

src/printArvoreb.o: src/printArvoreb.c
	gcc -o src/printArvoreb.o -c src/printArvoreb.c

src/removeArvoreb.o: src/removeArvoreb.c
	gcc -o src/removeArvoreb.o -c src/removeArvoreb.c

src/buscaArvoreb.o: src/buscaArvoreb.c
	gcc -o src/buscaArvoreb.o -c src/buscaArvoreb.c

src/criaArvoreb.o: src/criaArvoreb.c
	gcc -o src/criaArvoreb.o -c src/criaArvoreb.c

src/insereArvoreb.o: src/insereArvoreb.c
	gcc -o src/insereArvoreb.o -c src/insereArvoreb.c  

clean: 
	rm -f *.o

execClean:
	rm -f saida


