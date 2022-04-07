#include "montador.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>
#include "funcoesauxiliares.h"

//transforma strings hexadecimais em inteiros na base decimal
int hextodec(char* hex){
    char hexadecimais[16]={'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};
    int dec=0;
   
    for (int l=0;l<16;l++){
        if (hex[strlen(hex)-1]==hexadecimais[l])
            dec+=l*1;
        if (hex[strlen(hex)-2]==hexadecimais[l])
            dec+=l*16;
        if (hex[strlen(hex)-3]==hexadecimais[l])
            dec+=l*256;
    }
    return dec;
}

//transforma inteiros na base decimal em strings hexadecimais
char * dectohex (int decInt){
    char hexadecimais[16]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
    char *hex=malloc(4);
    for (int i=2;i>=0;i--){
        hex[i]=hexadecimais[decInt%16];
        decInt=decInt/16;
    }
    return hex;
}

//transforma um hexadecimal, decimal ou nome que venha depois de uma instrução, para um hexadecimal no formato apropriado para se inserir no mapa
char * dadotohex (Token *t, Token *n, int r, int s, int rots[1500][3], int syms[1500][2], char mapa[1024][5][4], int li, int co){
    char *hex=malloc(4);
    strcpy(hex,"000");
    int achado;

    if (n->tipo==Hexadecimal){
        int i=0;
        while (n->palavra[strlen(n->palavra)-i-1]!='x' && i<3){
            if (i==0)
                hex[2]=n->palavra[strlen(n->palavra)-i-1];
            else if (i==1)
                hex[1]=n->palavra[strlen(n->palavra)-i-1];
            else if (i==2)
                hex[0]=n->palavra[strlen(n->palavra)-i-1];
            i++;    
        }
    }else if (n->tipo==Decimal){
        strcpy(hex,dectohex(strtol(n->palavra,NULL,10)) ); 
    }
    

    else if (n->tipo==Nome){
        achado=0;
        for (int x=0;x<s;x++){
            if (strcmp(n->palavra,recuperaToken(syms[x][0])->palavra)==0){
                hex=dectohex(syms[x][1]);
                achado=1;
                break;
            }
        }if(achado==0){
            for (int y=0;y<r;y++){
                achado=2;
                for (int a=0;a<strlen(n->palavra);a++){
                    if(n->palavra[a]!=recuperaToken(rots[y][0])->palavra[a]){
                        achado=0;
                        break;
                    }
                }
                if (achado==2){
                    hex=dectohex(rots[y][1]);
                    if (strcmp(t->palavra,"jump")==0){
                        if (rots[y][2]==1)
                            strcpy(mapa[li][co],"0D");
                        else if (rots[y][2]==3)
                            strcpy(mapa[li][co],"0E");
                    }else if(strcmp(t->palavra,"jge")==0){
                        if (rots[y][2]==1)
                            strcpy(mapa[li][co],"0F");
                        else if (rots[y][2]==3)
                            strcpy(mapa[li][co],"10");
                    }else if(strcmp(t->palavra,"storend")==0){
                        if (rots[y][2]==1)
                            strcpy(mapa[li][co],"12");
                        else if (rots[y][2]==3)
                            strcpy(mapa[li][co],"13");
                    }
                    break;
                }
            }
        }if (achado==0){
            strcpy(hex,"err");
        }
    }
    return hex;
}