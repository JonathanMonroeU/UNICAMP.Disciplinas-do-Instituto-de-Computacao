//Lindon Jonathan S S P Monroe RA 220407 04-Contatos
#include <stdio.h>
#include <string.h>

typedef struct{
    char nome[51], ende[101], tel[13], ani[9]; //endereço, telefone e aniversário 
    }contatos; 

int insercao(int *ultimo,contatos *lista){
    *ultimo+=1;
    scanf(" %[^\n] ",lista[*ultimo].nome);
    scanf("%[^\n] ",lista[*ultimo].ende);
    scanf("%s ",lista[*ultimo].tel);
    scanf("%s ",lista[*ultimo].ani);
    printf("Contato para %s inserido.\n",lista[*ultimo].nome);  
    printf("\n");
    return 0;
}

int remocao(int *ultimo,contatos *lista){
    int i,j;
    int rem=0;
        char sol[50]; //solicitado
        scanf("%s ",sol);
        for (i=0;i<=*ultimo;i++){
            if(strcmp(lista[i].nome,sol)==0){
                *ultimo=*ultimo-1;
                rem+=1;
                for (j=i;j<=*ultimo;j++){
                    lista[j]=lista[j+1];    
                }i=i-1;
                } 

        }printf("Contatos de %s removidos: %d.\n",sol,rem);    
        
    printf("\n");    
    return 0;
}

int busca(int *ultimo,contatos *lista){
    int i,achado=0;
    char sol[50]; //solicitado
    scanf("%s ",sol);  
    for (i=0;i<=*ultimo;i++){
        if (strstr(lista[i].nome,sol)!=0){
            if(achado==0){printf("Resultado da busca:\n");}
            printf("(%d) %s\t%s\t%s\t%s\n",i+1,lista[i].nome,lista[i].ende,lista[i].tel,lista[i].ani);
            printf("\n");
            achado+=1;}
        }if (achado==0){
            printf("Resultado da busca:\nNenhum contato.\n");
            printf("\n");
    }
    return 0;
    }


int impressao(int *ultimo,contatos *lista){
       int i;
        if (*ultimo==-1){
                printf("Listagem:\nNenhum contato.\n");
                printf("\n");
                return 0;
        }printf("Listagem:\n");
        for (i=0;i<=*ultimo;i++){
            printf("(%d) %s\t%s\t%s\t%s\n",i+1,lista[i].nome,lista[i].ende,lista[i].tel,lista[i].ani);
        }
    printf("\n");
    return 0;
    }


    
int main(){
    contatos lista[1000];
    char o;
    int ultimo=-1,endless=1;

while(endless){
    scanf("%c ",&o);
    
    if (o=='f'){
        return 0;
    }    
    if (o=='i'){
        insercao(&ultimo,lista);          
    }
    if (o=='r'){
        remocao(&ultimo,lista);
    }
    if (o=='b'){
        busca(&ultimo,lista);
    }
    if (o=='p'){
        impressao(&ultimo,lista);
    }
}
}
