#include <cstdlib>

class Cliente {
    public:
    Cliente(int);
    int idCliente;
    Carreta* carreta;
    //El siguiente de la lista enlazada
    Cliente* siguiente;
};