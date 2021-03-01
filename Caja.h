#include <cstdlib>

class Caja{
    public:
    Caja(int, int);
    bool setClient(Cliente* cliente);

    int id;
    int tiempoServicio;
    int tiempo;
    bool disponible;
    Cliente* cliente;
    //Nodes for the LinkedDoubleList
    Caja* siguiente;
    Caja* anterior;
};