#include "pch.h"
#include "Matriz.h"
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include "Usuario.h"

using namespace std;
void Matriz::insertarElemento(string usuario, int numero, string empresa, string departamento, Usuario *user)
{
	Nodo* nodoUser;
	Nodo* nodoDepa;
	Nodo* nodoEmp;

	nodoUser = new Nodo(usuario, numero, user);

	nodoDepa = buscarDepa(departamento, cabecera);
	nodoEmp = buscarEmpresa(empresa, cabecera);

	//check if headers exists
	if (nodoDepa == 0)
		nodoDepa = crearDepartamento(departamento);
	if (nodoEmp == 0)
		nodoEmp = crearEmpresa(empresa);

	//INSERTAR EN NODO DEPARTAMENTO
		//Inserting at beginning
	if (nodoDepa->abajo == 0)
	{
		nodoDepa->abajo = nodoUser;
		nodoUser->arriba = nodoDepa;
	}   //Inserting at end
	else if (nodoEmp->abajo == 0)
	{
		Nodo* aux = nodoDepa->abajo;
		while (aux->abajo != 0)
		{
			aux = aux->abajo;
		}
		if (!verificarEmpresa(empresa, aux, nodoUser))
		{
			aux->abajo = nodoUser;
			nodoUser->arriba = aux;
		}
	}   //Insert at middle
	else
	{
		Nodo *aux = nodoDepa;
		do
		{
			aux = aux->abajo;
			if (!verificarEmpresa(empresa, aux, nodoUser))
			{
				Nodo *auxEmp = aux->anterior;
				while (auxEmp->anterior != 0)
				{
					auxEmp = auxEmp->anterior;
				}
				while (auxEmp->arriba != 0)
				{
					if (auxEmp->nombre == empresa)
					{
						nodoUser->abajo = aux;
						nodoUser->arriba = aux->arriba;

						aux->arriba->abajo = nodoUser;
						aux->arriba = nodoUser;
						break;
					}
					auxEmp = auxEmp->arriba;
				}
			}
		} while (aux->abajo != 0 && nodoUser->arriba == 0);
		if (nodoUser->arriba == 0 && nodoUser->adelante == 0)
		{
			aux->abajo = nodoUser;
			nodoUser->arriba = aux;
		}
	}

	if (nodoUser->adelante != 0)
	{
		return;
	}
	//INSERTAR EN NODO EMPRESA
		//Inserting at beginning
	if (nodoEmp->siguiente == 0)
	{
		nodoEmp->siguiente = nodoUser;
		nodoUser->anterior = nodoEmp;
	}   //Inserting at end
	else if (nodoDepa->siguiente == 0)
	{
		Nodo* aux = nodoEmp->siguiente;
		while (aux->siguiente != 0)
		{
			aux = aux->siguiente;
		}
		if (!verificarDepa(departamento, aux, nodoUser))
		{
			aux->siguiente = nodoUser;
			nodoUser->anterior = aux;
		}
	}//Inserting at middle
	else
	{
		Nodo *aux = nodoEmp;
		do
		{
			aux = aux->siguiente;
			if (!verificarDepa(departamento, aux, nodoUser))
			{
				Nodo *auxDepa = aux->arriba;
				while (auxDepa->arriba != 0)
				{
					auxDepa = auxDepa->arriba;
				}
				while (auxDepa->anterior != 0)
				{
					if (auxDepa->nombre == departamento)
					{
						nodoUser->siguiente = aux;
						nodoUser->anterior = aux->anterior;

						aux->anterior->siguiente = nodoUser;
						aux->anterior = nodoUser;
						break;
					}
					auxDepa = auxDepa->anterior;
				}
			}
		} while (aux->siguiente != 0 && nodoUser->anterior == 0);

		if (nodoUser->anterior == 0 && nodoUser->adelante == 0)
		{
			aux->siguiente = nodoUser;
			nodoUser->anterior = aux;
		}
	}
}

Nodo* Matriz::crearEmpresa(string empresa)
{
	Nodo* emp;
	Usuario *vacio = new Usuario("", "", "", "", "");
	emp = new Nodo(empresa, -1, vacio);
	Nodo* aux = cabecera;

	while (aux->abajo != 0) {
		aux = aux->abajo;
	}
	aux->abajo = emp;
	emp->arriba = aux;
	return emp;

}

