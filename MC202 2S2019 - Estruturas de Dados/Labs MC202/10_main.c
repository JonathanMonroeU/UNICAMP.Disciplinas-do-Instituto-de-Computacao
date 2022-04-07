//RA 220407 Lindon Jonathan S S P Monroe
//10-bst
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "10.h"

int main(){
    int x, y;
    node *root;
    root=NULL;
    while(1){
        char com[20];
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
        //SO FAR, IT'S EQUIVALENT TO THE LAB 9


        if (strcmp(com,"remover")==0){
            if (root){
                scanf("%d",&x);
                remover(x,&root);    
            }
        }
        if (strcmp(com,"minimo")==0){
            if(!root){
                printf("vazia\n");
            }else{
                node* temp=minimo(&root);
                printf("%d\n",temp->key);
            }
        }
        if (strcmp(com,"maximo")==0){
            if(!root){
                printf("vazia\n");
            }else{
                node* temp=maximo(&root);
                printf("%d\n",temp->key);
            }
        }

        if (strcmp(com,"sucessor")==0){
            if(!root){
                printf("nao ha\n");
            }else{
                scanf("%d",&x);
                sucessor(x,&root);
                printf("\n");
            }
        }
        if (strcmp(com,"predecessor")==0){
            if(!root){
                printf("nao ha\n");
            }else{
                scanf("%d",&x);
                predecessor(x,&root);
                printf("\n");
            }
        }
        if (strcmp(com,"buscar-intervalo")==0){
            scanf("%d %d",&x,&y);
            if (x<=y){
                if(root){
                    buscar_intervalo(x,y,&root); 
                }else{
                    printf("nenhuma");
                }printf("\n");
            }
        }
        if (strcmp(com,"terminar")==0){
            freetree(root);
            return 0;
        }
    }
}