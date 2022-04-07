//RA 220407 Lindon Jonathan S S P Monroe
//09-bst
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "09-bst.h"

int inserir(int x,node **root){
    node *current;
    current=*root;
    if (!*root){
        (*root)=malloc(sizeof(node));
        if (!root){
            return 1;
        }(*root)->key=x;
        (*root)->left=NULL;
        (*root)->right=NULL;
        (*root)->next=NULL;
    }else{
        while(current){
            if (x<(current->key)){
                if (!current->left){
                    node *new=malloc(sizeof(node));
                    if (!new){
                        return 1;
                    }new->key=x;
                    new->left=NULL;
                    new->right=NULL;
                    new->next=NULL;
                    current->left=new;
                    return 0;
                }else{
                current=current->left;
                }
            }else if(x>(current->key)){
                if (!current->right){
                    node *new=malloc(sizeof(node));
                    if (!new){
                        return 1;
                    }new->key=x;
                    new->left=NULL;
                    new->right=NULL;
                    new->next=NULL;
                    current->right=new;
                    return 0;
                }else{
                current=current->right;
                }
            }else if(x==(current->key)){
                return 0;
            }
        } 
    }return 0;
}

int buscar(int x,node **root){
    node *current;
    current=(*root);
    if (!*root){
        printf("%d nao pertence\n",x);
        return 0;
    }else{
        while(current){
            if (x<current->key){
                if (!current->left){
                    printf("%d nao pertence\n",x);
                    return 0;
                }else{
                current=current->left;
                }
            }else if(x>current->key){
                if (!current->right){
                    printf("%d nao pertence\n",x);
                    return 0;
                }else{
                current=current->right;
                }
            }else if(x==current->key){
                printf("%d pertence\n",x);
                return 0;
            }
        }    
    }return 0;
}   

void pre_ordem(node *root){
    if (root){
        printf("%d ",root->key);
        pre_ordem(root->left);
        pre_ordem(root->right);
    }
}

void em_ordem(node *root){
    if (root){
        em_ordem(root->left);
        printf("%d ",root->key);
        em_ordem(root->right);
    }
}

void pos_ordem(node *root){
    if (root){
        pos_ordem(root->left);
        pos_ordem(root->right);
        printf("%d ",root->key);
    }
}

void largura(node *root){
    queue *f;
    f=malloc(sizeof(queue));
    f->ini=root;
    f->fim=root;
    
    while(f->ini){
        node *p=dequeue(f);
        if (p){
            printf("%d ", p->key);
            if (p->left){
                enqueue(f, p->left);
            }if (p->right){
                enqueue(f, p->right);    
            }
        }
    }free(f);
}

int enqueue(queue *f,node *p){
    if(!f->ini){
        f->ini=p;
    }else{
        f->fim->next=p;
    }f->fim=p;
    return 0;
}

node* dequeue(queue *f){
    node *first=f->ini;
    f->ini=f->ini->next;
    return first;
}

void freetree(node *root){
    if (root){
        freetree(root->left);
        freetree(root->right);
        free(root);
    }
}
/*
int freequeue(queue *f){
    node *temp;
    temp=f->ini;
    while(temp){
        temp=temp->right;
        free(f->ini);
        f->ini=temp;
    }return 0;
}
*/
