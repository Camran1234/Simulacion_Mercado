#ifndef Cliente_H
#define Cliente_H

#include <cstdlib>
#include "../Nodos/Carreta.h"

class Cliente {
    public:
    Cliente(int);
    int idCliente;
    Carreta* carreta;
    //El siguiente de la lista enlazada
    Cliente* siguiente;
};

#endif