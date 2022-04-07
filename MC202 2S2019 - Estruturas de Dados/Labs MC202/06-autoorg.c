//RA 220407 Lindon Jonathan S dos S P Monroe
#include <stdlib.h>
#include <stdio.h>
#include "06-autoorg.h"

int create(int N,node** head){
    int i;
    *head=NULL;
    *head=malloc(sizeof(node));
    if (head==NULL){
        return 1;
    } 
    (*head)->chave=1;
    (*head)->contador=0;
    (*head)->next=NULL;

    node *current=*head;

    if (N>=2){
        for (i=2;i<=N;i++){
            current->next=malloc(sizeof(node));
            if (current->next==NULL){
                return 1;
            }
            current->next->chave=i;
            current->next->contador=0;
            current->next->next=NULL;
            current=current->next;
        }
    }
    return 0;
}

int freelista(node** head){  
    node* temp;
    while (*head != NULL){
       temp=*head;
       *head=(*head)->next;
       if (temp!=NULL){
       free(temp);
        }
    }
    return 0;
}

int mtf(int R,int *acessos,node **head){
    int i, aux=0;node *current,*temp1;
    for(i=0;i<R;i++){
        current=*head;
        aux++;
        if ((current->chave)==acessos[i]){
            ;
        }else{
            while ((current->next->chave)!=acessos[i]){
                current=current->next;
                aux++;
            }aux++;
            temp1=*head;
            *head=current->next;
            current->next=current->next->next;
            (*head)->next=temp1;
        }
    }return aux;
}

int tr(int R,int *acessos,node **head){
    int i,aux=0;node *current, *previous,*temp1;
    for(i=0;i<R;i++){
        current=*head;
        aux++;
        if ((current->chave)==acessos[i]){
            ;
        }else{
            while ((current->next->chave)!=acessos[i]){
                previous=current;
                current=current->next;
                aux++;
            }aux++;
            if ((*head)->next->chave==acessos[i]){
                temp1=*head;
                *head=current->next;
                current->next=current->next->next;
                (*head)->next=temp1;
            }else{
                temp1=current->next->next;
                current->next->next=previous->next;
                previous->next=current->next;
                current->next=temp1;
            }
        }
    }return aux;
}


int count(int R,int *acessos,node **head){
    int i,comparador,aux=0;node *current,*temp1,*p;
    for(i=0;i<R;i++){
        current=*head;
        aux++;
        if ((current->chave)==acessos[i]){
            current->contador++;
        }else{
            while ((current->next->chave)!=acessos[i]){
                current=current->next;
                aux++;
            }aux++;
            current->next->contador++;
            comparador=current->next->contador;
            p=current;

            current=*head;
            if (current->contador<=comparador){
                if (current!=p->next){
                    temp1=*head;
                    *head=p->next;
                    p->next=p->next->next;
                    (*head)->next=temp1;
                }
            }else{
                while ((current->next->contador)>comparador){
                    current=current->next;
                }if (current!=p){
                    temp1=current->next;
                    current->next=p->next;
                    p->next=p->next->next;
                    current->next->next=temp1;
                }
            }
        }
    }return aux;
}