#include "ArchivoVentas.h"


void ArchivoVentas::ListarVentas(){

    int pos=0, i=0;
    Venta registro;

    rlutil::locate(40, 3);
    std::cout<<"- LISTADO DE VENTAS RELIZADAS -";
    while(registro.leerDeDisco(pos++)){
        if(registro.getEstado()){
            registro.mostrarVenta(i);
            i++;
        }
    }
    rlutil::anykey();
}

///
void ArchivoVentas::ListarPorCliente(int dni){
    int pos=0, i=0;
    Venta registro;

    rlutil::locate(30, 3);
    std::cout<<"- LISTADO DE VENTAS RELIZADAS DEL CLIENTE CON DNI "<<dni<< " -";
    while(registro.leerDeDisco(pos++)){
        if(registro.getEstado() && dni == registro.getDniCliente()){
            registro.mostrarVenta(i);
            i++;
        }
    }
    if(i==0){
        rlutil::locate(25, 8);
        std::cout<<"No se encontraron ventas realizadas por el cliente solicitado.";
    }
    rlutil::anykey();
}

///
void ArchivoVentas::ListarPorVendedor(int legajo){
    int pos=0, i=0;
    Venta registro;

    rlutil::locate(30, 3);
    std::cout<<"- LISTADO DE VENTAS RELIZADAS POR EL EMPLEADO CON LEGAJO "<<legajo<< " -";
    while(registro.leerDeDisco(pos++)){
        if(registro.getEstado() && legajo == registro.getLegajoEmpleado()){
            registro.mostrarVenta(i);
            i++;
        }
    }
    if(i==0){
        rlutil::locate(25, 8);
        std::cout<<"No se encontraron ventas realizadas por el usuario solicitado.";
    }

    rlutil::anykey();
}

///

Venta ArchivoVentas::GetUltimaVenta(){
    Venta ultima;
    FILE *p;

    p = fopen("Ventas.dat", "rb");
    if(p==NULL){
        rlutil::locate(35, 13);
        std::cout<<"NO SE ENCUENTRA EL ARCHIVO DE CLIENTES.";
        rlutil::anykey();
        return ultima;
    }

    fseek(p, 0, 2);
    fseek(p,(ftell(p)-sizeof(Venta)), 0);
    fread(&ultima, sizeof (Venta), 1, p);

    fclose(p);
    return ultima;
}

///
int ArchivoVentas::getCantidad() {
  FILE* p = fopen("Ventas.dat", "rb");
  if (p == NULL) {
    return 0;
  }
  fseek(p, 0, SEEK_END);
  int cant = ftell(p) / sizeof(Venta);
  fclose(p);
  return cant;
}
