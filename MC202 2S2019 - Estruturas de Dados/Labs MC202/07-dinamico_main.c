//RA  220407 Lindon Jonathan S S P Monroe
//07-dinamico
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "07-dinamico.h"

int main(){
    stru_array v;
    (v.ini)=1;
    (v.fim)=-1;
    (v.tam)=0;
    (v.tamtot)=1;
    (v.vetor1)=calloc (1,sizeof(int));

    while (1){
        char com[20];
        scanf("%s",com);
        if (strcmp(com,"insert-first")==0){
            insert_first(&v);
        }
        else if (strcmp(com,"remove-first")==0){
            remove_first(&v);
        }
        else if (strcmp(com,"print-first")==0){
            print_first(&v);
        }
        else if (strcmp(com,"insert-last")==0){
            insert_last(&v);
        }
        else if (strcmp(com,"remove-last")==0){
            remove_last(&v);
        }
        else if (strcmp(com,"print-last")==0){
            print_last(&v);
        }
        else if (strcmp(com,"is-empty")==0){
            is_empty(&v);
        }
        else if (strcmp(com,"exit")==0){
            free(v.vetor1);
            return 0;
        }
    }return 0;
}
