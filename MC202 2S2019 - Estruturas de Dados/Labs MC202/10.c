//RA 220407 Lindon Jonathan S S P Monroe
//10-bst
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "10.h"

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
        (*root)->pai=NULL;
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
                    new->pai=current;
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
                    new->pai=current;
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

//SO FAR, IT'S EQUIVALENT TO THE LAB 9

int remover (int x,node** root){
    node *current;
    current=(*root);
    while(current){
        if (x<current->key){
            if (!current->left){
                return 0;
            }else{
            current=current->left;
            }
        }else if(x>current->key){
            if (!current->right){
                return 0;
            }else{
                current=current->right;
            }
        }else if(x==current->key){
            break;
        }
    }if ((current->left)==NULL && (current->right)==NULL){
        if (current==(*root)){
            (*root)=NULL;
        }else if (current->pai->right==current){
            current->pai->right=NULL;
        }else if (current->pai->left==current){
            current->pai->left=NULL;
        }
    }else if (!current->left){
        // *Substituir current por current right*
        current->right->pai=current->pai;
        if (current==(*root)){
            (*root)=current->right;
        }else if (current->pai->right==current){
            current->pai->right=current->right;
        }else if (current->pai->left==current){
            current->pai->left=current->right;
        }
        
    }else if (!current->right){
        // *Substituir current por current left*
        current->left->pai=current->pai;
        if (current==(*root)){
            (*root)=current->left;
        }else if (current->pai->right==current){
            current->pai->right=current->left;
        }else if (current->pai->left==current){
            current->pai->left=current->left;
        }
    }else{
        node* temp=current->right;
        node* su=minimo(&temp); //su=sucessor
        if (su->pai!=current){
            // *Substituir sucessor por sucessor right
            if (su->right){
            su->right->pai=su->pai;
            }
            su->pai->left=su->right;
            su->right=current->right;
            su->right->pai=su;
        } // *Enfim substituir current por sucessor*
        
        su->pai=current->pai;
        if (current==(*root)){
            (*root)=su;
        }else if (current->pai->right==current){
            current->pai->right=su;
        }else if (current->pai->left==current){
            current->pai->left=su;
        }su->left=current->left;
        su->left->pai=su; 
               
    }free(current);
    return 0;
}


node* minimo(node** root){
    node *current;
    current=(*root);
    while(current->left){
        current=current->left;
    }return current;
}

node* maximo(node** root){
    node *current;
    current=(*root);
    while(current->right){
        current=current->right;
    }return current;
}

int predecessor(int x, node** root){
    node *current;
    current=(*root);
    while(current){
        if (x<current->key){
            if (!current->left){
                printf("nao ha");
                return 0;
            }else{
            current=current->left;
            }
        }else if(x>current->key){
            if (!current->right){
                printf("nao ha");
                return 0;
            }else{
            current=current->right;
            }
        }else if(x==current->key){
            break;
        }    
    }if (current->left){
        node* temp=current->left;
        temp=maximo(&temp);
        printf("%d",(temp)->key);
        return 0;
    }node* p=current->pai;
    while (p!=NULL && current==p->left){
        current=p;
        p=p->pai;
    }if(!p){
        printf("nao ha");
    }else{
        printf("%d",p->key);
    }return 0;
}

int sucessor(int x, node** root){
    node *current;
    current=(*root);
    while(current){
        if (x<current->key){
            if (!current->left){
                printf("nao ha");
                return 0;
            }else{
            current=current->left;
            }
        }else if(x>current->key){
            if (!current->right){
                printf("nao ha");
                return 0;
            }else{
            current=current->right;
            }
        }else if(x==current->key){
            break;
        }    
    }if (current->right){
        node* temp=current->right;
        temp=minimo(&temp);
        printf("%d",(temp)->key);
        return 0;
    }node* p=current->pai;
    while (p!=NULL && current==p->right){
        current=p;
        p=p->pai;
    }if(!p){
        printf("nao ha");
    }else{
        printf("%d",p->key);
    }return 0;
}

int buscar_intervalo(int x,int y, node** root){
    node *current;
    current=(*root);
    while(current){
        if (x<current->key && y<current->key){
            if (!(current->left)){
                printf("nenhuma");
                return 0;
            }else{
            current=current->left;
            }
        }else if(x>current->key && y>current->key){
            if (!(current->right)){
                printf("nenhuma");
                return 0;
            }else{
            current=current->right;
            }
        }else if((current->key)>=x && (current->key)<=y){
            buscar_intervalo2(x,y,current);
            return 0;
        } 
    }return 0;
}

void buscar_intervalo2(int x,int y, node *root){
    if (root){
        if ((root->key)>x){
        buscar_intervalo2(x,y, root->left);
        }if ((root->key)>=x && (root->key)<=y){
            printf("%d ",root->key);
        }if ((root->key)<y){
        buscar_intervalo2(x,y,root->right);
        }
    }
}