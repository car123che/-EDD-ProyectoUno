#pragma once
#include <iostream>
#include "Activo.h"

class NodoLS
{
public:
	NodoLS* siguiente;
	int posicion;
	Activo* activo;
	NodoLS(Activo* a) { siguiente = 0; posicion = 0; activo = a; }
};

