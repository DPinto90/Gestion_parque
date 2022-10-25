#include "ArchivoPases.h"
#include <iostream>

using namespace std;

///
bool ArchivoPases::agregarPase(){
    Pase nuevo;

    nuevo.cargarPase();
    if(nuevo.GrabarEnDisco()){
        cout<<"Pase agregada exitosamente."<<endl;
        rlutil::anykey();
        return true;
    }else{
        cout<<"No se pudo guardar el pase."<<endl;
        rlutil::anykey();
        return false;
    }
}

///
bool ArchivoPases::buscarPase(int codigo){
    Pase registro;
    bool encontro=0;
    int pos =0;

    while(registro.leerDeDisco(pos++)){
        if(registro.getCodigo() == codigo){
            encontro = true;
        }
    }
    return encontro;
}

/// //sólo usar si el metodo buscar devuelve true.
Pase ArchivoPases::getPase(int codigo){
    Pase busqueda;
    int pos=0;

    while(busqueda.leerDeDisco(pos++)){
        if(busqueda.getCodigo() == codigo){
            //rlutil::locate(35, 13);
            std::cout<<"El Código ingresado corresponde al pase: "<< busqueda.getNombre()<<".";
            rlutil::anykey();
            return busqueda;
        }
    }

    //rlutil::locate(35, 13);
    std::cout<<"¡Ups! No pudimos encontrar el pase.";
    rlutil::anykey();

    return busqueda;

}
///
bool ArchivoPases::setPase(Pase pase){//Recime un PASE como parámetro y compara los CODIGOS para asignar el nuevo PASE en la posición deseada.
    Pase registro;
    bool setOk = 0;
    int pos=0;
    while(registro.leerDeDisco(pos++)){
        if(registro.getCodigo()==pase.getCodigo()){
            setOk = pase.ModificarEnDisco(pos-1);
        }
    }
    return setOk;
}

///
void ArchivoPases::ListarPases(){
    int pos=0, i=0;
    Pase registro;

    rlutil::locate(40, 3);
    std::cout<<"- LISTADO DE PASES DISPONIBLES -";
    while(registro.leerDeDisco(pos++)){
        if(registro.getEstado()){
           registro.mostrarPase(i);
           i++;
        }
    }
    rlutil::anykey();
}

///
int ArchivoPases::getCantidad() {
  FILE* p = fopen("Pases.dat", "rb");
  if (p == NULL) {
    return 0;
  }
  fseek(p, 0, SEEK_END);
  int cant = ftell(p) / sizeof(Pase);
  fclose(p);
  return cant;
}
