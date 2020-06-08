#include "pch.h"
/*
#include "ListaSimpleT.h"
#include "NodoT.h"
#include <iostream>

template<class TYPE>
void ListaSimpleT<TYPE>::insertarLast(TYPE data, int num)
{
	NodoT<TYPE> *newNode;
	newNode = new Nodo<TYPE>(data, num);
	if (head == 0)
	{
		head = newNode;
		newNode->next = 0;
		last = newNode;
	}
	else {
		head->next = newNode;
		newNode->next = 0;
		last = newNode;
	}
}

template<class TYPE>
void ListaSimpleT<TYPE>::show()
{
	NodoT<TYPE> *aux = head;
	while (aux != 0)
	{
		std::cout << aux->data << "->";
		aux = aux->next;
	}
}
*/