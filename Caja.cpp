#include <iostream>
#include <cstdlib>
#include "Caja.h"

Caja::Caja(int id, int tiempoServicio){
    this->id = id;
    this->tiempo=tiempoServicio;
    this->cliente = nullptr;
    this->disponible = true;
    this->siguiente = nullptr;
    this->anterior = nullptr;
}

/**
* Returns true if the Client sucesfully enter the Caja Object, otherwise it will return false and pass 1 turn
**/
bool setClient(Cliente* cliente){
    if(this->disponible){
        this->disponible=false;
        this->tiempoServicio = tiempo;
        this->cliente = cliente;
    }else{
        tiempoServicio--;
        if(tiempoServicio==0){
            this->disponible=true;
            this->cliente = nullptr;
            
        }
    }
}