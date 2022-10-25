#include "opcion_clientes.h"



/// Menú opción 1 (clientes):
void opcion_1(Parque &parque, Empleado &empleado){
    int opcion_menu;
    Menu menu_ventas;
    ArchivoCliente archivo_cli;
    ArchivoActividades archivo_act;
    ArchivoVentas archivo_ven;
    Fecha date;

    Ingresando_a_ventas();
    rlutil::cls();

    config_menu_ventas(menu_ventas);
    mostrar_datos_log(empleado);
    opcion_menu = menu_ventas.MostrarMenu();


    while(true){
        switch(opcion_menu){
            case 1:
                rlutil::cls();
                mostrar_datos_log(empleado);
                fecha(date);
                parque.VenderPase(empleado, date);
            break;
            case 2:
                rlutil::cls();
                mostrar_datos_log(empleado);
                archivo_act.vaciarActividades();
                rlutil::locate(40, 2);
                cout<<"SE HAN LIBERADO LOS LUGARES DE LAS ACTIVIDADES"<<endl;
                mostrar_datos_log(empleado);
                archivo_act.ListarActividades();
            break;
            case 3:
                rlutil::cls();
                mostrar_datos_log(empleado);
                Ventas_Por_Cliente();
            break;
            case 4:
                rlutil::cls();
                mostrar_datos_log(empleado);
                Ultima_venta();
            break;
            case 5:
                rlutil::cls();
                mostrar_datos_log(empleado);
                archivo_ven.ListarVentas();
            break;
            case 6:
                rlutil::cls();
                mostrar_datos_log(empleado);
                archivo_cli.ListarClientes();
            break;
            case 7:
                rlutil::cls();
                mostrar_datos_log(empleado);
                Ventas_Por_Empleado();
            break;

            case 0:
               rlutil::cls();
                rlutil::locate(45,12);
                std::cout<< "VOLVIENDO AL MENÚ INICIAL...";
                return;
            break;
            default:
                rlutil::cls();
                rlutil::locate(55,12);
                std::cout<< "SELECCIONE UNA OPCIÓN VÁLIDA.";
                rlutil::anykey();
                break;
        }
        rlutil::cls();
        mostrar_datos_log(empleado);
        opcion_menu = menu_ventas.MostrarMenu();
    }
}



///Función para mostrar el menú:

void config_menu_ventas(Menu &menu){
    std::setlocale(LC_ALL, "");

    menu.SetCantItems(8);
    menu.SetNombre("- ÁREA VENTAS -");
    menu.AddItem("COMPRAR PASE", 1);
    menu.AddItem("REINICIAR OCUPACIÓN DE ACTIVIDADES", 2);
    menu.AddItem("BUSCAR VENTAS DE UN CLIENTE", 3);
    menu.AddItem("VER ÚLTIMA VENTA", 4);
    menu.AddItem("LISTADO DE VENTAS", 5);
    menu.AddItem("LISTADO DE CLIENTES", 6);
    menu.AddItem("VENTAS POR EMPLEADO", 7);
}

/// Pantalla transición al menú:
void Ingresando_a_ventas(){
    rlutil::cls();
    rlutil::locate(20,15);
    cout<<"INGRESANDO AL ÁREA DE VENTAS.";
    dino();
    rlutil::locate(2,27);
    std::cout<< "Continuar...";
    rlutil::anykey();
}

///
void Ventas_Por_Cliente(){
    int dni;
    ArchivoVentas archivo;

    rlutil::locate(40, 3);
    std::cout<<"Ingrese el DNI del cliente: ";
    std::cin>>dni;
    rlutil::cls();
    archivo.ListarPorCliente(dni);
}

///
void Ventas_Por_Empleado(){
    int legajo;
    ArchivoVentas archivo;

    rlutil::locate(40, 3);
    std::cout<<"Ingrese el legajo del empleado: ";
    std::cin>>legajo;
    rlutil::cls();
    archivo.ListarPorVendedor(legajo);
}


///
void Ultima_venta(){
    Venta ultima;
    ArchivoVentas archivo;


    rlutil::locate(45, 3);
    std::cout<<"- ÚLTIMA VENTA REALIZADA -";

    if(archivo.getCantidad()>0){
        ultima = archivo.GetUltimaVenta();
        ultima.mostrarVenta(0);
    }else{
        rlutil::locate(40, 8);
        std::cout<<"No se encontraron ventas registradas.";
    }

    rlutil::anykey();
}
