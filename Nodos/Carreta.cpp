#include <cstdlib>
#include "../Nodos/Carreta.h"

//Our definition class of Carreta
Carreta::Carreta(int id){
    this->siguiente = nullptr;
    this->id = id;
}