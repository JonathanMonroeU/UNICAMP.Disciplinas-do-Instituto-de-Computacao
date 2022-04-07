public class Alongado {
    int idade;
    String vivomorto; 
    Entremeado econectado;
    
    Alongado(int idade, String vivomorto) {
        this.idade = idade;
        this.vivomorto = vivomorto;
        this.econectado=null;
    }
   
    void conecta(Entremeado econectado){
        this.econectado=econectado;
        if (econectado.vivomorto=="morto"||vivomorto=="morto"){
            ;
        }
        else if (econectado.idade<idade){
            econectado.idade++;
            vivomorto="morto";
        }else if(idade<econectado.idade){
            idade++;
            econectado.vivomorto="morto";
        }
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

class Entremeado {
    int idade;
    String vivomorto; 
    Alongado aconectado;
    
    Entremeado(int idade, String vivomorto) {
        this.idade = idade;
        this.vivomorto = vivomorto;
        aconectado=null;
    }
   
    void conecta(Alongado aconectado){
        this.aconectado=aconectado;
        if (aconectado.vivomorto=="morto"||vivomorto=="morto"){
            ;
        }
        else if (aconectado.idade<idade){
            aconectado.idade++;
            vivomorto="morto";
        }else if(idade<aconectado.idade){
            idade++;
            aconectado.vivomorto="morto";
        }
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

//----------------------

Alongado A1 = new Alongado(1,"vivo");
Alongado A2 = new Alongado(3,"vivo");
Entremeado E1 = new Entremeado(6,"vivo");
Entremeado E2 = new Entremeado(2,"vivo");

System.out.println("Coisas antes da conexão:");
System.out.print("A1: "); A1.mostrar();
System.out.print("A2: "); A2.mostrar();
System.out.print("E1: "); E1.mostrar();
System.out.print("E2: "); E2.mostrar();

A1.conecta(E1);
A2.conecta(E2);

System.out.println("\nDepois da conexão:");
System.out.print("A1: "); A1.mostrar();
System.out.print("A2: "); A2.mostrar();
System.out.print("E1: "); E1.mostrar();
System.out.print("E2: "); E2.mostrar();

//----------------------

public class Espaco{
    Alongado vAlo[];
    Entremeado vEnt[];
    int qtdAloAdd,qtdEntAdd;
        
    Espaco(){
        vAlo=new Alongado[5]; // representa (2xposição+1) no espaço, então interage com a mesma posição no outro vetor
        vEnt=new Entremeado[5]; //representa (2xposição+2) no espaço, então interage com a próxima posição no outro vetor
        qtdAloAdd=0;
        qtdEntAdd=0;
    }
    void adicionaAlongado(Alongado C){
        if (qtdAloAdd<5){
            vAlo[qtdAloAdd]=C;
            qtdAloAdd++;
        }else
            System.out.println("Vetor cheio");
    }
    void adicionaEntremeado(Entremeado C){
        if (qtdEntAdd<5){
            vEnt[qtdEntAdd]=C;
            qtdEntAdd++;
        }else
            System.out.println("Vetor cheio");
    }
    void processa(){
        int pos=0;
        for (int i=1;i<=9;i++){
            if (i%2!=0){
                pos=(i-1)/2;
                vAlo[pos].conecta(vEnt[pos]);
            }
            else if(i%2==0){
                pos=(i-2)/2;
                vEnt[pos].conecta(vAlo[pos+1]);
            }
        }
    }
}

//------------------------------

Espaco Esp1= new Espaco();
Alongado A1 = new Alongado(2,"vivo");
Alongado A2 = new Alongado(4,"vivo");
Alongado A3 = new Alongado(1,"vivo");
Alongado A4 = new Alongado(5,"vivo");
Alongado A5 = new Alongado(2,"vivo");

Entremeado E1 = new Entremeado(1,"vivo");
Entremeado E2 = new Entremeado(2,"vivo");
Entremeado E3 = new Entremeado(5,"vivo");
Entremeado E4 = new Entremeado(3,"vivo");
Entremeado E5 = new Entremeado(1,"vivo");

Esp1.adicionaAlongado(A1); 
Esp1.adicionaAlongado(A2);
Esp1.adicionaAlongado(A3);
Esp1.adicionaAlongado(A4);
Esp1.adicionaAlongado(A5);

Esp1.adicionaEntremeado(E1);
Esp1.adicionaEntremeado(E2);
Esp1.adicionaEntremeado(E3);
Esp1.adicionaEntremeado(E4);
Esp1.adicionaEntremeado(E5);

System.out.println("Coisas antes do processamento:");
System.out.print("A1: "); A1.mostrar();
System.out.print("A2: "); A2.mostrar();
System.out.print("A3: "); A3.mostrar();
System.out.print("A4: "); A4.mostrar();
System.out.print("A5: "); A5.mostrar();
System.out.print("E1: "); E1.mostrar();
System.out.print("E2: "); E2.mostrar();
System.out.print("E3: "); E3.mostrar();
System.out.print("E4: "); E4.mostrar();
System.out.print("E5: "); E5.mostrar();

Esp1.processa();

System.out.println("\nCoisas depois do processamento:");
System.out.print("A1: "); A1.mostrar();
System.out.print("A2: "); A2.mostrar();
System.out.print("A3: "); A3.mostrar();
System.out.print("A4: "); A4.mostrar();
System.out.print("A5: "); A5.mostrar();
System.out.print("E1: "); E1.mostrar();
System.out.print("E2: "); E2.mostrar();
System.out.print("E3: "); E3.mostrar();
System.out.print("E4: "); E4.mostrar();
System.out.print("E5: "); E5.mostrar();
