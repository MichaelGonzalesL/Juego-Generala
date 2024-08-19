#ifndef MODOSIMULADO_H_INCLUDED
#define MODOSIMULADO_H_INCLUDED

///MODO SIMULADO///

SIMULADO(char nombreS[],int capturaS[]){
    PlaySound(NULL,NULL,0);
    int ronda=1,puntajeTotal=0;     ///Cabecera
    int tiradas=1,tiradasTotales=0; ///Cabecera 2
    int seguir=0;                   ///Para salir del do while por si ingresa algun caracter incorrecto
    int elegir;
    int vDados[5];
    int decision;///Posicion en x para  la primera decision
    int vComb[10],puntajeParcial[10];
    bool tiene;
    int cant,servida,i;

    capturaS[0]=puntajeTotal; /// para la tabla de puntajes final
    capturaS[1]=tiradasTotales;

    ponerUno(puntajeParcial,10);///Pone  en -1
    cargaNombre(nombreS);
    cant=quieroJugar();

    while(ronda<=cant){   ///Inicio de while
        puntajeTotal=puntajeRonda(puntajeParcial);
        ponerUno(vComb,10);
        tiradasTotales++;
        cabecera(nombreS,ronda,puntajeTotal);
        cabecera2(tiradas,tiradasTotales);
            rectanguloDchaM();
            rlutil::setBackgroundColor(rlutil::COLOR::RED);
            locate(55,8);cout<<"Ingrese el dado"<<endl;
            rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
            int loc=56;
            for (i=0;i<5 ;i++){
            loc++;
            rlutil::setBackgroundColor(rlutil::COLOR::RED);
            locate(loc,10);cin>>vDados[i];
            rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
            while(!(vDados[i]>0&&vDados[i]<7)){
                locate(1,14);cout<<"Ingrese un numero del 1 al 6"<<endl;
                rlutil::setBackgroundColor(rlutil::COLOR::RED);
                locate(58,11);cin>>vDados[i];
                rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
                }
            }
            locate(1,14);cout<<"                            "<<endl;

        mostrarDados(vDados);
        seguir=0;
///---------------------------------Generala servida--------------------
        if(ronda==1&&tiradas==1){
            servida=generalaServida(vDados,5,capturaS,puntajeTotal,tiradasTotales);
            if(servida==0){
                    rlutil::setBackgroundColor(rlutil::COLOR::RED);
                    locate(36,13);cout<<"Generala servida";
                    rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
                    locate(1,16);system("pause");
                    tiradasTotales=1;puntajeTotal=100;system("cls");locate(45,13);cout<<"Generala servida";
                    ganadorIndividual(nombreS,tiradasTotales,puntajeTotal);
                    capturaS[0]=puntajeTotal;
                    capturaS[1]=tiradasTotales;
                    return 0;
                    }


        }
        combinaciones(vDados, 5, vComb);
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
                        cualDadoSim(vDados,opCant);
                        tiradas++;
                        tiradasTotales++;

                        system("cls");
                        cabecera(nombreS,ronda,puntajeTotal);
                        cabecera2(tiradas,tiradasTotales);
                        mostrarDados(vDados);

                        combinaciones(vDados, 5, vComb);
                        combDisponibles(vComb,puntajeParcial);

                        if(tiradas==3){
                                elegir=noSeguir(nombreS,ronda,puntajeTotal,tiradas,tiradasTotales,vDados,vComb,puntajeParcial,tiene);
                                switch(elegir){
                                    case 1:
                                            system("cls");
                                            cabecera(nombreS,ronda,puntajeTotal);
                                            cabecera2(tiradas,tiradasTotales);
                                            mostrarDados(vDados);
                                            previaTabla(puntajeParcial,vComb);
                                            locate(6,13);
                                            rlutil::setBackgroundColor(rlutil::COLOR::RED);
                                            cout<<"Elija la combinacion que desea anotar"<<endl;
                                            rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
                                            anotar(puntajeParcial,vComb);

                                            system("cls");
                                            cabecera(nombreS,ronda,puntajeTotal);
                                            cabecera2(tiradas,tiradasTotales);
                                            mostrarTabla(puntajeParcial);
                                            getch();
                                            seguir=1;
                                    break;
                                    case 2:
                                            system("cls");
                                            cabecera(nombreS,ronda,puntajeTotal);
                                            cabecera2(tiradas,tiradasTotales);
                                            tablaPreviaAnulado(puntajeParcial);
                                            anular(puntajeParcial);

                                            system("cls");
                                            cabecera(nombreS,ronda,puntajeTotal);
                                            cabecera2(tiradas,tiradasTotales);
                                            mostrarTabla(puntajeParcial);
                                            getch();
                                            seguir=1;
                                    break;
                                }
                        }
                }

            else{
                    elegir=noSeguir(nombreS,ronda,puntajeTotal,tiradas,tiradasTotales,vDados,vComb,puntajeParcial,tiene);
                    switch(elegir){
                                    case 1:
                                            system("cls");
                                            cabecera(nombreS,ronda,puntajeTotal);
                                            cabecera2(tiradas,tiradasTotales);
                                            mostrarDados(vDados);
                                            previaTabla(puntajeParcial,vComb);
                                            locate(6,13);
                                            rlutil::setBackgroundColor(rlutil::COLOR::RED);
                                            cout<<"Elija la combinacion que desea anotar"<<endl;
                                            rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
                                            anotar(puntajeParcial,vComb);

                                            system("cls");
                                            cabecera(nombreS,ronda,puntajeTotal);
                                            cabecera2(tiradas,tiradasTotales);
                                            mostrarTabla(puntajeParcial);
                                            getch();
                                            seguir=1;
                                    break;
                                    case 2:
                                            system("cls");
                                            cabecera(nombreS,ronda,puntajeTotal);
                                            cabecera2(tiradas,tiradasTotales);
                                            tablaPreviaAnulado(puntajeParcial);
                                            anular(puntajeParcial);

                                            system("cls");
                                            cabecera(nombreS,ronda,puntajeTotal);
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

    ganadorIndividual(nombreS,tiradasTotales,puntajeTotal);
    capturaS[0]=puntajeTotal;
    capturaS[1]=tiradasTotales;

}


#endif // MODOSIMULADO_H_INCLUDED
