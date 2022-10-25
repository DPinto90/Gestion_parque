#include "Persona.h"

///
Persona::Persona(){
	strcpy(_nombre, "");
	strcpy(_apellido, "");
	_dni = 0;
}

///
void Persona::cargarPersona(){
    std::setlocale(LC_ALL, "");
    rlutil::locate(43, 10);
    cout<<"Nombre: ";
    cin.ignore();
    cin.getline(_nombre,29);
    rlutil::locate(43, 11);
    cout<<"Apellido: ";
    cin.getline(_apellido,29);
}

///
void Persona::mostrarPersona(int x){
    setlocale(LC_ALL, "");
    rlutil::locate(43, 5 + (x * 5));
    cout << ">> " << _nombre << " " << _apellido<< endl;
    rlutil::locate(45, 6 + (x * 5));
    cout <<"- DNI: " << _dni << endl;

}

///
void Persona::setNombre(string nombre){
	strcpy(_nombre, nombre.c_str());
}

///
void Persona::setApellido(string apellido){
	strcpy(_apellido, apellido.c_str());
}

///
void Persona::setDni(int dni){
	_dni = dni;
}

///
char *Persona::getNombre(){
	return _nombre;
}

///
char *Persona::getApellido(){
	return _apellido;
}

///
int Persona::getDni(){
	return _dni;
}
