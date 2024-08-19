#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
///PROTOTIPOS

void showTime(const char*text,int posx,int posy,bool selected);///Fondo al mover el cursor de UP and DOWN
void showTime2(const char*text,int posx,int posy,bool selected);///Fondo al mover el cursor de LEFT and RIGHT
void cargaNombre(char nombre[]);///Carga el nombre
void cargarAleatorio(int v[], int tam, int limite);///Carga numeros aleatorios
void mostrarVector(int v[], int tam);///Muestra el vector,utilizado para mostrar los dados
int contarNumerosRepetidos(int v[], int numero, int tam);///Cuenta los numeros  repetidos en el vector
void ponerUno(int v[],int tam);///Pone un  vector  en -1.
void line2();///Funcion para separar de manera estetica.
int decision1(int x,int decision);///Devuelve un entero para ver si sigue o no tirando dados.
int canTirar();///Cant de dados que desea tirar
void cualDado(int vDados[],int opCant);///Elige que dados tirar,dependiendo de la cant de dados a tirar
void cualDadoSim(int vDados[],int opCant);///modo simulado
void ordenarVector(int v[], int tam );///Ordena el vector de  menor a  mayor
void copiarVector(int v[], int v2[],int tam );///Copia los valores de un vector en otro
void tiraDados(int vDados[],int tam);///Tira y muestra los dados
void cabecera(char nombre[],int ronda,int puntaje);///Funcion para mostrar en la parte superior el nombre del jugador
                                                  ///la ronda en la que estan y el puntaje total del partido.
void cabecera2(int tiradas,int tiradasT);///Funcion para mostrar en cabecera las tiraas por ronda y las totales en el juego.
int noSeguir(char nombre1[],int ronda,int puntajeTotal,int tiradas,int tiradasTotales,int vDados[],int vComb[],int puntajeParcial[],bool tiene);
void combinaciones(int vDados[], int tam, int vComb[]);///Calcula los puntajes segun los dados tirados
int deseaContinuar(int decision);///Funcion para decidir si seguir o no jugando S/N
bool combDisponibles(int vComb[], int puntajeParcial[]);///Muestra los  puntos segun  los  dados  tirados,pero solo si no anota ese  puntaje previamente.
int quieroJugar();///Elige la cant de rondas a jugar
void anotar(int puntajeParcial[], int opcion, int vComb[]);
int puntajeRonda(int puntajeParcial[]);///Suma vector,para el puntaje.
void  mostrarTabla(int puntajeParcial[]);///Muestra la tabla con las combinaciones elegidas.
void anular(int puntajeParcial[], int opcion);///Anula una combinacion ganadora
void  previaTabla(int puntajeParcial[],int vComb[]);///Muestra con color las combinaciones que puede elegir
int generalaServida(int vDados,int tam);///En caso de que le toque generala servida en la ronda=1,tirada=1
void mostrarDados(int vDados[]);///Muestra los dados y debajo sus numeros
void  tablaPreviaAnulado(int puntajeParcial[]); ///muestra la tabla con las combinaciones a anular
void ganadorIndividual(char nombre1[],int tiradasTotales,int puntajeTotal); ///pantalla ganador
///----

///--------PROTOTIPOS DADOS Y GRAFICOS-----------------------

void dadounoM();
void dadoDosM();
void dadoTresM();
void dadoCuatroM();
void dadoCincoM();
void MenuDeDadosM(int vDados[]);
void rectangulo();
void rectanguloDchaM();///Estetica,rectangulo de combinaciones disponibles
void rectanguloTabla();///Tabla en medio
void separa(int x,int y);///Separador de tabla


///FUNCIONES DE ESTETICA Y POSICION


void showTime(const char*text,int posx,int posy,bool selected){

    if(selected){
        rlutil::setBackgroundColor(rlutil::COLOR::RED);
    }
    else{
        rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
    }
    rlutil::locate(posx,posy);
    cout<<text<<endl;
    rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
}

