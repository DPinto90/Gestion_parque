#ifndef OPCION_CLIENTES_H_INCLUDED
#define OPCION_CLIENTES_H_INCLUDED

#include <fstream>
#include "Parque.h"
#include "funciones.h"

    void opcion_1(Parque &parque, Empleado &empleado);
    void config_menu_ventas(Menu &menu);
    void Ingresando_a_ventas();
    void Ventas_Por_Cliente();
    void Ventas_Por_Empleado();
    void Ultima_venta();
    //void Ventas_del_mes();
    void Ventas_del_dia();
    bool exportarVentas();
    bool exportarVentasMes();
    bool exportarClientes();
    bool error_csv();


#endif // OPCION_CLIENTES_H_INCLUDED
