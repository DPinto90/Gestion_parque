#include <iostream>
#include <cstring>
#include <stdlib.h>
#include "rlutil.h"
using namespace std;

///Clases
#include "Menu.h"
#include "Parque.h"
///funciones y submenús
#include "opcion_clientes.h"
#include "opcion_admin.h"


int main(){
    char  salir_inicio='N';
    int opcion_menu_inicio;
    Menu menu_inicio;
    Parque parque_jurasico;
    Empleado empleado_log;


    std::setlocale(LC_ALL, "");
    parque_jurasico.Abrir();
    pantalla_presentacion();
    rlutil::cls();

    if(ingreso(parque_jurasico, empleado_log) == false){
        return 0;
    }

    rlutil::cls();
    config_menu_inicio(menu_inicio);
    mostrar_datos_log(empleado_log);
    opcion_menu_inicio = menu_inicio.MostrarMenu();


    while(salir_inicio != 'S'){

        switch(opcion_menu_inicio){
            case 1:/// ////////////////////// MENÚ VENTAS /////////////////////////////////
                rlutil::cls();
                opcion_1(parque_jurasico, empleado_log);
                rlutil::anykey();
            break;
            case 2:/// //////////////////////////// MENÚ ADMIN ////////////////////////////
                rlutil::cls();
                mostrar_datos_log(empleado_log);
                opcion_2(empleado_log);
                rlutil::anykey();
            break;
            case 3:/// //////////////////////////// INGRESAR CON OTRO USUARIO ////////////////////////////
                rlutil::cls();
                if(ingreso(parque_jurasico, empleado_log) == false){
                    return 0;
                }
            break;
            case 0:
                rlutil::cls();
                opcion_salir(salir_inicio);
            break;
            default:
                rlutil::cls();
                rlutil::locate(55,12);
                std::cout<< "SELECCIONE UNA OPCIÓN VÁLIDA.";
                rlutil::anykey();
                break;
        }
        ///SALIR DEL PROGRAMA:
        if(salir_inicio != 'S'){
            rlutil::cls();
            mostrar_datos_log(empleado_log);
            opcion_menu_inicio = menu_inicio.MostrarMenu();
        }else{
            saliendo2();
            return 0;
        }

    }//fin del menú inicial
    saliendo2();
    return 0;
}
