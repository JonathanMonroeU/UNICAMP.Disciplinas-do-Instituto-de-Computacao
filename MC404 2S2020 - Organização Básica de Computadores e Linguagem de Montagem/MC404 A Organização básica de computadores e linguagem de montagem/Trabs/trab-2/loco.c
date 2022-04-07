// [LOCO] Lógica de Controle 
#include "api_car.h"

// Implemente aqui a lógica de controle do carro, utilizando as funções da api
void user_code(void) {
    int calesq, caldir, centro, hor=0, achadaesq, achadadir, achada, arrancadas=0;   //calesq=calçada esquerda  caldir=calçada direita
    unsigned int tempo, tempo_ini;
    unsigned char luz[256];

    while(1){ 
        //calculando onde estão as bordas da pista       
        
        read_sensors(luz);
        
        achadaesq=0;
        for (int i=127;i>=0;i--){
            if (luz[i]>160){
                calesq=i;
                for(int j=i; j>=0;j--){
                    if (luz[j]<160 || j==0){
                        if ((i-j)>=10){
                            achadaesq=1;
                            break;
                        }else{
                            i=j;
                            break;
                        }
                    }
                }
            }if (achadaesq)
                break;
        }

        achadadir=0;
        for (int i=128;i<=255;i++){
            if (luz[i]>160){
                caldir=i;
                for(int j=i; j<=255;j++){
                    if (luz[j]<160 || j==255){
                        if ((j-i)>=10){
                            achadadir=1;
                            break;
                        }else{
                            i=j;
                            break;
                        }
                    }
                }
            }if (achadadir)
                break;
        }
        
        
        if (achadadir && achadaesq){
            centro=(caldir+calesq)/2;
        }
        else if(achadadir){
            centro=caldir-119;
        }
        else if (achadaesq){
            centro=calesq+119;
        }
        

        /*
        achada=0;
        for (int i=127;i>=0;i--){
            calesq=-1;
            if (luz[i]>155){
                calesq=i;
                for(int j=i-1; i>=0;i--){
                    if (luz[j]<155 || j==0){
                        if ((i-j)>=20){
                            achada=1;
                            break;
                        }else{
                            i=j;
                            break;
                        }
                    }
                }  
            }if (achada)
                break;
        }

        achada=0;
        for (int i=128;i<=255;i++){
            caldir=300;
            if (luz[i]>155){
                caldir=i;
                for(int j=i+1; i<=255;i++){
                    if (luz[j]<155 || j==255){
                        if ((j-i)>=20){
                            achada=1;
                            break;
                        }else{
                            i=j;
                            break;
                        }
                    }
                }
            }if (achada)
                break;
        }
        
        if (calesq==-1){
            calesq=caldir-239;
        }
        if (caldir==300)
            caldir=calesq+239;
            

        centro=(calesq+caldir)/2;
        */
        
       /*
        if (centro<8){
            hor=-127;
        }else if (centro>=8 && centro<16){
            hor=-120;
        }else if (centro>=16 && centro<24){
            hor=-120;
        }else if (centro>=24 && centro<32){
            hor=-115;
        }else if (centro>=32 && centro<40){
            hor=-115;
        }else if (centro>=40 && centro<48){
            hor=-100;
        }else if (centro>=48 && centro<56){
            hor=-72;
        }else if (centro>=56 && centro<64){
            hor=-64;
        }else if (centro>=64 && centro<72){
            hor=-56;
        }else if (centro>=72 && centro<80){
            hor=-48;
        }else if (centro>=80 && centro<88){
            hor=-40;
        }else if (centro>=88 && centro<96){
            hor=-35;
        }else if (centro>=96 && centro<104){
            hor=-30;
        }else if (centro>=104 && centro<112){
            hor=-25;
        }else if (centro>=112 && centro<120){
            hor=-15;
        }else if (centro>=120 && centro<128){
            hor=0;
        }else if (centro>=128 && centro<136){
            hor=0;
        }else if (centro>=136 && centro<144){
            hor=15;
        }else if (centro>=144 && centro<152){
            hor=25;
        }else if (centro>=152 && centro<160){
            hor=30;
        }else if (centro>=160 && centro<168){
            hor=35;
        }else if (centro>=168 && centro<176){
            hor=40;
        }else if (centro>=176 && centro<184){
            hor=48;
        }else if (centro>=184 && centro<192){
            hor=56;
        }else if (centro>=192 && centro<200){
            hor=64;
        }else if (centro>=200 && centro<208){
            hor=72;
        }else if (centro>=208 && centro<216){
            hor=100;
        }else if (centro>=216 && centro<224){
            hor=115;
        }else if (centro>=224 && centro<232){
            hor=115;
        }else if (centro>=232 && centro<240){
            hor=120;
        }else if (centro>=240 && centro<248){
            hor=120;
        }else if (centro>=248){
            hor=127;
        }
        */
        
        if (centro<15){
            hor=-120;
        }else if (centro<30){
            hor=-100;
        }else if (centro<60){
            hor=-90;
        }else if (centro<45){
            hor=-75;
        }else if (centro<90){
            hor=-55;
        }else if (centro<105){
            hor=-35;
        }else if (centro<120){
            hor=-20;
        }else if (centro<124){
            hor=-10;
        }else if (centro<128){
            hor=-5;
        }else if (centro>240){
            hor=120;
        }else if (centro>225){
            hor=110;
        }else if (centro>210){
            hor=105;
        }else if (centro>195){
            hor=90;
        }else if (centro>180){
            hor=75;
        }else if (centro>165){
            hor=55;
        }else if (centro>150){
            hor=35;
        }else if (centro>135){
            hor=20;
        }else if (centro>132){
            hor=10;
        }else if (centro>128){
            hor=5;
        }
        
        
        tempo=get_time();

        tempo_ini=tempo;
        set_handbreak(3);
        tempo=get_time();
        while ((tempo-tempo_ini)<5){
            tempo=get_time();
        }
        tempo_ini=tempo;
        set_motor(1,hor);
        tempo=get_time();
        if (arrancadas>24 && arrancadas <=41){
            while ((tempo-tempo_ini)<350){
                set_motor(1,hor);
                tempo=get_time();
            }
        }else if (arrancadas<=72){
            while ((tempo-tempo_ini)<170){
                set_motor(1,hor);
                tempo=get_time();
            }
        }else if (arrancadas<=132){
            while ((tempo-tempo_ini)<135){
                set_motor(1,hor);
                tempo=get_time();
            }
        }else if (arrancadas<=197){
            while ((tempo-tempo_ini)<140){
                set_motor(1,hor);
                tempo=get_time();
            }
        }else{
            while ((tempo-tempo_ini)<100){
                set_motor(1,hor);
                tempo=get_time();
            }            
        }arrancadas++;
        tempo_ini=tempo;
        set_handbreak(1);
        tempo=get_time();
        while ((tempo-tempo_ini)<1100){
            tempo=get_time();
        }
         
    }
}
