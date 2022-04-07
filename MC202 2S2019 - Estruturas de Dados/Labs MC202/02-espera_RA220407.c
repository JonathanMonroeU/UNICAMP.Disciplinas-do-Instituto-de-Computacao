#include <stdio.h>

int main (){
  int C, N, a,b,c,T,D,aux,vendedor,somaparcial,qtde=0;
  float soma=0,media;
  scanf("%d",&C);scanf("%d",&N);
  int vende[C];
  
  for (a=0;a<C;a++){
    vende[a]=0;
  }
  for (b=0;b<N;b++){
    scanf("%d",&T);
    scanf("%d",&D);
    aux=999;
    for(c=0;c<C;c++){
	if (vende[c]<aux){
	  aux=vende[c];
	  vendedor=c;
	}
    }if (T>=aux){
      vende[vendedor]=T+D;
    }else if (T<aux){   
      somaparcial=(vende[vendedor])-T;
      soma+=somaparcial;
      if ((vende[vendedor]-T)>10){
	  qtde+=1;
      }vende[vendedor]+=D;
    }
  } 
  media=soma/N;
  printf("Espera media para %d clientes: %.1f minutos\n",N,media);
  printf("Numero de clientes que esperaram mais que 10 minutos: %d\n",qtde);
  return 0;
  }   

