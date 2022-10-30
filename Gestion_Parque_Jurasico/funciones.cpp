#include "funciones.h"


// Acá van las funciones del main y las que se utilicen a nivel general.

///Fecha del sistema:


void fecha(Fecha &date) {
    int day, month, year;
    //int hours, minutes, seconds;

    // `time_t` es un tipo de tiempo aritmético
    time_t now;

    // Obtener la hora actual
    // `time()` devuelve la hora actual del sistema como un valor `time_t`
    time(&now);

    // Convertir al formato de hora local e imprimir a stdout
    //printf("Today is %s", ctime(&now)); muestra la fecha con horas minutos y segundos.

    // localtime convierte un valor de `time_t` a la hora del calendario y
    // devuelve un puntero a una estructura `tm` con sus miembros
    // rellenado con los valores correspondientes
    struct tm *local = localtime(&now);


    day = local->tm_mday;            // obtener el día del mes (1 a 31)
    month = local->tm_mon + 1;      // obtener el mes del año (0 a 11)
    year = local->tm_year + 1900;   // obtener el año desde 1900

    date.setAnio(year);
    date.setDia(day);
    date.setMes(month);
}

///Menú inicio:
void config_menu_inicio(Menu &menu){
    std::setlocale(LC_ALL, "");

    menu.SetCantItems(4);
    menu.SetNombre("- PARQUE JURÁSICO -");
    menu.AddItem("ÁREA VENTAS", 1);
    menu.AddItem("ÁREA ADMINISTRATIVA", 2);
    menu.AddItem("INGRESAR CON OTRO USUARIO", 3);
}


///funcion para confirmar salida del programa
void opcion_salir(char &salir){
    rlutil::locate(55,12);
    std::cout<< "¿Salir? S / N: ";
    std::cin>> salir;
    salir = toupper(salir);
    while(salir != 'S' && salir != 'N'){
        rlutil::cls();
        rlutil::locate(55,12);
        std::cout<< "¿Salir? S / N: ";
        std::cin>> salir;
        salir = toupper(salir);
    }
}


///Función provisoria "proximamente", para las opciones que no estén operativas.
void proximamente(){
    rlutil::cls();
    rlutil::locate(30,15);
    cout<<"próximamente";
    dino();
    rlutil::locate(2,27);
    std::cout<< "Presione una tecla para volver al menú.";
    rlutil::anykey();
}

///
void saliendo(){
    ovni();
    rlutil::locate(65,10);
    std::cout<< "¡Ups! No se pudo ingresar al sistema.";
    rlutil::locate(75,12);
    std::cout<< "Byeeeee!";
    rlutil::locate(55,27);
}

void saliendo2(){
    rlutil::cls();
    ovni();
    rlutil::locate(75,12);
    std::cout<< "Byeeeee!";
    rlutil::locate(55,27);
}

///
void mostrar_datos_log(Empleado empleado){

    rlutil::locate(2,1);
    std::cout<< "PARQUE JURÁSICO | "<<empleado.getNombre()<<" "<<empleado.getApellido();
    rlutil::locate(1,2);
    std::cout<< "************************************************************************************************************************";
}


////////// iNICIO DE SESIÓN //////////

bool InicioSesion(Parque &parque, Empleado &empleado){
    Empleado registro;
    ArchivoEmpleados archivo_emp;
    bool encontro = 0, cargo = 0, registrar = 0;
    int legajo, pos=0;

    while(registro.leerDeDisco(pos++)){
        encontro = true;
    }
    if(encontro == false){
        rlutil::locate(35, 13);
        std::cout<<"NO SE ENCUENTRAN USUARIOS REGISTRADOS.";
        rlutil::locate(35, 15);
        std::cout<<"¿DESEA REGISTRARSE? 1 (SÍ) / 0 (NO)";
        rlutil::locate(35, 16);
        std::cout<<"Su elección: ";
        std::cin>>registrar;
        rlutil::cls();
        if(registrar){
            cargo = archivo_emp.agregarEmpleado();
            if(cargo){
                empleado = archivo_emp.getUltimoEmpleado();
                empleado.HacerAdmin();
                archivo_emp.setEmpleado(empleado);
                rlutil::locate(20, 25);
                std::cout<<"ATENCIÓN: El primer usuario registrado será admin indistintamente de su elección.";
                rlutil::anykey();
                rlutil::cls();
                rlutil::locate(45, 15);
                std::cout<<"¡Bienvenid@ "<<empleado.getNombre()<<"!"<<std::endl;
            }else{
                rlutil::cls();
                rlutil::locate(45, 15);
                std::cout<<"¡Ups! No pudimos cargar el registro."<<std::endl;
            }
            rlutil::anykey();
            return cargo;
        }else{
            parque.Cerrar();
            return false;
        }
    }

    rlutil::locate(40, 13);
    std::cout<<"INGRESE SU NUMERO DE LEGAJO PARA ACCEDER: ";
    std::cin>>legajo;
    rlutil::cls();
    if(archivo_emp.buscarEmpleado(legajo)){
        empleado = archivo_emp.getEmpleado(legajo);
        rlutil::cls();
        rlutil::locate(45, 15);
        std::cout<<"¡Hola "<<empleado.getNombre()<<"!"<<std::endl;
        rlutil::anykey();
        return true;
    }else{
        return false;
    }
}

///
bool ingreso(Parque &parque_jurasico, Empleado &empleado_log){
    int cont_intentos =0;
    bool ingresar = InicioSesion(parque_jurasico, empleado_log);
    rlutil::cls();

    while(ingresar == false){
        cont_intentos++;
        rlutil::cls();
        if(cont_intentos > 2 || parque_jurasico.GetEstado()== false){
            saliendo();
            return false;
        }
        rlutil::locate(20, 10);
        cout<<">> EL NÚMERO INGRESADO ES INCORRECTO...";
        rlutil::anykey();
        rlutil::cls();
        ingresar = InicioSesion(parque_jurasico, empleado_log);
    }
    return true;
}

