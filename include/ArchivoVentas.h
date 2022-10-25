#ifndef ARCHIVOVENTAS_H
#define ARCHIVOVENTAS_H

#include "Venta.h"
#include "Actividad.h"
#include "Cliente.h"
#include "Pase.h"
#include "Fecha.h"

class ArchivoVentas{
    public:
        //ArchivoVentas();
        void ListarVentas();
        void ListarPorCliente(int dni);
        void ListarPorVendedor(int legajo);
        Venta GetUltimaVenta();
        int getCantidad();
        //virtual ~ArchivoVentas();
};

#endif // ARCHIVOVENTAS_H
