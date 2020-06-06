#ifndef NODO_H
#define NODO_H
#include<iostream>

template <class TYPE>
class Nodo
{
    public:
        Nodo<TYPE>* next;
        Nodo<TYPE>* before;
        TYPE data;
        int num;

        Nodo(TYPE dataa, int numm){
            next = 0;
            before = 0;
            data = dataa;
            num = numm;
        }
};

#endif // NODO_H
