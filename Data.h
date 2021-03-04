#ifndef Data_H
#define Data_H
#include <cstdlib>
#include "Estructuras/Pila.h"
#include "Estructuras/Cola.h"
#include "Estructuras/LinkedCircleList.h"
#include "Estructuras/LinkedDoubleList.h"




class Data {
    public: 
    Data();
    void setCarretas(int carretas);
    void setCajas(int tiempoServicio);
    void setClientes(int clientes);
    bool stablishData();

    int clientesLeft;
    //Para carretas
    Pila* pilaCarreta1;
    Pila* pilaCarreta2;
    //Lista de Compras
    LinkedCircleList* listaCompras;
    //Cola de Pagos
    Cola* colaPagos;
    //Lista de Cajas
    LinkedDoubleList* listaCajas;

    void addCarreta(int numero, int indexCarreta);
    int noCarretas;
    int noCajas;
    int noClientes;
    bool noElements();
};

#endif