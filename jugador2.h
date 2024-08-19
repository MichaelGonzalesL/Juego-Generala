#ifndef JUGADOR2_H_INCLUDED
#define JUGADOR2_H_INCLUDED


JUGADOR2(char nombres[2][30],int puntajeTotalM[],int tiradasTotalesM[],int posMulti[]){
    PlaySound(NULL,NULL,0);
    int ronda=1;     ///Cabecera
    int tiradas=1; ///Cabecera 2
    int seguir=0;                   ///Para salir del do while por si ingresa algun caracter incorrecto
    int elegir;
    int vDados[5];
    int decision;///Posicion en x para  la primera decision
    int vComb[10],puntajeParcialM[2][10];
    bool tiene,win=true;
    int cant,servida,tam=0;

    puntajeTotalM[0]=0;
    puntajeTotalM[1]=0;
    tiradasTotalesM[0]=0;
    tiradasTotalesM[1]=0;

    menosUno(puntajeParcialM);///Pone  en -1
    multijugador(nombres);
    cant=quieroJugar();

    while(ronda<=cant){   ///Inicio de while
        tam=0;

        while(tam<2){

        puntajeTotalM[tam]=puntajeRondaM(puntajeParcialM,tam);
        ponerUno(vComb,10);
        tiradasTotalesM[tam]++;
        cabeceraM(nombres,ronda,puntajeTotalM,tam);
        cabecera2M(tiradas,tiradasTotalesM,tam);
        tiraDados(vDados,5);
        seguir=0;

///---------------------------------Generala servida--------------------

            servida=generalaServidaM(vDados,5);
            if(servida==0&&ronda==1&&tiradas==1){
                    if(win==true){
                    tiradasTotalesM[tam]=1;puntajeTotalM[tam]=100;
                    rlutil::setBackgroundColor(rlutil::COLOR::RED);locate(45,13);cout<<"Generala servida";
                    rlutil::setBackgroundColor(rlutil::COLOR::BLACK);locate(1,16);system("pause");win=false;
                    entreTurno(nombres,tiradasTotalesM,puntajeTotalM,tam,ronda);
                    }
                    else{
                        tiradasTotalesM[tam]=1;puntajeTotalM[tam]=100;
                        rlutil::setBackgroundColor(rlutil::COLOR::RED);locate(45,13);cout<<"Generala servida";getch();
                        rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
                        if(tiradasTotalesM[0]==tiradasTotalesM[1]){
                                puntajeParcialM[0][9]=100;
                                puntajeParcialM[1][9]=100;
                                entreTurno(nombres,tiradasTotalesM,puntajeTotalM,tam,ronda);
                        }
                    }
            }



        else{
///-------------------------------------Generala servida--------------------
        if(win==false&&tam==1){
                    rlutil::setBackgroundColor(rlutil::COLOR::RED);locate(48,13);cout<<"PERDISTE"<<endl;
                    rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
                    locate(1,16);system("pause");
                    ganador(nombres,tiradasTotalesM,puntajeTotalM,posMulti);return 0;
                    }


        combinaciones( vDados, 5, vComb);
        combDisponiblesM(vComb,puntajeParcialM,tam);


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
                        tiradasTotalesM[tam]++;

                        system("cls");
                        cabeceraM(nombres,ronda,puntajeTotalM,tam);
                        cabecera2M(tiradas,tiradasTotalesM,tam);
                        mostrarDados(vDados);

                        combinaciones( vDados, 5, vComb);
                        combDisponiblesM(vComb,puntajeParcialM,tam);

                        if(tiradas==3){
                                elegir=noSeguir(nombres,ronda,puntajeTotalM,tiradas,tiradasTotalesM,vDados,vComb,puntajeParcialM,tiene,tam);
                                switch(elegir){
                                    case 1:
                                            system("cls");
                                            cabeceraM(nombres,ronda,puntajeTotalM,tam);
                                            cabecera2M(tiradas,tiradasTotalesM,tam);
                                            mostrarDados(vDados);
                                            previaTablaM(puntajeParcialM,vComb,tam);
                                            locate(6,13);
                                            rlutil::setBackgroundColor(rlutil::COLOR::RED);
                                            cout<<"Elija la combinacion que desea anotar"<<endl;
                                            rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
                                            anotarM(puntajeParcialM,vComb,tam);

                                            system("cls");
                                            cabeceraM(nombres,ronda,puntajeTotalM,tam);
                                            cabecera2M(tiradas,tiradasTotalesM,tam);
                                            mostrarTablaM(puntajeParcialM,tam);
                                            getch();
                                            seguir=1;
                                    break;
                                    case 2:
                                            system("cls");
                                            cabeceraM(nombres,ronda,puntajeTotalM,tam);
                                            cabecera2M(tiradas,tiradasTotalesM,tam);
                                            tablaPreviaAnuladoM(puntajeParcialM,tam);//
                                            anularM(puntajeParcialM,tam);

                                            system("cls");
                                            cabeceraM(nombres,ronda,puntajeTotalM,tam);
                                            cabecera2M(tiradas,tiradasTotalesM,tam);
                                            mostrarTablaM(puntajeParcialM,tam);
                                            getch();
                                            seguir=1;
                                    break;
                                }
                        }
                }


            else{
                    elegir=noSeguir(nombres,ronda,puntajeTotalM,tiradas,tiradasTotalesM,vDados,vComb,puntajeParcialM,tiene,tam);
                    switch(elegir){
                                   case 1:
                                            system("cls");
                                            cabeceraM(nombres,ronda,puntajeTotalM,tam);
                                            cabecera2M(tiradas,tiradasTotalesM,tam);
                                            mostrarDados(vDados);
                                            previaTablaM(puntajeParcialM,vComb,tam);
                                            locate(6,13);
                                            rlutil::setBackgroundColor(rlutil::COLOR::RED);
                                            cout<<"Elija la combinacion que desea anotar"<<endl;
                                            rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
                                            anotarM(puntajeParcialM,vComb,tam);

                                            system("cls");
                                            cabeceraM(nombres,ronda,puntajeTotalM,tam);
                                            cabecera2M(tiradas,tiradasTotalesM,tam);
                                            mostrarTablaM(puntajeParcialM,tam);
                                            getch();
                                            seguir=1;
                                    break;
                                    case 2:
                                            system("cls");
                                            cabeceraM(nombres,ronda,puntajeTotalM,tam);
                                            cabecera2M(tiradas,tiradasTotalesM,tam);
                                            tablaPreviaAnuladoM(puntajeParcialM,tam);//
                                            anularM(puntajeParcialM,tam);

                                            system("cls");
                                            cabeceraM(nombres,ronda,puntajeTotalM,tam);
                                            cabecera2M(tiradas,tiradasTotalesM,tam);
                                            mostrarTablaM(puntajeParcialM,tam);
                                            getch();
                                            seguir=1;
                                    break;
                                }

                }///Termina parte de no seguir  jugando--------------------------------------------------------------------------------


            }///Fin while 2 ,tiradas && seguir---------------------------------------------------------------------

        puntajeTotalM[0]=puntajeRondaM(puntajeParcialM,0);
        puntajeTotalM[1]=puntajeRondaM(puntajeParcialM,1);
        entreTurno(nombres,tiradasTotalesM,puntajeTotalM,tam,ronda);
        }
        getch();
        system("cls");
        tiradas=1;
        tam++;
    }

    system("cls");
    tiradas=1;
    ronda++;
    } ///Fin de while------------------------------------------------------------------------------------------------
    system("cls");

   ganador(nombres,tiradasTotalesM,puntajeTotalM,posMulti);

}


#endif // JUGADOR2_H_INCLUDED
