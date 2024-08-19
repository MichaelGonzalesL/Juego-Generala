#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <ctime>

#include <string>
#include <windows.h>
#include <ctype.h>
#include "rlutil.h"
#include <MMSystem.h>

using namespace std;
using namespace rlutil;

#include "funciones.h"
#include "jugador1.h"
#include "funciones2.h"
#include "jugador2.h"
#include "puntuaciones.h"
#include "modosimulado.h"

int main(){

    char nombreIndividual[30],nombreIND[30];
    int captura1[2],p1,t1,pasoSimulado=0;
    char nombreSimulado[30], nombreSi[30];
    int capturaS[2],ps,ts;
    char multijugador[2][30],nombreM[30];
    int puntajeMulti[2],tiradasMulti[2],posM[1],valor,puntajeM,tiradasM;
    int pasoJugador1=0,pasoJugador2=0;
    int y=0;

    system("title JUEGO DE LA GENERALA");
    PlaySound(TEXT( "music.wav" ) ,NULL,SND_ASYNC);
    do{

        rlutil::hidecursor();
        rectangulo();
        showTime(" 1 JUGADOR  ",50,14,y==0);
        showTime("2 JUGADORES ",50,15,y==1);
        showTime("MODO SIMULADO",50,16,y==2);
        showTime("PUNTUACIONES",50,17,y==3);
        showTime("   SALIR    ",50,18,y==4);
        ///Cursor estetica
        switch(rlutil::getkey()){
            case 14:///UP
                    rlutil::locate(50,14+y);
                    y--;
                    if(y<0){y=0;}
            break;
            case 15:///DOWN
                    rlutil::locate(50,14+y);
                    y++;
                    if(y>4){y=4;}
            break;
            case 1:///ENTER
                   switch(y){
                        case 0:

                                JUGADOR1(nombreIndividual,captura1);
                                pasoJugador1++;

                                if(pasoJugador1==1){strcpy(nombreIND,nombreIndividual);p1=captura1[0];t1=captura1[1];}
                                else if(captura1[0]>p1){strcpy(nombreIND,nombreIndividual);p1=captura1[0];t1=captura1[1];}
                                PlaySound(TEXT( "music.wav" ) ,NULL,SND_ASYNC);
                        break;
                        case 1:
                                JUGADOR2(multijugador,puntajeMulti,tiradasMulti,posM);
                                valor=posM[0];
                                pasoJugador2++;

                                if(pasoJugador2==1){
                                    strcpy(nombreM,multijugador[valor]);puntajeM=puntajeMulti[valor];tiradasM=tiradasMulti[valor];}
                                else if(puntajeMulti[valor]>puntajeM){
                                   strcpy(nombreM,multijugador[valor]);puntajeM=puntajeMulti[valor];tiradasM=tiradasMulti[valor];}
                                PlaySound(TEXT( "music.wav" ) ,NULL,SND_ASYNC);
                        break;
                        case 2:
                                SIMULADO(nombreSimulado,capturaS);
                                pasoSimulado++;
                                if(pasoSimulado==1){strcpy(nombreSi,nombreSimulado);ps=capturaS[0];ts=capturaS[1];}
                                else if(capturaS[0]>ps){strcpy(nombreSi,nombreSimulado);ps=capturaS[0];ts=capturaS[1];}
                                PlaySound(TEXT( "music.wav" ) ,NULL,SND_ASYNC);

                        break;
                        case 3:
                                PUNTUACIONES(nombreIND,p1,t1,pasoJugador1,nombreM,puntajeM,tiradasM,pasoJugador2,nombreSi,ps,ts,pasoSimulado);
                                PlaySound(TEXT( "music.wav" ) ,NULL,SND_ASYNC);
                        break;
                        case 4:
                                system("cls");
                                rlutil::locate(50,13);
                                cout<<"HASTA LA PROXIMA";
                                getch();
                                return 0;
                        break;
                        }
            break;
        }   ///Fin cursor
    Sleep(70);
    }while(true);

return 0;
}

