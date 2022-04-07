//RA 220407 Lindon Jonathan S S P Monroe
//51-barras

#include <stdio.h>
int main (){
    int num, tam,i;
    char simb;

    while (scanf("(%d,%d,%c) ",&num,&tam,&simb)!=EOF){
        if(num<10)
            printf("  %d |",num);
        if(num>=10 && num<100)
            printf(" %d |",num);
        if(num>=100)
            printf("%d |",num);
        for (i=0;i<tam;i++)
            printf("%c",simb);
        printf(" %d\a\n",tam);
    }   
    return 0;
}   