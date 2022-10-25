#ifndef ARCHIVOEMPLEADOS_H
#define ARCHIVOEMPLEADOS_H

#include "Empleado.h"

class ArchivoEmpleados{
    private:

    public:
        //ArchivoEmpleados();
        bool agregarEmpleado();
        bool buscarEmpleado(int);
        Empleado getEmpleado(int);//sólo usar si el metodo buscar devuelve true.
        Empleado getUltimoEmpleado();
        bool setEmpleado(Empleado);//Recime un empleado como parámetro y compara los dnis para asignar el nuevo empleado en la posición deseada.
        void ListarEmpleados();
        int getCantidad();
        //virtual ~ArchivoEmpleados();

};

#endif // ARCHIVOEMPLEADOS_H
