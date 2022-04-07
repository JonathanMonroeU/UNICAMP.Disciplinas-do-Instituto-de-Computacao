//RA 220407 Lindon Jonathan S S P Monroe
//12-heapsort
#include <stdio.h>
#include <stdlib.h> 
#include "12.h"

int create(heap *A){
    int i,j,k,temp;
    for (k=0;k<A->vsize;k++){
        i=k; j=k;
        scanf("%d",&A->v[i]);
        while(j){
            j=(i-1)/2;
            if (A->v[i]>A->v[j]){ //then swap them
                temp=A->v[i];
                A->v[i]=A->v[j];
                A->v[j]=temp;
            }else{
                break;
            }i=j;
        }
    }
    return 0;
}

int heapsort(heap *A){
    int m,temp;

    for(m=(A->vsize)-1;m>=1;m--){
        temp=A->v[0];
        A->v[0]=A->v[m];
        A->v[m]=temp;
        (A->hsize)--;
        max_heapify(A);
    }return 0;
}

int max_heapify(heap *A){
    int i,j,k,temp;
    for (k=0;k<A->hsize;k++){
        i=k; j=k;
        while(j){
            j=(i-1)/2;
            if (A->v[i]>A->v[j]){ //then swap them
                temp=A->v[i];
                A->v[i]=A->v[j];                    A->v[j]=temp;
            }else{
                break;
            }i=j;
        }
    }return 0;
}