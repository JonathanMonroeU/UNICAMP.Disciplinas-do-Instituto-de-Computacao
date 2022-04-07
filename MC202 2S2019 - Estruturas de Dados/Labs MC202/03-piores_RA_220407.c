#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
  
int K,E,conjunto=0,dif,i,j,l,n;

while(scanf("%d %d", &K,&E)!=EOF){
  char palavras[K][30], frases[E][101],fraseslow[E][101];
  int qtd[E],aux=0;
    
for (i=0;i<E;i++){
   qtd[i]=0;
}
for (i=0;i<K;i++){
   scanf("%s ",palavras[i]);
}
for (i=0;i<E;i++){
   scanf("%[^\n] ",frases[i]);
} 

for(i=0;i<E;i++){for(j=0;j<strlen(frases[i]);j++) {
     fraseslow[i][j]=(tolower(frases[i][j])); }}

for (i=0;i<E;i++){
   printf("-----%s\n",fraseslow[i]);}

/*até aqui preenchi as listas de frases, palavras e qtd=0 pra todas*/


/*esse meio é a parte de comparar e ir somando se a frase tiver mais de uma palavra chave*/ 
for(i=0;i<E;i++){for(j=0;j<K;j++){for(l=0;l<strlen(frases[i])-(strlen(palavras[j]))+1;l++){
    if (fraseslow[i][l]==palavras[j][0]){
        dif=0;
        for(n=0;n<strlen(palavras[j]);n++){
            if (fraseslow[i][l+n]!=palavras[j][n]){
                dif+=1;}}
        if(dif==0){
            qtd[i]+=1;
            }
    }
}}}

/*  Daqui pra baixo é testar as frases que tem mais e imprimir */ 
for (i=0;i<E;i++){
  if(qtd[i]>aux){
       aux=qtd[i];
     }}
 conjunto+=1;
 printf("Conjunto de desculpas #%d\n",conjunto);
for (i=0;i<E;i++){
  if (qtd[i]==aux){
    printf("%s\n",frases[i]);
  }}
 printf("\n");
}
return 0;
}
