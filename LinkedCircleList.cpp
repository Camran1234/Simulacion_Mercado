#include <cstdlib>
#include <iostream>
#include "LinkedCircleList.h"
LinkedCircleList::LinkedCircleList(){
    this->inicio=nullptr;
    this->ultimo=nullptr;
}

void add(Cliente* cliente){
    if(this->inicio==NULL && this->ultimo==NULL)    {
        cliente->siguiente = cliente;
        this->ultimo = cliente;
        this->inicio = cliente;
    }else{
        cliente->siguiente = this->inicio;
        this->inicio = cliente;
        this->ultimo->siguiente = cliente;
    }
    cout<<"Se agrego a la lista de Compras el cliente: "<<cliente->idCliente<<", Carreta: "<< cliente->carreta->id;
}

bool isEmpty(){
    if(this->inicio==NULL && this->ultimo==NULL){
        return true;
    }else{
        return false;
    }
}

Cliente* pop(int id){
    int large = this->size();
    Cliente* aux= this->inicio;
    for(int i=0; i<large; i++){
        if(aux->idCliente==id){
            return aux;
        }else{
            aux=aux->siguiente;
        }
    }
    return NULL;
}

void print(){
    int large = this->size();
    Cliente* aux =this->inicio;
    for(int i=0; i<large; i++){
        cout<<i+1<<".- Cliente: "<<aux->idCliente<<", Carreta: "<<aux->carreta<<endl;
        aux=aux->siguiente;
    }
}

int size(){
    if(this->inicio==NULL && this->ultimo==NULL){
        return 0;
    }else{
        int contadora=0;
        bool flag=false;
        Cliente* aux = this->inicio;
        while(true){
            contadora++;
            if(aux==this->ultimo){
                break;
            }
            aux = aux->siguiente;
        }
    }
    return contadora;
}