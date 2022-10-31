#ifndef PASE_H
#define PASE_H

#include "../rlutil.h"

class Pase{
    private:
        char _nombre[30];
        int _cantActividades;//refiere a las actividades premium. La actividad parque general de juegos va siempre incluida.
        int _codigo;
        float _precio;
        bool _estado;

    public:
        Pase();
        void cargarPase();
        void suspenerPase();//setea el estado a false.
        void mostrarPase(int);
        void setNombre(std::string);
        void setPrecio(float);
        void setCantActividades(int);
        void setCodigo(int);
        char *getNombre();
        int getCantActividades();
        int getCodigo();
        float getPrecio();
        bool getEstado();

        bool leerDeDisco(int);
        bool GrabarEnDisco();
        bool ModificarEnDisco(int);
        //virtual ~Pase();


};

#endif // PASE_H
