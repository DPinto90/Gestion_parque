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
        void vaciarActividades();//habría que hacerlo cada día para que vuelva la ocupación a 0.
        int getCantidad();
        //virtual ~ArchivoActividades();

    protected:

    private:
};

#endif // ARCHIVOACTIVIDADES_H
