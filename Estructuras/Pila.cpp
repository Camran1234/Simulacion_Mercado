#include <cstdlib>
#include <iostream>
#include <sstream>
#include "../Estructuras/Pila.h"



Pila::Pila(){
    this->inicio = nullptr;
}

/** Method to add a new element Carreta to the pile
*
*
**/
void Pila::push(int id){
    Carreta* carreta = new Carreta(id);
    carreta->siguiente = this->inicio;
    this->inicio = carreta;
    //Posibles cambios
    cout<<"Se agrego la carreta: "<<this->inicio->id<<endl;
}

void Pila::pushOld(Carreta* carreta){
    carreta->siguiente = this->inicio;
    this->inicio = carreta;
    //Posibles cambios
    cout<<"Se agrego la carreta: "<<carreta->id<<endl;
}

/** Method to generate a pop to the pile, without deleting the top of the pile
 *
 *
 **/
Carreta* Pila::pop(){
    Carreta* aux = this->inicio;    
    //Retornamos el objeto de la primera pila
    //No eliminamos el objeto porque mas tarde ingresara a la pila  
    if(aux!=NULL){
        this->inicio = this->inicio->siguiente;
        //Son dos pilas
        cout<<"     Se retiro la carreta "<<aux->id<<endl;
    }else{
        cout<<"     Ya no hay mas carretas para retirar"<<endl;
    }      
    
    return aux;
}

/**
* Method to indicate if the pile is null
*
**/
bool Pila::isEmpty(){
    if(this->inicio==NULL){
        return true;
    }else{
        return false;
    }
}

/*Cliente* aux = this->inicio;
        int contadora=0;
        whie(aux!=NULL){
            code += "c"+contadora+" [label=\"Cliente: "+aux->idCliente+" \n Carreta:"+aux->carreta+"\" ];\n";
            contadora++;
            aux=aux->siguiente;
        }*/

/**
* Print the condition of the Pile, Carreta per Carreta
* int posicion
**/
string Pila::print(int posicion){
    Carreta* aux = this->inicio;
    char identificador;
    if(posicion==1){
        identificador = 'r';
    }else{
        identificador = 'm';
    }
    std::ostringstream graph;
     graph<<"subgraph cluster_"<<(posicion+3)<<"  {\n";
    graph << "style=filled;\n";
	graph <<  "color=lightgrey;\n";
	graph <<  "node [style=filled,color=white];\n";
    graph <<  "label=\"Lista Carretas: "<<posicion<<"\"\n";        
    graph << this->getLabels(posicion);
    int i=0;
    if(aux!=NULL){
        while(true){
            if(aux->siguiente!=NULL){
                //cout<<"Carreta ID: "<<aux->id<<endl;
                graph << identificador<<i<<" -> ";
                aux = aux->siguiente;
            }else{
                graph << identificador<<i<< " ;";
                break;
            }
            i++;
        }
    }
    graph << "\n}";
    return graph.str();
}

/*if(this->inicio!=NULL){
        Cliente* aux = this->inicio;
        int contadora=0;
        whie(aux!=NULL){
            code += "c"+contadora+" [label=\"Cliente: "+aux->idCliente+" \n Carreta:"+aux->carreta+"\" ];\n";
            contadora++;
            aux=aux->siguiente;
        }
    }*/

string Pila::getLabels(int posicion){
    char identificador;
    if(posicion==1){
        identificador = 'r';
    }else{
        identificador = 'm';
    }
    std::ostringstream code;
     code <<"";
    int contadora=0;
    Carreta* aux = this->inicio;
    while(true){
      if(aux!=NULL){
        code << identificador<<contadora<<" [label=\"Carreta: "<<aux->id<<"\" ];\n";
        aux = aux->siguiente;
      }else{
        break;
      }
      contadora++;
    }
    return code.str();
}

int Pila::size(){
    int size=0;
    Carreta * aux = this->inicio;
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