public class Alongado {
    int idade;
    String vivomorto; 
    
    Alongado(int idade, String vivomorto) {
        this.idade = idade;
        this.vivomorto = vivomorto;
    }
   
    void mostrar() {
        if (vivomorto=="morto")
            System.out.println("#");
        else{
            if (idade==1)
                System.out.println(".");
            if (idade==2)
                System.out.println("´");
            if (idade==3)
                System.out.println("-");
            if (idade>=4)
                System.out.println("~");
            
        }
   }void crescer(){
        idade++;
        mostrar();
    }
    void morrer(){
        vivomorto="morto";
        mostrar();
    }
    Alongado clonar(){
        return new Alongado(idade,vivomorto);
    }
}

//-----------------------------------------

public class Entremeado {
    int idade;
    String vivomorto; //vivo=1 morto=2
    
    Entremeado(int idade, String vivomorto) {
        this.idade = idade;
        this.vivomorto = vivomorto;
    }
   
    void mostrar() {
        if (vivomorto=="morto")
            System.out.println("#");
        else{
            if (idade==1)
                System.out.println(".");
            if (idade==2)
                System.out.println("+");
            if (idade==3)
                System.out.println("*");
            if (idade>=4)
                System.out.println("@");
            
        }
   }void crescer(){
        idade++;
        mostrar();
    }
    void morrer(){
        vivomorto="morto";
        mostrar();
    }
    
}

//-----------------------------------

Alongado A1 = new Alongado(1,"vivo");
Alongado A2 = new Alongado(3,"morto");
Entremeado E1 = new Entremeado(2,"vivo");
Entremeado E2 = new Entremeado(6,"morto");

System.out.print("A1: "); A1.mostrar();
System.out.print("A2: "); A2.mostrar();
System.out.print("E1: "); E1.mostrar();
System.out.print("E2: "); E2.mostrar();

System.out.print("\n");

System.out.println("A1:"); 
A1.crescer();
A1.crescer();
A1.crescer();
A1.crescer();
A1.crescer();
A1.morrer();

System.out.print("\n");

System.out.println("E1:");
E1.crescer();
E1.crescer();
E1.morrer();

//--------------------------

Alongado A1 = new Alongado(1,"vivo");
Alongado A2=A1.clonar();

System.out.println("A2:");
A2.crescer();
A2.crescer();
System.out.print("\n");
System.out.print("A1: "); A1.mostrar();
System.out.print("A2: "); A2.mostrar();
