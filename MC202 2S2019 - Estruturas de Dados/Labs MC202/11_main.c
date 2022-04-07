//RA 220407 Lindon Jonathan S S P Monroe
//11-hashing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "11.h"

int main(){
    data tab[6257];
    int i,id;
    id=0;
    for (i=0;i<6257;i++){
        strcpy((char*)tab[i].keyword,"n");
    }
    char c;
    while(1){
    scanf("%c",&c);  //lê o comando
        if (c=='i'){
            unsigned char word[251];
            scanf("%s",word);
            inserir(tab, word, &id);

        }if (c=='b'){
            unsigned char word[251];
            scanf("%s",word);
            buscar(tab, word);

        }if (c=='r'){
            unsigned char word[251];
            scanf("%s",word);
            remover(tab, word);

        }if (c=='f'){
            return 0;
        }
    }
}