#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <sstream>
#include <cstring>
#include "Rama.h"




void Rama::opcion(int opcion){
    if(opcion==1){
        this->deployAssignatures();
    }else if(opcion==2){
        if(this->data->noElements()==false){
            bool flag = this->data->stablishData();
            this->initialize();
        }else{
            cout<<"Debes establecer todos los parametros\n";
            cout<<"Falta por agregar: \n";
            if(this->data->noCajas<=0){
                cout<<"Existencia de Cajas Nula\n";
            }
            if(this->data->noClientes<=0){
                cout<<"Existencia de Clientes Nula\n";
            }
            if(this->data->noCarretas<=0){
                cout<<"Existencia de Carretas Nula\n";
            }
        }
    }
}

void Rama::deployAssignatures(){
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
                return;
                    break;
                default:
                cout<<"Opcion no reconocida"<<endl;
                    break;
            }
        }catch(...){
            cout<<"Formatos Invalidos"<<endl;
        }
    }
}

int Rama::generateRandomNumber(int parametro){
    srand((unsigned) time(0));
    int numero = (rand() % parametro);
    return numero;
}

/**
* Our method for initialize and work the simulation
**/
void Rama::initialize(){
    Data* dataGeneral = this->data;
    int clientesLeft = dataGeneral->noClientes;
    int opcion=0;
    bool flag=true;
    int paso=0;
    int valor;
    Cliente* clientePila;
    Carreta* carreta;
    Cliente* clienteCompra;
    Cliente* clientePagos;
    cout<<"EMPEZANDO SIMULACION...."<<endl;
    try{
        while(flag){

                cout<<"1.- Avanzar un Paso"<<endl;
                cout<<"2.- Terminar Simulacion"<<endl;
                cout<<"3.- Generar Imagen"<<endl;
                cin>>opcion;

                switch(opcion){
                    case 1:
                    {
                        paso++;
                        cout<<"Generando Paso "<<paso<<endl;
                        carreta=NULL;
                        clientePila=NULL;
                        clienteCompra=NULL;
                        clientePagos=NULL;
                        if(clientesLeft!=0){
                            cout<<"********"<<"Ingresando Cliente: "<<clientesLeft<<" al mercado"<<"********"<<endl;
                            //Codigo para introducir a la pila el cliente
                            valor = this->generateRandomNumber(2)+1;
                            if(valor==1){
                                if(dataGeneral->pilaCarreta1->isEmpty()==false){
                                    cout<<"Entro a Pila 1\n";
                                    carreta = dataGeneral->pilaCarreta1->pop();
                                }if(carreta==NULL){
                                    cout<<"Entro a Pila 2\n";
                                    carreta = dataGeneral->pilaCarreta2->pop();
                                }
                            }else{
                                if(dataGeneral->pilaCarreta2->isEmpty()==false){
                                    cout<<"Entro a Pila 2\n";
                                    carreta = dataGeneral->pilaCarreta2->pop();
                                }if(carreta==NULL){
                                    cout<<"Entro a Pila 1\n";
                                    carreta = dataGeneral->pilaCarreta1->pop();
                                }
                            }
                            clientePila = new Cliente( (dataGeneral->noClientes - clientesLeft)+1);
                            //Siempre introduce un cliente, siempre que hallan carretas
                            if(carreta!=NULL){
                                clientesLeft--;
                                //Debe tomar una carreta
                                clientePila->carreta = carreta;
                                //Si hay carretas introduce el cliente a la lista de compras con la carreta
                                dataGeneral->listaCompras->add(clientePila);
                            }
                            cout<<"********"<<"Termino Avance Cliente en Carretas"<<"********"<<endl;
                        }else{
                            cout<<"     Ya no quedan mas clientes\n";
                            /*cout<<"********"<<"Compradores"<<"********\n";
                            dataGeneral->listaCompras->print();*/
                        }

                        cout<<"********"<<"Generando Compras"<<"********"<<endl;
                        //Codigo para introducir las compras
                        if(dataGeneral->listaCompras->isEmpty()==false){
                            //Generar un numero aleatorio entre 0 a 100 
                            valor = this->generateRandomNumber(101);
                            //Comprobar si coincide el numero aleatorio con el id
                            cout<<"     Se genero el numero aleatorio: "<<valor<<endl;
                             clienteCompra = dataGeneral->listaCompras->pop(valor);
                            //Si es el mismo numero con el id cliente entonces se sale de las lista compra e ingresa a la cola de pagos
                            if(clienteCompra!=NULL){
                                cout<<"     Coincidio con el cliente: "<<clienteCompra->idCliente<<endl;
                                cout<<"     Agregando al cliente: " << clienteCompra->idCliente<<endl;
                                dataGeneral->colaPagos->add(clienteCompra);
                            }else{
                                cout<<"     No coincide ningun cliente"<<endl;
                            }
                        }
                        cout<<"********"<<"Termino Avance en Compras"<<"********"<<endl;

                        cout<<"********"<<"Generando Cola de Espera"<<"********"<<endl;
                        //Codigo para ingresar las Colas de esperas
                             clientePagos = dataGeneral->colaPagos->pop();
                            //Comprobar si hay clientes en la cola de espera, si no hay no hace nada
                            //Si hay clientes corroborar que caja esta disponible, si hay asignar a el cliente a la caja mas cercana y lo retira de la cola de espera
                            dataGeneral->listaCajas->addCliente(clientePagos);
                        cout<<"********"<<"Terminando Avance de la Cola de Espera"<<"********"<<endl;

                        cout<<"********"<<"Generando Pago en Caja"<<"********"<<endl;
                        //Codigo para generar pago en cajas
                        //Comprobar si hay clientes en alguna caja
                        //Intentar pasar turno, no dejara si aun estan los turnos disponibles
                        //Al retirar un cliente, se retorna la carreta a la pila de cajas
                        dataGeneral->listaCajas->returnCarretas(dataGeneral->pilaCarreta1, dataGeneral->pilaCarreta2);
                    }
                    break;

                    case 2:
                    {
                        flag=false;
                    }
                    break;
                    case 3:
                    {
                        //Code to generate a graphviz image
                         // Create a text file
                         //Create the output stream
                        ofstream MyWriteFile("graph.txt");
                        MyWriteFile << "digraph g { \n ";
                        MyWriteFile << dataGeneral->colaPagos->print();
                        MyWriteFile << dataGeneral->pilaCarreta1->print(1);
                        MyWriteFile << dataGeneral->pilaCarreta2->print(2);
                        MyWriteFile << dataGeneral->listaCompras->print();
                        MyWriteFile << dataGeneral->listaCajas->print();
                        MyWriteFile<<"}";
                        // Close the file
                        MyWriteFile.close();
                        std::ostringstream code;
                        code<<"dot -Tpng graph.txt -o Imagenes_Generadas/ImagenPaso"<<paso<<".jpg";
                        string commandString = code.str();
                        const char* command  = commandString.c_str();
                        system(command);
                    }
                    break;
                    default:{
                        cout<<"Opcion no reconocida"<<endl;
                    }
                }

        }
    }catch(...){
        cout<<"Formato Incorrecto, vuelva a intentar"<<endl;
    }
}

