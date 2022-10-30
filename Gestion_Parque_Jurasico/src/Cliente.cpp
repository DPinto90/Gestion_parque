#include "Cliente.h"
#include "../funciones.h"


///
Cliente::Cliente(){
    _estado = false;
    _edad = -1;
}

///
void Cliente::cargarCliente(){
    std::setlocale(LC_ALL, "");
    int dia, mes, anio;
    Fecha fecha;

    rlutil::locate(43, 8);
    cout<<"- Registrar cliente -"<<endl;
    cargarPersona();
    rlutil::locate(43, 13);
    cout<<"Fecha de Nacimiento";
    rlutil::locate(45, 14);
    cout<<"DÍA: ";
    cin>>dia;
    rlutil::locate(45, 15);
    cout<<"MES: ";
    cin>>mes;
    rlutil::locate(45, 16);
    cout<<"AÑO: ";
    cin>>anio;
    cout<<endl<<endl;
    _estado = true;

    fecha.setDia(dia);
    fecha.setMes(mes);
    fecha.setAnio(anio);
    setFecha(fecha);
}


///
void Cliente::mostrarCliente(int x){
    setlocale(LC_ALL, "");
    mostrarPersona(x);
    rlutil::locate(45, 7 + (x * 5));
    cout << "- Fecha de nacimiento: ";_fechaNac.Mostrar();
    rlutil::locate(45, 8 + (x * 5));
    cout << "- Edad: "<<getEdad();
    cout<<endl<<endl;
}



///
void Cliente::bajaCliente(){
    _estado=false;
}

///
void Cliente::setFecha(Fecha fecha){
    _fechaNac = fecha;
}



///
int Cliente::getEdad(){
    Fecha hoy;
    if(_fechaNac.getDia()!=0){
        fecha(hoy);
        if(_fechaNac.getMes()>hoy.getMes()|| (_fechaNac.getMes()==hoy.getMes()&&_fechaNac.getDia()>hoy.getDia())){
            _edad = hoy.getAnio() - _fechaNac.getAnio() - 1;
        }else{
            _edad = hoy.getAnio()- _fechaNac.getAnio();
        }
    }
    return _edad;
}


///
void Cliente::setEstado(bool estado){
    _estado = estado;
}

///
bool Cliente::getEstado(){
    return _estado;
}

///
Fecha Cliente::getFecha(){
    return _fechaNac;
}


////////////////////// Métodos de Archivos ///////////////////////////
///
bool Cliente::leerDeDisco(int pos){ //pos es la posición que ocupa el registro en el archivo, empezando por 0
    FILE *p;
    p=fopen("Clientes.dat","rb");
    if(p==NULL) return false;
    fseek(p, pos * sizeof (Cliente), 0);
    bool leyo = fread(this, sizeof (Cliente), 1, p);
    fclose(p);
    return leyo;
}

///
bool Cliente::GrabarEnDisco(){
    FILE *p;
    p=fopen("Clientes.dat","ab");
    if(p==NULL){
       return false;
    }
    bool escribio = fwrite(this, sizeof (Cliente), 1, p);
    fclose(p);
    return escribio;
}


///
bool Cliente::ModificarEnDisco(int pos){
    FILE *p;
    p=fopen("Clientes.dat", "rb+");
    if(p==NULL){
        return false;
    }
    fseek(p, sizeof(Cliente)*pos,0);
    bool cambio = fwrite(this, sizeof *this,1, p);
    fclose(p);
    return cambio;
}
