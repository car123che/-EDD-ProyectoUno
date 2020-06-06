#ifndef DOUBLE_CIRCULAR_LIST_H
#define DOUBLE_CIRCULAR_LIST_H
#include "Nodo.h"
#include <iostream>

template <class TYPE> class Double_Circular_List
{
    public:
        Nodo<TYPE>* head;
        Nodo<TYPE>* last;

        Double_Circular_List(){
            head = 0;
            last = 0;
        }

        void insertTop(TYPE data, int num);
        void show();
        /*template <class TYPE>void insertBottom(TYPE data, int num);
        template <class TYPE>void insertMiddle(TYPE data, int num);
        template <class TYPE>Nodo* searchNode(TYPE data);
        template <class TYPE>Nodo* deleteNode(TYPE data);*/
};



template <class TYPE>
void Double_Circular_List<TYPE>::insertTop(TYPE data, int num){
    Nodo<TYPE> *newNode;
    newNode = new Nodo<TYPE>(data, num);
    if(head==0){
        newNode->next=newNode;
        newNode->before=newNode;
        last = newNode;
    }else{
        newNode->next=head;
        newNode->before=last;
        last->next=newNode;
        head->before=newNode;
    }
    head = newNode;
}

template <class TYPE>
void Double_Circular_List<TYPE>::show(){
    Nodo<TYPE> *aux = head->next; // Aqui hay un error tambien estaba como head.next
    do{
        std::cout << aux->data<< "->";
        aux = aux->next;          //aqui habia otro error estaba como aux.next
    }while(aux!=head);
}











#endif // DOUBLE_CIRCULAR_LIST_H
