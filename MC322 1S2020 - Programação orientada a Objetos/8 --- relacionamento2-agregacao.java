import java.util.Scanner;

public class Emprestimo {
    double s,j;
     int n,k;
    
    Emprestimo(double s,int n, double j) {
       this.s = s;
       this.n = n;
       this.j = j;
        k=0;
    }
    
    double proximaParcela() {
         if(k==0){
             k++;
            return s;
        }k++;
        if (k<=n)
             return s+s*j/100;
        return -1;
    }
 }

 //-------------------


public class ConjuntoEmprestimos {
    int k,max,qtd,pos;    
    Emprestimo vEmp[];
    
    
    ConjuntoEmprestimos(int max) {
       this.max=max;
        qtd=0;
        k=1;
       vEmp=new Emprestimo[max]; 
    }
    
    void adicionaEmprestimo(Emprestimo E){
        if (qtd<max){
            vEmp[qtd]=E;
            qtd++;
        }else
            System.out.println("Vetor cheio");
    }
    
    void proximasParcelas() {
        for (pos=0;pos<qtd;pos++){   //pos é a posição de cada empréstimo
             if(k==1){			//k=parcela atual 
                System.out.println("Parcela "+k+" do Emprestimo "+(pos+1)+" : "+vEmp[pos].s);
             }
            
             else if (k<=vEmp[pos].n){
                 vEmp[pos].s= vEmp[pos].s+(vEmp[pos].s)*vEmp[pos].j/100;
                System.out.println("Parcela "+k+" do Emprestimo "+(pos+1)+" : "+vEmp[pos].s);      
                
             }else if (k>vEmp[pos].n)
                vEmp[pos].s=0;
        }k++;
     }
}


//----------------

import java.util.Scanner;
public class Exer{
	public static void main(String[] args) {
		int i=0;

		ConjuntoEmprestimos Ce1= new ConjuntoEmprestimos(5);
		Emprestimo E1 = new Emprestimo(100,1,5);
		Emprestimo E2 = new Emprestimo(200,2,4);
		Emprestimo E3 = new Emprestimo(300,3,3);
		Emprestimo E4 = new Emprestimo(400,4,2);
		Emprestimo E5 = new Emprestimo(500,5,1);

		Ce1.adicionaEmprestimo(E1); 
		Ce1.adicionaEmprestimo(E2); 
		Ce1.adicionaEmprestimo(E3); 
		Ce1.adicionaEmprestimo(E4); 
		Ce1.adicionaEmprestimo(E5); 
		
		boolean aindaTemParcelas=true;
		while(aindaTemParcelas){
		    Ce1.proximasParcelas();
		    
		    aindaTemParcelas=false;
		    for (i=0;i<Ce1.qtd;i++){
		        if (Ce1.vEmp[i].s!=0) {
		            aindaTemParcelas=true;
		            break;
		        }
		    }
		}
	}
}