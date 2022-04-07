//RA 220407 Lindon Jonathan S dos S P Monroe
#include <stdlib.h>
#include <stdio.h>
#include "06-autoorg.h"

int main (){
int i,N,R, custo_mtf, custo_tr, custo_c;
node *head;

scanf ("%d %d",&N,&R);

int acessos[R];
for (i=0;i<R;i++){
    scanf("%d", &acessos[i]);   
}
create(N, &head);
custo_mtf=mtf(R,acessos,&head);
freelista(&head);

create(N,&head);
custo_tr=tr(R,acessos,&head);
freelista(&head);

create(N,&head);
custo_c=count(R,acessos,&head);
freelista(&head);

printf ("%d %d %d", custo_mtf, custo_tr, custo_c);
printf ("\n");
return 0;
}
