#include <iostream>
#include <cstdlib>

class LinkedDoubleList {
    public:
    LinkedDoubleList();
    void add(Caja* caja);
    Caja* pop();
    void print();
    int size();
    private:
    Caja* inicio;
}