#include "ArchivoActividades.h"
///
bool ArchivoActividades::agregarActividad(){
	Actividad nueva;

    nueva.CargarActividad();
    if(nueva.GrabarEnDisco()){
        cout<<"Actividad agregada exitosamente."<<endl;
        rlutil::anykey();
        return true;
    }else{
        cout<<"No se pudo guardar la actividad."<<endl;
        rlutil::anykey();
        return false;
    }
}

///
void ArchivoActividades::ListarActividades(){

    int pos=0, i=0;
    Actividad registro;

    rlutil::locate(40, 3);
    std::cout<<"- LISTADO DE ACTIVIDADES DISPONIBLES -";
    while(registro.leerDeDisco(pos++)){
        if(registro.getEstado()){
            registro.mostrarDescripcion(i);
            i++;
        }
    }
    rlutil::anykey();
}

///
bool ArchivoActividades::setActividad(Actividad actividad){
    FILE *p;
    Actividad registro;
    bool escribio=false;

    p=fopen("Actividades.dat","rb+");
    if(p==NULL){
        cout<<"Error de archivo";
        return false;
    }

    while(fread(&registro, sizeof (Actividad), 1, p)){
        if(registro.getCodigo() == actividad.getCodigo()){
            registro = actividad;
            fseek(p, ftell(p)-sizeof (Actividad), 0);
            escribio=fwrite(&registro, sizeof (Actividad), 1, p);
            fclose(p);
            return escribio;
        }
    }
    fclose(p);
    return escribio;
}

///
void ArchivoActividades::vaciarActividades(){
    Actividad registro;
    int pos = 0;
    while(registro.leerDeDisco(pos++)){
        registro.setOcupacion(0);
        registro.setDisponibilidad(registro.getCapacidad());
        registro.ModificarEnDisco(pos-1);
    }
}

///
int ArchivoActividades::getCantidad() {
  FILE* p = fopen("Actividades.dat", "rb");
  if (p == NULL) {
    return 0;
  }
  fseek(p, 0, SEEK_END);
  int cant = ftell(p) / sizeof(Actividad);
  fclose(p);
  return cant;
}

