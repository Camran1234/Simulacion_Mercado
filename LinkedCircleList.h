#include <cstdlib>

class LinkedCircleList{
    public:
    LinkedCircleList();
    void add(Cliente* cliente);
    Cliente* pop(int id);
    void print();
    bool isEmpty();
    int size(); 
    private:
    Cliente* inicio;
    Cliente* ultimo;
};