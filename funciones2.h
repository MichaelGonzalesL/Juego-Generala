#ifndef FUNCIONES2_H_INCLUDED
#define FUNCIONES2_H_INCLUDED

///PROTOTIPOS

void multijugador(char nombres[2][30]);///Carga el nombre
int puntajeRondaM(int puntajeParcial[2][10],int tam);///Devuelve el puntaje de  cada jugador dependiendo de tam.
void  menosUno(int matriz[2][10]);///Pone toda la matriz en menos uno
void cabeceraM(char nombre[2][30],int ronda,int puntaje[],int tam);///Funcion para mostrar en la parte superior el nombre del jugador                                                  ///la ronda en la que estan y el puntaje total del partido.
void cabecera2M(int tiradas,int tiradasT[],int tam);///Funcion para mostrar en cabecera las tiraas por ronda y las totales en el juego.
bool combDisponiblesM(int vComb[], int puntajeParcialM[2][10],int tam);///Muestra solo los puntajes que  puede anotar
int noSeguir(char nombres[2][30],int ronda,int puntajeTotalM[],int tiradas,int tiradasTotalesM[],int vDados[],int vComb[],int puntajeParcialM[2][10],bool tiene,int tam);
void anotarM(int puntajeParcialM[2][10], int vComb[],int tam);
void  mostrarTablaM(int puntajeParcialM[2][10],int tam);
void anularM(int puntajeParcialM[2][10],int tam);
void  previaTablaM(int puntajeParcialM[2][10],int vComb[],int tam);
int generalaServidaM(int vDados[],int tam);
void  tablaPreviaAnuladoM(int puntajeParcialM[2][10],int tam);
void entreTurno(char nombres[2][30],int tiradasTotalesM[],int puntajeTotalM[],int tam,int rondas);
void ganador(char nombres[2][30],int tiradasTotalesM[],int puntajeTotalM[],int posMultiV[]);

///FUNCIONES SIMPLES


void multijugador(char nombres[2][30]){
    system("cls");
    for(int i=0; i<2;i++){
    rectangulo();
    rlutil::locate(43,15);
    cout<<"Ingrese nombre Jugador "<<i+1<<": "<<endl;
    rlutil::setBackgroundColor(rlutil::COLOR::RED);
    gotoxy(45,17);
    fflush(stdin);
    cin.getline(nombres[i],30);
    rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
    system("cls");
    }
}

int puntajeRondaM(int puntajeParcial[2][10],int tam){
    int j,total=0;
        for(j=0;j<10;j++){
            if(puntajeParcial[tam][j]!=-1){total+=puntajeParcial[tam][j];}
        }
return total;
}

void  menosUno(int matriz[2][10]){
    int i,j;
    for(i=0;i<2;i++){
        for(j=0;j<10;j++){matriz[i][j]=-1;}
    }
}

///FUNCIONES COMPUESTAS


void cabeceraM(char nombre[2][30],int ronda,int puntaje[],int tam){///Funcion para mostrar en la cabecera superior el nombre del jugador en esa ronda,
                                                   ///la ronda en la que estan y el puntaje total del partido.
            cout<<" TURNO DE "<<nombre[tam];
            cout<<" | ";
            cout<<" RONDA N"<<(char)248;
            cout<<ronda;
            cout<<" | ";
            cout<<" PUNTAJE TOTAL ";
            cout<<puntaje[tam];
            cout<<endl;
            line2();
            cout<<endl;

 }


void cabecera2M(int tiradas,int tiradasT[],int tam){///Funcion para mostrar en cabecera las tiraas por ronda y las totales en el juego.

    cout<<" TIRADA N"<<(char)248;
    cout<<tiradas;
    cout<<" - TIRADAS TOTALES ";
    cout<<tiradasT[tam];
    cout<<endl;
    line2();
    cout<<endl;
 }


