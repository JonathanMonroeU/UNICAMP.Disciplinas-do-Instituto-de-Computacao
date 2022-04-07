public class Horario {
    int hora,minuto,segundo;
 }

 //---------------

 Horario horas = new Horario();
horas.hora= 13;
horas.minuto = 10;
horas.segundo = 30;

System.out.println(horas.hora + ":" + horas.minuto + ":" + horas.segundo);

//---------------

public class Horario {
    int hora,minuto,segundo;
    
    int emSegundos() {
      return hora*3600+minuto*60+segundo;
   }
}

//--------------------

Horario horas = new Horario();
horas.hora= 13;
horas.minuto = 10;
horas.segundo = 30;

System.out.println("Horário em segundos: "+horas.emSegundos());

//------------------

public class Horario {
    int hora,minuto,segundo;
    
    Horario(int hora, int minuto, int segundo){
        this.hora=hora;
        this.minuto=minuto;
        this.segundo=segundo;    
    }
    
    int emSegundos() {
      return hora*3600+minuto*60+segundo;
   }
}

//---------------

Horario horas = new Horario(13,10,30);

System.out.println(horas.hora + ":" + horas.minuto + ":" + horas.segundo);
System.out.println("Horário em segundos: "+horas.emSegundos());