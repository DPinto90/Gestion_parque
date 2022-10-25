#ifndef PERSONA_H
#define PERSONA_H

#include <stdlib.h>
#include <string.h>
#include <iostream>
#include "rlutil.h"
using namespace std;

class Persona{
    private:
        char _nombre[30];
        char _apellido[30];
        int _dni;
    public:
        Persona();
        void cargarPersona();
        void mostrarPersona(int x);//falta
        void setNombre(string);
        void setApellido(string);
        void setDni(int);
        char *getNombre();
        char *getApellido();
        int getDni();
        //~Persona();
};


#endif // PERSONA_H
