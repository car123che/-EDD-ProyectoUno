#pragma once
#include <iostream>
#include "Activo.h"

class Nodo_AVL
{
public:
	Nodo_AVL(Activo* activo_) { hijoDer = 0; hijoIzq = 0; activo = activo_;  }
	Nodo_AVL* hijoIzq;
	Nodo_AVL* hijoDer;
	int dato, factorEqu;
	Activo* activo;

};