int noSeguir(char nombres[2][30],int ronda,int puntajeTotalM[],int tiradas,int tiradasTotalesM[],int vDados[],int vComb[],int puntajeParcialM[2][10],bool tiene,int tam){

            rlutil::hidecursor();
            system("cls");
            int elegir=0;
            int y=0;
            cabeceraM(nombres,ronda,puntajeTotalM,tam);
            cabecera2M(tiradas,tiradasTotalesM,tam);
            mostrarDados(vDados);
            cout<<endl;
            combinaciones(vDados,5,vComb);
            tiene=combDisponiblesM(vComb,puntajeParcialM,tam);
            if(tiene==true){
            do{
                rlutil::setColor(rlutil::COLOR::WHITE);
                showTime(" Combinaciones ganadoras disponibles ",1,18,y==0);
                showTime("      Anular una combinacion         ",1,19,y==1);
                switch(rlutil::getkey()){
                    case 14:///UP
                            rlutil::locate(1,18+y);
                            //cout<<" "<<endl;
                            y--;
                            if(y<0){y=0;}
                    break;
                    case 15:///DOWN
                            rlutil::locate(1,18+y);
                            //cout<<" "<<endl;
                            y++;
                            if(y>1){y=1;}
                    break;
                    case 1:///ENTER
                           switch(y){
                                case 0:
                                        elegir=1;
                                        return elegir;
                                break;
                                case 1:
                                        elegir=2;
                                        return elegir;
                                break;
                                }
                    break;
                }
            }while(elegir==0);
            }
            else{
                system("cls");
                gotoxy(22,15);
                cout<<"No tiene combinaciones para elegir,presione enter para anular una combinacion"<<endl;
                getch();
                elegir=2;
                return elegir;
            }

 }


bool combDisponiblesM(int vComb[], int puntajeParcialM[2][10],int tam){
                int i;
                bool tiene=true;
                char nCombinacion[4][10]={"Escalera","Full","Poker","Generala"};

                rectanguloDchaM();
                rlutil::locate(54,8);
                rlutil::setBackgroundColor(rlutil::COLOR::RED);
                cout<<"Combinaciones disponibles"<<endl;
                rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
                int cont=0,j=9;

                    for(i=0;i<6;i++){
                        if((vComb[i]!=-1)&&(puntajeParcialM[tam][i]==-1)){
                            j++;
                            rlutil::locate(57,j);
                            cout<<i+1<<")"<<"Puntos al "<<i+1<<" : "<<vComb[i]<<endl;
                            cont++;
                        }
                    }
                for(i=6;i<10;i++){
                    if(vComb[i]!=-1&&puntajeParcialM[tam][i]==-1){
                        j++;
                        rlutil::locate(57,j);
                        cout<<i+1<<")"<<nCombinacion[i-6]<<" : "<<vComb[i]<<endl; ///MATRIZ
                        cont++;
                    }
                }
                if(cont==0){tiene=false;}
return tiene;
}


void anotarM(int puntajeParcialM[2][10], int vComb[],int tam){
    int anoto=0,opcion;

    do{
        cin>>opcion;
        if(opcion>=1&&opcion<=10){
                if(vComb[opcion-1]!=-1&&puntajeParcialM[tam][opcion-1]==-1){
                        puntajeParcialM[tam][opcion-1]=vComb[opcion-1];
                        anoto=1;
                    }
                else{cout<<"Vuelva a escoger"<<endl;}
        }
        else{cout<<"Vuelva a escoger"<<endl;}

    }while(anoto==0);
}


void  mostrarTablaM(int puntajeParcialM[2][10],int tam){
        int i,j=10;
        char nCombinacion[4][10]={"Escalera","Full","Poker","Generala"};

        rectanguloTabla();
        rlutil::locate(48,8);
        rlutil::setBackgroundColor(rlutil::COLOR::RED);
        cout<<"Puntaje anotado"<<endl;
        rlutil::setBackgroundColor(rlutil::COLOR::BLACK);

        for(i=0;i<6;i++){
            if(puntajeParcialM[tam][i]==-1){
                    j++;
                    rlutil::locate(45,j);
                    cout<<"Juego de "<<i+1<<"|"<<"  "<<endl;}
            else{
                j++;
                rlutil::locate(45,j);
                cout<<"Juego de "<<i+1<<"|"<<puntajeParcialM[tam][i]<<endl;}
        }
        for(i=6;i<10;i++){
            if(puntajeParcialM[tam][i]==-1){
                    j++;
                    rlutil::locate(45,j);
                    cout<<nCombinacion[i-6];separa(55,j);cout<<"  "<<endl;}
            else{
                j++;
                rlutil::locate(45,j);
                cout<<nCombinacion[i-6];separa(55,j);cout<<puntajeParcialM[tam][i]<<endl;}
        }
}


