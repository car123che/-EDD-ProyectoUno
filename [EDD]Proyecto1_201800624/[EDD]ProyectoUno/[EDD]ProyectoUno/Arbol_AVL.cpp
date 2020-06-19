#include "pch.h"
#include "Arbol_AVL.h"
#include "Activo.h"
#include "Nodo_AVL.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
//ROTACIONES SIMPLES
Nodo_AVL* Arbol_AVL::rotacionSimpleDerecha(Nodo_AVL* padre, Nodo_AVL* aux)
{	//El padre estaba apuntando a su hijo izq, que es aux
	padre->hijoIzq = aux->hijoDer;//apunto el hijo izq del padre a lo que tenga a la derecha aux
	aux->hijoDer = padre;//apunto el hijo der el aux al padre
	padre->factorEqu = 0;//cambio el factor de equilibrio del padre a 0
	return aux;
}

Nodo_AVL* Arbol_AVL::rotacionSimpleIzquierda(Nodo_AVL* padre, Nodo_AVL* aux)
{
	//El padre estaba apuntado a su hijo der, que es aux
	padre->hijoDer = aux->hijoIzq;//apunto el hijo der del padre a lo que tenga a la izquierda aux
	aux->hijoIzq = padre;//apunto el hijo izq de aux al padre
	padre->factorEqu = 0;//cambio el facto de equilibro del padre a 0
	return aux;
}

//ROTACIONES DOBLES
Nodo_AVL* Arbol_AVL::rotacionDobleIzquierda(Nodo_AVL* padre, Nodo_AVL* aux)
{	//Al principio el padre esta apuntando a aux como su hijo izq
	Nodo_AVL* temp;
	temp = aux->hijoDer;//creo un nodo temp que me ayudara a cambiar los valores y le asigno el hijo der de aux
	padre->hijoIzq = temp->hijoDer;//al padre le asigno como hijo izquierdo lo que el hijo derecho de aux tengo como der
	temp->hijoDer = padre;//le asigno a temp como hijo derecho al padre
	aux->hijoDer = temp->hijoIzq;//luego a aux como hijo derecho le asigno lo que temp tuviera ala izq
	temp->hijoIzq = aux;//y asigno como  hijo izq de temp a aux
	if (temp->factorEqu == -1)
	{
		padre->factorEqu = 1;
	}
	else {
		padre->factorEqu = 0;
	}
	if (temp->factorEqu == 1)
	{
		aux->factorEqu = -1;
	}
	else {
		aux->factorEqu = 0;
	}
	return temp;
}

Nodo_AVL* Arbol_AVL::rotacionDobleDerecha(Nodo_AVL* padre, Nodo_AVL* aux)
{
	Nodo_AVL* temp;
	temp = aux->hijoIzq;
	padre->hijoDer = temp->hijoIzq;
	temp->hijoIzq = padre;
	aux->hijoIzq = temp->hijoDer;
	temp->hijoIzq = aux;

	if (temp->factorEqu == 1)
	{
		padre->factorEqu = -1;
	}
	else {
		padre->factorEqu = 0;
	}
	if (temp->factorEqu == -1)
	{
		aux->factorEqu = 1;
	}
	else {
		aux->factorEqu = 0;
	}
	return temp;
}

//INSERTAR
void Arbol_AVL::insertar(int dato, Nodo_AVL* raiz, int* b, Activo* activo)
{
	Nodo_AVL* aux;
	Nodo_AVL* temp;
	if (raiz != 0)
	{
		if (dato < raiz->dato)
		{
			insertar(dato, raiz->hijoIzq, b, activo);
			raiz->hijoIzq = raiz_;
			if (0 < *b)
			{
				if (raiz->factorEqu == 1)
				{
					raiz->factorEqu = 0;
					*b = 0;
				}
				else if (raiz->factorEqu == 0)
				{
					raiz->factorEqu = -1;
				}
				else if (raiz->factorEqu == -1)
				{
					aux = raiz->hijoIzq;
					if (aux->factorEqu <= 0)
					{
						raiz = rotacionSimpleDerecha(raiz, aux);
					}
					else
					{
						raiz = rotacionDobleIzquierda(raiz, aux);
					}
					raiz->factorEqu = 0;
					*b = 0;
				}
			}
		}
		else if (dato > raiz->dato)
		{
			insertar(dato, raiz->hijoDer, b, activo);
			raiz->hijoDer = raiz_;
			if (0 < *b)
			{
				if (raiz->factorEqu==-1)
				{
					raiz->factorEqu = 0;
					*b = 0;
				}
				else if (raiz->factorEqu == 0)
				{
					raiz->factorEqu = 1;
				}
				else if (raiz->factorEqu == 1)
				{
					aux = raiz->hijoDer;
					if (aux->factorEqu >= 0)
					{
						raiz = rotacionSimpleIzquierda(raiz,aux);
					}
					else
					{
						raiz = rotacionDobleDerecha(raiz,aux);
					}
					raiz->factorEqu = 0;
					*b = 0;
				}
			}
		}
		raiz_ = raiz;
	}
	else
	{
		temp = new Nodo_AVL(activo);
		contador += 1;
		temp->dato = dato;
		temp->factorEqu = 0;
		*b = 1;
		raiz_ = temp;
	}
}

