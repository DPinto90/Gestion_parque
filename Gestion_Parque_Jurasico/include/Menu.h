#ifndef MENU_H
#define MENU_H

#include "Items.h"
#include "../rlutil.h"


class Menu{

    private:
        std::string _nombre;
        int _cantidadItems;
        Items _opciones[12];

    protected:

    public:
        Menu();
        int MostrarMenu();
        void SetNombre(std::string);
        void SetCantItems(int);
        void AddItem(std::string, int);
        int GetCantItems();
        std::string GetNombre();
        ~Menu();

};

#endif // MENU_H
