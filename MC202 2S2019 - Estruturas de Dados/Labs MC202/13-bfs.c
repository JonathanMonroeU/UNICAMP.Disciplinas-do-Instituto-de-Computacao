//RA 220407 Lindon Jonathan S S P Monroe
//13-bfs
#include <stdio.h>
#include <stdlib.h> 
#include "13-bfs.h"

void bfs(vert *v, int *e){
    int s,i,j,k=1;
    scanf("%d",&s);
    printf("Origem da busca: %d\n",s);
    printf("Vertices alcancados e distancias:\n");
    if (v[s].adjs==-1){
        printf("%d 0\n",s);
    }

    //inicialmente todos marked já são = 0  //u.marked=false
    else{
        queue *f;                     
        v[s].dist=0;
        v[s].marked=1;              
        f=malloc(sizeof(queue));   
        f->ini=&v[s];
        f->fim=&v[s];
    
        while(f->ini){                
            vert *p=dequeue(f);     
            printf("%d %d\n",p->key,p->dist);

            j=v[p->key+k].adjs;
            while (j==-1){
                k++;
                j=v[p->key+k].adjs;
            }
            for (i=p->adjs;i<j;i++){
                if(v[e[i]].marked==0){
                    v[e[i]].dist=(p->dist)+1;
                    v[e[i]].ant=p->key;
                    enqueue(f, &v[e[i]]);
                    v[e[i]].marked=1;
                }
            }
        }free(f);
    }
}

int enqueue(queue *f,vert *p){
    if(!f->ini){
        f->ini=p;
    }else{
        f->fim->next=p;
    }f->fim=p;
    return 0;
}

vert* dequeue(queue *f){
    vert *first=f->ini;
    f->ini=f->ini->next;
    return first;
}