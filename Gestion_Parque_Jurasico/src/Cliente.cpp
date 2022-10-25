#include "Cliente.h"


///
Cliente::Cliente(){
    _edad = 0;
    _estado = false;
}

///
void Cliente::cargarCliente(){
    std::setlocale(LC_ALL, "");
    rlutil::locate(43, 8);
    cout<<"- Registrar cliente -"<<endl;
    cargarPersona();
    rlutil::locate(43, 12);
    cout<<"Edad (numero entero): ";
    cin>>_edad;
    cout<<endl<<endl;
    _estado = true;
}


///
void Cliente::mostrarCliente(int x){
    setlocale(LC_ALL, "");
    mostrarPersona(x);
    rlutil::locate(45, 7 + (x * 5));
    cout << "- Edad: " << _edad << endl;
    cout<<endl<<endl;
}



///
void Cliente::bajaCliente(){
    _estado=false;
}

///
void Cliente::setEdad(int edad){
    _edad = edad;
}



///
int Cliente::getEdad(){
    return _edad;
}


///
void Cliente::setEstado(bool estado){
    _estado = estado;
}

bool Cliente::getEstado(){
    return _estado;
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
