//RA 220407 Lindon Jonathan S S P Monroe
//11-hashing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "11.h"

unsigned long djb2(unsigned char *str){
    unsigned long hash=5381;
    int c;
    while((c=*str++))
        hash=((hash<<5)+hash)+c;
    return hash;
}

int inserir(data *tab, unsigned char *word,int *id){
    unsigned long keyoriginal=djb2(word);
    int key=keyoriginal%6257,i=0;
    if ((strcmp((char*)tab[key].keyword,"n")==0)||(strcmp((char*)tab[key].keyword,"r")==0)){
        strcpy((char*)tab[key].keyword,(char*) word);
        tab[key].id=(*id);
        (*id)++;
    }else{
        while((strcmp((char*)tab[key].keyword,"n")!=0)||(strcmp((char*)tab[key].keyword,"r")!=0)){
            if (strcmp((char*)tab[key].keyword,(char*) word)==0){
            return 0;
        }
        key=(keyoriginal%6257+i*(1+(keyoriginal%6256)))%6257;  
        i++; 
        }strcpy((char*)tab[key].keyword,(char*) word);
        tab[key].id=(*id);
        (*id)++;
    }
    return 0;
}

int buscar(data *tab, unsigned char *word){
    unsigned long keyoriginal=djb2(word);
    int key=keyoriginal%6257,i=0;
    if (strcmp((char*)tab[key].keyword,"n")==0){
        printf("%s nao encontrada\n",word);
        return 0;
    }else{
        while(strcmp((char*)tab[key].keyword,"n")!=0){
            if (strcmp((char*)tab[key].keyword,(char*) word)==0){
                printf("%s encontrada, id %d\n",word,tab[key].id);
                return 0;
            }key=(keyoriginal%6257+i*(1+(keyoriginal%6256)))%6257;  
            i++;       
        }
    }printf("%s nao encontrada\n",word);
    return 0;
}

int remover(data *tab, unsigned char *word){
    unsigned long keyoriginal=djb2(word);
    int key=keyoriginal%6257,i=0;
    if (strcmp((char*)tab[key].keyword,"n")==0){
        return 0;
    }else{
        while (strcmp((char*)tab[key].keyword,"n")!=0){
            if (strcmp((char*)tab[key].keyword,(char*) word)==0){
                strcpy((char*)tab[key].keyword,"r");
                return 0;
            }key=(keyoriginal%6257+i*(1+(keyoriginal%6256)))%6257;  
            i++;       
        }          
    }return 0;
}
