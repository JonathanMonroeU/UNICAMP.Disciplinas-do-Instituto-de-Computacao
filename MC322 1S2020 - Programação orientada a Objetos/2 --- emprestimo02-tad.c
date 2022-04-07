//emprestimo02 MC322
#include <stdio.h>   //esse programa usará valores para teste, como se fossem obtidos por scanf

struct emp{ //emp: empréstimo
	float pat,pante,j; //pat:parcela atual, pante:parcela anterior
	int i,n,num;
	int (*parcela)(struct emp*);  //modificação para TAD
};
typedef struct emp emp;

int parcela(struct emp *emprestimo){
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
	emprestimo.parcela=parcela;  //modificação para TAD

    printf("Parcela 1 do empréstimo %d: %.2f\n",empcalc,emprestimo.pat);;
    	
	for ((emprestimo.i)=0;(emprestimo.i)<(emprestimo.n-1);(emprestimo.i)++){
    	emprestimo.parcela(&emprestimo);
	}


	//empréstimo 2
	empcalc=2; //valor para teste
	emprestimo=v[empcalc-1];

	emprestimo.num=2;
	emprestimo.j=0.03;emprestimo.n=7;emprestimo.pat=250;  //valores para teste
	emprestimo.pante=emprestimo.pat;
	emprestimo.parcela=parcela;  //modificação para TAD

    printf("Parcela 1 do empréstimo %d: %.2f\n",empcalc,emprestimo.pat);;
    	
	for ((emprestimo.i)=0;(emprestimo.i)<(emprestimo.n-1);(emprestimo.i)++){
    	emprestimo.parcela(&emprestimo);  //modificação para TAD
	}


	return 0;
}
