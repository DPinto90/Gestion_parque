#ifndef CLIENTE_H
#define CLIENTE_H

#include "Persona.h"
#include "Fecha.h"
class Cliente : public Persona{
private:
	Fecha _fechaNac;
	bool _estado;
	int _edad;
public:
	Cliente();
	void cargarCliente();
	void mostrarCliente(int x);
	void bajaCliente();
	void realizarCompra();
	void setFecha(Fecha);
	void setEstado(bool);
	Fecha getFecha();
	int getEdad();
    bool getEstado();
    bool leerDeDisco(int);
    bool GrabarEnDisco();
    bool ModificarEnDisco(int);
};


#endif // CLIENTE_H
