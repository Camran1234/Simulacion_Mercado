#include <iostream>
#include <cstdlib>
#include "../Nodos/Caja.h"


Caja::Caja(int id, int tiempoServicio){
    this->id = id;
    this->tiempo=tiempoServicio;
    this->cliente = NULL;
    this->disponible = true;
    this->siguiente = nullptr;
    this->anterior = nullptr;
}

/**
* Returns true if the Client sucesfully enter the Caja Object, otherwise it will return false and pass 1 turn
**/
bool Caja::setClient(Cliente* cliente){
    if(this->disponible && cliente!=NULL){
        std::cout<<"Ingreso a Caja\n";
        this->disponible=false;
        this->tiempoServicio = tiempo;
        this->cliente = cliente;
        return true;
    }
    return false;
}

void Caja::passTurn(){
    if(this->cliente!=NULL){        
        tiempoServicio--;
        if(tiempoServicio==0){
            this->disponible=true;
        }
    }        
}
