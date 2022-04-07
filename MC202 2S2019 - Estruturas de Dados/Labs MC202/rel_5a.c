#include <stdio.h>
#include <math.h>

int main (){
    int com;
    scanf("%d",&com);
    if (com==1){
        double iCcal, 
            ca=4.19, //fixo
            mf=64.2338, 
            mq=48.7211, 
            tq=52.8,
            tf=26.6,
            teq=35.5,
            imq=0.00004, //fixo
            imf=0.00004, //fixo
            iteq=0.1, //fixo
            itq=0.1, //fixo
            itf=0.09; //fixo
        iCcal=sqrt( pow((ca*teq-ca*tq)/(tf-teq),2)  *pow(imq,2) 
                +pow( ca,2 )  *pow(imf,2) 
                +pow( ((mq*ca)*(tf-teq)+(mq*ca*(teq-tq)))/(pow(tf-teq,2) ),2 )  *pow(iteq,2) 
                +pow(-(mq*ca*(teq-tq))/(pow(tf-teq,2)),2 )  *pow(itf,2) 
                +pow( (-mq*ca)/(tf-teq),2 )  *pow(itq,2) );

        printf("%f\n",iCcal);
    return 0;

    }if (com==2){
        double icm,
            Ccal=109, //fixo
            ca=4.19,  //fixo
            cm,// don't need it
            ma=110,
            mm=101.54770, //fixo por metal
            ta=41.4,
            tm=17.6,
            teq=39.7,
            iCcal=3.0, //fixo
            ima=0.00004,  //fixo
            imm=0.00003, //fixo
            iteq=0.1, //fixo
            itm=0.08, //fixo
            ita=0.1; //fixo
        icm=sqrt( pow( (ca*teq-ca*ta)/(mm*(tm-teq)),2 )  *pow(ima,2) 
                +pow((-(Ccal+ma*ca)*(teq-ta))/(pow(mm,2)*(tm-teq)),2 )  *pow(imm,2) 
                +pow( ( (Ccal+ma*ca)*(mm*(tm-teq))-(Ccal+ma*ca)*(teq-ta)*(-mm) )/(pow(mm*(tm-teq),2)),2 )  *pow(iteq,2) 
                +pow( (-(Ccal+ma*ca)*(teq-ta)*mm)/(pow(mm*(tm-teq),2)),2 )  *pow(itm,2) 
                +pow( (-Ccal-ma*ca)/(mm*(tm-teq)),2 )  *pow(ita,2) 
                +pow( (teq-ta)/(mm*(tm-teq)),2 )  *pow(iCcal,2)   );

        printf("%f\n",icm);
    return 0;
    
    }if (com==3){
        double icm,
            Ccal=109.3459, //fixo
            ca=4.19,  //fixo
            cm,// don't need it
            ma=109.31770,
            mm=92.75990, //fixo por metal
            ta=46.4,
            tm=4.1,
            teq=43.8,
            iCcal=3, //fixo
            ima=0.00004,  //fixo
            imm=0.00003, //fixo
            iteq=0.1, //fixo
            itm=0.08, //fixo
            ita=0.1; //fixo
            cm=((Ccal+ma*ca)*(teq-ta))/(mm*(tm-teq));
            printf("%f\n",cm);

    return 0;
    }
}