void Arbol_AVL::inOrden(Nodo_AVL* raiz)
{
	if (raiz != 0) {
		inOrden(raiz->hijoIzq);
		std::cout << raiz->activo->getDescripcion() << " - ";
		inOrden(raiz->hijoDer);
	}

}

void Arbol_AVL::eliminar(Nodo_AVL* raiz, Nodo_AVL* padre, int dato, int *tipo)
{
	Nodo_AVL* aux;
	int b;
	bool dosHijos = false;
	bool mayor = false;
	if (raiz != 0)
	{
		if (dato < raiz->dato)
		{
			if (*tipo > 0)
				b = 1;
			else if (*tipo != 0)
				b = -1;
			*tipo = -1;
			eliminar(raiz->hijoIzq, raiz, dato, tipo);
			raiz = balanceoIzq(raiz, tipo);

			if (padre != 0)
			{
				if (b == -1)
				{
					padre->hijoIzq = raiz;
				}
				else if (b == 1)
				{
					padre->hijoDer = raiz;
				}
				else {
					return;
				}
			}
			else
			{
				raiz_ = raiz;
			}
		}
		else 
			if (dato > raiz->dato)
		{
				mayor = true;
			if (*tipo < 0)
				b = -1;
			else 
				if (*tipo != 0)
					b = 1;
			*tipo = 1;
			eliminar(raiz->hijoDer, raiz, dato, tipo);
			raiz = balanceoDer(raiz, tipo);
			if (padre != 0)
			{
				if (b == -1)
				{
					padre->hijoIzq = raiz;
				}
				else if (b == 1)
				{
					padre->hijoDer = raiz;
				}
				else
				{
					return;
				}
			}
			else
			{
				raiz_ = raiz;
			}
		}
		else
		{
			aux = raiz;
			if (aux->hijoDer == 0)
			{
				raiz = aux->hijoIzq;
				if (*tipo != 0)
				{
					if (*tipo < 0)
					{
						padre->hijoIzq = raiz;
					}
					else
					{
						padre->hijoDer = raiz;
					}
				}
				else
				{
					if (raiz == 0)
					{
						raiz_ = 0;
					}
					else
					{
						raiz_ = raiz;
					}
					*tipo = 1;
				}
			}
			else if(aux->hijoIzq==0)
			{
				raiz = aux->hijoDer;
				if (*tipo != 0)
				{
					if (*tipo < 0)
					{
						padre->hijoIzq = raiz;
					}
					else
					{
						padre->hijoDer = raiz;
					}
				}
				else 
					if(raiz==0)
					{
						raiz_ = 0;
					}
					else
					{
						raiz_ = raiz;
					}
				*tipo = 1;
			}
			else
			{
				dosHijos = true;
				reordenar(aux->hijoIzq, aux, tipo);
				raiz = balanceoIzq(raiz, tipo);
				if (dosHijos&&mayor)
				{
					*tipo = 1;
				}
				if (padre != 0)
				{
					if (*tipo <= 0)
					{
						padre->hijoIzq = raiz;
					}
					else
					{
						padre->hijoDer = raiz;
					}
				}
				else
				{
					raiz_ = raiz;
				}
			}
		}
	}
else {
std::cout << "\n!!!!!!!!!!!EL DATO A ELIMINAR NO EXISTE!!!!!!!!!!!!!!\n";
}
}

