#include <cstdlib>
#include "Carreta.h"
class Pila {
    public:
    Pila();
    void push(int id);
    Carreta* pop();
    bool isEmpty();
    void print();
    int size();
    private:
    Carreta* inicio;
};