void showTime2(const char*text,int posx,int posy,bool selected){

    if(selected){
        rlutil::setBackgroundColor(rlutil::COLOR::RED);
    }
    else{
        rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
    }
    rlutil::locate(posx,posy);
    cout<<text;
    rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
}

void rectangulo(){
       for(int x=31; x<80; x++){
            gotoxy(x,12); printf("%c",205);
            gotoxy(x,20); printf("%c",205);
        }
        for(int y=13; y<20; y++){
            gotoxy(30,y); printf("%c",186);
            gotoxy(80,y); printf("%c",186);
        }
        gotoxy(30,12); printf("%c",201);
        gotoxy(30,20); printf("%c",200);
        gotoxy(80,12); printf("%c",187);
        gotoxy(80,20); printf("%c",188);
}

void rectanguloDchaM(){
       for(int x=54; x<80; x++){ //horizontal
            gotoxy(x,6); printf("%c",205);
            gotoxy(x,25); printf("%c",205);
        }
        for(int y=7; y<25; y++){ //vertical
            gotoxy(53,y); printf("%c",186);
            gotoxy(80,y); printf("%c",186);
        }
        gotoxy(53,6); printf("%c",201);
        gotoxy(53,25); printf("%c",200);
        gotoxy(80,6); printf("%c",187);
        gotoxy(80,25); printf("%c",188);
}

void rectanguloTabla(){
       for(int x=43; x<69; x++){ //horizontal
            gotoxy(x,6); printf("%c",205);
            gotoxy(x,25); printf("%c",205);
        }
        for(int y=7; y<25; y++){ //vertical
            gotoxy(42,y); printf("%c",186);
            gotoxy(69,y); printf("%c",186);
        }
        gotoxy(42,6); printf("%c",201);
        gotoxy(42,25); printf("%c",200);
        gotoxy(69,6); printf("%c",187);
        gotoxy(69,25); printf("%c",188);
}


///FUNCIONES SIMPLES

void cargaNombre(char nombre[]){
    system("cls");
    rectangulo();
    rlutil::locate(45,15);
    cout<<"Ingrese su nombre"<<endl;
    rlutil::setBackgroundColor(rlutil::COLOR::RED);
    //cin.ignore();
    gotoxy(45,17);
    fflush(stdin);
    cin.getline(nombre,30);
    rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
    //system("cls");
    //cout<<nombre<<endl;

    system("cls");

}


void cargarAleatorio(int v[], int tam, int limite){
  int i;
  srand(time(NULL));
  for( i=0; i<tam; i++ ){
        v[i]=(rand()%limite)+1;
  }
}


int contarNumerosRepetidos(int v[], int numero, int tam){
    int i, cant=0;
    for(i=0;i<tam;i++){
        if(v[i]==numero) cant++;
        }
    return cant;
}

void line2(){///Funcion para separar de manera estetica.
    cout<<"  -------------------------------------------------------------------------------------------------------"<<endl;

}

int decision1(int x,int decision){
    switch(x){
            case 0:decision=0;
            break;
            case 2:decision=2;
            break;
            default:
            break;
            }
return decision;}

int canTirar(){
    cout<<endl;
    int opCant,hayCant=0;
        rlutil::setBackgroundColor(rlutil::COLOR::RED);
        cout<<(char)168<<"CUANTOS DADOS VOLVES A TIRAR?"<<endl;
        rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
        do{
            //gotoxy(33,15);
            cin>>opCant;
            if(opCant>=1&&opCant<=5){hayCant=1;}

        }while(hayCant==0);

return opCant;
}

