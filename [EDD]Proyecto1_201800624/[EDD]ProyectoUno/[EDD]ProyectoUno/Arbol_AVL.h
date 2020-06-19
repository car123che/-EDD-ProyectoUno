#pragma once
#include <iostream>
#include "Activo.h"
#include "Nodo_AVL.h"

class Arbol_AVL
{
public:
	std::string dato, datoDos, datoRentado, datoDosRentado;
	Arbol_AVL() { raiz_ = 0; contador = 0; auxi = 0; }

	Nodo_AVL* rotacionSimpleDerecha(Nodo_AVL* padre, Nodo_AVL* aux);
	Nodo_AVL* rotacionSimpleIzquierda(Nodo_AVL* padre, Nodo_AVL* aux);
	Nodo_AVL* rotacionDobleIzquierda(Nodo_AVL* padre, Nodo_AVL* aux);
	Nodo_AVL* rotacionDobleDerecha(Nodo_AVL* padre, Nodo_AVL* aux);

	void insertar(int dato, Nodo_AVL* raiz, int* b, Activo* activo);

	void inOrden(Nodo_AVL* raiz);

	void eliminar(Nodo_AVL* raiz,Nodo_AVL* padre,  int dato, int *tipo);
	Nodo_AVL* balanceoIzq(Nodo_AVL* padre, int *tipo);
	Nodo_AVL* balanceoDer(Nodo_AVL* padre, int *tipo);
	void reordenar(Nodo_AVL* padre, Nodo_AVL* aux, int *tipo);
	Nodo_AVL* raiz_;

	void graficar(int numero);
	void cuadritoG(Nodo_AVL*, std::string, int);
	void conexiones(Nodo_AVL*, std::string, int);
	
	void conexionesRentado(Nodo_AVL* raiz, std::string dato_, int numero);
	void cuadritoGRentado(Nodo_AVL*, std::string, int);
	int contador;

	void modificarActivo(int dato, Nodo_AVL* aux, std::string des, std::string nombre, int cont_);
	void preOrden(Nodo_AVL* raiz);

	void imprimir(Nodo_AVL* raiz);
	void buscarID(std::string ID, Nodo_AVL* raiz);
	Nodo_AVL* auxi;
	void imprimirActivosRentados(Nodo_AVL* raiz);
};

