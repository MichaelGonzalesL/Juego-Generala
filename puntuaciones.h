#ifndef PUNTUACIONES_H_INCLUDED
#define PUNTUACIONES_H_INCLUDED

PUNTUACIONES(char nombreI[],int p1,int t1,int jugo1,char nombreM[],int puntajeM,int tiradasM,int jugo2,char nombreSim[],int ps,int ts,int pasoSim){
    system("cls");
    int i,x;

    ///--------------Linea--------
    for(i=2;i<30;i++){
        gotoxy(60,i);
        cout<<"*"<<endl;
    }
    for(x=2;x<60;x++){
        gotoxy(x,15);
        cout<<"-"<<endl;
    }

    ///-------------Puntaje---------
    rlutil::setBackgroundColor(rlutil::COLOR::RED);
    gotoxy(23,3);
    cout<<" 1 JUGADOR/SIMULADO"<<endl;
    gotoxy(84,3);
    cout<<" 2 JUGADORES "<<endl;
    rlutil::setBackgroundColor(rlutil::COLOR::BLACK);

   ///----------------jUGADOR 1----------------------

    if(jugo1==0){gotoxy(5,10);cout<<"No hay partidas registradas para modo un jugador"<<endl;}
    else{
            gotoxy(15,10);cout<<"Nombre: "<<nombreI<<endl;
            gotoxy(15,11);cout<<"Puntaje: "<<p1<<endl;
            gotoxy(15,12);cout<<"Lanzamientos: "<<t1<<endl;
    }


    ///--------------------------Modo Simulado----------------


    if(pasoSim==0){gotoxy(7,21);cout<<"No hay partidas regitradas para modo simulado"<<endl;}
    else{
            gotoxy(15,20);cout<<"Nombre: "<<nombreSim<<endl;
            gotoxy(15,21);cout<<"Puntaje: "<<ps<<endl;
            gotoxy(15,22);cout<<"Lanzamientos: "<<ts<<endl;
    }


   ///--------------------------Jugador 2----------------

    if(jugo2==0){gotoxy(70,15);cout<<"No hay partidas regitradas para dos jugadores"<<endl;getch();}
    else{
                gotoxy(78,14);cout<<"Nombre: "<<nombreM<<endl;
                gotoxy(78,15);cout<<"Puntaje: "<<puntajeM<<endl;
                gotoxy(78,16);cout<<"Lanzamientos: "<<tiradasM<<endl;
    }

    getch();
    system("cls");

}

#endif // PUNTUACIONES_H_INCLUDED
