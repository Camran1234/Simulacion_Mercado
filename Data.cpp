#include <cstdlib>
#include <iostream>
#include <ctime>
#include "Data.h"

using namespace std;

Data::Data(){
    //Our data structure
    this->pilaCarreta1= new Pila();
    this->pilaCarreta2= new Pila();
    this->listaCompras= new LinkedCircleList();
    this->colaPagos = new Cola();
    this->listaCajas = new LinkedDoubleList();

    //Our data initializer
    this->noCarretas = 0;
    this->noCajas = 0;
    this->noClientes=0;
}

//Setters
void Data::setCarretas(int carretas){
    this->noCarretas = carretas;
}

//Setters
void Data::setCajas(int cajas){
    this->noCajas = cajas;
}

//Setters
void Data::setClientes(int clientes){
    this->noClientes = clientes;
}

/**
* Method that try to generate the data structure of the simulation
* returns false if the parameters of the simulation hasn't been initialize, and it will not add nothing to the data structures
*  returns true if the parameters has benn specified and it will generate the values of the data structures
**/
bool Data::stablishData(){
    try{
        if(this->noCarretas==0 || this->noCajas==0 || this->noClientes==0){
            return false;
        }else{
            cout<<"Generando Recursos: "<<endl;
            //To generate aleatory numbers
            srand((unsigned) time(0));
            //Adding the carretas to the piles
            int numero=0;
            cout<<"Generando Carretas: "<<endl;
            for(int indexCarreta=0; indexCarreta<this->noCarretas; indexCarreta++){
                numero = 1 + (rand() % 2);
                this->addCarreta(numero, indexCarreta);
            }
            //Adding the Cajas to the Linked double List
            Caja* caja;
            cout<<"Generando Cajas: "<<endl;
            for(int indexCaja=0; indexCaja<this->noCajas; indexCaja++){
                numero = 1 + (rand() % 4);
                caja = new Caja(indexCaja+1, numero);
                this->listaCajas->add(caja);
            }        
        }
        return true;
    }catch(...){
        cout<<"Error generando los valores iniciales"<<endl;
        return false;
    }
    
}

void Data::addCarreta(int numero, int indexCarreta){
    if(numero==1){
        cout<<"Se agrego a la Pila Carreta 1: \n";
        this->pilaCarreta1->push(indexCarreta+1);
    }else{
        cout<<"Se agrego a la Pila Carreta 2: \n";
        this->pilaCarreta2->push(indexCarreta+1);
    }
}

//Check if all the parameters of the simulation has been initialized
bool Data::noElements(){
    if(this->noCarretas==0 || this->noClientes==0 || this->noCajas==0){
        return true;
    }else{
        return false;
    }
}