Nodo_AVL* Arbol_AVL::balanceoIzq(Nodo_AVL* padre, int *tipo)
{
	Nodo_AVL* aux;
	if (*tipo > 0)
	{
		if (padre->factorEqu == -1) {
			padre->factorEqu = 0;
		}
		else if (padre->factorEqu == 0)
		{
			padre->factorEqu = 1;
			*tipo = 0;
		}
		else if (padre->factorEqu == 1)
		{
			aux = padre->hijoDer;
			if (aux->factorEqu >= 0)
			{
				padre->hijoDer = aux->hijoIzq;
				aux->hijoIzq = padre;
				if (aux->factorEqu == 0)
				{
					padre->factorEqu = 1;
					aux->factorEqu = -1;
					*tipo = 0;
				}
				else if (aux->factorEqu == 1)
				{
					padre->factorEqu = 0;
					aux->factorEqu = 0;
				}
				padre = aux;
			}
			else
			{
				padre = rotacionDobleDerecha(padre, aux);
				padre->factorEqu = 0;
			}
		}
	}
	return padre;
}

Nodo_AVL* Arbol_AVL::balanceoDer(Nodo_AVL* padre, int *tipo)
{

	Nodo_AVL* aux;
	if (*tipo > 0)
	{
		if (padre->factorEqu == 1) {
			padre->factorEqu = 0;
		}
		else if (padre->factorEqu == 0)
		{
			padre->factorEqu = -1;
			*tipo = 0;
		}
		else if (padre->factorEqu == -1)
		{
			aux = padre->hijoIzq;
			if (aux->factorEqu <= 0)
			{
				padre->hijoIzq = aux->hijoDer;
				aux->hijoDer = padre;
				if (aux->factorEqu == 0)
				{
					padre->factorEqu = -1;
					aux->factorEqu = 1;
					*tipo = 0;
				}
				else if (aux->factorEqu == -1)
				{
					padre->factorEqu = 0;
					aux->factorEqu = 0;
				}
				padre = aux;
			}
			else
			{
				padre = rotacionDobleIzquierda(padre, aux);
				padre->factorEqu = 0;
			}
		}
	}
	return padre;
}

void Arbol_AVL::reordenar(Nodo_AVL* padre, Nodo_AVL* aux, int *tipo)
{
	if (padre->hijoDer != 0)
	{
		reordenar(padre->hijoDer, aux, tipo);
		if (aux->hijoIzq == 0)
		{
			padre->hijoDer = 0;
		}
		else
		{
			padre->hijoDer = aux->hijoIzq;
		}
		padre = balanceoDer(padre, tipo);
	}
	else
	{
		
		aux->dato = padre->dato;
		aux->activo = padre->activo;
		padre = padre->hijoIzq;
		*tipo = 1;
	}
	aux->hijoIzq = padre;
}

void Arbol_AVL::graficar(int numero)
{
	fstream archivo;
	archivo.open("../Reportes/arbolAVL.dot", ios::out);
	archivo << "digraph ArbolAVL{\n";
	Nodo_AVL* aux = raiz_;
	cuadritoG(aux, "",numero);
	archivo << dato<<"\n";
	conexiones(aux, "", numero);
	archivo << datoDos << "\n";
	dato = "";
	archivo << "}";
	archivo.close();
	system("dot.exe  -Tpng ../Reportes//arbolAVL.dot -o ../Reportes/arbolAVL.png");
	system("start ../Reportes//arbolAVL.png");
}

void Arbol_AVL::cuadritoG(Nodo_AVL* raiz, string dato_, int numero)
{
	dato = dato_;
	if (raiz != 0)
	{
		if (!raiz->activo->rentado)
		{
			dato += "node[style=filled, fillcolor=skyblue];\n";
		}
		else
		{
			dato += "node[style=filled, fillcolor=blue];\n";
		}
		dato += "X_"+to_string(numero)+ to_string(raiz->dato)+ "[shape=record label=\""
			+to_string(raiz->dato)+"|{" + raiz->activo->getID() + "|" + raiz->activo->getNombre() + "|" 
			+ raiz->activo->getDescripcion() + "}|\"];\n";
		cuadritoG(raiz->hijoIzq, dato, numero);
		cuadritoG(raiz->hijoDer, dato, numero);
	}
}

void Arbol_AVL::conexiones(Nodo_AVL* raiz, std::string dato_, int numero)
{
	datoDos = dato_;
	if (raiz != 0)
	{
		if (raiz->hijoIzq != 0)
		{
			datoDos += "X_" + to_string(numero) + to_string(raiz->dato) + "->"+ "X_" + to_string(numero) + to_string(raiz->hijoIzq->dato)+ ";\n";
		}
		if (raiz->hijoDer != 0)
		{
			datoDos += "X_" + to_string(numero)+ to_string(raiz->dato) + "->"+ "X_" + to_string(numero) + to_string(raiz->hijoDer->dato)+";\n";
		}
		conexiones(raiz->hijoIzq, datoDos, numero);
		conexiones(raiz->hijoDer, datoDos, numero);
	}
}

