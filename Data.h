#include <cstdlib>
#include "Pila.h"
#include "Cola.h"
#include "LinkedCircleList.h"
#include "LinkedDoubleList.h"

class Data {
    public: 
    Data();
    void setCarretas(int carretas);
    void setCajas(int tiempoServicio);
    void setClientes(int clientes);
    void stablishData();

    unsigned int clientesLeft;
    //Para carretas
    Pila* pilaCarreta1;
    Pila* pilaCarreta2;
    //Lista de Compras
    LinkedCircleList* listaCompras;
    //Cola de Pagos
    Cola* colaPagos;
    //Lista de Cajas
    LinkedDoubleList* listaCajas;

    private:
    void addCarreta(int numero);
    unsigned int noCarretas;
    unsigned int noCajas;
    unsigned int noClientes;
};