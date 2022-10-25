#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include <string>
#include <stdio.h>
#include <time.h>

#include "visuales.h"
#include "Menu.h"
#include "Parque.h"

    void config_menu_inicio(Menu &menu);
    void opcion_salir(char &salir);
    void proximamente();
    void saliendo();
    void saliendo2();
    void mostrar_datos_log(Empleado empleado);
    bool InicioSesion(Parque &parque_jurasico, Empleado &empleado_log);
    bool ingreso(Parque &parque_jurasico, Empleado &empleado_log);
    void fecha(Fecha &date);

#endif // FUNCIONES_H_INCLUDED
