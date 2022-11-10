#include <iostream>
#include "Parque.h"


using namespace std;

Parque::Parque(){
	_estado = false;
}

///
void Parque::Abrir(){
	_estado = true;
}

///
void Parque::Cerrar(){
	_estado = false;
}


///
bool Parque::GetEstado(){
    return  _estado;
}

///
void Parque::cargarVecPases(){
    int i;
    Pase registro;

    for(i=0; i<3; i++){
        registro.leerDeDisco(i);
        if(registro.getEstado()){
            _Pases[i]=registro;
        }
    }
}

void Parque::mostrarVecPases(){
    for(int y=0; y<3; y++){
        _Pases[y].mostrarPase(y);
    }
    rlutil::anykey();
}

///
void Parque::cargarVecActividades(){
    int i;
    Actividad registro;

    for(i=0; i<4; i++){
        registro.leerDeDisco(i);
        if(registro.getEstado()){
            _actividad[i]=registro;
        }
    }
}

///
void Parque::mostrarVecActividades(){
    for(int y=0; y<4; y++){
        _actividad[y].mostrarDescripcion(y);
    }
    rlutil::anykey();
}


// ////////////////////////// Venta de pases ///////////////////////////
///
bool Parque::VenderPase(Empleado empleado, Fecha &date){
    bool compraExitosa;
    Cliente cliente;
    Pase pase;
    Venta venta;

    rlutil::locate(45, 3);
    std::cout<<"- COMPRA DE PASES -"<<std::endl;
    rlutil::locate(30, 4);
    std::cout<<"-------------------------------------------------------"<<std::endl;

    //Paso 1: identificación del cliente
    identificarCliente(cliente);
    rlutil::cls();

    //Paso 2: elección del pase: Devuelve la cant de actividades extra incluidas.
    int cant_actividades = ElegirPase(pase);
    rlutil::cls();

    //Paso 3: elección de la actividad: Recibe como parámetro la cantidad de actividades incluidas.
    ElegirActividad(cant_actividades);

    //Paso 4: Guarda la compra en el archivo de ventas. Si la compra no se confirma, queda todo como está, salvo por la creación de un nuevo cliente, en caso de que no sea un cliente ya registrados anteriormente.
    compraExitosa = confirmarVenta(venta, pase, empleado, cliente, _actividad, date);
    return compraExitosa;
}

/////////////////// Métodos para la venta ///////////////////
///
void Parque::identificarCliente(Cliente &cliente){

    int dni;

    rlutil::locate(30, 6);
    std::cout<<"Ingrese el DNI del cliente: ";
    std::cin>>dni;
    rlutil::cls();
    if(_ArchivoCli.buscarCliente(dni)){
            cout << dni;
        cliente = _ArchivoCli.getCliente(dni);
    }else{
        rlutil::cls();
        _ArchivoCli.agregarCliente(dni);
        cliente = _ArchivoCli.getUltimoCliente();
    }
}

///
int Parque::ElegirPase(Pase &pase){
    int pase_elegido;
    cargarVecActividades();
    cargarVecPases();

    MostrarOpcionesPases();
    std::cin>>pase_elegido;

    while(pase_elegido<1 || pase_elegido>3){
        MostrarOpcionesPases();
        std::cin>>pase_elegido;
    }
    pase = _Pases[pase_elegido-1];
    return pase.getCantActividades();
}

///
void Parque::ElegirActividad(int cant_actividades){
    int actividad_elegida;
    bool disponible[4]={};

    for (int i=0; i<cant_actividades; i++){

        for(int x=1; x<4; x++){//la actividad 0 es el parque de juegos general y no se elige. Viene siempre incluida.
            if (_actividad[x].getDisponibilidad()>=1){
                disponible[x] = true;
            }else{
                disponible[x] = false;
            }
        }
        MostrarOpcionesActividades(i);
        std::cin>>actividad_elegida;
        rlutil::cls();

        while(actividad_elegida<1 || actividad_elegida>3){

            MostrarOpcionesActividades(i);
            std::cin>>actividad_elegida;
            rlutil::cls();
        }

        while(disponible[actividad_elegida]==false){
            rlutil::locate(25, 15);
            std::cout<<"Lo sentimos, no quedan lugares disponibles para esa actividad.";
            rlutil::anykey();
            rlutil::cls();
            MostrarOpcionesActividades(i);
            std::cin>>actividad_elegida;
            rlutil::cls();
        }

        if(disponible[actividad_elegida]==true){
            _actividad[actividad_elegida].ocuparLugar();
            rlutil::locate(40, 18);
            std::cout<<"Actividad agregada exitosamente.";
            rlutil::anykey();
            rlutil::cls();
        }
    }
}

