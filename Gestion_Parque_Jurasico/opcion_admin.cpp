#include "funciones.h"
#include "Menu.h"
#include "opcion_admin.h"

using namespace std;


///Opcion 2 (admin):
void opcion_2(Empleado &empleado_log){
    int opcion_menu_admin;
    Menu menu_dos;
    Empleado empleado;
    ArchivoEmpleados archivo_emp;
    ArchivoActividades archivo_act;
    ArchivoPases archivo_pas;

    Ingresando_admin();
    rlutil::cls();
    config_menu_admin(menu_dos, empleado_log);
    mostrar_datos_log(empleado_log);
    opcion_menu_admin = menu_dos.MostrarMenu();

    while(true){
        if (empleado_log.getAdmin()) {
            switch (opcion_menu_admin) {
            case 1:
                rlutil::cls();
                mostrar_datos_log(empleado_log);
                Item1(empleado_log);
                break;
            case 2:
                rlutil::cls();
                mostrar_datos_log(empleado_log);
                Item2(empleado_log);
                break;
            case 3:
                rlutil::cls();
                mostrar_datos_log(empleado_log);
                archivo_emp.ListarEmpleados();
                break;
            case 4:
                rlutil::cls();
                mostrar_datos_log(empleado_log);
                Item4(empleado_log);
                break;
            case 5:
                rlutil::cls();
                mostrar_datos_log(empleado_log);
                Item5(empleado_log);
                break;
            case 6:
                rlutil::cls();
                mostrar_datos_log(empleado_log);
                archivo_pas.ListarPases();
                break;
            case 7:
                rlutil::cls();
                mostrar_datos_log(empleado_log);
                Item7(empleado_log);
                break;
            case 8:
                rlutil::cls();
                mostrar_datos_log(empleado_log);
                archivo_act.ListarActividades();
                break;
            case 9:
                rlutil::cls();
                mostrar_datos_log(empleado_log);
                Item9(empleado_log);
                break;
            case 10:
                rlutil::cls();
                mostrar_datos_log(empleado_log);
                Item10();
                rlutil::anykey();
                break;
            case 0:
                rlutil::cls();
                rlutil::locate(45, 12);
                std::cout << "VOLVIENDO AL MENÚ INICIAL...";
                return;
                break;
            default:
                rlutil::cls();
                rlutil::locate(55, 12);
                std::cout << "ELIJA UNA OPCIÓN VÁLIDA.";
                rlutil::anykey();
                break;

            }
        }
        else {
            switch (opcion_menu_admin) {
            case 1:
                rlutil::cls();
                mostrar_datos_log(empleado_log);
                archivo_emp.ListarEmpleados();
                break;
            case 2:
                rlutil::cls();
                mostrar_datos_log(empleado_log);
                archivo_pas.ListarPases();
                break;
            case 3:
                rlutil::cls();
                mostrar_datos_log(empleado_log);
                archivo_act.ListarActividades();
                break;
            case 4:
                rlutil::cls();
                mostrar_datos_log(empleado_log);
                Item10();
                rlutil::anykey();
                break;
            case 0:
                rlutil::cls();
                rlutil::locate(45, 12);
                std::cout << "VOLVIENDO AL MENÚ INICIAL...";
                return;
                break;
            default:
                rlutil::cls();
                rlutil::locate(55, 12);
                std::cout << "ELIJA UNA OPCIÓN VÁLIDA.";
                rlutil::anykey();
                break;

            }
        }
        rlutil::cls();
        mostrar_datos_log(empleado_log);
        opcion_menu_admin = menu_dos.MostrarMenu();
    }
}



///Menú Administración:
void config_menu_admin(Menu &menu, Empleado &empleado_log){
    std::setlocale(LC_ALL, "");

    menu.SetNombre("- ÁREA ADMINISTRATIVA -");
    if (empleado_log.getAdmin()) {
        menu.SetCantItems(11);
        menu.AddItem("EDITAR EMPLEADO", 1);
        menu.AddItem("AGREGAR EMPLEADO", 2);
        menu.AddItem("MOSTRAR LISTADO DE EMPLEADOS", 3);
        menu.AddItem("AGREGAR PASE NUEVO", 4);
        menu.AddItem("EDITAR PASES", 5);
        menu.AddItem("MOSTRAR PASES DISPONIBLES", 6);
        menu.AddItem("AGREGAR ACTIVIDAD NUEVA", 7);
        menu.AddItem("MOSTRAR ACTIVIDADES DISPONIBLES", 8);
        menu.AddItem("EDITAR ACTIVIDADES", 9);
        menu.AddItem("ESTADÍSTICAS", 10);
    }
    else {
        menu.SetCantItems(5);
        menu.AddItem("MOSTRAR LISTADO DE EMPLEADOS", 1);
        menu.AddItem("MOSTRAR PASES DISPONIBLES", 2);
        menu.AddItem("MOSTRAR ACTIVIDADES DISPONIBLES", 3);
        menu.AddItem("ESTADÍSTICAS", 4);
    }
}

