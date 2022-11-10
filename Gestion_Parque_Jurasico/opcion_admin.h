#ifndef OPCION_ADMIN_H_INCLUDED
#define OPCION_ADMIN_H_INCLUDED

#include "ArchivoEmpleados.h"
#include "ArchivoPases.h"
#include "Parque.h"

    void opcion_2(Empleado &empleado);
    void config_menu_admin(Menu &menu, Empleado &empleado_log);
    void Ingresando_admin();
    void Item1();
    void Item2();
    void Item4();
    void Item5();
    void Item7();
    void Item9();
    void Item10();
    Pase pase_mas_vendido();
    float monto_mes_actual();
    float monto_mes_pasado(int &mes);
    float monto_mes_pasado2(int &mes);
    Empleado mejor_vendedor(int &cant);
    Empleado mejor_vendedor_act(int &cant);
    int medio_preferido(int &cant_elecciones);



#endif // OPCION_ADMIN_H_INCLUDED
