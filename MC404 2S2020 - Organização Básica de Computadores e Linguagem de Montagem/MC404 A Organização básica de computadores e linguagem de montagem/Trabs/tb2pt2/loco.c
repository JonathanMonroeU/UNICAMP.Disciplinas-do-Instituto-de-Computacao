// [LOCO] Lógica de Controle 
#include "api_car.h"

int esquina_ao_longe (int x, int z, int roty);
int na_esquina(int x, int z, int sentido);
int proxima_direcao (int direcao, int esq);
int ajuste_direcao (int roty, int direcao);

// Implemente aqui a lógica de controle do carro, utilizando as funções da api
void user_code(void) {
    int hor=0, x, y, z, rotx, roty, rotz, naesquina, esq=0, direcao, sentido, direcionado=0, ang_curva; 
    unsigned int tempo, tempo_ini;
    unsigned char luz[256];

    //CRUZAMENTOS:              ESQUINAS, em média:
    //1: -17 ,1, 12             1: -17 ,1, 12
    //2: 141 ,1, 8             2: 141 ,1, 8 
                            // 2,5: 290, 1, 12
    //3: 290 ,1, 203           3: 290,1, 203
                            // 3,5: 141 ,1, 203 
                            // 4: -17, 1, 203
    
    //Olhando para 1: rotação= 0, 180, 0
    //Olhando de 1 para 2: rotação= 0,90,0
    //Olhando de 2,5 para 3: rotação= 0, 0 , 0
    //Olhando de 3 para 4: rotação= 0, 270, 0

    //========================================================================
    //PARTE 1: Andando até uma esquina ao longe
    hor=0;

    get_position(&x,&y,&z);
    get_rotation(&rotx, &roty, &rotz);
    if (x<30  && z>166){ //28 //168
        esq=6;
    }else{
        esq=esquina_ao_longe(x,z,roty);
    }

    while(esq==0){ 
        
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
        while ((tempo-tempo_ini)<300){
            set_motor(1,hor);
            tempo=get_time();
        }            

        tempo_ini=tempo;
        set_handbreak(1);
        tempo=get_time();
        while ((tempo-tempo_ini)<1100){
            tempo=get_time();
        }
        get_position(&x,&y,&z);
        get_rotation(&rotx, &roty, &rotz);
        esq=esquina_ao_longe(x,z,roty);
        
    }

    //PARTE 2: Anti-horario(-90) ou horário(90)?
    get_rotation(&rotx, &roty, &rotz);

    if (esq==1 && roty>135 && roty<225){ //180
        sentido=-90;
    }else if (esq==1 && roty>225 && roty<315){ //270
        sentido=90;
    }else if (esq==2 && roty>135 && roty<225){ //180
        sentido=-90;
    }else if (esq==2 && roty>45 && roty<135){  //90
        sentido=-90;
    }else if (esq==2 && roty>225 && roty<315){ //270
        sentido=90;
    }else if (esq==3 && roty>45 && roty<135){ //90
        sentido=-90;
    }else if (esq==3 && roty>135 && roty<225){ //180
        sentido=90;
    }else if (esq==4 && ( (roty>-1 && roty<45) || (roty>315) )){ //0
        sentido=-90;
    }else if (esq==4 && roty>45 && roty<135){ //90
        sentido=90;
    }else if (esq==5 && ( (roty>-1 && roty<45) || (roty>315) )){ //0
        sentido=90;
    }else if (esq==5 && roty>225 && roty<315){ //270
        sentido=-90;
    }else if (esq==5 && roty>45 && roty<135){  //90
        sentido=90;
    }else if (esq==6 && roty>160 && roty<315){ //270
        sentido=-90;
    }else if (esq==6 && ( (roty>-1 && roty<110) || (roty>330) )){ //0
        sentido=90;
    }

    //PARTE 3: Andando até realmente o primeiro ponto chave da primeira esquina
    hor=0;
    
    if (esq==6 && sentido==-90 && x<30){ //28
        esq=6;
    }else if (esq==6 && sentido==90 && z>166) { //168
        esq=6;
    }else {
        esq=na_esquina(x,z,sentido);
    }
    get_position(&x,&y,&z);
    

    while(esq==0){ 
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
        while ((tempo-tempo_ini)<140){
            set_motor(1,hor);
            tempo=get_time();
        }            

        tempo_ini=tempo;
        set_handbreak(1);
        tempo=get_time();
        while ((tempo-tempo_ini)<1100){
            tempo=get_time();
        }
        get_position(&x,&y,&z);
        esq=na_esquina(x,z,sentido);
    }

    //PARTE 4: Fazendo curva dependendo do horario ou anti-horario
    while(1){
        //Fazendo curva
        get_rotation(&rotx, &roty, &rotz);
        direcao=proxima_direcao(roty, esq);
        
        ang_curva=10;
        if (direcao!=-50){
            while ((roty-direcao<-ang_curva) || (roty-direcao>ang_curva)){ //roty!=direcao
                tempo=get_time();
                tempo_ini=tempo;
                set_handbreak(3);
                tempo=get_time();
                while ((tempo-tempo_ini)<5){
                    tempo=get_time();
                }

                tempo_ini=tempo;
                if(esq==1 && sentido==90){
                    get_rotation(&rotx, &roty, &rotz);
                    if (roty>350)
                        break;
                }
                if(esq==6 && sentido==-90){
                    set_motor(1,-23);
                    ang_curva=2;
                }else if(esq==6 && sentido==90){  
                    set_motor(1,22);
                    ang_curva=2;
                }else{
                    set_motor(1,sentido);
                }
                tempo=get_time();
                while ((tempo-tempo_ini)<2){
                    get_rotation(&rotx, &roty, &rotz);
                    if (roty-direcao>-ang_curva && roty-direcao<ang_curva){ //roty==direcao, na verdade
                        direcionado=1;
                        break;
                    }
                    tempo=get_time();
                }            
                if (direcionado)
                    break;

                tempo_ini=tempo;
                set_handbreak(1);
                tempo=get_time();
                while ((tempo-tempo_ini)<1100){
                    tempo=get_time();
                }
                get_rotation(&rotx, &roty, &rotz);
            }
        }

        //andando reto
        esq=0;
        direcionado=0;
        
        for(int i=0;i<4;i++){ 
            
            tempo=get_time();
            tempo_ini=tempo;
            set_handbreak(3);
            tempo=get_time();
            while ((tempo-tempo_ini)<5){
                tempo=get_time();
            }


            tempo_ini=tempo;
            set_motor(1,ajuste_direcao(roty, direcao));
            tempo=get_time();
            while ((tempo-tempo_ini)<500){
                set_motor(1,ajuste_direcao(roty, direcao));
                tempo=get_time();
            }            

            tempo_ini=tempo;
            set_handbreak(1);
            tempo=get_time();
            while ((tempo-tempo_ini)<1100){
                tempo=get_time();
            }
            get_rotation(&rotx, &roty, &rotz);
        }

        esq=0;
        while(esq==0){    
            tempo=get_time();
            tempo_ini=tempo;
            set_handbreak(3);
            tempo=get_time();
            while ((tempo-tempo_ini)<5){
                tempo=get_time();
            }


            tempo_ini=tempo;
            set_motor(1,ajuste_direcao(roty, direcao));
            tempo=get_time();
            while ((tempo-tempo_ini)<500){
                set_motor(1,ajuste_direcao(roty, direcao));
                tempo=get_time();
            }            

            tempo_ini=tempo;
            set_handbreak(1);
            tempo=get_time();
            while ((tempo-tempo_ini)<1100){
                tempo=get_time();
            }
            get_position(&x,&y,&z);
            esq=esquina_ao_longe(x,z,roty);
            if (esq!=0)
                break;
            get_rotation(&rotx, &roty, &rotz);
        }

        esq=0;
        while(esq==0){ 
            
            tempo=get_time();
            tempo_ini=tempo;
            set_handbreak(3);
            tempo=get_time();
            while ((tempo-tempo_ini)<5){
                tempo=get_time();
            }

            ajuste_direcao(roty,direcao);

            tempo_ini=tempo;
            set_motor(1,ajuste_direcao(roty, direcao));
            tempo=get_time();
            while ((tempo-tempo_ini)<140){
                set_motor(1,ajuste_direcao(roty, direcao));
                tempo=get_time();
            }            

            tempo_ini=tempo;
            set_handbreak(1);
            tempo=get_time();
            while ((tempo-tempo_ini)<1100){
                tempo=get_time();
            }
            get_position(&x,&y,&z);
            esq=na_esquina(x,z,sentido);
            get_rotation(&rotx, &roty, &rotz);
        }
    }
}
//FUNÇÕES AUXILIARES================================================
int na_esquina (int x, int z, int sentido){
    if(sentido==-90){ //sentido anti-horario
        if ( (x<40) && (z<15) ){ //z=3  >>>> 15
            return 1;
        }else if ( (x>60 && x<200) && (z<9) ){ //z=2  >>>9
            return 2;
        }else if ( (x>276) && (z<40) ){ //x=282  >>>>>276
            return 3;
        }else if ( (x>250) && (z>196) ){ //z=200  >>>196
            return 4;
        }else if ( (x<30) && (z>170) ){ //x=23 >>>28     //28
            return 6;
        }else {
            return 0;
        }
    }else if(sentido==90){  //sentido horario
        if ( (x<-6) && (z<50) ){ //x=-12 >>>-6
            return 1;
        }
        else if ( (x>250) && (z<1) ){ //z=-4   >>>>3
            return 3;
        }else if ( (x>280) && (z>150) ){ //x=284
            return 4;
        }else if ( (x>120 && x<200) && (z>198) ){ //z=204
            return 5;
        }else if (x<50 && (z>166) ){ //z=172 >>>168  //168
            return 6;
        }else {
            return 0;
        }
    }else{
        return -1;
    }

}