void anularM(int puntajeParcialM[2][10],int tam){
    int anoto=0,opcion,j=10;

    do{
        gotoxy(1,j);
        j+=2;
        cin>>opcion;
        if(opcion>=1&&opcion<=10){
                if(puntajeParcialM[tam][opcion-1]==-1){
                        puntajeParcialM[tam][opcion-1]=0;
                        anoto=1;
                    }
                else{cout<<"Vuelva a escoger"<<endl;}
        }
        else{cout<<"Vuelva a escoger"<<endl;}

    }while(anoto==0);

}


void  previaTablaM(int puntajeParcialM[2][10],int vComb[],int tam){
        int i,j=10;
        char nCombinacion[4][10]={"Escalera","Full","Poker","Generala"};

        rectanguloDchaM();
        rlutil::locate(57,8);
        rlutil::setBackgroundColor(rlutil::COLOR::RED);
        cout<<"Anote la combinacion"<<endl;

        for(i=0;i<6;i++){

            if(vComb[i]!=-1&&puntajeParcialM[tam][i]==-1){
                j++;
                rlutil::locate(56,j);
                rlutil::setBackgroundColor(rlutil::COLOR::RED);
                cout<<i+1<<")"<<"Juego de "<<i+1<<"|"<<vComb[i]<<endl;}
            else if(puntajeParcialM[tam][i]!=-1){
                j++;
                rlutil::locate(56,j);
                rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
                cout<<i+1<<")"<<"Juego de "<<i+1<<"|"<<puntajeParcialM[tam][i]<<endl;}
            else{
                j++;
                rlutil::locate(56,j);
                rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
                cout<<i+1<<")"<<"Juego de "<<i+1<<"|"<<"  "<<endl;}
        }
        int cont=13;
        for(i=6;i<10;i++){

            if(vComb[i]!=-1&&puntajeParcialM[tam][i]==-1){
                    j++;
                    rlutil::locate(56,j);
                    rlutil::setBackgroundColor(rlutil::COLOR::RED);
                    cout<<i+1<<")"<<nCombinacion[i-6];separa(68,j);cout<<vComb[i]<<endl;
                    cont++;
                    }
            else if(puntajeParcialM[tam][i]!=-1){
                j++;
                rlutil::locate(56,j);
                rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
                cout<<i+1<<")"<<nCombinacion[i-6];separa(68,j);cout<<puntajeParcialM[tam][i]<<endl;
                cont++;
            }
            else{
                j++;
                rlutil::locate(56,j);
                rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
                cout<<i+1<<")"<<nCombinacion[i-6];separa(68,j);cout<<"  "<<endl;
                cont++;
            }
        }
        rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
        cout<<endl;
}

///------------------------------------------------
int generalaServidaM(int vDados[],int tam){
    int i,servida=1,vRep[6];

        for(i=1;i<7;i++){
            vRep[i-1]=contarNumerosRepetidos(vDados,i,tam);
        }

        for(i=0;i<6;i++){
            if(vRep[i]==5){servida=0;return servida;}/// sumar puntaje 100 pts,gana la  partida.
        }
return servida;
}
//--------------------------------------------

void  tablaPreviaAnuladoM(int puntajeParcialM[2][10],int tam){
        int i,j=10;
        char nCombinacion[4][10]={"Escalera","Full","Poker","Generala"};

        rlutil::locate(3,8);
        cout<<"Elija la combinacion que desea anular"<<endl;

        rectanguloTabla();
        rlutil::locate(47,8);
        rlutil::setBackgroundColor(rlutil::COLOR::RED);
        cout<<"Elija cual anular"<<endl;
        rlutil::setBackgroundColor(rlutil::COLOR::BLACK);

        for(i=0;i<6;i++){
            if(puntajeParcialM[tam][i]==-1){
                    j++;
                    rlutil::locate(45,j);
                    cout<<"Juego de "<<i+1<<"|"<<"  "<<endl;}
            else{
                j++;
                rlutil::locate(45,j);
                cout<<"Juego de "<<i+1<<"|"<<puntajeParcialM[tam][i]<<endl;}
        }
        for(i=6;i<10;i++){
            if(puntajeParcialM[tam][i]==-1){
                    j++;
                    rlutil::locate(45,j);
                    cout<<nCombinacion[i-6];separa(55,j);cout<<"  "<<endl;}
            else{
                j++;
                rlutil::locate(45,j);
                cout<<nCombinacion[i-6];separa(55,j);cout<<puntajeParcialM[tam][i]<<endl;}
        }
}


