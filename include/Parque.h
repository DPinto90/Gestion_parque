#ifndef PARQUE_H
#define PARQUE_H

#include "ArchivoEmpleados.h"
#include "ArchivoCliente.h"
#include "ArchivoActividades.h"
#include "ArchivoVentas.h"

class Parque{
    private:
        Pase _Pases[3];
        Actividad _actividad[4];
        ArchivoActividades _ArchivoAct;
        ArchivoCliente _ArchivoCli;
        bool _estado;

    public:
        Parque();
        void Abrir();
        void Cerrar();

        void cargarVecPases();
        void cargarVecActividades();
        void mostrarVecPases();
        void mostrarVecActividades();

        int ContarVentas();
        bool VenderPase(Empleado empleado, Fecha &);
        void identificarCliente(Cliente &);
        int ElegirPase(Pase &);
        void ElegirActividad(int cant_actividades);
        bool confirmarVenta(Venta, Pase, Empleado, Cliente, Actividad *, Fecha &);
        void MostrarOpcionesPases();
        void MostrarOpcionesActividades(int i);

        bool GetEstado();
        ~Parque();
};


#endif // PARQUE_H
