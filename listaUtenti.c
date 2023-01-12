#include "listaUtenti.h"

Lista *ricerca(Lista *pl){
    while (*pl)
    {
        pl=&(*pl)->next;
    }
    return pl;
    
}

void insTesta(Lista *pl, Dato d){
    Nodo *aux;
    aux=(Nodo*)malloc(sizeof(Nodo));
    aux->dato=d;
    aux->next=*pl;
    *pl=aux;

}

void insCoda(Lista *pl, Dato help){
    pl=ricerca(pl);
    insTesta(pl, help);
}

void copiaFile(char file[], Lista *pl){
    FILE* pfb;
    Dato help;
    pfb=fopen(file, "rb");
    if (pfb==NULL)
    {
        printf("Errore nell'apertura del file %s\n", file);
        exit(3);
    }

    *pl=NULL;
    while (fread(&help,sizeof(Dato),1,pfb)==1)//inserisco dentro a help uno alla volta i componenti del file binario
    {
        insCoda(pl,help);
        //printf("%.2f\n", );
    }
    
    
    //rewind(pfb);
    fclose(pfb);
  
}


float pianoA(float credito, int tempo){//restituisce il consumo dopo una chiamata di un cliente con il contratto A
    int i;
    float consumo= 0.15;//applica 0.15 a ogni chiamata
    for ( i = 0; i < tempo; i=i+60)
    {
        consumo+=0.08;
    }
    
    return consumo;
    
}

float pianoB(float credito, int tempo){//restituisce il consumo dopo una chiamata di un cliente con il contratto B
    int i;
    float consumo=0.0;
    for ( i = 0; i < tempo; i++)
    {
        consumo+=0.12/60;
    }
    
    return consumo;
    
}
float calcola(Lista l, char file[]){//usa la lista collegata(copia del file binario)
    FILE *pf;
    Chiamate call; 
    pf=fopen(file, "rt");
    if (pf==NULL)
    {
        printf("Errore nell'apertura del file %s\n", file);
        exit(2);
    }
    while (l)//scorre la lista collegata per leggere i numeri, credito e piano tariffario
    {
        float credito= l->dato.credito;//prende uno alla volta il credito degli utenti
        while(fscanf(pf, "%s%d",call.numero, &call.tempo)==2){//leggo uno alla volta le varie chiamate del file testo per controllare: chi esegue chiamate e quanto tempo
            if (strcmp(l->dato.numero,call.numero)==0)//quando trova il numero di telefono fra le chiamate
            {
                if (l->dato.piano=='A')//controlla quale piano ha attivo
                {
                    credito-=pianoA(l->dato.credito, call.tempo);//sottrae al credito iniziale i soldi
                }else credito-=pianoB(l->dato.credito, call.tempo);
                
                
            }
            
        }
        printf("Numero: %s Credito: %.2f\n",l->dato.numero, credito);//stampa il credito dell'utente dopo tutte le chiamate
        l=l->next;//passa al dato contenente il prossimo cliente
        rewind(pf);//torna all'inizio del file di testo
        
    }
    fclose(pf);
    
}

