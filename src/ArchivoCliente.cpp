#include "ArchivoCliente.h"

bool ArchivoCliente::agregarCliente(int dni){
    Cliente nuevo;
    nuevo.cargarCliente();
    nuevo.setDni(dni);
    if(nuevo.GrabarEnDisco()){
        rlutil::locate(40, 15);
        cout<<"Registro agregado exitosamente."<<endl;
        rlutil::anykey();
        return true;
    }else{
        rlutil::locate(40, 15);
        cout<<"No se pudo guardar el registro."<<endl;
        rlutil::anykey();
        return false;
    }
}

///
bool ArchivoCliente::buscarCliente(int dni){
    Cliente registro;
    bool encontro=0;
    int pos =0;

    while(registro.leerDeDisco(pos++)){
        if(registro.getDni() == dni){
            encontro = true;
        }
    }

    return encontro;
}

///
Cliente ArchivoCliente::getCliente(int dni){
    Cliente busqueda;
    int pos=0;

    while(busqueda.leerDeDisco(pos++)){
        if(busqueda.getDni() == dni){
            rlutil::locate(30, 13);
            std::cout<<"El DNI ingresado corresponde al Cliente: "<< busqueda.getNombre()<<" "<<busqueda.getApellido();
            rlutil::anykey();
            return busqueda;
        }
    }

    rlutil::locate(35, 13);
    std::cout<<"¡Ups! No pudimos encontrar el cliente.";
    rlutil::anykey();

    return busqueda;
}

///
Cliente ArchivoCliente::getUltimoCliente(){
    Cliente ultimo;
    FILE *p;

    p = fopen("Clientes.dat", "rb");
    if(p==NULL){
        rlutil::locate(35, 13);
        std::cout<<"NO SE ENCUENTRA EL ARCHIVO DE CLIENTES.";
        rlutil::anykey();
        return ultimo;
    }

    fseek(p, 0, 2);
    fseek(p,(ftell(p)-sizeof(Cliente)), 0);
    fread(&ultimo, sizeof (Cliente), 1, p);

    fclose(p);
    return ultimo;
}


///
void ArchivoCliente::ListarClientes(){
    Cliente registro;
    int pos=0, i=0;

    rlutil::locate(40, 3);
    std::cout<<"- LISTADO DE CLIENTES -";
    while(registro.leerDeDisco(pos++)){
        if(registro.getEstado()){
            registro.mostrarCliente(i);
            i++;
        }

    }
    rlutil::anykey();

}
