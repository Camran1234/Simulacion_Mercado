#include <iostream>
#include <cstdlib>
#include "LinkedDoubleList.h"

LinkedDoubleList::LinkedDoubleList(){
    this->inicio=nullptr;
}

void add(Caja* caja){
    if(this->inicio==NULL){
        this->inicio = caja;
    }else{
        this->inicio->anterior = caja;
        caja->siguiente = this->inicio;
        this->inicio = caja;
    }
}

Caja* pop(){
    if(this->inicio==NULL){
        cout<<"No hay cajas en la lista doble enlazada"<<endl;
        return NULL;
    }else{
        Caja* aux = this->inicio;
        this->inicio = aux->siguiente;
        this->inicio->anterior = nullptr;
        aux->siguiente = nullptr;
        aux->anterior = nullptr;
        return aux;
    }
}

void print(){
    if(this->inicio==NULL){
        cout<<"No hay cajas para imprimir en la lista doble enlazada"<<endl;        
    }else{
        Caja* aux = this->inicio;
        while(aux!=NULL){
            cout<<"Caja No: "<<aux->id<<", Tiempo de Servicio: "<<aux->tiempoServicio<<", Estado: ";
            if(aux->estado){
                cout<<"Libre ";
            }else{
                cout<<"Ocupado ";
            }
            cout<<", Cliente: ";
            if(aux->cliente==NULL){
               cout<<" Ninguno"<<", Carreta: Ninguna";
            }else{
                cout<<aux->cliente->idCliente<<", Carreta: "<<aux->cliente->carreta->id;
            }
            cout<<endl;
            aux = aux->siguiente;
        }
    }
}

int size(){
    int contadora=0;
    if(this->inicio!=NULL){
        Caja* aux = this->inicio;
        while(aux!=NULL){
            contadora++;
            aux = aux->siguiente;
        }
    }
    return contadora;
}

