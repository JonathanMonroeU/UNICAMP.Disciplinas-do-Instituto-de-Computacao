public class Grafico {
    boolean preenchido;
    char caractere;
    
    Grafico(boolean preenchido, char caractere) {
       this.preenchido = preenchido;
       this.caractere = caractere;
    }
 
    void plota(int y) {
       for (int v = 1; v < y; v++)
          System.out.print((preenchido) ? caractere : ' ');
       System.out.println(caractere);
    }
 }

 //---------------

 public class SegundoGrau{
    int a,b,c;
    Grafico saida;
    
    SegundoGrau(int a,int b,int c){
        this.a=a;
        this.b=b;
        this.c=c;
        saida=null;
    }
    void conecta(Grafico saida){
        this.saida=saida;
    }
    
    void apresenta() {
        if (saida != null) {
            int y;
            for (int x= -5; x<= 5; x++) {
                y=a*x*x+b*x+c;
                saida.plota(y);
            }
        }
    }
}

//-------------

Grafico g1 = new Grafico(true, '#');
Grafico g2 = new Grafico(false, '*');

SegundoGrau sg = new SegundoGrau(1,2,3);

sg.conecta(g1);
sg.apresenta();

sg.conecta(g2);
sg.apresenta();