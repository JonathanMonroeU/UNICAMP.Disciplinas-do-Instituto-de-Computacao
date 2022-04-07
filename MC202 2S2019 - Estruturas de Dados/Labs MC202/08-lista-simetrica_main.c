//RA  220407 Lindon Jonathan S S P Monroe
//08-lista-sim
#include <stdio.h>
#include <stdlib.h>
#include "08-lista-simetrica.h"

int main(){
    node* head;
    head=malloc(sizeof(node));
    if (head==NULL){
        return 1;
    }head->A=NULL;
    head->B=NULL;
    int started=0;
    char com;
    while (1){
        scanf("%c",&com);
        if (com=='i'){
            inserir(&head,&started);
        }
        if (com=='p'){
            imprimir(&head,&started);
        }
        if (com=='v'){
            reverter(&head,&started);
        }
        if (com=='t'){
            liberar(&head,&started);
            
            return 0;
        }
    }
    return 0;
}