void cualDado(int vDados[],int opCant){

    int vOp[5],i,v[4]={0,0,0,0};
    int verificar;
    int cont=0,cual;
            //cout<<endl;
            if(opCant==5){tiraDados(vDados,5);} ///segunda  y tercera tirada de dados
            else{
            cout<<"SELECCIONE CUAL/ES:"<<endl;

            for(i=0;i<=4;i++){
            rlutil::setBackgroundColor(rlutil::COLOR::RED);
            cout<<"Dado ";
            rlutil::setBackgroundColor(rlutil::COLOR::RED);
            cout<<i+1;
            rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
            cout<<": "<<vDados[i]<<"\t"<<endl;}///Muestra los dados que tiene para elegir volver a tirar

            cargarAleatorio(vOp,opCant,6);
            cout<<"Seleccione "<<opCant<<" dados"<<endl;
                while(cont!=opCant){
                    cin>>cual;
                        if(cual>=1&&cual<=5){
                            v[cont]=cual;
                            verificar=contarNumerosRepetidos(v,cual,4);
                            if(verificar<2){vDados[cual-1]=vOp[cont];v[cont]=cual;cont++;}

                        }
                    }
                }

}

void cualDadoSim(int vDados[],int opCant){

    int vOp[5],i,v[4]={0,0,0,0};
    int verificar;
    int cont=0,cual;
            //cout<<endl;
            if(opCant==5){mostrarDados(vDados);} ///segunda  y tercera tirada de dados
            else{
            cout<<"SELECCIONE CUAL/ES:"<<endl;

            for(i=0;i<=4;i++){
            rlutil::setBackgroundColor(rlutil::COLOR::RED);
            cout<<"Dado ";
            rlutil::setBackgroundColor(rlutil::COLOR::RED);
            cout<<i+1;
            rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
            cout<<": "<<vDados[i]<<"\t"<<endl;}///Muestra los dados que tiene para elegir volver a tirar

            cargarAleatorio(vOp,opCant,6);
            cout<<"Seleccione "<<opCant<<" dados"<<endl;
                while(cont!=opCant){
                    cin>>cual;
                        if(cual>=1&&cual<=5){
                            v[cont]=cual;
                            verificar=contarNumerosRepetidos(v,cual,4);
                            if(verificar<2){vDados[cual-1]=vOp[cont];v[cont]=cual;cont++;}

                        }
                    }
                }

}


void ordenarVector(int v[], int tam ){
    int i,j, posmin, aux;
    for(i=0;i<tam-1;i++){
        posmin=i;
        for(j=i+1;j<tam;j++){
            if(v[j]<v[posmin]) posmin=j;
        }
        aux=v[i];
        v[i]=v[posmin];
        v[posmin]=aux;
    }
}

void copiarVector(int v[], int v2[],int tam ){
    int i;
    for(i=0;i<tam;i++){
        v2[i]=v[i];
    }
}

void ponerUno(int v[],int tam){
    int i;
    for(i=0;i<tam;i++){v[i]=-1;}
}

int quieroJugar(){
    int perfecto=0;
    int can;
    system("cls");
    do{
        rectangulo();
        gotoxy(40,15);
        cout<<"Cuantas rondas quiere jugar"<<endl;
        gotoxy(53,17);
        rlutil::setBackgroundColor(rlutil::COLOR::RED);
        cin>>can;
        if(can>=1&&can<=10){perfecto=1;}
        rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
        system("cls");
    }while(perfecto==0);

return can;
}


///FUNCIONES COMPUESTAS


void tiraDados(int vDados[],int tam){

    cargarAleatorio(vDados,5,6);
    mostrarDados(vDados);
}

void cabecera(char nombre[],int ronda,int puntaje){///Funcion para mostrar en la cabecera superior el nombre del jugador en esa ronda,
                                                   ///la ronda en la que estan y el puntaje total del partido.
            cout<<" TURNO DE "<<nombre;
            cout<<" | ";
            cout<<" RONDA N"<<(char)248;
            cout<<ronda;
            cout<<" | ";
            cout<<" PUNTAJE TOTAL ";
            cout<<puntaje;
            cout<<endl;
            line2();
            cout<<endl;

 }

void cabecera2(int tiradas,int tiradasT){///Funcion para mostrar en cabecera las tiradas por ronda y las totales en el juego.

    cout<<" TIRADA N"<<(char)248;
    cout<<tiradas;
    cout<<" - TIRADAS TOTALES ";
    cout<<tiradasT;
    cout<<endl;
    line2();
    cout<<endl;
 }

