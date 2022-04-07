//RA 220407 Lindon Jonathan S S P Monroe
//13-bfs
#include <stdio.h>
#include <stdlib.h> 
#include "13-bfs.h"

int main() {
    int qtd,qtd_e=0,i,j,pos=0,*e;
    vert *v; vert2 *v2,*current,*temp;
    scanf("%d",&qtd);

    //1ª parte: Gera listas de adjacências auxiliares para armazenar os dados
    v2=malloc((qtd+1)*(sizeof(vert2)));
    if (!v2)
        return 1;
    while(1){
        scanf("%d,%d",&i,&j);
        if (i==0 && j==0)
            break;
        
        //par i,j
        if(v2[i].key==0){
            v2[i].key=j;
            qtd_e++;
        }
        else{
            current=&v2[i];
            while(current->next){
                current=current->next;
            }current->next=malloc(sizeof(vert2));
            if (!(current->next))
                return 1;
            current->next->key=j;
            qtd_e++;
        }

        //par j,i
        if(v2[j].key==0){
            v2[j].key=i;
            qtd_e++;
        }
        else{
            current=&v2[j];
            while(current->next){
                current=current->next;
            }current->next=malloc(sizeof(vert2));
            if (!(current->next))
                return 1;
            current->next->key=i;
            qtd_e++;
        }
    }   
    
    //2ª parte: Com os dados armazenados, gera o vetor de adjacências
    v=malloc((qtd+2)*(sizeof(vert)));
    if (!v)
        return 1;
    e=malloc((qtd_e)*(sizeof(int)));
    if (!e)
        return 1;
    for (i=1;i<(qtd+1);i++){
        v[i].key=i;
        v[i].adjs=-1;
        if(v2[i].key){
            current=&v2[i];
            v[i].adjs=pos;
            e[pos]=current->key;
            pos++;
            while(current->next){
                current=current->next;
                e[pos]=current->key;
                pos++;
            }
        }
    }v[qtd+1].adjs=pos;

    //3ª parte: Realiza o BFS
    bfs(v,e);

    //printf para checar o vetor se o vetor está correto:
    /*
    for (i=0;i<(qtd+2);i++){
        printf("v%d-%d\n",i,v[i].adjs);
    }
    
    
    for (i=0;i<(qtd_e);i++){
        printf("e%d-%d\n",i,e[i]);
    }
    */
    

    //FREE:
    for (i=1;i<(qtd+1);i++){
        current=&v2[i];
        current=current->next;
        while(current){
            temp=current;
            current=current->next;
            free(temp);
        }
    }
    free(v2);free(v);free(e);
    return 0;
}