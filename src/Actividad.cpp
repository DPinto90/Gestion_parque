#include "Actividad.h"

using namespace std;

Actividad::Actividad() {
    strcpy(_nombre, "Sin definir");
    _codigo = 0;
    _ocupacion = 0;
    _capacidad = 0;
    _disponibilidad = _capacidad;
    _estado = 0;
}

///
Actividad::Actividad(string nombre, int codigo, int capacidad) {
    strcpy(_nombre, nombre.c_str());
    _codigo = codigo;
    _ocupacion = 0;
    _capacidad = capacidad;
    _disponibilidad = _capacidad;
}

///
void Actividad::CargarActividad(){
    std::setlocale(LC_ALL, "");
    cout<<"- Registrar actividad -"<<endl;
    cout<<"Nombre: ";
    cin.ignore();
    cin.getline(_nombre,29);
    cout<<"Código (4 dígitos numéricos): ";
    cin>>_codigo;
    cout<<"Capacidad: ";
    cin>>_capacidad;
    cout<<endl<<endl;
    _ocupacion=0;
    _disponibilidad = _capacidad;
    _estado = true;
}

///
void Actividad::ocuparLugar(){
    if (_disponibilidad >= 1) {
        _ocupacion++;
        _disponibilidad--;
    }
}

///
void Actividad::liberarLugar() {
    _ocupacion--;
    _disponibilidad++;
}

///
void Actividad::mostrarDescripcion(int x) {
    setlocale(LC_ALL, "");
    rlutil::locate(43, 5 + (x * 5));
    cout << ">> " << _nombre << endl;
    rlutil::locate(45, 6 + (x * 5));
    cout <<"- Código: " << _codigo << endl;
    rlutil::locate(45, 7 + (x * 5));
    cout << "- Capacidad: " << _capacidad << " personas" << endl;
    rlutil::locate(45, 8 + (x * 5));
    cout << "- Disponibilidad: " << _disponibilidad << " lugares" << endl;
    cout << endl;
}


///
void Actividad::vaciar(){
    _ocupacion = 0;
    _disponibilidad = _capacidad;
}


///
void Actividad::setCodigo(int codigo) {
    if (codigo > 0) {
        _codigo = codigo;
    }
}


///
void Actividad::setNombre(std::string nombre) {
    strcpy(_nombre, nombre.c_str());
}


///
void Actividad::setCapacidad(int capacidad) {
    _capacidad = capacidad;
}


///
void Actividad::setOcupacion(int ocupacion){
    _ocupacion = ocupacion;
}


///
void Actividad::setEstado(bool estado){
    _estado = estado;
}


///
void Actividad::setDisponibilidad(int disponibilidad){
    _disponibilidad = disponibilidad;
}

///
int Actividad::getCapacidad() {
    return _capacidad;
}

///
int Actividad::getOcupacion() {
    return _ocupacion;
}

///
int Actividad::getDisponibilidad() {
    return _disponibilidad;
}

///
bool Actividad::getEstado(){
    return _estado;
}

///
int Actividad::getCodigo() {
    return _codigo;
}

///
string Actividad::getNombre() {
    return _nombre;
}


///////////// Archivo ///////////////////
///
bool Actividad::leerDeDisco(int pos){ //pos es la posición que ocupa el registro en el archivo, empezando por 0
    FILE *p;
    p=fopen("Actividades.dat","rb");
    if(p==NULL) return false;
    fseek(p, pos * sizeof (Actividad), 0);
    bool leyo = fread(this, sizeof (Actividad), 1, p);
    fclose(p);
    return leyo;
}

///
bool Actividad::GrabarEnDisco(){
    FILE *p;
    p=fopen("Actividades.dat","ab");
    if(p==NULL){
       return false;
    }
    bool escribio = fwrite(this, sizeof (Actividad), 1, p);
    fclose(p);
    return escribio;
}

///

bool Actividad::ModificarEnDisco(int pos){
    FILE *p;
    p=fopen("Actividades.dat", "rb+");
    if(p==NULL){
        return false;
    }
    fseek(p, sizeof(Actividad)*pos,0);
    bool cambio = fwrite(this, sizeof *this,1, p);
    fclose(p);
    return cambio;
}
