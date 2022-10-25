#include <iostream>
#include "rlutil.h"
#include <windows.h>

using namespace std;

///Ovni
void ovni(){
     int presentacion[26][28]={

            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,1,1,0,1,1,0,1,1,0,1,1,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,1,1,0,0,0,1,1,1,0,0,0,1,1,0,0,0,0,0,0,0,0},
            {0,0,1,1,1,1,1,1,1,0,0,1,1,0,1,1,0,0,1,1,1,1,1,1,1,0,0,0},
            {0,0,1,1,1,1,1,1,1,0,0,1,0,0,0,1,0,0,1,1,1,1,1,1,1,0,0,0},
            {0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0},
            {0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0},
            {0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,2,2,2,2,2,2,2,2,0,0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,2,2,2,2,2,2,2,2,0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0,2,2,2,2,2,2,2,2,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0,0,2,2,2,2,2,2,2,2,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,2,2,2,2,2,2,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,2,2,2,2,2,2,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,2,2,2,2,2,2,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
            {3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
            {3,3,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
            {3,3,3,0,0,0,3,3,0,0,3,3,3,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0},
            {3,3,3,3,0,3,3,3,3,3,3,3,3,3,3,3,0,3,3,3,0,0,3,0,0,0,3,0},
            {3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3},

        };


    std::setlocale(LC_ALL, "C");
    for(int i=0;i<26;i++){

        for(int j=0; j<28; j++){
            if(presentacion[i][j]==0){
                SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),0);
                cout<<char(219)<<char(219);
            }else if(presentacion[i][j]==1){
                SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),15);
                cout<<char(219)<<char(219);
            }else if(presentacion[i][j]==2){
                SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),6);
                cout<<char(92)<<char(92);
            }else if(presentacion[i][j]==3){
                SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),2);
                cout<<char(176)<<char(176);
            }
        }
        cout << endl;
    }


    SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),9);
    for(int x=0; x<120; x++){
        rlutil::locate(x,27);
        cout<<char(178);
    }

    std::setlocale(LC_ALL, "");
    SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),15);
}

///Presentación:
void pantalla_presentacion(){

    ovni();
    rlutil::locate(65,10);
    cout<< "SISTEMA DE GESTIÓN - PARQUE JURÁSICO";
    rlutil::locate(70,24);
    cout<< "Presione una tecla para comenzar.";
    rlutil::anykey();
}


///Dino
void dino(){

    int cara_dino[19][22]={
            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,1,1,2,3,3,2,1,1,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,1,1,2,2,3,3,3,2,2,1,0,0,0,0,0,0},
            {0,0,1,1,0,0,1,2,2,3,3,3,3,3,2,1,0,0,0,0,0,0},
            {0,0,1,4,1,0,1,2,2,2,2,2,2,2,2,1,1,0,0,0,0,0},
            {0,0,1,4,1,1,2,2,2,2,2,2,2,2,2,2,1,0,0,0,0,0},
            {0,0,1,4,4,2,2,2,2,2,2,2,2,2,2,2,1,1,0,0,0,0},
            {0,0,0,1,4,2,2,2,2,2,2,2,2,2,2,2,1,1,1,0,0,0},
            {0,0,0,1,1,2,2,2,2,2,2,2,2,2,2,2,1,3,1,0,0,0},
            {0,0,0,0,1,2,2,1,1,2,2,2,2,2,2,1,1,2,3,3,0,0},
            {0,1,1,1,1,2,2,2,1,2,2,2,2,3,1,1,2,2,3,0,0,0},
            {0,1,4,4,4,2,2,2,2,2,2,3,1,1,1,3,2,3,0,0,0,0},
            {0,0,1,1,2,2,2,2,2,1,1,1,1,3,3,3,3,0,0,0,0,0},
            {0,0,0,1,2,2,2,1,1,1,1,3,3,3,3,0,0,0,0,0,0,0},
            {0,0,0,1,1,1,1,0,0,1,1,3,3,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0,1,3,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},

        };


    std::setlocale(LC_ALL, "C");
    for(int i=0;i<19;i++){
        rlutil::locate(65, 7+i);
        for(int j=0; j<22; j++){
            if(cara_dino[i][j]==0){
                SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),3);
                cout<<char(176)<<char(176);
            }else if(cara_dino[i][j]==1){
                SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),0);
                cout<<char(219)<<char(219);
            }else if(cara_dino[i][j]==2){
                SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),10);
                cout<<char(219)<<char(219);
            }else if(cara_dino[i][j]==3){
                SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),2);
                cout<<char(219)<<char(219);
            }else if(cara_dino[i][j]==4){
                SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),6);
                cout<<char(219)<<char(219);
            }
        }
        cout << endl;
    }
    std::setlocale(LC_ALL, "");
    SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),15);
}

