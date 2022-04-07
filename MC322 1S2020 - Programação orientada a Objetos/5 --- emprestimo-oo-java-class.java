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

 //----------------------

Emprestimo E1 = new Emprestimo(200,5,1);
Emprestimo E2 = new Emprestimo(300,3,2);

int i,p;
if (E1.n>=E2.n)
    p=E1.n;
else
    p=E2.n;

for (i=1;i<=p;i++){
        E1.s=E1.proximaParcela();
        System.out.println("Parcela "+i+" do Emprestimo E1: "+E1.s);
       
        E2.s=E2.proximaParcela();
        System.out.println("Parcela "+i+" do Emprestimo E2: "+E2.s);
}