#include "Fecha.h"

Fecha::Fecha(){
    dia = 0;
    mes = 0;
    anio = 0;
}
void Fecha::Cargar(){
    int d;
    cout<<"DIA ";
    cin>>d;
    if(d>0 && d<31) dia=d;
    cout<<"MES ";
    cin>>mes;
    cout<<"ANIO ";
    cin>>anio;
}
