#include "Venta.h"
#include <iostream>
#include "rlutil.h"

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
/*
void Venta::setCodPase(int cod_pase){
    _codigoDelPase = cod_pase;
}
*/

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
/*
int Venta::getCodPase(){
    return _codigoDelPase;
}
*/

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
void Venta::mostrarVenta(int x){
    setlocale(LC_ALL, "");
    rlutil::locate(42, 5 + (x * 6));
    cout << ">> Venta número " << _numeroVenta << " - "; _fecha.Mostrar();
    cout << endl;
    rlutil::locate(45, 6 + (x * 6));
    cout << "- Cliente (DNI): " << _dniCliente << endl;
    rlutil::locate(45, 7 + (x * 6));
    cout << "- Código del pase: " << _pase.getCodigo() <<" - "<<_pase.getNombre() << endl;
    rlutil::locate(45, 8 + (x * 6));
    cout << "- Monto de la venta: " << _monto << endl;
    rlutil::locate(45, 9 + (x * 6));
    cout << "- Vendedor: " << _legajoEmpleado << endl;
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
