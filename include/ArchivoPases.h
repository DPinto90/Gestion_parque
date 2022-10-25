#ifndef ARCHIVOPASES_H
#define ARCHIVOPASES_H

#include "Pase.h"

class ArchivoPases{
    public:
        //ArchivoPases();
        bool agregarPase();
        bool buscarPase(int);
        Pase getPase(int);//s�lo usar si el metodo buscar devuelve true.
        bool setPase(Pase);//Recime un pase como par�metro y compara los codigos para asignar el nuevo pase en la posici�n deseada.
        void ListarPases();
        int getCantidad();
        //virtual ~ArchivoPases();

};

#endif // ARCHIVOPASES_H
