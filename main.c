#include "listaUtenti.h"

int main(int argc, char* argv[]){
    FILE* pf;
    Lista l;
    


    if (argc!=3)
    {
        printf("Errore nell'utilizo\nUsare: %s file_binario file_testo\n",argv[0]);
        exit(1);
    }
    
    copiaFile(argv[1], &l);

    calcola(l,argv[2]);
        
    
    
    



    
    
    
}