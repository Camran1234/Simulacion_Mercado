#include <cstdlib>
#include "../Nodos/Cliente.h"
#ifndef Caja_H
#define Caja_H

class Caja{
    public:
    Caja(int, int);
    bool setClient(Cliente* cliente);
    void passTurn();
    int id;
    int tiempoServicio;
    int tiempo;
    bool disponible;
    Cliente* cliente;
    //Nodes for the LinkedDoubleList
    Caja* siguiente;
    Caja* anterior;
};

#endif