int noSeguir(char nombre1[],int ronda,int puntajeTotal,int tiradas,int tiradasTotales,int vDados[],int vComb[],int puntajeParcial[],bool tiene){

            rlutil::hidecursor();
            system("cls");
            int elegir=0;
            int y=0;
            cabecera(nombre1,ronda,puntajeTotal);
            cabecera2(tiradas,tiradasTotales);
            mostrarDados(vDados);
            cout<<endl;
            combinaciones(vDados,5,vComb);
            tiene=combDisponibles(vComb,puntajeParcial);
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

void combinaciones(int vDados[], int tam, int vComb[]){
                    int x,i,vRep[6];

                    for(x=1;x<7;x++){
                        vRep[x-1]=contarNumerosRepetidos(vDados,x,5);
                    }
                    cout<<endl;
                    ///puntos a los numeros
                    for(i=1;i<7;i++){
                            if(vRep[i-1]!=0){vComb[i-1]=vRep[i-1]*i;}
                    }

                    ///FULL
                    bool banderaRepe2 = false;
                    bool banderaRepe3 = false;
                    for(i=0;i<6;i++){
                        if(vRep[i]==2){
                                banderaRepe2= true;

                        }if(vRep[i]==3){
                                banderaRepe3=true;
                        }
                    }
                    if((banderaRepe2==true)&&(banderaRepe3==true)){vComb[7]=30;}

                    /// POKER 4 y 1
                    for(i=0;i<6;i++){
                        if(vRep[i]==4){vComb[8]=40;}
                    }

                    ///generala
                    for(i=0;i<6;i++){
                        if(vRep[i]==5){vComb[9]=50;}
                    }


                    ///Escalera
                    int vCopia[5];
                    copiarVector(vDados,vCopia,5);
                    ordenarVector(vCopia,5);
                    int cont =0;
                    if(vCopia[0]==1){
                        for(i=0;i<4;i++){
                            if(vCopia[i+1]==(i+2)){cont++;}
                                if(cont==4){vComb[6]=25;}
                        }
                    }
                    cont =0;
                    if(vCopia[0]==2){
                        for(i=1;i<5;i++){
                            if(vCopia[i]==(i+2)){cont++;}
                            if(cont==4){vComb[6]=25;}
                            }
                        }
}

bool combDisponibles(int vComb[], int puntajeParcial[]){
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
                    if(vComb[i]!=-1&&puntajeParcial[i]==-1){
                        j++;
                        rlutil::locate(57,j);
                        cout<<i+1<<")"<<"Puntos al "<<i+1<<" : "<<vComb[i]<<endl;
                        cont++;
                    }
                }

                for(i=6;i<10;i++){
                    if(vComb[i]!=-1&&puntajeParcial[i]==-1){
                        j++;
                        rlutil::locate(57,j);
                        cout<<i+1<<")"<<nCombinacion[i-6]<<" : "<<vComb[i]<<endl; ///MATRIZ
                        cont++;
                    }
                }
                if(cont==0){tiene=false;}
return tiene;
}

int deseaContinuar(int decision){
            int x=0;
            do{
                        decision=-1;
                        rlutil::locate(1,14);
                        cout<<(char)168<<"DESEA CONTINUAR LANZANDO? (";
                        showTime2("S",29,14,x==0);
                        cout<<"/";
                        showTime2("N",31,14,x==2);
                        cout<<")";//<<endl;

                       switch(rlutil::getkey()){
                                case 16:///LEFT
                                        rlutil::locate(29+x,14);
                                        x-=2;
                                        if(x<0){x=0;}
                                break;
                                case 17:///RIGHT
                                        rlutil::locate(29+x,14);
                                        x+=2;
                                        if(x>2){x=2;}
                                break;
                                case 1:///ENTER
                                        decision=decision1(x,decision);
                                break;

                                default:
                                break;
                            }
                        }while(decision==-1);
return decision;
}

