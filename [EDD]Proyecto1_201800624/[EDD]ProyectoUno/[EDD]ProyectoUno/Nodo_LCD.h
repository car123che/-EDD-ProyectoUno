#pragma once
#include <iostream>
#include "Transaccion.h"
class Nodo_LCD
{
public:
	Nodo_LCD(Transaccion* trans) {
		transaccion = trans;
		siguiente = 0;
		anterior = 0;
		posicion = 0;
	}
	Transaccion* transaccion;
	Nodo_LCD* siguiente;
	Nodo_LCD* anterior;
	int posicion;
};