int esquina_ao_longe (int x, int z, int roty){
    if ((x-(-12)>-40 && x-(-12)<40) && (z-3>-40 && z-3<40)  && roty>135 && roty<225){ //180
        return 1;
    }else if ((x-(-12)>-40 && x-(-12)<40) && (z-3>-40 && z-3<40)  && roty>225 && roty<315){ //270
        return 1;
    }else if ((x-146>-40 && x-146<40) && (z-2>-45 && z-2<45) && roty>135 && roty<225){ //180
        return 2;
    }else if ((x-146>-40 && x-146<40) && (z-2>-40 && z-2<40) && roty>45 && roty<135){  //90
        return 0;
    }else if ((x-146>-40 && x-146<40) && (z-2>-40 && z-2<40) && roty>225 && roty<315){ //270
        return 0;
    }else if ((x-282>-40 && x-282<40) && (z-4>-40 && z-4<40) && roty>45 && roty<135){ //90
        return 3;
    }else if ((x-282>-40 && x-282<40) && (z-4>-40 && z-4<40) && roty>135 && roty<225){ //180
        return 3;
    }else if ((x-284>-40 && x-284<40) && (z-200>-40 && z-200<40) && ( (roty>-1 && roty<45) || (roty>315) )){ //0
        return 4;
    }else if ((x-284>-40 && x-284<40) && (z-200>-40 && z-200<40) && roty>45 && roty<135){ //90
        return 4;
    }else if ((x-157>-40 && x-157<40) && (z-204>-40 && z-204<40) && ( (roty>-1 && roty<45) || (roty>315) )){ //0
        return 5;
    }else if ((x-157>-40 && x-157<40) && (z-204>-40 && z-204<40) && roty>225 && roty<315){ //270
        return 0;
    }else if ((x-157>-40 && x-157<40) && (z-204>-40 && z-204<40) && roty>45 && roty<135){  //90
        return 0;
    }else if ((x-23>-70 && x-23<70) && (z-172>-50 && z-172<50) && roty>225 && roty<315){ //270
        return 6;
    }else if ((x-23>-70 && x-23<70) && (z-172>-50 && z-172<50) && ( (roty>-1 && roty<45) || (roty>315) )){ //0
        return 6;
    }else{
        return 0;
    }
}