/// Pantalla transición al menú:
void Ingresando_admin(){
    rlutil::cls();
    rlutil::locate(20,15);
    cout<<"INGRESANDO AL ÁREA ADMINISTRATIVA.";
    dino();
    rlutil::locate(2,27);
    std::cout<< "Continuar...";
    rlutil::anykey();
}

///
void Item1(Empleado empleado_log){
    ArchivoEmpleados archivo_emp;
    int legajo, dni;
    Empleado empleado_set;
    char nuevo_cargo[30];
    bool admin;

    rlutil::locate(25, 3);
    cout<<"Ingrese el número de legajo del empleado que desea actualizar:";
    cin>>legajo;
    if(archivo_emp.buscarEmpleado(legajo)){
        rlutil::locate(30, 5);
        cout<<"- Ingrese los nuevos datos del empleado -"<<endl;
        rlutil::locate(43, 9);
        cout<<"DNI: ";
        cin>>dni;
        empleado_set.cargarPersona();
        rlutil::locate(43, 12);
        cout<<"Cargo: ";
        cin.getline(nuevo_cargo,29);
        rlutil::locate(43, 13);
        cout<<"Permiso ADMIN  - Sí(1) / No(0) : ";
        cin>>admin;

        empleado_set.setLegajo(legajo);
        empleado_set.setDni(dni);
        empleado_set.setCargo(nuevo_cargo);
        empleado_set.setAdmin(admin);
        empleado_set.setEstado(true);

        if(archivo_emp.setEmpleado(empleado_set)){
            rlutil::locate(40, 23);
            cout<<"Empleado editado exitosamente."<<endl;
        }else{
            rlutil::locate(28, 23);
            cout<<"Ups! No se pudo editar el empleado."<<endl;
        }
    }else{
        rlutil::locate(25, 5);
        cout<<"- EL LEGAJO INGRESADO NO CORRESPONDE A UN USUARIO EXISTENTE -"<<endl;
    }
    rlutil::anykey();
}

///
void Item2(Empleado empleado_log){
    ArchivoEmpleados archivo_emp;
    archivo_emp.agregarEmpleado();
    rlutil::anykey();
}

///
void Item4(Empleado empleado_log){
    ArchivoPases archivo_pase;
    int cant = archivo_pase.getCantidad();

    if(cant>=3){
        rlutil::locate(30, 13);
        cout<<"Se ha alcanzado la cantidad máxima de pases."<<endl;
    }else{
        archivo_pase.agregarPase();
    }
    rlutil::anykey();
}



///
void Item5(Empleado empleado_log){

    ArchivoPases archivo_pas;
    Pase pase_set;
    rlutil::locate(35, 3);
    cout<<"Ingrese los datos del pase que desea actualzar."<<endl;
    rlutil::locate(28, 5);
    cout<<"ATENCIÓN: El código del mismo debe corresponderse con el de un pase ya registrado."<<endl<<endl;
    pase_set.cargarPase();
    if(archivo_pas.setPase(pase_set)){
        rlutil::locate(40, 23);
        cout<<"Pase editado exitosamente."<<endl;
    }else{
        rlutil::locate(28, 23);
        cout<<"Ups! No se pudo editar el pase. Asegurese de que el código sea correcto."<<endl;
    }
    rlutil::anykey();
}

void Item9(Empleado empleado_log){
    ArchivoActividades archivo_act;
    Actividad actividad_set;

    rlutil::locate(35, 3);
    cout<<"Ingrese los datos dela actividad que desea actualzar."<<endl;
    rlutil::locate(28, 5);
    cout<<"ATENCIÓN: El código de la misma debe corresponderse con el de una actividad ya registrada."<<endl<<endl;
    actividad_set.CargarActividad();
    if(archivo_act.setActividad(actividad_set)){
        rlutil::locate(40, 23);
        cout<<"Actividad editada exitosamente."<<endl;
    }else{
        rlutil::locate(28, 23);
        cout<<"Ups! No se pudo editar La actividad. Asegurese de que el código sea correcto."<<endl;
    }
    rlutil::anykey();
}

