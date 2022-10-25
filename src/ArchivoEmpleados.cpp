#include "ArchivoEmpleados.h"

bool ArchivoEmpleados::agregarEmpleado(){
    Empleado nuevo;

    if(nuevo.CargarEmpleado()){

        nuevo.setLegajo(getCantidad()+1000);// Generación automática de legajo.

        if(nuevo.GrabarEnDisco()){
            rlutil::locate(40, 18);
            cout<<"Registro agregado exitosamente."<<endl;
            //rlutil::anykey();
            return true;
        }else{
            rlutil::locate(40, 15);
            cout<<"No se pudo guardar el registro."<<endl;
            //rlutil::anykey();
            return false;
        }
    }else{
        return false;
    }
}

///
bool ArchivoEmpleados::buscarEmpleado(int legajo){
    Empleado registro;
    bool encontro=0;
    int pos =0;

    while(registro.leerDeDisco(pos++)){
        if(registro.getLegajo() == legajo){
            encontro = true;
        }
    }

    return encontro;
}

/// Usar sólo si buscarEmpleado == true.
Empleado ArchivoEmpleados::getEmpleado(int legajo){
    Empleado busqueda;
    int pos=0;

    while(busqueda.leerDeDisco(pos++)){
        if(busqueda.getLegajo() == legajo){
            rlutil::locate(30, 13);
            std::cout<<"El número de legajo ingresado corresponde al Empleado: "<< busqueda.getNombre()<<" "<<busqueda.getApellido();
            rlutil::anykey();
            return busqueda;
        }
    }

    rlutil::locate(35, 13);
    std::cout<<"¡Ups! No pudimos encontrar el empleado.";
    rlutil::anykey();

    return busqueda;
}

///
Empleado ArchivoEmpleados::getUltimoEmpleado(){
    Empleado ultimo;
    FILE *p;

    p = fopen("Empleados.dat", "rb");
    if(p==NULL){
        rlutil::locate(35, 13);
        std::cout<<"NO SE ENCUENTRA EL ARCHIVO DE EMPLEADOS.";
        rlutil::anykey();
        return ultimo;
    }

    fseek(p, 0, 2);
    fseek(p,(ftell(p)-sizeof(Empleado)), 0);
    fread(&ultimo, sizeof (Empleado), 1, p);

    fclose(p);
    return ultimo;

}

///
bool ArchivoEmpleados::setEmpleado(Empleado empleado){
    Empleado registro;
    bool setOk = 0;
    int pos=0;
    while(registro.leerDeDisco(pos++)){
        if(registro.getLegajo()==empleado.getLegajo()){
            setOk = empleado.ModificarEnDisco(pos-1);
        }
    }
    return setOk;
}

///
void ArchivoEmpleados::ListarEmpleados(){
    int pos=0, i=0;
    Empleado registro;

    rlutil::locate(40, 3);
    std::cout<<"- LISTADO DE EMPLEADOS ACTIVOS -";
    while(registro.leerDeDisco(pos++)){
        if(registro.getEstado()){
           registro.MostrarEmpleado(i);
           i++;
        }
    }
    rlutil::anykey();

}

///
int ArchivoEmpleados::getCantidad() {
  FILE* p = fopen("Empleados.dat", "rb");
  if (p == NULL) {
    return 0;
  }
  fseek(p, 0, SEEK_END);
  int cant = ftell(p) / sizeof(Empleado);
  fclose(p);
  return cant;
}



