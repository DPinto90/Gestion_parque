#ifndef ARCHIVOACTIVIDADES_H
#define ARCHIVOACTIVIDADES_H

#include "Actividad.h"

class ArchivoActividades
{
    public:
        //ArchivoActividades();
        bool agregarActividad();
        void ListarActividades();
        bool setActividad(Actividad);
        void vaciarActividades();//habr�a que hacerlo cada d�a para que vuelva la ocupaci�n a 0.
        int getCantidad();
        //virtual ~ArchivoActividades();

    protected:

    private:
};

#endif // ARCHIVOACTIVIDADES_H
