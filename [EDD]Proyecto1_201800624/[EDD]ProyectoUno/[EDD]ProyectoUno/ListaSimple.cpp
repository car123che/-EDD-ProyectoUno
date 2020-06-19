#include "pch.h"
#include "ListaSimple.h"
#include <iostream>
#include "Activo.h"
#include <string>
bool ListaSimple::estaVacia()
{
	return inicio == 0;
}
void ListaSimple::agregar(Activo* a)
{
	NodoLS* nuevo = new NodoLS(a);
	nuevo->posicion++;
	if (estaVacia())
	{
		inicio = nuevo;
		contador++;
	}
	else
	{
		NodoLS* aux = inicio;
		nuevo->posicion++;
		while (aux->siguiente != 0)
		{
			nuevo->posicion++;
			aux = aux->siguiente;
		}
		aux->siguiente = nuevo;
		contador++;
	}
}

void ListaSimple::imprimir()

{
	NodoLS* aux = inicio;
	while (aux != 0)
	{
		std::cout <<"*ID: " <<aux->activo->getID()<<", DESCRIPCION: "<<
			aux->activo->getDescripcion()<<", NOMBRE: "<< 
			aux->activo->getNombre()<<std::endl;
		aux = aux->siguiente;

	}
}

void ListaSimple::graficar()
{
	int contador = 0;
	fstream archivo;
	archivo.open("../Reportes/ActivosRentadosUsuario.dot", ios::out);
	archivo << "digraph ReporteTransaccion{rankdir=LR\n";
	NodoLS* actual = inicio;
	if (!estaVacia())
	{
		do
		{
			archivo << "X" << to_string(contador) << "[shape=record label=\"" 
				<< "|{" << actual->activo->getID() << "|" << actual->activo->getNombre()
				<< "|" << actual->activo->getDescripcion()
				<< "}|"  << "\"];\n";
			actual = actual->siguiente;
			contador++;
		} while (actual!=0);
		contador -= 1;
		for (int i = 0; i <= contador; i++)
		{
			if(i+1<=contador)
				archivo << "X" << to_string(i) << "->" << "X" << to_string(i + 1) << ";\n";
		}
		archivo << "}";
		archivo.close();
		system("dot.exe  -Tpng ../Reportes/ActivosRentadosUsuario.dot -o ../Reportes/ActivosRentadosUsuario.png");
		system("start ../Reportes/ActivosRentadosUsuario.png");

	}
}

void ListaSimple::eliminar(string ID)
{
	if (estaVacia())
		std::cout << "\n!!!!!!!!NO TIENES ACTIVOS RENTADOS!!!!!!!!\n";
	else if (inicio->siguiente == 0 && inicio->activo->getID() == ID)
		inicio = 0;
	else if (inicio->siguiente != 0)
	{
		NodoLS* aux = inicio;
		NodoLS* sig = inicio;
		while (sig != 0 && sig->activo->getID() != ID)
		{
			aux = aux->siguiente;
			sig = sig->siguiente;
		}
		if (sig != 0)
		{
			aux->siguiente = 0;
			aux->siguiente = sig->siguiente;
			std::cout << "\n!!!!!!!!!ACTIVO DEVUELTO CON EXITO!!!!!!!!\n";
		}
		else {
			std::cout << "\n!!!!!!!!!NO SE ENCONTRO ESTE ACTIVO EN TUS ACITVOS RENTADOS!!!!!!!!\n";
		}
	}
}

