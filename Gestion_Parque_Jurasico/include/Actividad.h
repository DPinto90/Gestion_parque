#ifndef ACTIVIDAD_H
#define ACTIVIDAD_H

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include "../rlutil.h"
using namespace std;


class Actividad{

    private:
        char _nombre[30];
        int _codigo;
        int  _capacidad;
        int _disponibilidad;
        int _ocupacion;
        //float _precio;
        //float _alturaMin;
        //int _edadMin;
        bool _estado;
    public:
        Actividad();
        Actividad(std::string, int, int);
        void CargarActividad();
        void ocuparLugar();
        void liberarLugar();
        void mostrarDescripcion(int x);
        void vaciar();

        void setCodigo(int);
        void setNombre(std::string);
        void setCapacidad(int);
        void setEstado(bool);
        void setOcupacion(int);
        void setDisponibilidad(int);

        int getCapacidad();
        int getOcupacion();
        int getDisponibilidad();
        int getCodigo();
        std::string getNombre();
        bool getEstado();

        bool leerDeDisco(int);
        bool GrabarEnDisco();
        bool ModificarEnDisco(int);
};



#endif // ACTIVIDAD_H
