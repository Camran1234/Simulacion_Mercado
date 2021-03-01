#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Rama.h"

using namespace std;


void opcion(int opcion){
    if(opcion==1){
        this->deployAssignatures();
    }else if(opcion==2){
        bool flag = this->data->stablishData();

        this->initialize();
    }
}

void deployAssignatures(){
    int option=0;
    int valores=0;

    while(true){
        try{
            cout<<"ASIGNACION DE PARAMETROS"<<endl;
            cout<<"1.- Establecer Clientes"<<endl;
            cout<<"2.- Establecer Carretas"<<endl;
            cout<<"3.- Establecer Cajas"<<endl;
            cout<<"4.- Regresar Menu"<<endl;
            cin>>option;
            switch(option){
                case 1:
                    cout<<endl<<"Clientes de la simulacion: ";
                    cin>>valores;
                    this->data->setClientes(valores);
                break;
                case 2:
                    cout<<endl<<"Carretas en la simulacion: ";
                    cin>>valores;
                    this->data->setCarretas(valores);
                break;
                case 3:
                    cout<<endl<<"Cajas en la simulacion: ";
                    cin>>valores;
                    this->data->setCajas(valores);
                break;
                case 4:
                //NOTHING, bc it returns to the main cpp
                    break;
                default:
            }
        }catch(...){
            cout<<"Formatos Invalidos"<<endl;
        }
    }

}

int generateRandomNumber(int parametro){
    srand((unsigned) time(0));
    int numero = 1 + (rand() % parametro);
    return numero;
}

/**
* Our method for initialize and work the simulation
**/
void initialize(){
    Data dataGeneral = this->data;
    int clientesLeft = dataGeneral->noClientes;
    int opcion=0;
    bool flag=true;
    int paso=0;
    int valor;
    while(flag){
        try{
            cout<<"EMPEZANDO SIMULACIN...."<<endl;
            cout<<"1.- Avanzar un Paso"<<endl;
            cout<<"2.- Terminar Simulacion"<<endl;
            cout<<"3.- Generar Imagen"<<endl;
            cin>>opcion;

            switch(opcion){
                case 1:
                    paso++;
                    cout<<"Generando Paso "<<paso;
                    cout<<"Ingresando Cliente al mercado";
                    //Codigo para introducir a la pila el cliente
                    valor = this->generateRandomNumber(2);
                    Carreta* carreta;
                    if(valor==1){
                        if(dataGeneral->pilaCarreta1->isEmpty()){
                            carreta = dataGeneral->pilaCarreta2->pop();
                        }else{
                            carreta = dataGeneral->pilaCarreta1->pop();
                        }
                    }else{
                        if(dataGeneral->pilaCarreta1->isEmpty()){
                            carreta = dataGeneral->pilaCarreta1->pop();
                        }else{
                            carreta = dataGeneral->pilaCarreta2->pop();
                        }
                    }
                    Cliente* cliente = new Cliente( (dataGeneral->noCliente - clientesLeft)+1);
                    //Siempre introduce un cliente, siempre que hallan carretas
                    if(carreta!=NULL){
                        clientesLeft--;
                        //Debe tomar una carreta
                        cliente->carreta = carreta;
                        //Si hay carretas introduce el cliente a la lista de compras con la carreta
                        listaCompras->add(cliente);
                    }
                    cout<<"Termino Avance Cliente en Carretas"

                    cout<<"Generando Compras";
                    //Codigo para introducir las compras
                    //Generar un numero aleatorio entre 0 a 100 
                    //Comprobar si coincide el numero aleatorio con el id
                    //Si es el mismo numero con el id cliente entonces se sale de las lista compra e ingresa a la cola de pagos
                    cout<<"Termino Avance en Compras"

                    cout<<"Generando Cola de Espera";
                    //Codigo para ingresar las Colas de esperas
                    //Comprobar si hay clientes en la cola de espera, si no hay no hace nada
                    //Si hay clientes corroborar que caja esta disponible, si hay asignar a el cliente a la caja mas cercana y lo retira de la cola de espera
                    cout<<"Terminando Avance de la Cola de Espera"

                    cout<<"Generando Pago en Caja";
                    //Codigo para generar pago en cajas
                    //Comprobar si hay clientes en alguna caja
                    //Intentar pasar turno, no dejara si aun estan los turnos disponibles
                    //Al retirar un cliente, se retorna la carreta a la pila de cajas
                    cout<<'Termino Pago en Cajas'

                break;
                case 2:
                    flag=false;
                break;
                case 3:
                    //Code to generate a graphviz image
                break;
                default:
                
            }

        }catch(...){
            cout<<"Formato Incorrecto, vuelva a intentar"<<endl;
        }
    }
}
