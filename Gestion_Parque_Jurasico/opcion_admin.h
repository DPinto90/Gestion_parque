#ifndef OPCION_ADMIN_H_INCLUDED
#define OPCION_ADMIN_H_INCLUDED

#include "ArchivoEmpleados.h"
#include "ArchivoPases.h"
#include "Parque.h"

    void opcion_2(Empleado &empleado);
    void config_menu_admin(Menu &menu, Empleado &empleado_log);
    void Ingresando_admin();
    void Item1(Empleado empleado_log);
    void Item2(Empleado empleado_log);
    void Item4(Empleado empleado_log);
    void Item5(Empleado empleado_log);
    void Item7(Empleado empleado_log);
    void Item9(Empleado empleado_log);
    void Item10();
    Pase pase_mas_vendido();
    float monto_mes_actual();
    float monto_mes_pasado(int &mes);
    float monto_mes_pasado2(int &mes);
    Empleado mejor_vendedor(int &cant);
    Empleado mejor_vendedor_act(int &cant);



#endif // OPCION_ADMIN_H_INCLUDED
