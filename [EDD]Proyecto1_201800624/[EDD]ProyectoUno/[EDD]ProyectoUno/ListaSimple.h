#pragma once
#include <iostream>
#include "NodoLS.h"
#include <string>
#include <fstream>
#include <stdlib.h>
using namespace std;
class ListaSimple
{
public:
	NodoLS* inicio;
	int contador;
	ListaSimple() { inicio = 0; contador = 0; }
	bool estaVacia();
	void agregar(Activo* a);
	void imprimir();
	void graficar();
	void eliminar(string ID);
};

