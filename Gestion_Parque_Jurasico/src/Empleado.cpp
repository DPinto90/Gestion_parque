#include "Empleado.h"

Empleado::Empleado(){
	strcpy(_cargo, "");
	_estado = false;
	_admin = false;
	_legajo = 0;
}

///
bool Empleado::CargarEmpleado(){
    int dni, pos = 0;
    std::setlocale(LC_ALL, "");
    rlutil::locate(43, 8);
    cout<<"- Registrar Empleado -"<<endl;
    rlutil::locate(43, 9);
    cout << "DNI (sin separaciones ni puntos): ";
    cin >> dni;

    while (leerDeDisco(pos++)) {
        if (getDni() == dni) {
            rlutil::anykey();
            rlutil::cls();
            rlutil::locate(43, 9);
            cout << " YA EXISTE UN USUARIO CON EL DNI INGRESADO ";
            return false;
        }
    }
    setDni(dni);
    cargarPersona();
    rlutil::locate(43, 12);
    cout<<"Cargo: ";
    cin.getline(_cargo,29);
    rlutil::locate(43, 13);
    cout<<"¿Es admin? si (1) / no (0): ";
    cin>>_admin;
    cout<<endl<<endl;

    _estado = true;
    return true;
}


///
void Empleado::MostrarEmpleado(int x){
    setlocale(LC_ALL, "");
    mostrarPersona(x);
    rlutil::locate(45, 7 + (x * 5));
    cout << "- Cargo: " << _cargo << endl;
    rlutil::locate(45, 8 + (x * 5));
    cout << "- Legajo: "<<_legajo <<endl;
}

///
void Empleado::setCargo(string cargo){
	strcpy(_cargo, cargo.c_str());
}

///
void Empleado::setEstado(bool estado){
	_estado = estado;
}

///
void Empleado::setAdmin(bool admin){
    _admin = admin;
}

///
void Empleado::setLegajo(int num){
    _legajo = num;
}


///
char *Empleado::getCargo(){
	return _cargo;
}

///
bool Empleado::getEstado(){
	return _estado;
}

///
bool Empleado::getAdmin(){
    return _admin;
}

///
int Empleado::getLegajo(){
    return _legajo;
}

///
void Empleado::BajaEmpleado(){
    _estado = false;
}

///
void Empleado::HacerAdmin(){
    _admin = true;
}

////////////// Métodos de Archivos ///////////////////////
///
bool Empleado::leerDeDisco(int pos){ //pos es la posición que ocupa el registro en el archivo, empezando por 0
    FILE *p;
    p=fopen("Empleados.dat","rb");
    if(p==NULL) return false;
    fseek(p, pos * sizeof (Empleado), 0);
    bool leyo = fread(this, sizeof (Empleado), 1, p);
    fclose(p);
    return leyo;
}

///
bool Empleado::GrabarEnDisco(){
    FILE *p;
    p=fopen("Empleados.dat","ab");
    if(p==NULL){
       return false;
    }
    bool escribio = fwrite(this, sizeof (Empleado), 1, p);
    fclose(p);
    return escribio;
}

///
bool Empleado::ModificarEnDisco(int pos){
    FILE *p;
    p=fopen("Empleados.dat", "rb+");
    if(p==NULL){
        return false;
    }
    fseek(p, sizeof(Empleado)*pos,0);
    bool cambio = fwrite(this, sizeof *this,1, p);
    fclose(p);
    return cambio;
}

///
