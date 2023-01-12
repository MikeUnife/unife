utenti: main.o listaUtenti.o 
	gcc -g -o utenti main.o listaUtenti.o
main.o: main.c
	 gcc -c -g main.c
listaUtenti.o: listaUtenti.c
	gcc -c -g listaUtenti.c