///
void Item7(Empleado empleado_log){
    ArchivoActividades archivo_act;
    int cant = archivo_act.getCantidad();

    if(cant>=4){
        rlutil::locate(30, 13);
            cout<<"Se a alcanzado la cantidad máxima de actividades."<<endl;
    }else{
        archivo_act.agregarActividad();
    }
    rlutil::anykey();
}
///
void Item10(){
    ArchivoVentas archivo;
    Empleado empleado_ventas, empleado_act;
    string meses[12]{"Enero", "Febrero", "Marzo", "Abril", "Mayo", "Junio", "Julio", "Agosto", "Septiembre", "Octubre", "Noviembre", "Diciembre"};
    string medio[3]{"Efectivo", "Tarjeta", "QR"};
    int mes1, mes2, max_ventas, max_actividades, medio_pago, cant_elecciones;
    float monto1, monto2;

    monto1 = monto_mes_pasado(mes1);
    monto2 = monto_mes_pasado2(mes2);
    empleado_ventas = mejor_vendedor(max_ventas);
    empleado_act = mejor_vendedor_act(max_actividades);
    medio_pago = medio_preferido(cant_elecciones);

    rlutil::locate(50, 5);
    cout<<"- ESTADÍSTICAS -"<<endl;
    rlutil::locate(17, 6);
    cout<<"----------------------------------------------------------------------------------------"<<endl;

    if(archivo.getCantidad()>0){
        rlutil::locate(17, 7);
        cout<<">> Monto recaudado en el mes actual: ";
        rlutil::locate(60, 7);
        cout<<"$"<<monto_mes_actual()<<endl;
        rlutil::locate(17, 8);
        cout<<">> Monto meses anteriores: ";
        rlutil::locate(60, 8);
        cout<<meses[mes2-1]<<": $"<<monto2<<" - "<<meses[mes1-1]<<": $"<<monto1<<endl;
        rlutil::locate(17, 9);
        cout<<">> Pase más vendido: ";
        rlutil::locate(60, 9);
        cout<<pase_mas_vendido().getNombre()<<endl;
        rlutil::locate(17, 10);
        cout<<">> Empleado que realizó más ventas: ";
        rlutil::locate(60, 10);
        cout<<empleado_ventas.getApellido()<<" "<<empleado_ventas.getNombre()<<" - Legajo "<<empleado_ventas.getLegajo()<<" ("<<max_ventas<<" ventas)"<<endl;
        rlutil::locate(17, 11);
        cout<<">> Empleado que vendió más actividades: ";
        rlutil::locate(60, 11);
        cout<<empleado_act.getApellido()<<" "<<empleado_act.getNombre()<<" - Legajo "<<empleado_act.getLegajo()<<" ("<<max_actividades<<" actividades)"<<endl;
        rlutil::locate(17, 12);
        cout<<">> Medio de pago más utilizado: ";
        rlutil::locate(60, 12);
        cout<<medio[medio_pago-1]<<" ("<<cant_elecciones<<" veces elegido)"<<endl;
    }else{
        rlutil::locate(25, 8);
        cout<<"AÚN NO HAY VENTAS REGISTRADAS"<<endl;
    }
}

/// Funciones para las Estadísticas:
/*
Monto recaudado en el último mes (contando desde el día 1 del mes actual)
Recaudación de cada uno de los dos meses anteriores.
Pase más vendido
Empleado que realizó más ventas
*/
Pase pase_mas_vendido(){
    ArchivoPases archivo_p;
    Pase pase;
    Venta reg_venta;
    int cant_reg_pases, x, pos = 0, mas_vendido, max_ventas, cod;

    cant_reg_pases = archivo_p.getCantidad();

    int *cont_pases = new int [cant_reg_pases]{};

    while(reg_venta.leerDeDisco(pos++)){
        cod = reg_venta.getPase().getCodigo();
        cont_pases[cod-1]++;
    }

    mas_vendido = 1;
    max_ventas = cont_pases[0];
    for(x=1; x<cant_reg_pases; x++){
        if(cont_pases[x]>max_ventas){
            mas_vendido = x+1;
            max_ventas = cont_pases[x];
        }
    }

    delete[] cont_pases;

    pos=0;
    while(pase.leerDeDisco(pos++)){
        if (pase.getCodigo()== mas_vendido){
            return pase;
        }
    }
    pase.setCodigo(0);
    return pase;
}

