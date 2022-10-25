#include "Items.h"


Items::Items(){
    _nombre = "opcion";
    _posicion = 1;
}

Items::Items(std::string nombre, int posicion){
    _nombre = nombre;
    _posicion = posicion;
}

void Items::SetPosision(int posicion){
    _posicion = posicion;
}

void Items::SetNombre(std::string nombre){
    _nombre = nombre;
}

std::string Items::GetNombre(){
    return _nombre;
}
int Items::GetPosicion(){
    return _posicion;
}

Items::~Items(){
    //dtor
}
