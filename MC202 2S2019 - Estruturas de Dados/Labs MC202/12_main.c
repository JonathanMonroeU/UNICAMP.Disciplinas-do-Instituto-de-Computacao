//RA 220407 Lindon Jonathan S S P Monroe
//12-heapsort
#include <stdio.h>
#include <stdlib.h>
#include "12.h"

int main(){
    heap* A;
    int i;
    A=malloc(sizeof(heap));
    scanf("%d",&(A->vsize));
    A->hsize=A->vsize;

    A->v=malloc((A->vsize)*sizeof(int)); 
    create(A);
    heapsort(A);
    
    for (i=0;i<(A->vsize);i++){
    printf("%d ",A->v[i]);
    }printf("\n");

    free(A->v);
    free(A);
    return 0;
}