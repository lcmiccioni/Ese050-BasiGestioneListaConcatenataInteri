#include <stdio.h>
#include <stdlib.h>

struct s_elemento {
    int value;
    struct s_elemento *next;
};

typedef struct s_elemento elemento;

elemento* inputInteri(elemento *primo);
void outputInteri(elemento *primo);
void vuotaLista(elemento *primo);

int main(int argc, char** argv) {
    elemento* primo;
    
    primo = (elemento*) malloc(sizeof(elemento));
    if(primo==NULL) {
        fprintf(stderr,"Impossible allocare memoria");
        exit(1);
    }
    printf("Inserisci un numero (0 per terminare): ");
    scanf("%d", &((*primo).value));
    
    primo = inputInteri(primo);
    outputInteri(primo);
    vuotaLista(primo);
    
    return (EXIT_SUCCESS);
}

elemento* inputInteri(elemento *primo) {
    elemento* nuovoElemento;
    
    nuovoElemento = (elemento*) malloc(sizeof(elemento));
    if(nuovoElemento==NULL) {
        fprintf(stderr,"Impossible allocare memoria");
        exit(1);
    }
    
    printf("Inserisci un numero (0 per terminare): ");
    scanf("%d", &(nuovoElemento->value));
    
    while(nuovoElemento->value) {
        nuovoElemento->next = primo;
        primo = nuovoElemento;
        
        nuovoElemento = (elemento*) malloc(sizeof(elemento));
        if(nuovoElemento == NULL) {
            fprintf(stderr, "Impossibile allocare memoria");
            exit(1);
        }
        printf("Inserisci un numero(0 per terminare): ");
        scanf("%d", &(nuovoElemento->value));
    }
    
    return primo;
}

void outputInteri(elemento *primo) {
    elemento* scorri;
    
    scorri = primo;
    while(scorri != NULL) {
        printf("Elemento della lista: %d\n", scorri->value);
        scorri = scorri->next;
    }
    
    return;
}

void vuotaLista(elemento *primo) {
    elemento* temp;
    
    temp = NULL;
    while(primo!=NULL) {
        temp = primo->next;
        free(primo);
        primo = temp;
    }
    
    return;
}