void Arbol_AVL::conexionesRentado(Nodo_AVL* raiz, std::string dato_, int numero)
{
	datoDosRentado = dato_;
	if (raiz != 0)
	{
		if (!raiz->activo->rentado)
		{
			if (raiz->hijoIzq != 0)
			{
				datoDosRentado += "X_" + to_string(numero) + to_string(raiz->dato) + "->" + "X_" + to_string(numero) + to_string(raiz->hijoIzq->dato) + ";\n";
			}
			if (raiz->hijoDer != 0)
			{
				datoDosRentado += "X_" + to_string(numero) + to_string(raiz->dato) + "->" + "X_" + to_string(numero) + to_string(raiz->hijoDer->dato) + ";\n";
			}
		}
		conexionesRentado(raiz->hijoIzq, datoDosRentado, numero);
		conexionesRentado(raiz->hijoDer, datoDosRentado, numero);
	}
}

void Arbol_AVL::cuadritoGRentado(Nodo_AVL* raiz, std::string dato_, int numero)
{
	datoRentado = dato_;
	if (raiz != 0)
	{
		if (!raiz->activo->rentado)
		{
			datoRentado += "node[style=filled, fillcolor=blue];\n";
			datoRentado += "X_" + to_string(numero) + to_string(raiz->dato) + "[shape=record label=\""
				+to_string(raiz->dato)+"|{" + raiz->activo->getID() + "|" + raiz->activo->getNombre() + "|"
				+ raiz->activo->getDescripcion() + "}|\"];\n";
		}
			cuadritoGRentado(raiz->hijoIzq, datoRentado, numero);
			cuadritoGRentado(raiz->hijoDer, datoRentado, numero);
	}
}

void Arbol_AVL::modificarActivo(int dato, Nodo_AVL* aux, string des, string nombre, int cont_)
{
	int cont = cont_;
	if (aux != 0)
	{
		if (cont <= contador)
		{
			if (aux->dato == dato)
			{
				aux->activo->setDescripcion(des);
				aux->activo->setNombre(nombre);
				cout << "\nACTIVO MODIFICADO CORRECTAMENTE\n";
				return;
			}
			else if (dato < aux->dato)
			{
				cont += 1;
				modificarActivo(dato, aux->hijoIzq, des, nombre, cont);
			}
			else if (dato > aux->dato)
			{
				cont += 1;
				modificarActivo(dato, aux->hijoDer,des,nombre, cont);
			}
		}
		else
		{
			cout << "\n!!!!!!!!!!EL ACTIVO A ELIMINAR NO EXISTE!!!!!!!!!!!\n";
			return;
		}
	}
	else
	{
		cont -= 1;
	}
}

void Arbol_AVL::preOrden(Nodo_AVL* raiz)
{
	if (raiz != 0)
	{
		preOrden(raiz->hijoIzq);
		cout << raiz->dato << ". ID: " << raiz->activo->getID()<< ", Nombre: " 
		<< raiz->activo->getNombre()<<", Descripcion: "<< raiz->activo->getDescripcion()<<endl;
		preOrden(raiz->hijoDer);
	}
}

void Arbol_AVL::imprimir(Nodo_AVL *raiz)
{
	if (raiz!= 0)
	{	
		imprimir(raiz->hijoIzq);
		if (!raiz->activo->rentado)
		{
			cout << ". ID: " << raiz->activo->getID() << ", Nombre: "
				<< raiz->activo->getNombre() << ", Descripcion: " << raiz->activo->getDescripcion() << endl;
		}
		imprimir(raiz->hijoDer);
	}
}

void Arbol_AVL::buscarID(std::string ID, Nodo_AVL* raiz)
{
	if (raiz != 0)
	{
		if (raiz->activo->getID() == ID)
		{
			auxi = raiz;
			return;
		}
		buscarID(ID, raiz->hijoIzq);
		buscarID(ID, raiz->hijoDer);
	}
	else
	{
		return;
	}
	
}

void Arbol_AVL::imprimirActivosRentados(Nodo_AVL *raiz)
{
	if (raiz != 0)
	{
		imprimirActivosRentados(raiz->hijoIzq);
		if (raiz->activo->rentado)
		{
			cout << ". ID: " << raiz->activo->getID() << ", Nombre: "
				<< raiz->activo->getNombre() << ", Descripcion: " << raiz->activo->getDescripcion() << endl;
		}
		imprimirActivosRentados(raiz->hijoDer);
	}
}