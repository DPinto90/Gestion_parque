#ifndef ITEMS_H
#define ITEMS_H

#include <string>
#include <iostream>



class Items
{
    protected:
        std::string _nombre;
        int _posicion;

    public:
        Items();
        Items(std::string, int);
        void SetPosision(int);
        void SetNombre(std::string);
        std::string GetNombre();
        int GetPosicion();
        virtual ~Items();




};

#endif // ITEMS_H
