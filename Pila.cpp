#include <cstdlib>
#include <iostream>
#include "Pila.h"

using namespace std;

Pila::Pila(){
    this->inicio = nullptr;
}

/** Method to add a new element Carreta to the pile
*
*
**/
void Pila::push(int id){
    Carreta* carreta = new Carreta(id);
    carreta->anterior = this->inicio;
    this->inicio = carreta;
    //Posibles cambios
    cout<<"Se agrego la carreta: "<<this->inicio->id<<endl;
}

/** Method to generate a pop to the pile, without deleting the top of the pile
 *
 *
 **/
Carreta* Pile::pop(){
    Carreta* aux = this->inicio;
    this->inicio = this->inicio->siguiente;
    //Retornamos el objeto de la primera pila
    //No eliminamos el objeto porque mas tarde ingresara a la pila        
    cout<<"Se retiro la carreta "<<aux->id;
    return aux;
}

/**
* Method to indicate if the pile is null
*
**/
bool isEmpty(){
    if(this->inicio==NULL){
        return true;
    }else{
        return false;
    }
}

/**
* Print the condition of the Pile, Carreta per Carreta
**/
void print(){
    Carreta* aux = this->inicio;
    while(true){
      if(aux!=NULL){
        cout<<"Carreta ID: "<<aux->id<<endl;
        aux = aux->siguiente;
      }else{
        break;
      }
    }
}

int size(){
    int size=0;
    Node * aux = this->inicio;
    while(true){
        if(aux!=NULL){
          size++;
        aux = aux->siguiente;
        }else{
            break;
        }
    }
    return size;
}