#ifndef Cola_H
#define Cola_H
#include <cstdlib>

#include "../Nodos/Cliente.h"
#include <string>
#include <iostream>
using namespace std;

class Cola {
    public:
    Cola();
    void add(Cliente* cliente);
    Cliente* pop();
    string getLabels();
    string print();
    int size(); 
    bool isEmpty();
    private:
    Cliente* inicio;
};
#endif