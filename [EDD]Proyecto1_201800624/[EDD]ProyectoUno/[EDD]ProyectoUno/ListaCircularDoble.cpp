#include "pch.h"
#include "ListaCircularDoble.h"
#include <iostream>
#include "Nodo_LCD.h"
#include "Transaccion.h"
#include <string>
#include <string.h>
#include <fstream>
#include <stdlib.h>
using namespace std;

void ListaCircularDoble::ingresar(Transaccion* transaccion)
{
	Nodo_LCD* nuevo = new Nodo_LCD(transaccion);

	if (estaVacia())
	{
		primero = nuevo;
		primero->siguiente = primero;
		primero->anterior = primero;
		tam++;
	}
	else
	{
		Nodo_LCD* aux = primero;
		while (aux->siguiente != primero)
		{
			aux = aux->siguiente;
		}
		aux->siguiente = nuevo;
		nuevo->siguiente = primero;
		nuevo->anterior = aux;
		aux = nuevo;
		primero->anterior = aux;
		tam++;
	}
}

bool ListaCircularDoble::estaVacia()
{
	return primero == 0;
}

void ListaCircularDoble::imprimir()
{
	Nodo_LCD* actual = primero;
	if (!estaVacia())
	{
		do
		{
			std::cout << actual->transaccion->IDActivo;
			actual = actual->siguiente;
		} while (actual != primero);
	}
	else
	{
		std::cout << "\nLISTA VACIA\n"; 
	}
}

void ListaCircularDoble::graficar()
{
	int contador = 0;
	fstream archivo;
	archivo.open("../Reportes/ReporteTransacciones.dot", ios::out);
	archivo << "digraph ReporteTransaccion{rankdir=LR\n";
	Nodo_LCD* actual = primero;
	if (!estaVacia())
	{
		do
		{
			archivo << "X" << to_string(contador) << "[shape=record label=\"" <<
				actual->transaccion->IDTransaccion<<"_"<<
				actual->transaccion->fecha<< "|{" << actual->transaccion->usuario
				<< "|" << actual->transaccion->departmaneto << "|" << actual->transaccion->empresa
				<< "}|" << actual->transaccion->IDActivo <<"_"<<actual->transaccion->tiempo<<
				"\"];\n";
			actual = actual->siguiente;
			contador++;
		} while (actual != primero);
		contador -= 1;
		for (int i = 0; i<=contador; i++)
		{
			if (i + 1 <=contador)
			{

				archivo << "X" << to_string(i) << "->" << "X" << to_string(i + 1) << ";\n";
				archivo << "X" << to_string(i + 1) << "->" << "X" << to_string(i) << ";\n";
			}
			if (i == contador)
			{
				archivo << "X" << to_string(contador) << "->" << "X0;\n";
				archivo << "X0" << "->" << "X" << to_string(contador) << ";\n";
			}
				
		}

		archivo << "}";
		archivo.close();
		system("dot.exe  -Tpng ../Reportes/ReporteTransacciones.dot -o ../Reportes/ReporteTransacciones.png");
		system("start ../Reportes/ReporteTransacciones.png");
	}
	else
	{
		cout << "\n!!!!!!NO SE HAN REALIZADO TRANSACCIONES!!!!!!\n";
	}
}

void ListaCircularDoble::ordenarAscendente()
{
	Nodo_LCD* aux = primero;
	Nodo_LCD* aux2=primero;
	char uno[16];
	char dos[16];
	Nodo_LCD* temp;
	do
	{
		do {
			if (aux2->siguiente != primero)
			{
				strcpy_s(uno, aux2->transaccion->IDTransaccion.c_str());
				strcpy_s(dos, aux2->siguiente->transaccion->IDTransaccion.c_str());
				if (strcmp(uno, dos))
				{
					temp = aux2;
					aux2 = aux2->siguiente;
					aux2->siguiente = temp;
				}
				aux2 = aux2->siguiente;
			}
		} while (aux2 != primero);
		aux = aux->siguiente;
	} while (aux != primero);
}

void ListaCircularDoble::ordenarDescendente()
{

}