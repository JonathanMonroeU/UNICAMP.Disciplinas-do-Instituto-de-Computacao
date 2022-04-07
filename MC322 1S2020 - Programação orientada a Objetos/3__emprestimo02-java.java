//1------------------------------------
import java.util.Scanner;

public class Exer {

	public static void main(String[] args) {
		
		
		float pat,pante,j;  //pat:parcela atual, pante:parcela anterior
		int i,n;
		j=0.01f;n=5;pat=200; //valores para teste
		
		System.out.printf("Parcela 1: %.2f\n",pat);
		for (i=0;i<(n-1);i++){
			pante=pat;
	    	pat=pante+(j*pante);
	    	System.out.printf("Parcela %d: %.2f\n",i+2,pat);
		}
	}
}
 

//2--------------
import java.util.Scanner;

public class Exer {
	
	static double parcela(double pat, double pante,int i,double j){
    	pat=pante+j*pante;
    	System.out.printf("Parcela %d: %.2f\n",i+2,pat);
    	return pat;
	}



	public static void main(String[] args) {
		double pat,pante,j; //pat:parcela atual, pante:parcela anterior
		int x,i,n;
		j=0.01f;n=5;pat=200;  //valores para teste
		pante=pat;

	    System.out.printf("Parcela 1: %.2f\n",pat);
	    	
		for (i=0;i<(n-1);i++){
			pante=pat;
	    	pat=parcela(pat,pante,i,j);
		}
	}
}

//3------------------------------------------------
import java.util.Scanner;

public class ExTres {
    public static void main(String args[]) {
   	 Scanner teclado = new Scanner(System.in);
   	 double a,b,c,delta,x1,x2,raizdedelta;
   	 a=teclado.nextDouble();
   	 b=teclado.nextDouble();
   	 c=teclado.nextDouble();
   	 
   	 delta=b*b-(4*a*c);
   	 raizdedelta=Math.sqrt(delta);
   	 
   	 if (delta<0)
   		 System.out.println("Não possui raiz real.");
   		 
   	 else {
   		 x1=(-b+raizdedelta)/(2*a);
   		 x2=(-b-raizdedelta)/(2*a);
   	 
   		 if(x1==x2)
   			 System.out.print(x1);
   		 else
   			 System.out.print(x1+","+x2);
   	 }
    }
}

//4------------------------------------------------------

import java.util.Scanner;

public class ExQuatro {

    static void comswitch(int numero) {
   	 switch(numero) {
   		 case(1):
   			 System.out.println("janeiro");
   			 break;
   		 case(2):
   			 System.out.println("fevereiro");
   			 break;
   		 case(3):
   			 System.out.println("março");
   			 break;
   	 }
    }
    
    static void comvetor (int numero) {
   	 String meses[]= {"janeiro","fevereiro","março"};
   	 System.out.println(meses[numero-1]);
    }
    
    public static void main(String[] args) {
   	 	Scanner teclado = new Scanner(System.in);
   	 	int numero=teclado.nextInt();
   	 
   	 	if (numero>3||numero<1) {
   			System.out.println("mês não disponivel");
   	 	}
   	 	else {
   			comvetor(numero);
   			comswitch(numero);
   	 	}
    }
}

//5-------------------

import java.util.Scanner;

public class Exer {
	
	public static void main(String[] args) {
		int i, acima=0;
		double media, soma=0;
		double salarios[]= {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
	    	
		for (i=0;i<(salarios.length);i++){
			soma+=(salarios[i]);
		}
		
		media=soma/salarios.length;
		for (i=0;i<(salarios.length);i++) {
			
			if (salarios[i]>media)
				acima++;
		}
		System.out.println(acima);
	}
}



