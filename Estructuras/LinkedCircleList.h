#ifndef LinkedCircleList_H
#define LinkedCircleList_H
#include <cstdlib>
#include <string>
#include <iostream>

#include "../Nodos/Cliente.h"
using namespace std;

class LinkedCircleList{
    public:
    LinkedCircleList();
    void add(Cliente* cliente);
    Cliente* pop(int id);
    string getLabels();
    string print();
    bool isEmpty();
    int size(); 
    private:
    Cliente* inicio;
    Cliente* ultimo;
};
#endif