///
float monto_mes_actual(){
    Venta reg_venta;
    int pos = 0;
    float acu_monto=0;
    Fecha date;

    fecha(date);
    int anio = date.getAnio();
    int mes = date.getMes();

    while(reg_venta.leerDeDisco(pos++)){
        if(reg_venta.getFecha().getAnio()==anio && reg_venta.getFecha().getMes()==mes ){
            acu_monto+=reg_venta.getMonto();
        }
    }
    return acu_monto;
}
///
/*
monto del mes anterior
*/
float monto_mes_pasado(int &mes){
    Venta reg_venta;
    int pos = 0;
    float acu_monto=0;
    Fecha date;
     int anio;

    fecha(date);

    if(date.getMes()>1){
        anio = date.getAnio();
        mes = date.getMes()-1;
    }else{
        anio = date.getAnio()-1;
        mes = date.getMes()+11;
    }

    while(reg_venta.leerDeDisco(pos++)){
        if(reg_venta.getFecha().getAnio()==anio && reg_venta.getFecha().getMes()==mes ){
            acu_monto+=reg_venta.getMonto();
        }
    }
    return acu_monto;
}

///
/*
Monto de dos meses atrás:
*/
float monto_mes_pasado2(int &mes){
    Venta reg_venta;
    int pos = 0;
    float acu_monto=0;
    Fecha date;
    int anio;

    fecha(date);

    if(date.getMes()>2){
        anio = date.getAnio();
        mes = date.getMes()-2;
    }else{
        anio = date.getAnio()-1;
        mes = date.getMes()+10;
    }

    while(reg_venta.leerDeDisco(pos++)){
        if(reg_venta.getFecha().getAnio()==anio && reg_venta.getFecha().getMes()==mes ){
            acu_monto+=reg_venta.getMonto();
        }
    }
    return acu_monto;
}


///
/*
Vendedor que hizo más ventas en general
*/
Empleado mejor_vendedor(int &cant){
    Empleado empleado;
    ArchivoEmpleados archivo_e;
    Venta reg_venta;
    int cant_empleados, x, pos = 0, max_ventas, legajo, pos_max_ventas;

    cant_empleados = archivo_e.getCantidad();

    int *cont_ventas = new int [cant_empleados]{};

    while(empleado.leerDeDisco(pos++)){
        legajo = empleado.getLegajo();
        int pos2=0;
        while(reg_venta.leerDeDisco(pos2++)){
            if(reg_venta.getLegajoEmpleado()==legajo){
                cont_ventas[pos-1]++;
            }
        }
    }

    pos_max_ventas = 0;
    max_ventas = cont_ventas[0];
    for(x=1; x<cant_empleados; x++){
        if(cont_ventas[x]>max_ventas){
            pos_max_ventas = x;
            max_ventas = cont_ventas[x];
        }
    }
    delete[] cont_ventas;

    cant = max_ventas;

    if(empleado.leerDeDisco(pos_max_ventas)){
        return empleado;
    }
    empleado.setLegajo(0);
    return empleado;
}
///
/*
Vendedor que vendio más actividades en total entre todas sus ventas:
*/
Empleado mejor_vendedor_act(int &cant){
    Empleado empleado;
    ArchivoEmpleados archivo_e;
    Venta reg_venta;
    int cant_empleados, x, pos = 0, max_act, legajo, pos_max_act;

    cant_empleados = archivo_e.getCantidad();

    int *cont_act = new int [cant_empleados]{};

    while(empleado.leerDeDisco(pos++)){
        legajo = empleado.getLegajo();
        int pos2=0;
        while(reg_venta.leerDeDisco(pos2++)){
            if(reg_venta.getLegajoEmpleado()==legajo){
                cont_act[pos-1]+= reg_venta.getPase().getCantActividades();
            }
        }
    }
    pos_max_act = 0;
    max_act = cont_act[0];
    for(x=1; x<cant_empleados; x++){
        if(cont_act[x]>max_act){
            pos_max_act = x;
            max_act = cont_act[x];
        }
    }
    delete[] cont_act;

    cant = max_act;

    if(empleado.leerDeDisco(pos_max_act)){
        return empleado;
    }
    empleado.setLegajo(0);
    return empleado;
}

///
int medio_preferido(int &cant_elecciones){

    Venta reg_venta;
    int medio[3]{}, x, pos = 0, max_cant, max_medio;

    while(reg_venta.leerDeDisco(pos++)){
        medio[reg_venta.getMedioDePago()-1]++;
    }

    max_medio = 1;
    max_cant = medio[0];
    for(x=1; x<3; x++){
        if(medio[x]>max_cant){
            max_medio = x+1;
            max_cant = medio[x];
        }
    }

    cant_elecciones = max_cant;

    return max_medio;
}



