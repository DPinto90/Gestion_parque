#ifndef EMPLEADO_H
#define EMPLEADO_H
#include <iostream>

#include "Persona.h"

class Empleado :public Persona{

    private:
        char _cargo[30];
        bool _estado;
        bool _admin;
        int _legajo;
    public:
        Empleado();
        bool CargarEmpleado();
        void MostrarEmpleado(int x);
        void BajaEmpleado();
        void setCargo(string);
        void setEstado(bool);
        void setAdmin(bool);
        void setLegajo(int);
        char *getCargo();
        bool getEstado();
        bool getAdmin();
        int getLegajo();
        void HacerAdmin();
        bool leerDeDisco(int);
        bool GrabarEnDisco();
        bool ModificarEnDisco(int);
        //~Empleado();
};



#endif // EMPLEADO_H