int proxima_direcao (int roty, int esq){
    if (esq==1 && roty>135 && roty<225){ //180
        return 92; 
    }else if (esq==1 && roty>225 && roty<315){ //273
        return 359;
    }else if (esq==2 && roty>135 && roty<225){ //182
        return 92; 
    }else if (esq==2 && roty>45 && roty<135){  //92
        return -50; //não faz curva
    }else if (esq==2 && roty>225 && roty<315){ //273
        return -50; //não faz curva
    }else if (esq==3 && roty>45 && roty<135){ //92
        return 1;
    }else if (esq==3 && roty>135 && roty<225){ //181
        return 272;
    }else if (esq==4 && ( (roty>-1 && roty<45) || (roty>315) )  ){ //1
        return 271;
    }else if (esq==4 && roty>45 && roty<135){ //91
        return 181;
    }else if (esq==5 && ( (roty>-1 && roty<45) || (roty>315) )){ //2
        return 91;
    }else if (esq==5 && roty>225 && roty<315){ //271
        return -50; //não faz curva
    }else if (esq==5 && roty>45 && roty<135){  //91
        return -50; //não faz curva
    }else if (esq==6 && roty>160 && roty<315){ //271
        return 180;
    }else if (esq==6 && ( (roty>-1 && roty<100) || (roty>330) )){ //0
        return 91;
    }else{
        return -50;
    }  
}

int ajuste_direcao (int roty, int direcao){
    if (roty>45 && roty<315){
        if (roty<direcao)
            return 4;
        else if (roty>direcao)
            return -4;
        else 
            return 0;
    }else{ //se for em torno do 0
        if (roty>1 && roty<315)
            return -4;
        else if (roty>=315)
            return 4;
        else 
            return 0;

    }
}


