//RA  220407 Lindon Jonathan S S P Monroe
//08-lista-sim
#include <stdio.h>
#include <stdlib.h>
#include "08-lista-simetrica.h"

int inserir(node **head,int* started){
    int pos,current=0; double valor;
    node *temp,*prev,*aux;
    temp=(*head);
    prev=(*head);
    scanf("%d %lf",&pos,&valor);
    if((*started)==0){
        (*head)->value=valor;
        (*head)->A=NULL;
        (*head)->B=NULL;
        (*started)++;
        
    }else{
        while(temp){
            if ((temp->A)==NULL && (temp->B)==NULL){
                if (pos==0){
                    aux=(*head);
                    (*head)=malloc(sizeof(node));
                    (*head)->value=valor;
                    (*head)->A=NULL;
                    (*head)->B=aux;
                    aux->A=(*head); 
                    break;
                }else if(pos>0){
                    temp->B=malloc(sizeof(node));
                    temp->B->value=valor;
                    temp->B->A=temp;
                    temp->B->B=NULL;
                    break;
                }
                prev=temp;
                temp=temp->B; 
                            

            }else if ((temp->A)==prev && (temp->B)==NULL){
                if ((pos==current)&&(prev->A==temp)){
                    prev->A=malloc(sizeof(node));
                    prev->A->value=valor;
                    prev->A->A=prev;
                    prev->A->B=temp;
                    temp->A=prev->A;
                    break;
                }
                else if ((pos==current) &&(prev->B==temp)){
                    prev->B=malloc(sizeof(node));
                    prev->B->value=valor;
                    prev->B->A=prev;
                    prev->B->B=temp;
                    temp->A=prev->B;
                    break;
                    
                }else if (pos>current){
                    temp->B=malloc(sizeof(node));
                    temp->B->value=valor;
                    temp->B->A=temp;
                    temp->B->B=NULL;
                    break;
                }prev=temp;
                temp=temp->B;

            }else if ((temp->B)==prev && (temp->A)==NULL){
                if ((pos==current)&&(prev->A==temp)){
                    prev->A=malloc(sizeof(node));
                    prev->A->value=valor;
                    prev->A->A=prev;
                    prev->A->B=temp;
                    temp->B=prev->A;
                    break;
                }
                else if ((pos==current) && (prev->B==temp)){
                    prev->B=malloc(sizeof(node));
                    prev->B->value=valor;
                    prev->B->A=prev;
                    prev->B->B=temp;
                    temp->B=prev->B; 
                    break;
                }
                else if(pos>current){
                    temp->A=malloc(sizeof(node));
                    temp->A->value=valor;
                    temp->A->A=temp;
                    temp->A->B=NULL;
                    break;
                }prev=temp;
                temp=temp->A;
                
                
            }else if ((temp->A)==prev || (temp->A==NULL)){
                if ((pos==0) && (temp->A==NULL)){
                    aux=(*head);
                    (*head)=malloc(sizeof(node));
                    (*head)->value=valor;
                    (*head)->B=aux;
                    aux->A=(*head);
                    break;
                }
                else if ((pos==current)&&(prev->A==temp)){
                    prev->A=malloc(sizeof(node));
                    prev->A->value=valor;
                    prev->A->A=prev;
                    prev->A->B=temp;
                    temp->A=prev->A;
                    break;
                }
                else if ((pos==current) &&(prev->B==temp)){
                    prev->B=malloc(sizeof(node));
                    prev->B->value=valor;
                    prev->B->A=prev;
                    prev->B->B=temp;
                    temp->A=prev->B;  
                    break;
                }prev=temp;
                temp=temp->B; 

            }else if ((temp->B)==prev || (temp->B==NULL)){
                if ((pos==0) && (temp->B==NULL)){
                    aux=(*head);
                    (*head)=malloc(sizeof(node));
                    (*head)->value=valor;
                    (*head)->B=aux;
                    aux->B=(*head);
                    break;
                }
                else if ((pos==current)&&(prev->A==temp)){
                    prev->A=malloc(sizeof(node));
                    prev->A->value=valor;
                    prev->A->A=prev;
                    prev->A->B=temp;
                    temp->B=prev->A;
                    break;
                }

                else if ((pos==current) && (prev->B==temp)){
                    prev->B=malloc(sizeof(node));
                    prev->B->value=valor;
                    prev->B->A=prev;
                    prev->B->B=temp;
                    temp->B=prev->B; 
                    break; 
                }prev=temp;
                temp=temp->A;
            }current++;   
        }
    }return 0;
}