Nodo* Matriz::crearDepartamento(string departamento)
{
	Usuario* vacio = new Usuario("", "", "", "", "");
	Nodo* dep;
	dep = new Nodo(departamento, -1, vacio);
	Nodo* aux = cabecera;

	while (aux->siguiente != 0)
	{
		aux = aux->siguiente;
	}
	aux->siguiente = dep;
	dep->anterior = aux;
	return dep;
}

Nodo* Matriz::buscarDepa(string departamento, Nodo* inicio)
{
	Nodo* aux = inicio;
	while (aux != 0)
	{
		if (aux->nombre == departamento)
		{
			return aux;
		}
		else
		{
			aux = aux->siguiente;
		}
	}
	return 0;
}


Nodo* Matriz::buscarEmpresa(string empresa, Nodo* inicio)
{
	Nodo* aux = inicio;
	while (aux != 0)
	{
		if (aux->nombre == empresa)
		{
			return aux;
		}
		else
		{
			aux = aux->abajo;
		}
	}
	return 0;
}

bool Matriz::verificarEmpresa(string empresa, Nodo* inicio, Nodo *USER)
{
	Nodo* auxEmp = inicio->anterior;
	while (auxEmp->anterior != 0)
	{
		auxEmp = auxEmp->anterior;
	}
	if (auxEmp->nombre == empresa)
	{
		while (inicio->atras != 0)
		{
			inicio = inicio->atras;
		}
		inicio->atras = USER;
		USER->adelante = inicio;
		return true;
	}
	return false;
}

bool Matriz::verificarDepa(string departamento, Nodo* inicio, Nodo *USER)
{
	Nodo* auxDepa = inicio->arriba;
	while (auxDepa->arriba != 0)
	{
		auxDepa = auxDepa->arriba;
	}
	if (auxDepa->nombre == departamento)
	{
		while (inicio->atras != 0)
		{
			inicio = inicio->atras;
		}
		inicio->atras = USER;
		USER->adelante = inicio;

		return true;
	}
	return false;
}

