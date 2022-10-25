#ifndef CLIENTE_H
#define CLIENTE_H

#include "Persona.h"


class Cliente : public Persona{
private:
	int _edad;
	//float _altura;
	bool _estado;
public:
	Cliente();
	void cargarCliente();
	void mostrarCliente(int x);
	void bajaCliente();
	void realizarCompra();
	void setEdad(int);
	//void setAltura(float);
	void setEstado(bool);
	int getEdad();
	//float getAltura();
    bool getEstado();
    bool leerDeDisco(int);
    bool GrabarEnDisco();
    bool ModificarEnDisco(int);
	//~Cliente();
};


#endif // CLIENTE_H
