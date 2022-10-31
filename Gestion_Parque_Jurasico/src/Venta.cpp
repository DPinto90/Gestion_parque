#include "Venta.h"
#include <iostream>
#include "../rlutil.h"

using namespace std;


Venta::Venta(){

}

///
void Venta::setNumVenta(int n){
    _numeroVenta = n;
}


///
void Venta::setDniCliente(int dni){
    _dniCliente = dni;
}



///
void Venta::setLegajoEmpleado(int leg_empleado){
    _legajoEmpleado = leg_empleado;
}


///
void Venta::setMonto(float monto){
    _monto = monto;
}

///
void Venta::setEstado(bool estado){
    _estado = estado;
}


///
void Venta::setFecha(Fecha date){
    _fecha = date;
}

///

void Venta::setPase(Pase pase){
    _pase = pase;
}

///
void Venta::setMedioDePago(int medio){
    _medioDePago = medio;
}

///
bool Venta::getEstado(){
    return _estado;
}


///
int Venta::getNumVenta(){
    return _numeroVenta;
}


///
int Venta::getDniCliente(){
    return _dniCliente;
}




///
int Venta::getLegajoEmpleado(){
    return _legajoEmpleado;
}


///
float Venta::getMonto(){
    return _monto;
}

///
Fecha Venta::getFecha(){
    return _fecha;
}

///

Pase Venta::getPase(){
    return _pase;
}

///
int Venta::getMedioDePago(){
    return _medioDePago;
}
///
void Venta::mostrarVenta(int x){
    string medio[3]{"Efectivo", "Tarjeta", "QR"};

    setlocale(LC_ALL, "");
    rlutil::locate(42, 5 + (x * 8));
    cout << ">> Venta número " << _numeroVenta;
    rlutil::locate(45, 6 + (x * 8));
    cout << "- Fecha: "; _fecha.Mostrar();
    rlutil::locate(45, 7 + (x * 8));
    cout << "- Cliente (DNI): " << _dniCliente;
    rlutil::locate(45, 8 + (x * 8));
    cout << "- Código del pase: " << _pase.getCodigo() <<" - "<<_pase.getNombre();
    rlutil::locate(45, 9 + (x * 8));
    cout << "- Monto de la venta: " << _monto;
    rlutil::locate(45, 10 + (x * 8));
    cout << "- Medio de pago: " << medio[_medioDePago-1];
    rlutil::locate(45, 11 + (x * 8));
    cout << "- Vendedor: " << _legajoEmpleado;
    cout << endl;
}



///////////// Archivo ///////////////////
///
bool Venta::leerDeDisco(int pos){ //pos es la posición que ocupa el registro en el archivo, empezando por 0
    FILE *p;
    p=fopen("Ventas.dat","rb");
    if(p==NULL) return false;
    fseek(p, pos * sizeof (Venta), 0);
    bool leyo = fread(this, sizeof (Venta), 1, p);
    fclose(p);
    return leyo;
}

///
bool Venta::GrabarEnDisco(){
    FILE *p;
    p=fopen("Ventas.dat","ab");
    if(p==NULL){
       return false;
    }
    bool escribio = fwrite(this, sizeof (Venta), 1, p);
    fclose(p);
    return escribio;
}
