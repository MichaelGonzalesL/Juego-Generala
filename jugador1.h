#ifndef JUGADOR1_H_INCLUDED
#define JUGADOR1_H_INCLUDED


JUGADOR1(char nombre1[],int captura1[]){
    PlaySound(NULL,NULL,0);
    int ronda=1,puntajeTotal=0;     ///Cabecera
    int tiradas=1,tiradasTotales=0; ///Cabecera 2
    int seguir=0;                   ///Para salir del do while por si ingresa algun caracter incorrecto
    int elegir;
    int vDados[5];
    int decision;///Posicion en x para  la primera decision
    int vComb[10],puntajeParcial[10];
    bool tiene;
    int cant,servida;

    captura1[0]=puntajeTotal; /// para la tabla de puntajes final
    captura1[1]=tiradasTotales;

    ponerUno(puntajeParcial,10);///Pone  en -1
    cargaNombre(nombre1);
    cant=quieroJugar();

    while(ronda<=cant){   ///Inicio de while
        puntajeTotal=puntajeRonda(puntajeParcial);
        ponerUno(vComb,10);
        tiradasTotales++;
        cabecera(nombre1,ronda,puntajeTotal);
        cabecera2(tiradas,tiradasTotales);
        tiraDados(vDados,5); ///primer tirada de dados
        seguir=0;
///---------------------------------Generala servida--------------------
        if(ronda==1&&tiradas==1){
            servida=generalaServida(vDados,5,captura1,puntajeTotal,tiradasTotales);
            if(servida==0){
                    rlutil::setBackgroundColor(rlutil::COLOR::RED);
                    locate(45,13);cout<<"Generala servida";
                    rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
                    locate(1,16);system("pause");
                    tiradasTotales=1;puntajeTotal=100;system("cls");locate(45,13);cout<<"Generala servida";
                    ganadorIndividual(nombre1,tiradasTotales,puntajeTotal);
                    captura1[0]=puntajeTotal;
                    captura1[1]=tiradasTotales;
                    return 0;
                    }
        }
        combinaciones( vDados, 5, vComb);
        combDisponibles(vComb,puntajeParcial);
///-------------------------------------Generala servida--------------------
        while(tiradas<3&&seguir==0){

            decision=deseaContinuar(decision);
            rlutil::showcursor();

            if(decision==0){   ///Inicio if de seguir jugando
                        cout<<endl;
                        int opCant;
                        ponerUno(vComb,10);///Pone en -1
                        opCant=canTirar();
                        cualDado(vDados,opCant);
                        tiradas++;
                        tiradasTotales++;

                        system("cls");
                        cabecera(nombre1,ronda,puntajeTotal);
                        cabecera2(tiradas,tiradasTotales);
                        mostrarDados(vDados);

                        combinaciones( vDados, 5, vComb);
                        combDisponibles(vComb,puntajeParcial);

                        if(tiradas==3){
                                elegir=noSeguir(nombre1,ronda,puntajeTotal,tiradas,tiradasTotales,vDados,vComb,puntajeParcial,tiene);
                                switch(elegir){
                                    case 1:
                                            system("cls");
                                            cabecera(nombre1,ronda,puntajeTotal);
                                            cabecera2(tiradas,tiradasTotales);
                                            mostrarDados(vDados);
                                            previaTabla(puntajeParcial,vComb);
                                            locate(6,13);
                                            rlutil::setBackgroundColor(rlutil::COLOR::RED);
                                            cout<<"Elija la combinacion que desea anotar"<<endl;
                                            rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
                                            anotar(puntajeParcial,vComb);

                                            system("cls");
                                            cabecera(nombre1,ronda,puntajeTotal);
                                            cabecera2(tiradas,tiradasTotales);
                                            mostrarTabla(puntajeParcial);
                                            getch();
                                            seguir=1;
                                    break;
                                    case 2:
                                            system("cls");
                                            cabecera(nombre1,ronda,puntajeTotal);
                                            cabecera2(tiradas,tiradasTotales);
                                            tablaPreviaAnulado(puntajeParcial);
                                            anular(puntajeParcial);

                                            system("cls");
                                            cabecera(nombre1,ronda,puntajeTotal);
                                            cabecera2(tiradas,tiradasTotales);
                                            mostrarTabla(puntajeParcial);
                                            getch();
                                            seguir=1;
                                    break;
                                }
                        }
                }

            else{
                    elegir=noSeguir(nombre1,ronda,puntajeTotal,tiradas,tiradasTotales,vDados,vComb,puntajeParcial,tiene);
                    switch(elegir){
                                    case 1:
                                            system("cls");
                                            cabecera(nombre1,ronda,puntajeTotal);
                                            cabecera2(tiradas,tiradasTotales);
                                            mostrarDados(vDados);
                                            previaTabla(puntajeParcial,vComb);
                                            locate(6,13);
                                            rlutil::setBackgroundColor(rlutil::COLOR::RED);
                                            cout<<"Elija la combinacion que desea anotar"<<endl;
                                            rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
                                            anotar(puntajeParcial,vComb);

                                            system("cls");
                                            cabecera(nombre1,ronda,puntajeTotal);
                                            cabecera2(tiradas,tiradasTotales);
                                            mostrarTabla(puntajeParcial);
                                            getch();
                                            seguir=1;
                                    break;
                                    case 2:
                                            system("cls");
                                            cabecera(nombre1,ronda,puntajeTotal);
                                            cabecera2(tiradas,tiradasTotales);
                                            tablaPreviaAnulado(puntajeParcial);
                                            anular(puntajeParcial);

                                            system("cls");
                                            cabecera(nombre1,ronda,puntajeTotal);
                                            cabecera2(tiradas,tiradasTotales);
                                            mostrarTabla(puntajeParcial);
                                            getch();
                                            seguir=1;
                                    break;
                                }

                }
///Termina parte de no seguir  jugando--------------------------------------------------------------------------------


            }///Fin while 2 tiradas && seguir---------------------------------------------------------------------

    ///Mostrar puntaje hasta el momento.Mostrar y elegir puntaje segun los dados obtenidos
    puntajeTotal=puntajeRonda(puntajeParcial);
    system("cls");
    tiradas=1;
    ronda++;
    } ///Fin de while------------------------------------------------------------------------------------------------
    system("cls");

    ganadorIndividual(nombre1,tiradasTotales,puntajeTotal);
    captura1[0]=puntajeTotal;
    captura1[1]=tiradasTotales;
}


#endif // JUGADOR1_H_INCLUDED

