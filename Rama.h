#ifndef Rama_H
#define Rama_H
#include <cstdlib>

#include <iostream>
#include "Data.h"

#include <string>
#include <iostream>
using namespace std;
//Our header of class Carreta

/**
* This method works to set values and initialize the simulation
**/
class Rama {
    public:
    void opcion(int opcion);    

    private:
    Data* data=new Data();
    void deployAssignatures();
    void initialize();
    int generateRandomNumber(int parametro);
};

#endif