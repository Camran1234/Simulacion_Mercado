
#include <iostream>
#include <cstdlib>
#include "../Nodos/Caja.h"
#include "../Nodos/Cliente.h"
#include "../Data.h"

#ifndef LinkedDoubleList_H
#define LinkedDoubleList_H
#include <string>
#include <iostream>
using namespace std;



class LinkedDoubleList {
    public:
    LinkedDoubleList();
    void add(Caja* caja);
    void returnCarretas(Pila* pilaCarreta1, Pila* pilaCarreta2);
    bool addCliente(Cliente* cliente);
    Caja* pop();
    string getLabels();
    string print();
    int size();
    int generateRandomNumber(int parametro);
    private:
    Caja* inicio;
};
#endif