void Matriz::graficar()
{
	fstream archivo;
	archivo.open("C:/Users/CARLOS/Documents/test.dot", ios::out);

	//Inicializando graphviz
	archivo << "digraph MatrizDispersa{node[shape=box]\n";
	//Cabecera Matriz
	archivo << "INIT[label=\"Emp/Dep\", width = 1.5, style = filled, fillcolor=firebrick1, group=1];\n";
	//Mostrar cabeceras de las filas
	Nodo *aux = cabecera->abajo;
	int contadorUno = 0;
	while (aux != 0)
	{
		cout << "\n" << aux->nombre;
		archivo << "y" << to_string(contadorUno) << "[label = " << aux->nombre << " width=1.5 style = filled, fillcolor=bisque1, group=1];\n";
		contadorUno++;
		aux = aux->abajo;
	}
	if (contadorUno > 0) {
		archivo << "INIT->y0;\n";
		archivo << "y0->INIT;\n";
	}
	for (int i = 0; i < contadorUno - 1; i++) {
		archivo << "y" << to_string(i) << " -> y" << to_string(i + 1) << ";\n";
		archivo << "y" << to_string(i + 1) << " -> y" << to_string(i) << ";\n";
	}

	//Mostrar cabeceras de las columnas
	aux = cabecera->siguiente;
	int contadorDos = 0;
	while (aux != 0)
	{
		cout << aux->nombre << " ";
		archivo << "x" << to_string(contadorDos) << "[label = " << aux->nombre << " width=1.5 style=filled, fillcolor=lightskyblue, group=" << to_string(contadorDos + 2) << "];\n";
		contadorDos++;
		aux = aux->siguiente;
	}
	if (contadorDos > 0) {
		archivo << "INIT->x0;\n";
		archivo << "x0->INIT;\n";
		archivo << "{rank=same;INIT;x0;x" << to_string(contadorDos - 1) << "}";
	}

	for (int i = 0; i < contadorDos - 1; i++) {
		archivo << "x" << to_string(i) << " -> x" << to_string(i + 1) << ";\n";
		archivo << "x" << to_string(1 + i) << " -> x" << to_string(i) << ";\n";
		if (i > 0)
			archivo << "{rank=same; x" << to_string(i - 1) << "; x" << to_string(i) << "; }";
	}

	//MOSTAR DATOS DE ENMEDIO
	Nodo *auxi1 = cabecera->abajo;
	Nodo *auxi2 = cabecera->siguiente;
	Nodo *auxi3 = cabecera->abajo->siguiente;
	Nodo *auxi4 = cabecera->siguiente->abajo;
	int x = 0, y = 0;
	string temp[30][30];
	
	int  xx=0;
	while (auxi1 != 0)
	{
		while (auxi2 != 0) {
			if (auxi3->usuario->getDepartamento() == auxi2->nombre)
			{
				if(auxi3->atras!=0)
					archivo << "\nnode[shape = box3d]\n";
				else
					archivo << "\nnode[shape = box]\n";
				archivo << "x" << to_string(y) << "_y" << to_string(x) << "[label=" << auxi3->nombre << " width=1.5, group=" << to_string(y)<<"];\n";
				temp[y][x] = "x" + to_string(y) + "_y" + to_string(x);

				cout << "\n"<<auxi3->nombre;
				if (auxi3->siguiente != 0) {
					auxi3 = auxi3->siguiente;
				}
			
			}
			if (x == contadorDos - 1) {
				if (auxi1->abajo != 0) {

					while (auxi4->abajo == 0) {
						auxi4 = auxi4->siguiente;
					}
					auxi3 = auxi4->abajo;
					x = 0;
				}
			}
				
			
			auxi2 = auxi2->siguiente;
			x++;
		}
		x--;
		auxi2 = cabecera->siguiente;
		if (auxi1->abajo != 0) {
			auxi4 = auxi1->abajo->siguiente;
		}
		y++;
		auxi1 = auxi1->abajo;
	}

	while (auxi2 != 0) {
		x++;
		auxi2 = auxi2->siguiente;
	}
	int account = 0;
	int account2 = 0;
	int a,b;
	//auxi1 = cabecera->abajo;
	//auxi2 = cabecera->siguiente;
	
	for (int i = 0; i <x; i++) {
		for (int j = 0; j < y; j++) {
			cout << " " << temp[i][j] << "";
			if(account < 1){
				if (temp[i][j] != "") {
					account++;
					archivo << "y" << to_string(i) << "->" << temp[i][j] << ";\n";
					archivo << temp[i][j] << "->" << "y" << to_string(i);
					archivo << "{rank = same; y" << to_string(i) << "; " << temp[i][j] << "; }\n";
					a = j;
				}
			}
			else {
				if (temp[i][j] != "") {
					archivo << temp[i][a] << "->" << temp[i][j] << ";\n";
					archivo << temp[i][j] << "->" << temp[i][a] << ";\n";
					//cout << "\n" << temp[i][j - 1] << "->" << temp[i][j];
					archivo << "{rank = same; " << temp[i][a] << "; " << temp[i][j] << "; }\n";
					a = j;
				}
				else {

				}
			}
		}
		account = 0;
		cout << "\n";
	}

	for (int j = 0; j < y; j++) {
		for (int i = 0; i < x; i++) {
			if (account2 < 1) {
				if (temp[i][j] != "") {
					account2++;
					archivo << "x" << to_string(j) << "->" << temp[i][j] << ";\n";
					archivo << temp[i][j] << "->x" << to_string(j) << ";\n";
					//archivo << "{rank = same; x" << to_string(j) << "; " << temp[i][j] << "; }\n";
					b = i;
				}
			}
			else {
				if (temp[i][j] != "") {
					archivo << temp[b][j] << "->" << temp[i][j] << ";\n";
					archivo << temp[i][j] << "->" << temp[b][j] << ";\n";
					//cout << "\n" << temp[i][j - 1] << "->" << temp[i][j];
					//archivo << "{rank = same; " << temp[b][j] << "; " << temp[i][j] << "; }\n";
					b = i;
				}
			}
		}
		account2 = 0;
	}

	archivo << "}";
	archivo.close();

	system("dot.exe  -Tpng C:/Users/CARLOS/Documents/test.dot -o C:/Users/CARLOS/Documents/test.png");
	system("start C:/Users/CARLOS/Documents/test.png");
}
