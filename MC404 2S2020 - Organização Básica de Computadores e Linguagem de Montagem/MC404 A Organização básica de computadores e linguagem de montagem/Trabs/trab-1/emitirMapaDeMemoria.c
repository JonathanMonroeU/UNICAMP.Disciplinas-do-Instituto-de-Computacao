#include "montador.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>
#include "funcoesauxiliares.h"

int emitirMapaDeMemoria(){
    int rots[1500][3];//vetor que indica os rótulos já declarados, tem 3 colunas:posição i da palavra no vetor de tokens, linha da memória a que se refere, coluna a que se refere 
    int syms[1500][2]; //vetor que indica os símbolos já declarados, tem 3 colunas:posição i da palavra no vetor de tokens, seu valor na base decimal 
    int li=0, co=1, r=0, s=0, i=0, achado; //linha da memória, coluna da memória, quantidade de rótulos e simbolos já adicionados, i é a posição no vetor de tokens e achado serve true e false
    int ordem[1024], ult=0; //ordem guarda a posição de uma linha na memória em que foi adicionado algo, ult guarda a ultima posição dessee vetor preenchida
    for (int b=0;b<1024;b++)
        ordem[b]=-1;
    long int dado;

    Token *t,*n, *n2;  //apontadores para o token atual, para o próximo e para o duas posições à frente
    char mapa[1024][5][4]; //matriz que guarda a memória do IAS
    
    //a matriz é preenchida inicialmente com o padrão inicial da memória, emm que todas as posições contém zeros
    for (int m=0;m<1024;m++){ 
        for (int n=0;n<5;n++){
            if (n==1 || n==3)
                strcpy(mapa[m][n],"00");
            else
                strcpy(mapa[m][n],"000");
        }
    }

    int h= getNumberOfTokens(); //pega a quantidade de tokens para se ir passando pelo seu vetor, preenchendo a memória
    while(i<h){
        //se a linha atual não estiver vazia, é adicionada na lista de linhas preenchidas para se imprimir
        if ((strcmp(mapa[li][1],"00")!=0 || strcmp(mapa[li][2],"000")!=0 || strcmp(mapa[li][3],"00")!=0 || strcmp(mapa[li][4],"000")!=0) && ordem[ult]!=li){ 
            ult+=1;
            ordem[ult]=li;
        }
        if (strcmp(mapa[li][0],"000")==0) //se a linha atual ainda estiver com o número 000 padrão, o número da linha na matriz é convertido para hexadecimal para preencher esse valor
            strcpy(mapa[li][0],dectohex(li));
        t=recuperaToken(i);
        n=recuperaToken(i+1);
        
        /*Instrução------ dependendo do mnemonico, é adicionado ao mapa a instrução apropriada e são passados os argumentos necessários para a função 
        que adapta os próximos tokens para o hexadecimal que irá preenncher a posição seguinte à instrução no mapa*/
        if (t->tipo==Instrucao){
            if (strcmp(t->palavra,"ld") ==0){
                strcpy(mapa[li][co],"01");
                strcpy(mapa[li][co+1],dadotohex(t, n, r, s, rots, syms, mapa, li, co));
                i+=2;
            }else if (strcmp(t->palavra,"ldinv")==0){
                strcpy(mapa[li][co],"02");
                strcpy(mapa[li][co+1],dadotohex(t, n, r, s, rots, syms, mapa, li, co));
                i+=2;
            }else if (strcmp(t->palavra,"ldabs")==0){
                strcpy(mapa[li][co],"03");
                strcpy(mapa[li][co+1],dadotohex(t, n, r, s, rots, syms, mapa, li, co));
                i+=2;
            }else if (strcmp(t->palavra,"ldmq")==0){
                strcpy(mapa[li][co],"0A");
                i+=1;
            }else if (strcmp(t->palavra,"ldmqmx")==0){
                strcpy(mapa[li][co],"09");
                strcpy(mapa[li][co+1],dadotohex(t, n, r, s, rots, syms, mapa, li, co));
                i+=2;
            }else if (strcmp(t->palavra,"store")==0){
                strcpy(mapa[li][co],"21");
                strcpy(mapa[li][co+1],dadotohex(t, n, r, s, rots, syms, mapa, li, co));
                i+=2;
            }else if (strcmp(t->palavra,"jump")==0){
                strcpy(mapa[li][co],"0D");
                strcpy(mapa[li][co+1],dadotohex(t, n, r, s, rots, syms, mapa, li, co));
                i+=2;
            }else if (strcmp(t->palavra,"jge")==0){
                strcpy(mapa[li][co],"0F");
                strcpy(mapa[li][co+1],dadotohex(t, n, r, s, rots, syms, mapa, li, co));
                i+=2;
            }else if (strcmp(t->palavra,"add")==0){
                strcpy(mapa[li][co],"05");
                strcpy(mapa[li][co+1],dadotohex(t, n, r, s, rots, syms, mapa, li, co));
                i+=2;
            }else if (strcmp(t->palavra,"addabs")==0){
                strcpy(mapa[li][co],"07");
                strcpy(mapa[li][co+1],dadotohex(t, n, r, s, rots, syms, mapa, li, co));
                i+=2;
            }else if (strcmp(t->palavra,"sub")==0){
                strcpy(mapa[li][co],"06");
                strcpy(mapa[li][co+1],dadotohex(t, n, r, s, rots, syms, mapa, li, co));
                i+=2;
            }else if (strcmp(t->palavra,"subabs")==0){
                strcpy(mapa[li][co],"08");
                strcpy(mapa[li][co+1],dadotohex(t, n, r, s, rots, syms, mapa, li, co));
                i+=2;
            }else if (strcmp(t->palavra,"mult")==0){
                strcpy(mapa[li][co],"0B");
                strcpy(mapa[li][co+1],dadotohex(t, n, r, s, rots, syms, mapa, li, co));
                i+=2;
            }else if (strcmp(t->palavra,"div")==0){
                strcpy(mapa[li][co],"0C");
                strcpy(mapa[li][co+1],dadotohex(t, n, r, s, rots, syms, mapa, li, co));
                i+=2;
            }else if (strcmp(t->palavra,"lsh")==0){
                strcpy(mapa[li][co],"14");
                i+=1;
            }else if (strcmp(t->palavra,"rsh")==0){
                strcpy(mapa[li][co],"15");
                i+=1;
            }else if (strcmp(t->palavra,"storend")==0){
                strcpy(mapa[li][co],"12");
                strcpy(mapa[li][co+1],dadotohex(t, n, r, s, rots, syms, mapa, li, co));
                i+=2;
            }
            if (strcmp(mapa[li][co+1],"err")==0){
                fprintf(stderr,"ERRO: Rótulo ou símbolo usado mas não definido: %s\n",n->palavra);
                return 1;
            }
            
            if ((strcmp(mapa[li][1],"00")!=0 || strcmp(mapa[li][2],"000")!=0 || strcmp(mapa[li][3],"00")!=0 || strcmp(mapa[li][4],"000")!=0) && ordem[ult]!=li){
                ult+=1;
                ordem[ult]=li;
            }
            
            if (co==1){
                co=3;
            }else if (co==3){
                co=1;
                li+=1;
            }if (li==1024)
                break;
        }
        //Diretiva------dependendo da diretiva, são analisados os tipos de parâmetros possíveis de serem passados para ela, e adicionados ao mapa se for necessário, ou ao vetor de símbolos
        //no caso das diretivas .word e .wfill, os valores a serem adicionados ainda são adaptados ao formato de 10 digitos
        else if (t->tipo==Diretiva){
            if (strcmp(t->palavra,".set")==0){
                n2=recuperaToken(i+2);
                syms[s][0]=i+1;
                if (n2->tipo==Hexadecimal){
                    syms[s][1]=hextodec(n2->palavra);
                }else{
                    syms[s][1]=strtol(n2->palavra,NULL,10);
                }
                s+=1;
                i+=3;
            }
            else if (strcmp(t->palavra,".org")==0){
                if (n->tipo==Hexadecimal){
                   li=hextodec(n->palavra);
            
                   strcpy(mapa[li][0],dectohex(li));
                }else if (n->tipo==Decimal){
                    li=strtol(n->palavra,NULL,10);
                    strcpy(mapa[li][0],dectohex(li));
                }i+=2;
                co=1;
            }
            else if (strcmp(t->palavra,".align")==0){
                int divisor=strtol(n->palavra,NULL,10);
                for (int linha=li+1;linha<1024;linha++){
                    if (linha%divisor==0){
                        li=linha;
                        strcpy(mapa[li][0],dectohex(li));
                        break;
                    }
                }i+=2;
                co=1;
            }
            else if (strcmp(t->palavra,".wfill")==0){
                n2=recuperaToken(i+2);
                if (co==1){
                    if (n2->tipo==Hexadecimal){
                        dado=hextodec(n2->palavra);
                        achado=1;
                    }
                    else if (n2->tipo==Decimal){
                        dado=strtol(n2->palavra,NULL,10);
                        achado=1;   
                    }
                    //else if (n->tipo==DefRotulo){}

                    else if (n2->tipo==Nome){
                        achado=0;
                        for (int x=0;x<s;x++){
                            if (strcmp(n2->palavra,recuperaToken(syms[x][0])->palavra)==0){
                                dado=syms[x][1];
                                achado=1;
                                break;
                            }
                        }if(achado==0){
                            for (int y=0;y<r;y++){
                                achado=2;
                                for (int a=0;a<strlen(n2->palavra);a++){
                                    if(n2->palavra[a]!=recuperaToken(rots[y][0])->palavra[a]){
                                        achado=0;
                                        break;
                                    }
                                }
                                if (achado==2){
                                    for (int j=li;j<li+strtol(n->palavra,NULL,10);j++){
                                        for (int e=1;e<5;i++){
                                            strcpy(mapa[j][e],mapa[rots[y][1]][e]);
                                        }
                                        strcpy(mapa[j][0],dectohex(j));
                                    }
                                    //co=3;
                                    break;
                                }
                            }
                        }if (achado==0){
                            fprintf(stderr,"ERRO: Rótulo ou símbolo usado mas não definido: %s\n",n->palavra);
                            return 1;
                        }
                    }
                    //--------------------------------------
                    if (achado==1){
                        char num[12];
                        char numStr[12];
                        strcpy(num,dectohex(dado));
                        for (int z=0;z<10;z++){
                            if(z<10-strlen(num)){
                                numStr[z]='0';
                            }else
                                numStr[z]=num[z-(10-strlen(num))];
                        }
                        //---------------------------------------
                        for (int j=li;j<li+strtol(n->palavra,NULL,10);j++){
                            mapa[j][1][0]=numStr[0];
                            mapa[j][1][1]=numStr[1];
                            mapa[j][2][0]=numStr[2];
                            mapa[j][2][1]=numStr[3];
                            mapa[j][2][2]=numStr[4];
                            mapa[j][3][0]=numStr[5];
                            mapa[j][3][1]=numStr[6];
                            mapa[j][4][0]=numStr[7];
                            mapa[j][4][1]=numStr[8];
                            mapa[j][4][2]=numStr[9];
                            ult+=1;
                            ordem[ult]=j;
                            strcpy(mapa[j][0],dectohex(j));
                        }
                    }
                }else{
                    fprintf(stderr,"ERRO: Rótulo ou símbolo usado mas não definido: %s\n",n->palavra);
                    return 1;
                }i+=3;
                co=1;

                

                li+=strtol(n->palavra,NULL,10)+1;
                if (li==1024)
                    break;
            }
            else if (strcmp(t->palavra,".word")==0){
                if (co==1){
                    if (n->tipo==Hexadecimal){
                        dado=hextodec(n->palavra);
                        achado=1;
                    }
                    else if (n->tipo==Decimal){
                        dado=strtol(n->palavra,NULL,10);  
                        achado=1; 
                    }
                    //else if (n->tipo==DefRotulo){}

                    else if (n->tipo==Nome){
                        achado=0;
                        for (int x=0;x<s;x++){
                            if (strcmp(n->palavra,recuperaToken(syms[x][0])->palavra)==0){
                                dado=syms[x][1];
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
                                    for (int e=1;e<5;i++){
                                        strcpy(mapa[li][e],mapa[rots[y][1]][e]);
                                    }
                                    strcpy(mapa[li][0],dectohex(li));    
                                    //co=3;
                                    break;
                                }
                            }
                        }if (achado==0){
                            fprintf(stderr,"ERRO: Rótulo ou símbolo usado mas não definido: %s\n",n->palavra);
                            return 1;
                        }
                    }
                    //--------------------------------------
                    if (achado==1){
                        char num[12];
                        char numStr[12];
                        strcpy(num,dectohex(dado));
                        for (int z=0;z<10;z++){
                            if(z<10-strlen(num)){
                                numStr[z]='0';
                            }else
                                numStr[z]=num[z-(10-strlen(num))];
                        }
                        //---------------------------------------
                        mapa[li][1][0]=numStr[0];
                        mapa[li][1][1]=numStr[1];
                        mapa[li][2][0]=numStr[2];
                        mapa[li][2][1]=numStr[3];
                        mapa[li][2][2]=numStr[4];
                        mapa[li][3][0]=numStr[5];
                        mapa[li][3][1]=numStr[6];
                        mapa[li][4][0]=numStr[7];
                        mapa[li][4][1]=numStr[8];
                        mapa[li][4][2]=numStr[9];
                    }
                }
                else{
                    fprintf(stderr,"ERRO: Tentando inserir na posição da direita.\n");
                    return 1;
                }i+=2;
                co=1;
                
                if ((strcmp(mapa[li][1],"00")!=0 || strcmp(mapa[li][2],"000")!=0 || strcmp(mapa[li][3],"00")!=0 || strcmp(mapa[li][4],"000")!=0) && ordem[ult]!=li){
                    ult+=1;
                    ordem[ult]=li;
                }

                li+=1;
                if (li==1024)
                    break;
            }
        }
        //DefRotulo----------a posição do rótulo no vetor de tokens é adicionado ao vetor de rótulos, assim como a linha e a coluna que indicam no mapa
        else if (t->tipo==DefRotulo){
            rots[r][0]=i;
            rots[r][1]=li;
            rots[r][2]=co;
            r+=1;
            i+=1;
        }
        //Hexadecimal----------------------------------
        else if (t->tipo==Hexadecimal){
            i+=1;  
        }
        //Decimal----------------------------------
        else if (t->tipo==Decimal){
            i+=1;
        }
        //Nome----------------------------------
        else if (t->tipo==Nome){
            i+=1;
        }

        if ((strcmp(mapa[li][1],"00")!=0 || strcmp(mapa[li][2],"000")!=0 || strcmp(mapa[li][3],"00")!=0 || strcmp(mapa[li][4],"000")!=0) && ordem[ult]!=li){
            ult+=1;
            ordem[ult]=li;
        }

    }
    for (int d=1;d<=ult;d++){
            printf("%s %s %s %s %s\n",mapa[ordem[d]][0],mapa[ordem[d]][1],mapa[ordem[d]][2],mapa[ordem[d]][3],mapa[ordem[d]][4]);
    }
    return 0;
}

