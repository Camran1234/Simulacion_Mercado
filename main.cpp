#include <cstdlib>
#include <iostream>
#include <string>
#include <iostream>
#include "Rama.h"

using namespace std;
typedef Rama Menu;

int main(){
    int opcion=0;
    Menu rama;
    while(true){
        cout<<"☆☆BIENVENIDO A LA SIMULACION DE MERCADOS☆☆"<<endl;
        cout<<"1.- Establecer Parametros❆❆"<<endl;
        cout<<"2.- Iniciar Simulacion❆❆"<<endl;
        cout<<"3.- Salir❆❆"<<endl;
        
        try{
            cin>>opcion;
            switch(opcion){
                case 1:
                    rama.opcion(1);
                break;
                case 2:
                    rama.opcion(2);
                break;
                case 3:
                    cout<<"ADIOS, FIN SIMULACION";
                    return 0;
                break;
                default:
                cout<<"OPCION INVALIDA, SOLO INGRESAR NUMEROS";
            }
        }catch(...){
            cout<<"Formato Invalido"<<endl;
        }
    }
    return 0;
}