void anotar(int puntajeParcial[], int vComb[]){
    int anoto=0,opcion;

    do{
        cin>>opcion;
        if(opcion>=1&&opcion<=10){
                if(vComb[opcion-1]!=-1&&puntajeParcial[opcion-1]==-1){
                        puntajeParcial[opcion-1]=vComb[opcion-1];
                        anoto=1;
                    }
                else{cout<<"Vuelva a escoger"<<endl;}
        }
        else{cout<<"Vuelva a escoger"<<endl;}

    }while(anoto==0);
}

void  mostrarTabla(int puntajeParcial[]){
        int i,j=10;
        char nCombinacion[4][10]={"Escalera","Full","Poker","Generala"};

        rectanguloTabla();
        rlutil::locate(48,8);
        rlutil::setBackgroundColor(rlutil::COLOR::RED);
        cout<<"Puntaje anotado"<<endl;
        rlutil::setBackgroundColor(rlutil::COLOR::BLACK);

        for(i=0;i<6;i++){
            if(puntajeParcial[i]==-1){
                    j++;
                    rlutil::locate(45,j);
                    cout<<"Juego de "<<i+1<<"|"<<"  "<<endl;}
            else{
                j++;
                rlutil::locate(45,j);
                cout<<"Juego de "<<i+1<<"|"<<puntajeParcial[i]<<endl;}
        }
        for(i=6;i<10;i++){
            if(puntajeParcial[i]==-1){
                    j++;
                    rlutil::locate(45,j);
                    cout<<nCombinacion[i-6];separa(55,j);cout<<"  "<<endl;}
            else{
                j++;
                rlutil::locate(45,j);
                cout<<nCombinacion[i-6];separa(55,j);cout<<puntajeParcial[i]<<endl;}
        }
}

int puntajeRonda(int puntajeParcial[]){
    int i,total=0;
    for(i=0;i<10;i++){
        if(puntajeParcial[i]!=-1){total+=puntajeParcial[i];}
    }
return total;
}

void anular(int puntajeParcial[]){
    int anoto=0,opcion,j=10;

    do{
        gotoxy(1,j);
        j+=2;
        cin>>opcion;
        if(opcion>=1&&opcion<=10){
                if(puntajeParcial[opcion-1]==-1){
                        puntajeParcial[opcion-1]=0;
                        anoto=1;
                    }
                else{cout<<"Vuelva a escoger"<<endl;}
        }
        else{cout<<"Vuelva a escoger"<<endl;}

    }while(anoto==0);

}

