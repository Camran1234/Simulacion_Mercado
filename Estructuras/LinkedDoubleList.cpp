#include <iostream>
#include <cstdlib>
#include <ctime>
#include <sstream>
#include "LinkedDoubleList.h"




LinkedDoubleList::LinkedDoubleList(){
    this->inicio=nullptr;
}

void LinkedDoubleList::add(Caja* caja){
    Caja* aux = this->inicio;
    if(aux==NULL){
        this->inicio = caja;
    }else{
        this->inicio->anterior = caja;
        caja->siguiente = this->inicio;
        this->inicio = caja;
    }
    cout<<"Se agrego la caja: "<<caja->id<<", con tiempo de servicio: "<<caja->tiempo<<endl;
}

/**
* Agrega un nuevo cliente a las cajas
**/
bool LinkedDoubleList::addCliente(Cliente* cliente){
    Caja* aux = this->inicio;
    Cliente* clienteAux = cliente;
    bool flagReturn =false;
    while(aux!=NULL){
        //Avanzamos un paso ingresa un cliente o avanza de turno
        if(aux->setClient(clienteAux) && clienteAux!=NULL){
            cout<<"El Cliente: "<<cliente->idCliente<<" pasa a pagar a la Caja: "<<aux->id<<endl;
            clienteAux=NULL;
            bool flagReturn =true;
            aux = aux->siguiente;
        }else{
            aux->passTurn();
            aux = aux->siguiente;
        }
    }
    if(flagReturn==false){
        cout<<"Avanzando Turno"<<endl;
        if(clienteAux==NULL){
            cout<<"Las cajas avanzan de turno\n";
        }else{
            cout<<"Todas las cajas estan ocupadas"<<endl;
        }
    }
        
    return flagReturn;
}

/**
* Metodo que comprueba si termino su turno el de la caja 
* y le agrega la carreta a las pilas
**/
void LinkedDoubleList::returnCarretas(Pila* pilaCarreta1, Pila* pilaCarreta2){
    Caja* aux = this->inicio;
    Pila* pilaCarretas1 = pilaCarreta1;
    Pila* pilaCarretas2 = pilaCarreta2;
    Cliente* clienteUltimo;
    Carreta* carretaCliente;
    int numeroAleatorio=0;
    while(aux!=NULL){
        numeroAleatorio = this->generateRandomNumber(2);
        //Comparamos las cajas que ya esten disponibles yel cliente que atienden no sea nulo
        if(aux->disponible && aux->cliente!=NULL){
            //Obtenemos el cliente y limpiamos la caja
            clienteUltimo = aux->cliente;
            aux->cliente=nullptr;
            carretaCliente = clienteUltimo->carreta;
            //Liberamos la memoria del cliente
            delete(clienteUltimo);
            //Agregamos la carreta a la pila
            if(numeroAleatorio==1){ 
                cout<<"Agregando a la pila 1\n";
                pilaCarretas1->pushOld(carretaCliente);
            }else{
                cout<<"Agregando a la pila 2\n";
                pilaCarretas2->pushOld(carretaCliente);
            }
        }
        //Avanzamos de caja
        aux = aux->siguiente;
    }
}

int LinkedDoubleList::generateRandomNumber(int parametro){
    srand((unsigned) time(0));
    int numero = 1+(rand() % parametro);
    return numero;
}

Caja* LinkedDoubleList::pop(){
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

string LinkedDoubleList::print(){
    std::ostringstream graph;
    graph<<"subgraph cluster_2 {\n";
    graph << "style=filled;\n";
	graph <<  "color=lightgrey;\n";
	graph <<  "node [style=filled,color=white];\n";
    graph <<  "label=\"Lista Cajas\"\n";           
    graph << this->getLabels();
    int contadora=0;

    if(this->inicio==NULL){
        cout<<"No hay cajas para imprimir en la lista doble enlazada"<<endl;        
    }else{
        Caja* aux = this->inicio;
        while(aux!=NULL){
            if(aux->siguiente==NULL){
                graph << "d"<<contadora << ";\n";
            }else{
                graph << "d"<<contadora<< " -> ";
            }
            /*cout<<"Caja No: "<<aux->id<<", Tiempo de Servicio: "<<aux->tiempoServicio<<", Estado: ";
            if(aux->disponible){
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
            cout<<endl;*/
            aux = aux->siguiente;
            contadora++;
        }
        contadora--;
        aux = this->inicio;
        while(aux!=NULL){
            if(aux->siguiente==NULL){
                graph << "d"<<contadora << ";\n";
            }else{
                graph << "d"<<contadora<< " -> ";
            }
            aux = aux->siguiente;
            contadora--;
        }
    }
    graph << "\n}";
    return graph.str();
}



string LinkedDoubleList::getLabels(){
    int contadora=0;
    std::ostringstream code;
    code<<"";
    if(this->inicio==NULL){
        cout<<"No hay cajas para imprimir en la lista doble enlazada"<<endl;        
    }else{
        Caja* aux = this->inicio;
        while(aux!=NULL){
            code << "d"<<contadora<<" [label=\"Caja: "<<aux->id<<" \n Turnos:"<<aux->tiempo<<" Disponible: "<<aux->disponible<<" \" ];\n";
            aux = aux->siguiente;
            contadora++;
        }
    }
    return code.str();
}

int LinkedDoubleList::size(){
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

