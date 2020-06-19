#pragma once
#include <iostream>
#include "Nodo_LCD.h"
#include "Transaccion.h"
class ListaCircularDoble
{
public:
	ListaCircularDoble() {
		tam = 0;
		primero = 0;
	}
	Nodo_LCD* primero;
	int tam;

	void ingresar(Transaccion* transaccion);
	bool estaVacia();
	void imprimir();
	void graficar();
	void ordenarAscendente();
	void ordenarDescendente();
};

