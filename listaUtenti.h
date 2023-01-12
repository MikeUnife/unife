#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char numero[11];
    char piano;
    float credito;
}Dato;

typedef struct nodo{
    Dato dato;
    struct nodo* next;
}Nodo;

typedef Nodo* Lista;

typedef struct {
    char numero[11];
    int tempo;
}Chiamate;


void copiaFile(char file[], Lista *pl);
float calcola(Lista l, char file[]);

