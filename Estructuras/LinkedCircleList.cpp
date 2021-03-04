#include <cstdlib>
#include <iostream>
#include <sstream>
#include "../Estructuras/LinkedCircleList.h"


LinkedCircleList::LinkedCircleList(){
    this->inicio=nullptr;
    this->ultimo=nullptr;
}

void LinkedCircleList::add(Cliente* cliente){
    if(this->inicio==NULL && this->ultimo==NULL)    {
        cliente->siguiente = cliente;
        this->ultimo = cliente;
        this->inicio = cliente;
    }else{
        cliente->siguiente = this->inicio;
        this->inicio = cliente;
        this->ultimo->siguiente = cliente;
    }
    cout<<"     Se agrego a la lista de Compras el cliente: "<<cliente->idCliente<<", Carreta: "<< cliente->carreta->id<<endl;
    cout<<"********"<<"Compradores"<<"********\n";
}

bool LinkedCircleList::isEmpty(){
    if(this->inicio==NULL && this->ultimo==NULL){
        return true;
    }else{
        return false;
    }
}

Cliente* LinkedCircleList::pop(int id){
    int large = this->size();
    Cliente* aux= this->inicio;
    Cliente* anterior = aux;
    int i=0;
    while(true){
        if(i!=0 && aux==inicio){
            break;
        }        
        if(aux->idCliente==id){
            if(aux==this->inicio){
                anterior->siguiente = aux->siguiente;
                this->inicio = aux->siguiente;
            }else if(aux==this->ultimo){
                anterior->siguiente = aux->siguiente;
                this->ultimo = anterior;
            }else{
                anterior->siguiente = aux->siguiente;
            }
            return aux;
        }else{
            anterior = aux;
            aux=aux->siguiente;
        }
        i++;
    }
    return NULL;
}

string LinkedCircleList::print(){
    
    int large = this->size();
    Cliente* aux =this->inicio;
    int i=0;
    std::ostringstream graph;
    graph<<"subgraph cluster_1 {\n";
    graph << "style=filled;\n";
	graph <<  "color=lightgrey;\n";
	graph <<  "node [style=filled,color=white];\n";
    graph <<  "label=\"Lista Circular Compras\"\n";
    graph << this->getLabels();
    if(aux!=NULL){
        while(true){
            if(i!=0 && aux==inicio){
                if(i==1){
                    graph << "l"<<i-1<<" \n";
                }else{
                    graph << " l0;\n";
                }
                
                break;
            }else{
                graph << "l"<<i<<" -> ";
            }
            //cout<<i+1<<".- Cliente: "<<aux->idCliente<<", Carreta: "<<aux->carreta->id<<endl;
            aux=aux->siguiente;
            i++;
        }    
    }
    graph << "\n}";
    return graph.str();
}



string LinkedCircleList::getLabels(){
    std::ostringstream code;
    code <<"";
    int i=0;
    Cliente* aux = this->inicio;
    while(true){
        if(this->inicio!=NULL){
            if(i!=0 && aux==inicio){
                break;
            }
            code << "l"<<i<<" [label=\"Cliente: "<<aux->idCliente<<" \n Carreta:"<<aux->carreta->id<<"\" ];\n";
            aux=aux->siguiente;
            i++;
        }else{
            break;
        }
    }
    return code.str();
}

int LinkedCircleList::size(){
    int contadora=0;
    if(this->inicio==NULL && this->ultimo==NULL){
        return contadora;
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

