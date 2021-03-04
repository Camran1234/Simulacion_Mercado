#include <cstdlib>
#include <iostream>
#include <sstream>
#include "../Estructuras/Cola.h"


Cola::Cola(){
    this->inicio = nullptr;
}

bool Cola::isEmpty(){
    if(this->inicio==NULL){
        return true;
    }else{
        return false;
    }
}

void Cola::add(Cliente* cliente){
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

Cliente* Cola::pop(){
    if(this->inicio==NULL){
        cout<<"No se pudo retirar el cliente, no hay clientes en la cola"<<endl;        
        return NULL;
    }else{  
        Cliente* aux = this->inicio;
        this->inicio = this->inicio->siguiente;
        return aux;
    }
}

string Cola::print(){
    std::ostringstream graph;
    graph<<"subgraph cluster_0 {\n";
    graph<< "style=filled;\n";
	graph<<  "color=lightgrey;\n";
	graph<<  "node [style=filled,color=white];\n";
    graph<<  "label=\"Cola Espera\"\n";      
    graph<< this->getLabels();
    if(this->inicio==NULL){
        //cout<<"No hay elementos clientes en la cola para imprimir"<<endl;
    }else{
        Cliente* aux = this->inicio;
        int contadora=0;
        while(true){
            //cout<<"Cliente: "<<aux->idCliente<<", Carreta: "<<aux->carreta->id<<endl;
            if(aux->siguiente==NULL){
                //End the command
                graph << "c"<<contadora<<" ;\n";
            }else{
                //Sent the command
                graph << "c"<<contadora<<" -> ";
            }
            
            contadora++;
            aux = aux->siguiente;
        }
        
    }
    graph << "\n}";

    return graph.str();
}

string Cola::getLabels(){
    std::ostringstream code;
    code<<"";
    if(this->inicio!=NULL){
        Cliente* aux = this->inicio;
        int contadora=0;
        while(aux!=NULL){
            code << "c"<<contadora<<" [label=\"Cliente: "<<aux->idCliente<<" \n Carreta:"<<aux->carreta<<"\" ];\n";
            contadora++;
            aux=aux->siguiente;
        }
    }
    return code.str();
}

int Cola::size(){
    int elementos=0;
    if(this->inicio==NULL){
        return 0;
    }else{
        Cliente* aux = this->inicio;
        while(true){
            elementos++;
            if(aux->siguiente!=NULL){
                aux = aux->siguiente;
            }else if(aux->siguiente==NULL){
                break;
            }
        }
        
    }
    return elementos;
}

