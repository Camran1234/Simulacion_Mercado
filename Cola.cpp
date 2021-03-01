#include <cstdlib>
#include <iostream>
#include "Cola.h"

Cola::Cola(){
    this->inicio = nullptr;
}

void add(Cliente* cliente){
    if(this->inicio==NULL){
        cliente->siguiente = this->inicio;
        this->inicio = cliente;
    }else{
        Cliente* aux = this->inicio;
        while(true){
            if(aux->siguiente!=NULL){
                aux = aux->siguiente;
            }else if(aux->siguiente==NULL){
                aux->siguiente = cliente;
                break;
            }
        }
    }
}

Cliente* pop(){
    if(this->inicio==NULL){
        cout<<"No se pudo retirar el cliente, no hay clientes en la cola"<<endl;        
        return NULL;
    }else{  
        Cliente* aux = this->inicio;
        this->inicio = this->inicio->siguiente;
        return aux;
    }
}

void print(){
    if(this->inicio==NULL){
        cout<<"No hay elementos clientes en la cola para imprimir"<<endl;        
    }else{
        Cliente* aux = this->inicio;
        while(true){
            cout<<"Cliente: "<<aux->idCliente<<", Carreta: "<<carreta->id<<endl;
            if(aux->siguiente!=NULL){
                aux = aux->siguiente;
            }else if(aux->siguiente==NULL{
                cout<<"Fin Cola"<<endl;
                break;
            }
        }
        
    }
}

int size(){
    int elementos=0;
    if(this->inicio==NULL){
        return 0;
    }else{
        Cliente* aux = this->inicio;
        while(true){
            elementos++;
            if(aux->siguiente!=NULL){
                aux = aux->siguiente;
            }else if(aux->siguiente==NULL{
                break;
            }
        }
        
    }
    return elementos;
}