///
bool Parque::confirmarVenta(Venta venta, Pase pase, Empleado empleado, Cliente cliente, Actividad _actividad[], Fecha &date){
    bool confirmar, compraExitosa;

    rlutil::locate(30, 15);
    std::cout<<"CONFIRMAR COMPRA (1) - VOLVER AL MENÚ (0).";
    rlutil::locate(30, 17);
    std::cout<<"Su elección: ";
    std::cin>>confirmar;
    rlutil::cls();

    if(confirmar){
        int medio;

        _actividad[0].ocuparLugar();
        for(int y=1; y<4; y++){
            _ArchivoAct.setActividad(_actividad[y]);
        }

        do{
            rlutil::locate(45, 3);
            std::cout<<"- Elija el medio de pago -";
            rlutil::locate(48, 5);
            std::cout<<"[1] Efectivo ";
            rlutil::locate(48, 6);
            std::cout<<"[2] Tarjeta ";
            rlutil::locate(48, 7);
            std::cout<<"[3] QR ";
            rlutil::locate(48, 9);
            std::cout<<"SU ELECCIÓN: ";
            std::cin>>medio;
            rlutil::cls();
        }while(medio<1||medio>3);

        venta.setMedioDePago(medio);
        venta.setNumVenta(ContarVentas()+1);
        venta.setDniCliente(cliente.getDni());
        venta.setLegajoEmpleado(empleado.getLegajo());
        venta.setMonto(pase.getPrecio());
        venta.setEstado(true);
        venta.setFecha(date);
        venta.setPase(pase);

        compraExitosa = venta.GrabarEnDisco();

        rlutil::locate(45, 3);
        std::cout<<"- DATOS DE LA VENTA -";
        venta.mostrarVenta(0);
        rlutil::anykey();
    }else{
        compraExitosa = false;
    }
    return compraExitosa;
}


///
void Parque::MostrarOpcionesPases(){

    rlutil::locate(30, 6);
    std::cout<<"Seleccione el pase de su preferencia: ";
    rlutil::locate(30, 7);
    std::cout<<"---------------------------------------------------------------------";
    rlutil::locate(30, 9);
    std::cout<<"ACLARACIÓN: Todos los pases incluyen acceso al área general de juegos.";
    rlutil::locate(30, 11);
    std::cout<<"[1] "<<_Pases[0].getNombre();
    rlutil::locate(60, 11);
    cout<< "  -  Incluye "<< _Pases[0].getCantActividades()<<" Actividades premium.";
    rlutil::locate(30, 12);
    std::cout<<"[2] "<<_Pases[1].getNombre();
    rlutil::locate(60, 12);
    cout<< "  -  Incluye "<<_Pases[1].getCantActividades()<<" Actividades premium.";
    rlutil::locate(30, 13);
    std::cout<<"[3] "<<_Pases[2].getNombre();
    rlutil::locate(60, 13);
    cout<< "  -  Incluye "<<_Pases[2].getCantActividades()<<" Actividades premium.";

    rlutil::locate(30, 14);
    std::cout<<"---------------------------------------------------------------------";

    rlutil::locate(30, 15);
    std::cout<<"Su elección: ";

}

///
void Parque::MostrarOpcionesActividades(int i){
    rlutil::locate(30, 6);
    std::cout<<"Elija su actividad número: " << i+1;
    rlutil::locate(30, 7);
    std::cout<<"-------------------------------------------------------";
    rlutil::locate(30, 9);
    std::cout<<"- 1 "<<_actividad[1].getNombre();
    rlutil::locate(60, 9);
    cout<< "  -  " << _actividad[1].getDisponibilidad() << " lugares disponibles.";
    rlutil::locate(30, 10);
    std::cout<<"- 2 "<<_actividad[2].getNombre();
    rlutil::locate(60, 10);
    cout<< "  -  " << _actividad[2].getDisponibilidad() << " lugares disponibles.";
    rlutil::locate(30, 11);
    std::cout<<"- 3 "<<_actividad[3].getNombre();
    rlutil::locate(60, 11);
    cout<< "  -  " << _actividad[3].getDisponibilidad() << " lugares disponibles.";
    rlutil::locate(30, 14);
    std::cout<<"Su elección: ";
}


///
int Parque::ContarVentas(){
    Venta registro;
    int pos = 0, cont = 0;
    while(registro.leerDeDisco(pos++)){
        cont++;
    }
    return cont;
}


///
Parque::~Parque(){
}
