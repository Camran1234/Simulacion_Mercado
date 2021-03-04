#ifndef Pila_H
#define Pila_H
#include <cstdlib>
#include <string>
#include <iostream>
#include "../Nodos/Carreta.h"
#include <string>
#include <iostream>
using namespace std;


class Pila {
    public:
    Pila();
    void push(int id);
    void pushOld(Carreta* carreta);
    Carreta* pop();
    bool isEmpty();
    string getLabels(int posicion);
    string print(int posicion);
    int size();
    private:
    Carreta* inicio;
};

#endif