#pragma once
#include <iostream>
#include "Usuario.h"
class Nodo
{
public:
	Nodo *siguiente;
	Nodo *anterior;
	Nodo *arriba;
	Nodo *abajo;
	Nodo *adelante;
	Nodo *atras;


	std::string nombre;
	Usuario *usuario;
	int numero;

	Nodo(std::string dato1, int dato2, Usuario *user)
	{
		siguiente = 0;
		anterior = 0;
		arriba = 0;
		abajo = 0;
		adelante = 0;
		atras = 0;
		nombre = dato1;
		numero = dato2;
		usuario = user;
	}


};

