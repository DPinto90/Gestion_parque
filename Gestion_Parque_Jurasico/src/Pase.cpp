#include "Pase.h"

#include <iostream>
using namespace std;

Pase::Pase(){
    strcpy(_nombre, "Sin cargar");
    _cantActividades=0;
    _precio=0;
    _estado=0;
    _codigo=0;
}

///
void Pase::cargarPase(){
    std::setlocale(LC_ALL, "");
    rlutil::locate(43, 8);
    cout<<"- Ingresar Pase -"<<endl;
    rlutil::locate(43, 13);
    cout<<"Nombre: ";
    cin.ignore();
    cin.getline(_nombre,29);
    rlutil::locate(43, 14);
    cout<<"Cantidad de actividades: ";
    cin>>_cantActividades;
    rlutil::locate(43, 15);
    cout<<"Precio: ";
    cin>>_precio;
    rlutil::locate(43, 16);
    cout<<"Código: ";
    cin>>_codigo;
    cout<<endl<<endl;
    _estado = true;
}

///
void Pase::mostrarPase(int x){
    setlocale(LC_ALL, "");
    rlutil::locate(45, 5 + (x * 5));
    cout << "- Nombre: " << _nombre << endl;
    rlutil::locate(45, 6 + (x * 5));
    cout << "- Cantidad de actividades: " << _cantActividades << endl;
    rlutil::locate(45, 7 + (x * 5));
    cout << "- Precio: " << _precio << endl;
    rlutil::locate(45, 8 + (x * 5));
    cout << "- Código: " << _codigo << endl;

}

///
void Pase::suspenerPase(){
    _estado=false;
}

///
void Pase::setNombre(string nombre){
    strcpy(_nombre, nombre.c_str());
}

///
void Pase::setPrecio(float precio){
    _precio = precio;
}

///
void Pase::setCantActividades(int cant){
    _cantActividades = cant;
}

///
void Pase::setCodigo(int codigo){
    _codigo = codigo;
}

///
char *Pase::getNombre(){
    return _nombre;
}

///
int Pase::getCantActividades(){
    return _cantActividades;
}

///
float Pase::getPrecio(){
    return _precio;
}

///
bool Pase::getEstado(){
    return _estado;
}

///
int Pase::getCodigo(){
    return _codigo;
}


///
/*/Pase::~Pase(){
    //dtor
}*/

/////////////// Archivos //////////////////////////////////

///
bool Pase::leerDeDisco(int pos){ //pos es la posición que ocupa el registro en el archivo, empezando por 0
    FILE *p;
    p=fopen("Pases.dat","rb");
    if(p==NULL) return false;
    fseek(p, pos * sizeof (Pase), 0);
    bool leyo = fread(this, sizeof (Pase), 1, p);
    fclose(p);
    return leyo;
}

///
bool Pase::GrabarEnDisco(){
    FILE *p;
    p=fopen("Pases.dat","ab");
    if(p==NULL){
       return false;
    }
    bool escribio = fwrite(this, sizeof (Pase), 1, p);
    fclose(p);
    return escribio;
}

///
bool Pase::ModificarEnDisco(int pos){
    FILE *p;
    p=fopen("Pases.dat", "rb+");
    if(p==NULL){
        return false;
    }
    fseek(p, sizeof(Pase)*pos,0);
    bool cambio = fwrite(this, sizeof *this,1, p);
    fclose(p);
    return cambio;
}
