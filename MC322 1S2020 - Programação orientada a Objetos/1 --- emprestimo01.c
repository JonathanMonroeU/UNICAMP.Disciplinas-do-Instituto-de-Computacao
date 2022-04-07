//emprestimo01 MC322

//1------------------
#include <stdio.h>  //esse programa usará valores para teste, como se fossem obtidos por scanf

int main(){
	float pat,pante,j;  //pat:parcela atual, pante:parcela anterior
	int i,n;
	j=0.01;n=5;pat=200; //valores para teste
	
	printf("Parcela 1: %.2f\n",pat);
	for (i=0;i<(n-1);i++){
		pante=pat;
    	pat=pante+(j*pante);
    	printf("Parcela %d: %.2f\n",i+2,pat);
    	
	}
	return 0;
}


//2----------------
#include <stdio.h>  //esse programa usará valores para teste, como se fossem obtidos por scanf

int parcela(float *pat, float *pante,int i,float j){
		pante=pat;
    	(*pat)=(*pante)+j*(*pante);
    	printf("Parcela %d: %.2f\n",i+2,*pat);
    	return 0;
}

int main(){
	float pat,pante,j; //pat:parcela atual, pante:parcela anterior
	int x,i,n;
	j=0.01;n=5;pat=200;  //valores para teste
	pante=pat;

    printf("Parcela 1: %.2f\n",pat);
    	
	for (i=0;i<(n-1);i++){
    	parcela(&pat,&pante,i,j);
	}
	return 0;
}


//3---------

#include <stdio.h>  //esse programa usará valores para teste, como se fossem obtidos por scanf

float pat,pante,j; //pat:parcela atual, pante:parcela anterior
int i,n;

int parcela(){
		pante=pat;
    	(pat)=(pante)+j*(pante);
    	printf("Parcela %d: %.2f\n",i+2,pat);
    	return 0;
}

int main(){
	j=0.01;n=5;pat=200;  //valores para teste
	
	printf("Parcela 1: %.2f\n",pat);;
    
	for (i=0;i<(n-1);i++){
    	parcela();
	}return 0;
}


//4-----------

#include <stdio.h>  //esse programa usará valores para teste, como se fossem obtidos por scanf

struct emp{   //emp: empréstimo
	float pat,pante,j; //pat:parcela atual, pante:parcela anterior
	int i,n;
};
typedef struct emp emp;

int parcela(emp *d){
		d->pante=d->pat;
    	(d->pat)=(d->pante)+(d->j)*(d->pante);
        printf("Parcela %d: %.2f\n",d->i+2,d->pat);
    	return 0;
}

int main(){
	emp d;
	d.j=0.01;d.n=5;d.pat=200;  //valores para teste
	d.pante=d.pat;

	printf("Parcela 1: %.2f\n",d.pat);;
    
	for ((d.i)=0;(d.i)<(d.n-1);(d.i)++){
    parcela(&d);
	}return 0;
}


//5----------

#include <stdio.h>   //esse programa usará valores para teste, como se fossem obtidos por scanf

struct emp{ //emp: empréstimo
	float pat,pante,j; //pat:parcela atual, pante:parcela anterior
	int i,n,num;
};
typedef struct emp emp;

int parcela(emp *emprestimo){
		emprestimo->pante=emprestimo->pat;
    	emprestimo->pat=emprestimo->pante+(emprestimo->j)*(emprestimo->pante);
    	
        printf("Parcela %d do empréstimo %d: %.2f\n",emprestimo->i+2,emprestimo->num,emprestimo->pat);
    	return 0;
}

int main(){
	int qtd=2; //valor  para teste, quantidade de empréstimos
	emp v[qtd-1]; //vetor de empréstimos, o empréstimo na posição 0 é o empréstimo 1
	emp emprestimo;
	int empcalc; //número do empreśtimo a ser calculado

/*Se fosse usada a função scanf, poderia ser feito um while em que
	o programa terminaria quando fosse digitado 0 ao ser perguntado 
	qual o número do empréstimo que vai ter as parcela calculadas.
	Como não há scanf, foram inseridos 2 empréstimos simultâneos de exemplo*/


	//empréstimo 1
	empcalc=1; //valor para teste 
	emprestimo=v[empcalc-1];

	emprestimo.num=1;
	emprestimo.j=0.01;emprestimo.n=5;emprestimo.pat=200;  //valores para teste
	emprestimo.pante=emprestimo.pat;

    printf("Parcela 1 do empréstimo %d: %.2f\n",empcalc,emprestimo.pat);;
    	
	for ((emprestimo.i)=0;(emprestimo.i)<(emprestimo.n-1);(emprestimo.i)++){
    	parcela(&emprestimo);
	}


	//empréstimo 2
	empcalc=2; //valor para teste
	emprestimo=v[empcalc-1];

	emprestimo.num=2;
	emprestimo.j=0.03;emprestimo.n=7;emprestimo.pat=250;  //valores para teste
	emprestimo.pante=emprestimo.pat;

    printf("Parcela 1 do empréstimo %d: %.2f\n",empcalc,emprestimo.pat);;
    	
	for ((emprestimo.i)=0;(emprestimo.i)<(emprestimo.n-1);(emprestimo.i)++){
    	parcela(&emprestimo);
	}


	return 0;
}