void  previaTabla(int puntajeParcial[],int vComb[]){
        int i,j=10;
        char nCombinacion[4][10]={"Escalera","Full","Poker","Generala"};

        rectanguloDchaM();
        rlutil::locate(57,8);
        rlutil::setBackgroundColor(rlutil::COLOR::RED);
        cout<<"Anote la combinacion"<<endl;

        for(i=0;i<6;i++){

            if(vComb[i]!=-1&&puntajeParcial[i]==-1){
                j++;
                rlutil::locate(56,j);
                rlutil::setBackgroundColor(rlutil::COLOR::RED);
                cout<<i+1<<")"<<"Juego de "<<i+1<<"|"<<vComb[i]<<endl;}
            else if(puntajeParcial[i]!=-1){
                j++;
                rlutil::locate(56,j);
                rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
                cout<<i+1<<")"<<"Juego de "<<i+1<<"|"<<puntajeParcial[i]<<endl;}
            else{
                j++;
                rlutil::locate(56,j);
                rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
                cout<<i+1<<")"<<"Juego de "<<i+1<<"|"<<"  "<<endl;}
        }
        int cont=13;
        for(i=6;i<10;i++){

            if(vComb[i]!=-1&&puntajeParcial[i]==-1){
                    j++;
                    rlutil::locate(56,j);
                    rlutil::setBackgroundColor(rlutil::COLOR::RED);
                    cout<<i+1<<")"<<nCombinacion[i-6];separa(68,j);cout<<vComb[i]<<endl;
                    cont++;
                    }
            else if(puntajeParcial[i]!=-1){
                j++;
                rlutil::locate(56,j);
                rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
                cout<<i+1<<")"<<nCombinacion[i-6];separa(68,j);cout<<puntajeParcial[i]<<endl;
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

void separa(int x,int y){
    locate(x,y);
    cout<<"|";
}

int generalaServida(int vDados[],int tam,int captura[],int puntajeTotal, int tiradasTotales){
    int i,servida=1,vRep[6];

        for(i=1;i<7;i++){
            vRep[i-1]=contarNumerosRepetidos(vDados,i,tam);
        }

        for(i=0;i<6;i++){
            if(vRep[i]==5){servida=0;return servida;}/// sumar puntaje 100 pts,gana la  partida.
        }
        captura[0]=puntajeTotal;
        captura[1]=tiradasTotales;

return servida;
}

void mostrarDados(int vDados[]){
    MenuDeDadosM(vDados);
    cout<<endl;
    cout<<endl;
    locate(6, 11);cout<<vDados[0];
    locate(16,11);cout<<vDados[1];
    locate(26,11);cout<<vDados[2];
    locate(36,11);cout<<vDados[3];
    locate(46,11);cout<<vDados[4];
    cout<<endl;
}

void  tablaPreviaAnulado(int puntajeParcial[]){
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
            if(puntajeParcial[i]==-1){
                    j++;
                    rlutil::locate(45,j);
                    cout<<"Juego de "<<i+1<<"|"<<"  "<<endl;}
            else{
                j++;
                rlutil::locate(45,j);
                cout<<"Juego de "<<i+1<<"|"<<puntajeParcial[i]<<endl;}
        }
        for(i=6;i<10;i++){
            if(puntajeParcial[i]==-1){
                    j++;
                    rlutil::locate(45,j);
                    cout<<nCombinacion[i-6];separa(55,j);cout<<"  "<<endl;}
            else{
                j++;
                rlutil::locate(45,j);
                cout<<nCombinacion[i-6];separa(55,j);cout<<puntajeParcial[i]<<endl;}
        }
}

void ganadorIndividual(char nombre1[],int tiradasTotales,int puntajeTotal){
    rectangulo();
    locate(45,15);
    cout<<"Ganador: "<<nombre1<<endl;
    locate(45,16);
    cout<<"Lanzamientos: "<<tiradasTotales<<endl;
    locate(45,17);
    cout<<"Puntaje total: "<<puntajeTotal;
    getch();
    system("cls");

}


///-------------DADOS-----------------------

void dadounoM() {
    // HORIZONTAL
    for (int x = 3 ; x < 10; x++) {
        locate(x, 6); printf("%c", 205);
        locate(x, 10); printf("%c", 205);
    }
    // VERTICAL
    for (int y = 7; y< 10; y++) {
        locate(2, y); printf("%c", 186);
        locate(10, y); printf("%c", 186);
    }
    ///ESQUINAS
    locate(2, 6); printf("%c", 201); //superior izquierda
    locate(2, 10); printf("%c", 200); //inferior izquierda
    locate(10, 6); printf("%c", 187); //superior derecha
    locate(10, 10); printf("%c", 188); // inferior derecha
}

void dadoDosM() {
    // HORIZONTAL
    for (int i = 13; i < 20; i++) {
        locate(i, 6); printf("%c", 205);
        locate(i, 10); printf("%c", 205);
    }
    // VERTICAL
    for (int i = 7; i < 10; i++) {
        locate(12, i); printf("%c", 186);
        locate(20, i); printf("%c", 186);
    }
    //ESQUINAS
    locate(12, 6); printf("%c", 201);
    locate(12, 10); printf("%c", 200);
    locate(20, 6); printf("%c", 187);
    locate(20, 10); printf("%c", 188);
}

void dadoTresM() {

    // HORIZONTAL
    for (int i = 23; i < 30; i++) {
        locate(i, 6); printf("%c", 205);
        locate(i, 10); printf("%c", 205);
    }
    // VERTICAL
    for (int i = 7; i <10; i++) {
        locate(22, i); printf("%c", 186);
        locate(30, i); printf("%c", 186);
    }
    //ESQUINAS
    locate(22, 6); printf("%c", 201);
    locate(22, 10); printf("%c", 200);
    locate(30, 6); printf("%c", 187);
    locate(30, 10); printf("%c", 188);
}

void dadoCuatroM() {
    // HORIZONTAL
    for (int i = 33; i < 40; i++) {
        locate(i, 6); printf("%c", 205);
        locate(i, 10); printf("%c", 205);
    }
    // VERTICAL
    for (int i = 7; i < 10; i++) {
        locate(32, i); printf("%c", 186);
        locate(40, i); printf("%c", 186);
    }
    //ESQUINAS
    locate(32, 6); printf("%c", 201);
    locate(32, 10); printf("%c", 200);
    locate(40, 6); printf("%c", 187);
    locate(40, 10); printf("%c", 188);
}

void dadoCincoM() {
    // HORIZONTAL
    for (int i = 43; i < 50; i++) {
        locate(i, 6); printf("%c", 205);
        locate(i, 10); printf("%c", 205);
    }
    // VERTICAL
    for (int i = 7; i < 10; i++) {
        locate(42, i); printf("%c", 186);
        locate(50, i); printf("%c", 186);
    }
    //ESQUINAS
    locate(42, 6); printf("%c", 201);
    locate(42, 10); printf("%c", 200);
    locate(50, 6); printf("%c", 187);
    locate(50, 10); printf("%c", 188);
}

void MenuDeDadosM(int vDados[]) {
    int i;
    dadounoM(); dadoDosM(); dadoTresM(); dadoCuatroM(); dadoCincoM();
    for (i = 0; i <5; i++) {
        switch (vDados[i]) {
            case 1:
            if (i == 0) { locate(6, 8); printf("%c", 254); }
            if (i == 1) { locate(16, 8); printf("%c", 254); }
            if (i == 2) { locate(26, 8); printf("%c", 254); }
            if (i == 3) { locate(36, 8); printf("%c", 254); }
            if (i == 4) { locate(46, 8); printf("%c", 254); }
            ; break;
            case 2:
            if (i == 0) {
                locate(4, 9); printf("%c", 254); //punto izq
                locate(8, 7); printf("%c", 254);  //pto dcha
            }
            if (i == 1) {
                locate(14, 9); printf("%c", 254);
                locate(18, 7); printf("%c", 254);
            }
            if (i == 2) {
                locate(24, 9); printf("%c", 254);
                locate(28, 7); printf("%c", 254);
            }
            if (i == 3) {
                locate(34, 9); printf("%c", 254);
                locate(38, 7); printf("%c", 254);
            }
            if (i == 4) {
                locate(44, 9); printf("%c", 254);
                locate(48, 7); printf("%c", 254);
            }

            ; break;
            case 3:
            if (i == 0) {
                locate(6, 8); printf("%c", 254);
                locate(8, 7); printf("%c", 254);
                locate(4, 9); printf("%c", 254);
            }

            if (i == 1) {
                locate(16, 8); printf("%c", 254);
                locate(18, 7); printf("%c", 254);
                locate(14, 9); printf("%c", 254);
            }

            if (i == 2) {
                locate(26, 8); printf("%c", 254);
                locate(28, 7); printf("%c", 254);
                locate(24, 9); printf("%c", 254);
            }
            if (i == 3) {
                locate(36, 8); printf("%c", 254);
                locate(38, 7); printf("%c", 254);
                locate(34, 9); printf("%c", 254);
            }
            if (i == 4) {
                locate(46, 8); printf("%c", 254);
                locate(48, 7); printf("%c", 254);
                locate(44, 9); printf("%c", 254);
            }
            ; break;
            case 4:
            if (i == 0) {
                locate(4, 7); printf("%c", 254);
                locate(4, 9); printf("%c", 254);
                locate(8, 7); printf("%c", 254);
                locate(8, 9); printf("%c", 254);
            }
            if (i == 1) {
                locate(14, 7); printf("%c", 254);
                locate(14, 9); printf("%c", 254);
                locate(18, 7); printf("%c", 254);
                locate(18, 9); printf("%c", 254);
            }
            if (i == 2)
            {
                locate(24, 7); printf("%c", 254);
                locate(24, 9); printf("%c", 254);
                locate(28, 7); printf("%c", 254);
                locate(28, 9); printf("%c", 254);
            }
            if (i == 3)
            {
                locate(34, 7); printf("%c", 254);
                locate(34, 9); printf("%c", 254);
                locate(38, 7); printf("%c", 254);
                locate(38, 9); printf("%c", 254);
            }
            if (i == 4) {
                locate(44, 7); printf("%c", 254);
                locate(44, 9); printf("%c", 254);
                locate(48, 7); printf("%c", 254);
                locate(48, 9    ); printf("%c", 254);
            }
            break;
            case 5:
            if (i == 0)
            {
                locate(4, 7); printf("%c", 254);
                locate(4, 9); printf("%c", 254);
                locate(8, 7); printf("%c", 254);
                locate(6, 8); printf("%c", 254);
                locate(8, 9); printf("%c", 254);
            }
            if (i == 1)
            {
                locate(14, 7); printf("%c", 254);
                locate(14, 9); printf("%c", 254);
                locate(18, 7); printf("%c", 254);
                locate(16, 8); printf("%c", 254);
                locate(18, 9); printf("%c", 254);
            }
            if (i == 2)
            {
                locate(24, 7); printf("%c", 254);
                locate(24, 9); printf("%c", 254);
                locate(28, 7); printf("%c", 254);
                locate(26, 8); printf("%c", 254);
                locate(28, 9); printf("%c", 254);
            }
            if (i == 3) {
                locate(34, 7); printf("%c", 254);
                locate(34, 9); printf("%c", 254);
                locate(38, 7); printf("%c", 254);
                locate(36, 8); printf("%c", 254);
                locate(38, 9); printf("%c", 254);
            }
            if (i == 4)
            {
                locate(44, 7); printf("%c", 254);
                locate(44, 9); printf("%c", 254);
                locate(48, 7); printf("%c", 254);
                locate(46, 8); printf("%c", 254);
                locate(48, 9); printf("%c", 254);
            }
            break;
            case 6:
            if (i == 0) {
                locate(4, 7); printf("%c", 254);
                locate(4, 8); printf("%c", 254);
                locate(8, 7); printf("%c", 254);
                locate(4, 9); printf("%c", 254);
                locate(8, 8); printf("%c", 254);
                locate(8, 9); printf("%c", 254);
            }
            if (i == 1) {
                locate(14, 7); printf("%c", 254);
                locate(14, 8); printf("%c", 254);
                locate(18, 7); printf("%c", 254);
                locate(14, 9); printf("%c", 254);
                locate(18, 8); printf("%c", 254);
                locate(18, 9); printf("%c", 254);
            }
            if (i == 2) {
                locate(24, 7); printf("%c", 254);
                locate(24, 8); printf("%c", 254);
                locate(28, 7); printf("%c", 254);
                locate(24, 9); printf("%c", 254);
                locate(28, 8); printf("%c", 254);
                locate(28, 9); printf("%c", 254);
            }
            if (i == 3) {
                locate(34, 7); printf("%c", 254);
                locate(34, 8); printf("%c", 254);
                locate(38, 7); printf("%c", 254);
                locate(34, 9); printf("%c", 254);
                locate(38, 8); printf("%c", 254);
                locate(38, 9); printf("%c", 254);
            }
            if (i == 4) {
                locate(44, 7); printf("%c", 254);
                locate(44, 8); printf("%c", 254);
                locate(48, 7); printf("%c", 254);
                locate(44, 9); printf("%c", 254);
                locate(48, 8); printf("%c", 254);
                locate(48, 9); printf("%c", 254);
            }
            break;
        }
    }
}



#endif // FUNCIONES_H_INCLUDED







