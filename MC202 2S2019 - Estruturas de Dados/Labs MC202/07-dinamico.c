//RA  220407 Lindon Jonathan S S P Monroe
//07-dinamico
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "07-dinamico.h"

int insert_first(stru_array *v){
    int inteiro,i;
    scanf("%d",&inteiro);
    if ((v->tam)<(v->tamtot)){
        (v->tam)++; (v->ini)--;
        if ((v->tam)==1){
            (v->fim)=0;
        }
        if ((v->ini)<0){
            (v->ini)=(v->tamtot)-1;
        }v->vetor1[v->ini]=inteiro;
    }else{
        (v->tamtot)=(v->tamtot)*2;
        v->vetor2=(int*)calloc ((v->tamtot),sizeof(int));
        
        if ((v->fim)-(v->ini)<0){
            for (i=0;i<=(v->fim);i++){
                v->vetor2[i]=v->vetor1[i];
            }
            for (i=(v->fim)+1+((v->tamtot)/2);i<(v->tamtot);i++){
                v->vetor2[i]=v->vetor1[i-((v->tamtot)/2)];
            }(v->ini)=(v->ini)+(v->tamtot)/2;        
        }else{
            for(i=(v->ini);i<=(v->fim);i++){
                v->vetor2[i]=v->vetor1[i];
            }
        }free(v->vetor1);
        v->vetor1=v->vetor2;
    
        (v->tam)++; (v->ini)--;
        if ((v->tam)==1){
            (v->fim)=0;
        }
        if ((v->ini)<0){
            (v->ini)=(v->tamtot)-1;
        }v->vetor1[(v->ini)]=inteiro;
    }
    return 0;
}

int remove_first(stru_array *v){
    if (v->tam!=0){
        int i;
        if (((v->tam)*100)/(v->tamtot)>25){
            (v->tam)--; (v->ini)++;
            if ((v->ini)>(v->tamtot)-1){
                (v->ini)=0;
            }
        }else{
            (v->tamtot)=(v->tamtot)/2;
            v->vetor2=(int*)calloc ((v->tamtot),sizeof(int));
        
            if ((v->fim)-(v->ini)<0){
                for (i=0;i<=(v->fim);i++){
                    v->vetor2[i]=v->vetor1[i];
                }for (i=(v->ini)-(v->tamtot);i<(v->tamtot);i++){
                    v->vetor2[i]=v->vetor1[i+(v->tamtot)];
                }(v->ini)=(v->ini)-(v->tamtot);        
            }else{
                for(i=(v->ini);i<=(v->fim);i++){
                    v->vetor2[i-(v->ini)]=v->vetor1[i];
                }(v->ini)=0;(v->fim)=(v->fim)-(v->ini);
            }free(v->vetor1);
            v->vetor1=v->vetor2;
           
            (v->tam)--; (v->ini)++;
            if ((v->ini)>(v->tamtot)-1){
                (v->ini)=0;
            }
        }
    }return 0;
}

int print_first(stru_array *v){
    if (v->tam!=0){
    printf("%d\n",(v->vetor1[v->ini]));
    }return 0;
}

int insert_last(stru_array *v){
    int inteiro,i;
    scanf("%d",&inteiro);
    if ((v->tam)<(v->tamtot)){
        (v->tam)++; (v->fim)++;
        if ((v->tam)==1){
            (v->ini)=0;
        }
        if ((v->fim)>(v->tamtot)-1){
            (v->fim)=0;
        }v->vetor1[(v->fim)]=inteiro;
    }else{
        (v->tamtot)=(v->tamtot)*2;
        v->vetor2=(int*)calloc ((v->tamtot),sizeof(int));
        
        if ((v->fim)-(v->ini)<0){
            for (i=0;i<=(v->fim);i++){
                v->vetor2[i]=v->vetor1[i];
            }
            for (i=(v->fim)+1+((v->tamtot)/2);i<(v->tamtot);i++){
                v->vetor2[i]=v->vetor1[i-1-((v->tamtot)/2)];
            }(v->ini)=(v->ini)+(v->tamtot)/2;        
        }else{
            for(i=(v->ini);i<=(v->fim);i++){
                v->vetor2[i]=v->vetor1[i];
            }
        }free(v->vetor1);
        v->vetor1=v->vetor2;
        
        (v->tam)++; (v->fim)++;
        if ((v->tam)==1){
            (v->ini)=0;
        }
        if ((v->fim)>(v->tamtot)-1){
            (v->fim)=0;
        }v->vetor1[(v->fim)]=inteiro;
    }
    return 0;
}

int remove_last(stru_array *v){
    if (v->tam!=0){
        int i;
        if (((v->tam)*100)/(v->tamtot)>25){
            (v->tam)--; (v->fim)--;
            if ((v->fim)<0){
                (v->fim)=(v->tamtot)-1;
            }
        }else{
            (v->tamtot)=(v->tamtot)/2;
            v->vetor2=(int*)calloc ((v->tamtot),sizeof(int));
        
            if ((v->fim)-(v->ini)<0){
                for (i=0;i<=(v->fim);i++){
                    v->vetor2[i]=v->vetor1[i];
                }for (i=(v->ini)-(v->tamtot);i<(v->tamtot);i++){
                    v->vetor2[i]=v->vetor1[i+(v->tamtot)];
                }(v->ini)=(v->ini)-(v->tamtot);        
            }else{
                for(i=(v->ini);i<=(v->fim);i++){
                    v->vetor2[i-(v->ini)]=v->vetor1[i];
                }(v->ini)=0;(v->fim)=(v->fim)-(v->ini);
            }free(v->vetor1);
            v->vetor1=v->vetor2;

            (v->tam)--; (v->fim)--;
            if ((v->fim)<0){
                (v->fim)=(v->tamtot)-1;
            }
        }
    }return 0;
}

int print_last(stru_array *v){
    if (v->tam!=0){
    printf("%d\n",(v->vetor1[v->fim]));
    }return 0;
}

int is_empty(stru_array *v){
    if ((v->tam)==0){
        printf("yes\n");
    }else{
        printf("no\n");
    }
    return 0;
}