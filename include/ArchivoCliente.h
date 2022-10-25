#ifndef ARCHIVOCLIENTE_H
#define ARCHIVOCLIENTE_H

#include "Cliente.h"
class ArchivoCliente
{
    public:
        //ArchivoCliente();
        bool agregarCliente(int dni);
        bool buscarCliente(int);
        Cliente getCliente(int);//sólo usar si el metodo buscar devuelve true.
        Cliente getUltimoCliente();
        void ListarClientes();
        int getCantidad();
        //virtual ~ArchivoCliente();
};

#endif // ARCHIVOCLIENTE_H
