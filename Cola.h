#include <cstdlib>
#include "Cliente.h"

class Cola {
    public:
    Cola();
    void add(Cliente* cliente);
    Cliente* pop();
    void print();
    int size(); 
    private:
    Cliente* inicio;
};