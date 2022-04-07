//RA 220407 Lindon Jonathan S S P Monroe
//09-bst
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "09-bst.h"

int main(){
    int x;
    node *root;
    root=NULL;
    while(1){
        char com[10];
        scanf("%s",com);  //lê o comando
        if (strcmp(com,"inserir")==0){
            scanf("%d",&x);
            inserir(x,&root);    
        }
        if (strcmp(com,"buscar")==0){
            scanf("%d",&x);
            buscar(x,&root);
        }
        if (strcmp(com,"pre-ordem")==0){
            if(!root){
                printf("vazia\n");
            }else{
                pre_ordem(root);
                printf("\n");
            }
        }
        if (strcmp(com,"em-ordem")==0){
            if(!root){
                printf("vazia\n");
            }else{
                em_ordem(root);
                printf("\n");
            }
        }
        if (strcmp(com,"pos-ordem")==0){
            if(!root){
                printf("vazia\n");
            }else{
                pos_ordem(root);
                printf("\n");
            }
        }
        if (strcmp(com,"largura")==0){
            if(!root){
                printf("vazia\n");
            }else{
                largura(root);
                printf("\n");
            }
        }
        if (strcmp(com,"terminar")==0){
            freetree(root);
            return 0;
        }
    }
    return 0;
}