int imprimir(node **head,int* started){
    if((*started)==0){
        printf("\n");
    }else{
        node *temp,*prev;
        temp=(*head);
        prev=(*head);
        while(temp){
            printf("%.4lf ",temp->value);
            if ((temp->A)==NULL && (temp->B)==NULL){
                temp=temp->B; 
                
            }else if ((temp->A)==prev && (temp->B)==NULL){
                temp=temp->B; 
                   
            }else if ((temp->B)==prev && (temp->A)==NULL){
                temp=temp->A; 
                
            }else if ((temp->A)==prev || (temp->A==NULL)){
                prev=temp;
                temp=temp->B;                
            }    
            else if ((temp->B)==prev || (temp->B==NULL)){
                prev=temp;
                temp=temp->A;
            }
        }
    }printf("\n");
    return 0;
}

int reverter(node **head,int* started){
    int pos,pos2,current=0; 
    node* temp, *prev,*pre_trocar1,*trocar1, *trocar2,*pos_trocar2;
    temp=(*head);
    prev=(*head);
    scanf("%d %d",&pos,&pos2);
    if (pos==pos2){
        return 0;
    }
    if((*started)==0){
        return 0;
    }else{
        if (pos==0){
            trocar1=temp;
            pre_trocar1=NULL;
        }
        while(temp){
            if ((temp->A)==NULL && (temp->B)==NULL){
                return 0;

            }else if ((temp->A)==prev && (temp->B)==NULL){
                if (pos2==current){
                    trocar2=temp;
                    pos_trocar2=NULL;
                }prev=temp;
                temp=temp->B; 

            }else if ((temp->B)==prev && (temp->A)==NULL){
                if (pos2==current){
                    trocar2=temp;
                    pos_trocar2=NULL;
                }prev=temp;
                temp=temp->A; 
                

            }else if ((temp->A)==prev || (temp->A==NULL)){
                if (pos==current){
                    trocar1=temp;
                    pre_trocar1=temp->A;
                }if (pos2==current){
                    trocar2=temp;
                    pos_trocar2=temp->B;
                }prev=temp;
                temp=temp->B;              
            
            
            }else if ((temp->B)==prev || (temp->B==NULL)){
                if (pos==current){
                    trocar1=temp;
                    pre_trocar1=temp->B;
                }if (pos2==current){
                    trocar2=temp;
                    pos_trocar2=temp->A;
                }prev=temp;
                temp=temp->A;
            }current++;
        }
        
    }//realizando a reversão 
    if(!(pre_trocar1)){
        (*head)=trocar2;
    } 

    else if (pre_trocar1->A==trocar1){
        pre_trocar1->A=trocar2;
    }else if (pre_trocar1->B==trocar1){
        pre_trocar1->B=trocar2; 
    }

    if (trocar2->A==pos_trocar2){
        trocar2->A=pre_trocar1;
    }else if (trocar2->B==pos_trocar2){
        trocar2->B=pre_trocar1;
    }

    if (trocar1->A==pre_trocar1){
        trocar1->A=pos_trocar2;
    }else if (trocar1->B==pre_trocar1){
        trocar1->B=pos_trocar2;
    }

    if(!(pos_trocar2)){
        ;
    }
    else if (pos_trocar2->A==trocar2){
        pos_trocar2->A=trocar1;   
    }else if (pos_trocar2->B==trocar2){
        pos_trocar2->B=trocar1;  
    }
    return 0;
}

int liberar(node **head, int *started){
    if((*started)==0){
        free(*head);
    }else{
        node *temp,*prev;
        temp=(*head);
        prev=(*head);
        while(temp){
            if ((temp->A)==NULL && (temp->B)==NULL){
                temp=temp->B; 
                free(prev);
            }else if ((temp->A)==prev && (temp->B)==NULL){
                free(prev);
                free(temp);
                temp=NULL;     
            }else if ((temp->B)==prev && (temp->A)==NULL){
                free(prev);
                free(temp);
                temp=NULL;
            }else if ((temp->A)==prev){
                free(prev);
                prev=temp;
                temp=temp->B;                  
            }    
            else if ((temp->A)==NULL){
                prev=temp;
                temp=temp->B; 
            }
            else if ((temp->B)==prev){
                free(prev);
                prev=temp;
                temp=temp->A;
            }
            else if ((temp->B)==NULL){
                prev=temp;
                temp=temp->A;
            }
        }   
    }return 0;
}