#ifndef ARCHIVOCLIENTE_H
#define ARCHIVOCLIENTE_H

#include "Cliente.h"
class ArchivoCliente
{
    public:
        //ArchivoCliente();
        bool agregarCliente(int dni);
        bool buscarCliente(int);
        Cliente getCliente(int);
        Cliente getUltimoCliente();
        void ListarClientes();
        int getCantidad();
};

#endif // ARCHIVOCLIENTE_H