void entreTurno(char nombres[2][30],int tiradasTotalesM[],int puntajeTotalM[],int tam,int rondas){
            system("cls");
            rectangulo();
            if(tam==0){
                    rlutil::setBackgroundColor(rlutil::COLOR::RED);
                    rlutil::locate(50,13);
                    cout<<"RONDA"<<(char)248<<rondas<<endl;
                    rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
                    rlutil::locate(45,14);
                    cout<<"PROXIMO TURNO :"<<nombres[tam+1]<<endl;
                    rlutil::locate(45,15);
                    cout<<"LANZAMIENTOS :"<<tiradasTotalesM[tam]<<endl;
                    rlutil::locate(45,17);
                    cout<<"PUNTAJE "<<nombres[0]<<" : "<<puntajeTotalM[tam]<<endl;
                    rlutil::locate(45,18);
                    cout<<"PUNTAJE "<<nombres[1]<<" : "<<puntajeTotalM[tam+1]<<endl;
                    }
            else {
                    rlutil::setBackgroundColor(rlutil::COLOR::RED);
                    rlutil::locate(50,13);
                    cout<<"RONDA"<<(char)248<<rondas<<endl;
                    rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
                    rlutil::locate(45,14);
                    cout<<"PROXIMO  TURNO :"<<nombres[tam-1]<<endl;
                    rlutil::locate(45,15);
                    cout<<"LANZAMIENTOS :"<<tiradasTotalesM[tam]<<endl;
                    rlutil::locate(45,17);
                    cout<<"PUNTAJE "<<nombres[0]<<" : "<<puntajeTotalM[tam-1]<<endl;
                    rlutil::locate(45,18);
                    cout<<"PUNTAJE "<<nombres[1]<<" : "<<puntajeTotalM[tam]<<endl;
                    }

}

void ganador(char nombres[2][30],int tiradasTotalesM[],int puntajeTotalM[],int posMultiV[]){
    system("cls");
    if(puntajeTotalM[0]>puntajeTotalM[1]){
        rectangulo();
        locate(45,15);
        cout<<"Ganador: "<<nombres[0]<<endl;
        locate(45,16);
        cout<<"Lanzamientos: "<<tiradasTotalesM[0]<<endl;
        locate(45,17);
        cout<<"Puntaje total: "<<puntajeTotalM[0];
        posMultiV[0]=0;
        getch();
        system("cls");
   }
   else if(puntajeTotalM[1]>puntajeTotalM[0]){
        rectangulo();
        locate(45,15);
        cout<<"Ganador: "<<nombres[1]<<endl;
        locate(45,16);
        cout<<"Lanzamientos: "<<tiradasTotalesM[1]<<endl;
        locate(45,17);
        cout<<"Puntaje total: "<<puntajeTotalM[1];
        posMultiV[0]=1;
        getch();
        system("cls");
   }
   else{
        if(tiradasTotalesM[0]>tiradasTotalesM[1]){
            rectangulo();
            locate(45,15);
            cout<<"Ganador: "<<nombres[0]<<endl;
            locate(45,16);
            cout<<"Lanzamientos: "<<tiradasTotalesM[0]<<endl;
            locate(45,17);
            cout<<"Puntaje total: "<<puntajeTotalM[0];
            posMultiV[0]=0;
            getch();
            system("cls");
        }
        else{
            rectangulo();
            locate(45,15);
            cout<<"Ganador: "<<nombres[1]<<endl;
            locate(45,16);
            cout<<"Lanzamientos: "<<tiradasTotalesM[1]<<endl;
            locate(45,17);
            cout<<"Puntaje total: "<<puntajeTotalM[1];
            posMultiV[0]=1;
            getch();
            system("cls");
        }
   }



}


#endif // FUNCIONES2_H_INCLUDED
