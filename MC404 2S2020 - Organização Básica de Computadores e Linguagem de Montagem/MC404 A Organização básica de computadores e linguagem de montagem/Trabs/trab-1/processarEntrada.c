#include "montador.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>

/*
    ---- Você Deve implementar esta função para a parte 1.  ----
    Essa função é chamada pela main em main.c
    Entrada da função: arquivo de texto lido e seu tamanho
*/
int processarEntrada(char* entrada, unsigned tamanho){
    //////////começo aqui
    
    char *tok, *iniLinha, *fimLinha, *sharp; 
    /*tok aponta o token atual, iniLinha aponta o início da linha atual, fimLinha aponta o fim da linha atual.
     sharp aponta o primeiro '#' da linha atual. */
    char *lexico= "ERRO LEXICO: palavra inválida na linha %d!\n";
    char *gramatical= "ERRO GRAMATICAL: palavra na linha %d!\n";
    char mnemonicos[17][8]={"ld","ldinv","ldabs","ldmq","ldmqmx","store","jump","jge","add","addabs","sub","subabs","mult","div","lsh","rsh","storend"};
    char diretivas[5][7]={".set",".org",".align",".wfill",".word"};
    int numLinha=0, erro=0, valido=0; 
    /*numLinha guarda o numero da linha atual, erro varia entre 1 e 0, se for encontrado um erro assume 1.
     valido começa valendo 0 para cada linha, e ao ser verificado que é um mnemonicos no vetor de mnemonicos ou uma diretiva no vetor de diretivas, valido assume 1.*/

    static unsigned tam= 0;
    Token *t;
    
    iniLinha=entrada; //O início da primeira linha é o início da entrada.

    if (t && gramatical){ //apenas para não correr o risco de se acusar o warning de que t ou gramatical não são usados, eles são.
        ;
    }
    
    //PRIMEIRA PARTE: adicionando tokens, já filtrando os erros lexicos===============================
    while (iniLinha != NULL) { 
        numLinha+=1;

        //Abaixo são localizadas as posições de início e fim da linha atual.
        if (numLinha==1)
            fimLinha= strchr(iniLinha,'\n');
        else if (iniLinha!=NULL)
            fimLinha= strchr(iniLinha,'\n');
        else
            break;

        //Caso o início seja igual ao fim da linha, a linha é vazia, então se pula para a próxima.
        if (iniLinha==fimLinha){
            iniLinha+=1;
            continue;
        }

        sharp=strchr(iniLinha, '#');

        //Se procura o primeiro '#' na linha atual e o transforma em '\0', de modo que o strtok a seguir para de capturar os tokens na linha quando o encontra.
        if (sharp!=NULL){
            if (fimLinha!=NULL){
                if (sharp<fimLinha){
                    *sharp='\0'; 
                }
            }else
                *sharp='\0';
        }
        
        //Encontra o fimLinha na linha atual e o transforma em '\0', de modo que o strtok a seguir para de capturar os tokens na linha quando o encontra.
        if (fimLinha!=NULL)
            *fimLinha='\0';


        tok= strtok(iniLinha," \n"); //Inicia a busca pelos tokens a partir do começo da linha.
       
        while (tok != NULL) { 
            valido=0;
    
            for(char *p=tok; *p; p++) *p=tolower(*p);  //Transforma todas as letras do token atual em caixa baixa.
            
            //Instrução----------------------------------------------------
            for (int i=0;i<17;i++){
                if (strcmp(mnemonicos[i],tok)==0){
                    tam=adicionarToken(Instrucao,tok,numLinha);
                    tok = strtok(NULL, " \n");
                    valido=1;
                    break;
                }
            }if (valido)
                continue;

            //Diretiva-----------------------------------------------------
            if (tok[0]=='.'){
                
                for (int i=0;i<5;i++){
                    if (strcmp(diretivas[i],tok)==0){
                        tam=adicionarToken(Diretiva,tok,numLinha);
                        valido=1;
                        break;
                    }
                }
            }

            //DefRotulo-----------------------------------------------------
            else if (tok[strlen(tok)-1]==':'){
                if (isdigit(tok[0])){
                    erro=1;   
                }
                if (erro==0){
                    for (int i=0;i<strlen(tok)-1;i++){
                        if (tok[i]==':' || ((isalnum(tok[i])==0 && tok[i]!='_'))){
                            erro=1;
                        }
                    }
                }
                if (erro){
                    fprintf(stderr,lexico,numLinha);
                    return 1;
                }
                tam=adicionarToken(DefRotulo,tok,numLinha);
                valido=1;
            }

            //Hexadecimal---------------------------------------------------
            else if (tok[0]=='0' && tok[1]=='x'){
                
                if (strlen(tok)<3){
                    erro=1;  
                }
                if (erro==0){
                    for (int i=2;i<strlen(tok);i++){
                        if (isdigit(tok[i])==0 && tok[i]!='a' && tok[i]!='b' && tok[i]!='c' && tok[i]!='d' && tok[i]!='e' && tok[i]!='f'){
                            erro=1;
                            
                        }
                    }
                }
                if (erro){
                    fprintf(stderr,lexico,numLinha);
                    return 1;
                }
                tam=adicionarToken(Hexadecimal,tok,numLinha);
                valido=1;
                }

            //Decimal----------------------------------------------------
            else if (isdigit(tok[0])){
                //Decimal
                for (int i=0;i<strlen(tok);i++){
                    if (isdigit(tok[i])==0){
                        erro=1;
                        break;
                    }
                }
                if (erro){
                    fprintf(stderr,lexico,numLinha);
                    return 1;
                }
                tam=adicionarToken(Decimal,tok,numLinha);
                valido=1;
            }

            //Nome-----------------------------------------------------------
            else {
                for (int i=0;i<strlen(tok);i++){
                    if (isalnum(tok[i])==0 && tok[i]!='_'){
                        erro=1;
                        break;
                    }
                }
                if (erro){
                    fprintf(stderr,lexico,numLinha);
                    return 1;
                }
                tam=adicionarToken(Nome,tok,numLinha);
                valido=1;
            }
            //---------------------------------------------------------
            
            if (valido==0){
                fprintf(stderr,lexico,numLinha);
                return 1;
            }
            tok = strtok(NULL, " \n"); //Procura pelo próximo token.
        }
        //Vai para a próxima linha, se não tiver chegado ao final da entrada.
        if (fimLinha!=NULL)
            iniLinha = fimLinha+1;  
        else
            break;
    }
    tam+=1;


    //SEGUNDA PARTE:passando pelos tokens adicionados e verificando erros gramaticais, tratando casos específicos. ========================================================
    for (unsigned i=0;i<tam;i++){
        t=recuperaToken(i);

        //Instrução-------------------------------------------------------
        if (t->tipo==Instrucao){
            if (strcmp(t->palavra,"lsh")==0 || strcmp(t->palavra,"rsh")==0 || strcmp(t->palavra,"ldmq")==0 ){
                if (i+1<tam){
                   if (recuperaToken(i+1)->tipo==Nome || recuperaToken(i+1)->tipo==Decimal || recuperaToken(i+1)->tipo==Hexadecimal)
                        erro=1;
                }
            }else{
                if ((i+1)<tam){
                   if (recuperaToken(i+1)->tipo==Nome || (recuperaToken(i+1)->tipo==Decimal && strtol(recuperaToken(i+1)->palavra,NULL,10)<1024) || recuperaToken(i+1)->tipo==Hexadecimal)
                        ;
                    else
                        erro=1;
                }else
                    erro=1;
            }
        }
        //Diretiva---------------------------------------------------------
        if (t->tipo==Diretiva){
            if (strcmp(t->palavra,".set")==0){
                if (i+2<tam){
                   if (recuperaToken(i+1)->tipo==Nome && (recuperaToken(i+2)->tipo==Hexadecimal || (recuperaToken(i+2)->tipo==Decimal && strtol(recuperaToken(i+2)->palavra,NULL,10)<1024)) ) 
                        ;
                    else
                        erro=1;
                }
                else
                    erro=1;

            }if (strcmp(t->palavra,".org")==0){
                if (i+1<tam){
                   if (recuperaToken(i+1)->tipo==Hexadecimal || (recuperaToken(i+1)->tipo==Decimal && strtol(recuperaToken(i+1)->palavra,NULL,10)<1024) ) 
                        ;
                    else
                        erro=1;
                }
                else
                    erro=1;

            }if (strcmp(t->palavra,".align")==0){
                if (i+1<tam){
                   if (recuperaToken(i+1)->tipo==Decimal && strtol(recuperaToken(i+1)->palavra,NULL,10)<1024)
                        ;
                    else
                        erro=1;
                }
                else
                    erro=1;

            }if (strcmp(t->palavra,".wfill")==0){
                if (i+2<tam){
                   if ( (recuperaToken(i+1)->tipo==Decimal && strtol(recuperaToken(i+1)->palavra,NULL,10)<1024) && (recuperaToken(i+2)->tipo==Hexadecimal || (recuperaToken(i+2)->tipo==Decimal && strtol(recuperaToken(i+1)->palavra,NULL,10)>=pow(-2,31) && strtol(recuperaToken(i+1)->palavra,NULL,10)<=(pow(2,31)-1)  ) || recuperaToken(i+2)->tipo==Nome) )
                        ;
                    else
                        erro=1;
                }
                else
                    erro=1;

            }if (strcmp(t->palavra,".word")==0){
                if (i+1<tam){
                   if (recuperaToken(i+1)->tipo==Hexadecimal || (recuperaToken(i+1)->tipo==Decimal && strtol(recuperaToken(i+1)->palavra,NULL,10)>=pow(-2,31) && strtol(recuperaToken(i+1)->palavra,NULL,10)<=(pow(2,31)-1)  )|| recuperaToken(i+1)->tipo==Nome )
                        ;
                    else
                        erro=1;
                }
                else
                    erro=1;

            }
             
        }
        //DefRotulo----------------------------------
        else if (t->tipo==DefRotulo){
            ;
        }
        //Hexadecimal----------------------------------
        else if (t->tipo==Hexadecimal){
            if (i-2>=0){
                if (recuperaToken(i-1)->tipo==Diretiva || recuperaToken(i-1)->tipo==Instrucao || (recuperaToken(i-1)->tipo==Nome && strcmp(recuperaToken(i-2)->palavra,".set")==0) ||  (recuperaToken(i-1)->tipo==Decimal && strcmp(recuperaToken(i-2)->palavra,".wfill")==0)  )
                    ;
                else
                    erro=1;
            }
            else if (i-1>=0){
                if (recuperaToken(i-1)->tipo==Diretiva || recuperaToken(i-1)->tipo==Instrucao || recuperaToken(i-1)->tipo==Nome )
                    ;
                else
                    erro=1;
            }
            else
                erro=1;   
        }
        //Decimal----------------------------------
        else if (t->tipo==Decimal){
            if (i-2>=0){
                if (recuperaToken(i-1)->tipo==Diretiva || recuperaToken(i-1)->tipo==Instrucao || (recuperaToken(i-1)->tipo==Nome && strcmp(recuperaToken(i-2)->palavra,".set")==0)  || (recuperaToken(i-1)->tipo==Decimal && strcmp(recuperaToken(i-2)->palavra,".wfill")==0)  )
                    ;
                else
                    erro=1;
            }
            else if (i-1>=0){
                if (recuperaToken(i-1)->tipo==Diretiva || recuperaToken(i-1)->tipo==Instrucao || recuperaToken(i-1)->tipo==Nome )
                    ;
                else
                    erro=1;
            }
            else
                erro=1; 
        }
        //Nome----------------------------------
        else if (t->tipo==Nome){
            if (i-2>=0){
                if (recuperaToken(i-1)->tipo==Diretiva || recuperaToken(i-1)->tipo==Instrucao || (recuperaToken(i-1)->tipo==Decimal && strcmp(recuperaToken(i-2)->palavra,".wfill")==0) )
                    ;
                else
                    erro=1;
            }
            else if (i-1>=0){
                if (recuperaToken(i-1)->tipo==Diretiva || recuperaToken(i-1)->tipo==Instrucao )
                    ;
                else
                    erro=1;
            }
        }//Verifica se foi encontrado um erro gramatical e imprime o erro.
        if (erro){
            fprintf(stderr,gramatical,recuperaToken(i)->linha);
            return 1;
        }
    }
    return 0;
}