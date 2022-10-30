#include "opcion_clientes.h"



/// Men� opci�n 1 (clientes):
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
                Ultima_venta();
            break;
            case 4:
                rlutil::cls();
                mostrar_datos_log(empleado);
                archivo_ven.ListarVentas();
            break;
            case 5:
                rlutil::cls();
                mostrar_datos_log(empleado);
                archivo_cli.ListarClientes();
            break;
            case 6:
                rlutil::cls();
                mostrar_datos_log(empleado);
                Ventas_Por_Cliente();
            break;
            case 7:
                rlutil::cls();
                mostrar_datos_log(empleado);
                Ventas_Por_Empleado();
            break;
            case 8:
                rlutil::cls();
                mostrar_datos_log(empleado);
                if(exportarVentas()){
                    rlutil::locate(40,12);
                    cout<<"Archivo csv generado correctamente.";
                }
                rlutil::anykey();
            break;
            case 9:
                rlutil::cls();
                mostrar_datos_log(empleado);
                if(exportarVentasMes()){
                    rlutil::locate(40,12);
                    cout<<"Archivo csv generado correctamente.";
                }
                rlutil::anykey();
            break;
            case 10:
                rlutil::cls();
                mostrar_datos_log(empleado);
                if(exportarClientes()){
                    rlutil::locate(40,12);
                    cout<<"Archivo csv generado correctamente.";
                }
                rlutil::anykey();
            break;
            case 0:
               rlutil::cls();
                rlutil::locate(45,12);
                std::cout<< "VOLVIENDO AL MEN� INICIAL...";
                return;
            break;
            default:
                rlutil::cls();
                rlutil::locate(55,12);
                std::cout<< "SELECCIONE UNA OPCI�N V�LIDA.";
                rlutil::anykey();
                break;
        }
        rlutil::cls();
        mostrar_datos_log(empleado);
        opcion_menu = menu_ventas.MostrarMenu();
    }
}



///Funci�n para mostrar el men�:

void config_menu_ventas(Menu &menu){
    std::setlocale(LC_ALL, "");

    menu.SetCantItems(11);
    menu.SetNombre("- �REA VENTAS -");
    menu.AddItem("COMPRAR PASE", 1);
    menu.AddItem("REINICIAR OCUPACI�N DE ACTIVIDADES", 2);
    menu.AddItem("VER �LTIMA VENTA", 3);
    menu.AddItem("VER LISTADO DE VENTAS", 4);
    menu.AddItem("VER LISTADO DE CLIENTES", 5);
    menu.AddItem("VER VENTAS DE UN CLIENTE", 6);
    menu.AddItem("VER VENTAS DE UN EMPLEADO", 7);
    menu.AddItem("EXPORTAR LISTADO DE VENTAS ORDENADO POR VENDEDOR", 8);
    menu.AddItem("EXPORTAR lISTADO DE VENTAS DEL MES ACTUAL", 9);
    menu.AddItem("EXPORTAR LISTADO DE CLIENTES", 10);
}

/// Pantalla transici�n al men�:
void Ingresando_a_ventas(){
    rlutil::cls();
    rlutil::locate(20,15);
    cout<<"INGRESANDO AL �REA DE VENTAS.";
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
    std::cout<<"- �LTIMA VENTA REALIZADA -";

    if(archivo.getCantidad()>0){
        ultima = archivo.GetUltimaVenta();
        ultima.mostrarVenta(0);
    }else{
        rlutil::locate(40, 8);
        std::cout<<"No se encontraron ventas registradas.";
    }

    rlutil::anykey();
}

