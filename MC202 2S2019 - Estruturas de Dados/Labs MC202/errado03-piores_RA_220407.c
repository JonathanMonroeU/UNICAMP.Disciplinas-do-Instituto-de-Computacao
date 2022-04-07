#include <stdio.h>
#include <string.h>
#include <ctype.h>

void main(){
  
int K,E,conjunto=0,i,j,l,m;

while(scanf("%d %d", &K,&E)!=EOF){
  char palavras[K][30], frases[E][101],fraseslow[E][101],*p;
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
/*até aqui preenchi as listas de frases, palavras e qtd=0 pra todas*/
 
/*esse meio é a parte de comparar e ir somando se a frase tiver mais de uma palavra chave*/ 
for(i=0;i<E;i++){for(j=0;j<strlen(frases[i]);j++) {
     fraseslow[i][j]=(tolower(frases[i][j]));
 }}

for (m=0;m<E;m++){for (l=0;l<K;l++){
  p=strstr(fraseslow[m],palavras[l]);
   printf("||%ld||",p-fraseslow[m]+1);
   while (p-fraseslow[m]!=0){
       qtd[m]+=1;
       p=strstr(p+1,palavras[l]);
   } 
 }}

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
 
}
}
