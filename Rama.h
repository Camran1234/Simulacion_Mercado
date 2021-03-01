#include <cstdlib>
#include "Data.h"
//Our header of class Carreta

/**
* This method works to set values and initialize the simulation
**/
class Rama {
    public:
    void opcion(int opcion);    

    private:
    Data data;
    void deployAssignatures();
    void initialize();
    int generateRandomNumber(int parametro);
};