///
/*
EXPORTAR LISTADO DE VENTAS ORDENADO POR VENDEDOR
*/
bool exportarVentas(){
    bool csv_ok, archivoVentas_ok = false;
    ofstream archivo_csv("VentasPorVendedor.csv");

    if(!archivo_csv){
        csv_ok = error_csv();
    }else{
        archivo_csv<<"Num. venta,Fecha,DNI cliente,Pase,Monto,Medio de pago,Vendedor"<<endl;
        string medios[3]{"Efectivo", "Tarjeta", "QR"};
        Venta reg_venta;
        Empleado reg_empleado;
        int pos_v, pos_e = 0, legajo;
        while(reg_empleado.leerDeDisco(pos_e++)){
            legajo = reg_empleado.getLegajo();
            pos_v=0;
            while(reg_venta.leerDeDisco(pos_v++)){
                archivoVentas_ok = true;
                if(reg_venta.getLegajoEmpleado()==legajo){
                    int num = reg_venta.getNumVenta();
                    int dia = reg_venta.getFecha().getDia();
                    int mes = reg_venta.getFecha().getMes();
                    int anio = reg_venta.getFecha().getAnio();
                    int DNI_cli = reg_venta.getDniCliente();
                    string pase = reg_venta.getPase().getNombre();
                    float monto = reg_venta.getMonto();
                    int medio = reg_venta.getMedioDePago();
                    archivo_csv<<num<<","<<dia<<"/"<<mes<<"/"<<anio<<","<<DNI_cli<<","<<pase<<","<<monto<<","<<medios[medio-1]<<","<<legajo<<endl;
                }
            }
        }
        if(archivoVentas_ok){
            csv_ok = true;
        }
    }
    return csv_ok;
}
///
/*
EXPORTAR lISTADO DE VENTAS DEL MES ACTUAL
*/
bool exportarVentasMes(){
    bool csv_ok, archivoVentas_ok = false;
    ofstream archivo_csv("VentasDelMes.csv");

    if(!archivo_csv){
        csv_ok = error_csv();
    }else{
        archivo_csv<<"Num. venta,Fecha,DNI cliente,Pase,Monto,Medio de pago,Vendedor"<<endl;
        string medios[3]{"Efectivo", "Tarjeta", "QR"};
        Venta reg_venta;
        int pos_v = 0;
        Fecha hoy, date;
        fecha(hoy);
        while(reg_venta.leerDeDisco(pos_v++)){
            archivoVentas_ok = true;
            date = reg_venta.getFecha();
            if(date.getAnio()==hoy.getAnio()&&date.getMes()==hoy.getMes()){
                int num = reg_venta.getNumVenta();
                int DNI_cli = reg_venta.getDniCliente();
                string pase = reg_venta.getPase().getNombre();
                float monto = reg_venta.getMonto();
                int medio = reg_venta.getMedioDePago();
                int legajo = reg_venta.getLegajoEmpleado();
                archivo_csv<<num<<","<<date.getDia()<<"/"<<date.getMes()<<"/"<<date.getAnio()<<","<<DNI_cli<<","<<pase<<","<<monto<<","<<medios[medio-1]<<","<<legajo<<endl;
            }
        }
        if(archivoVentas_ok){
            csv_ok = true;
        }
    }
    return csv_ok;
}

///
/*
EXPORTAR LISTADO DE CLIENTES
*/
bool exportarClientes(){
    bool csv_ok, archivoVentas_ok = false;
    ofstream archivo_csv("Clientes.csv");

    if(!archivo_csv){
        csv_ok = error_csv();
    }else{
        archivo_csv<<"Nombre,Apellido,DNI,Fecha de Nacimiento"<<endl;
        Cliente reg_cliente;
        int pos = 0;
        Fecha date;
        while(reg_cliente.leerDeDisco(pos++)){
            archivoVentas_ok = true;
            date = reg_cliente.getFecha();
            string nombre = reg_cliente.getNombre();
            string apellido = reg_cliente.getApellido();
            int DNI_cli = reg_cliente.getDni();
            archivo_csv<<nombre<<","<<apellido<<","<<DNI_cli<<","<<date.getDia()<<"/"<<date.getMes()<<"/"<<date.getAnio()<<endl;
        }
        if(archivoVentas_ok){
            csv_ok = true;
        }
    }
    return csv_ok;
}


///
bool error_csv(){
    rlutil::locate(40,12);
    cout<<"Error al crear el archivo csv...";
    rlutil::locate(40,14);
    cout<<"Es posible que se encuentre en uso."<<endl;
    return false;
}
