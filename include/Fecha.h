#ifndef FECHA_H
#define FECHA_H

#include <iostream>
using namespace std;

class Fecha{
    private:
        int dia, mes, anio;///propiedades
    public:
        void Mostrar(){
            cout<<dia<<"/"<<mes<<"/"<<anio<<endl;
        }
        Fecha();
        void Cargar();
        ///sets()
        void setDia(int val){dia=val;}
        void setMes(int val){mes=val;}
        void setAnio(int val){anio=val;}

        ///gets()
        int getDia(){return dia;}
        int getMes(){return mes;}
        int getAnio(){return anio;}
};


#endif // FECHA_H
