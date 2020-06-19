#include "pch.h"
#include "Matriz.h"
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include "Usuario.h"
#include "Nodo_AVL.h"
using namespace std;
void Matriz::insertarElemento(string usuario, int numero, string empresa, string departamento, Usuario *user)
{
	Nodo* auxx = buscarUsuario(usuario, user->getPassword(), departamento, empresa);
	if (auxx==0)
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
		cout << "\nUSUARIO GUARDADO CORRECTAMENTE" << endl;
	}
	else
	{
	cout << "\n!!!!!!!!!!EL USUARIO YA EXISTE!!!!!!!!!!";
	}
}

Nodo* Matriz::buscarUsuario(string usuario, string password, string departamento, string empresa)
{
	Nodo* col;
	Nodo* fil = cabecera->abajo;
	Nodo* prim;
	Nodo* aux ;
	Nodo* aux2=0;
	if (fil != 0)
	{
		while (fil != 0)
		{
			col = cabecera->siguiente;
			aux = fil->siguiente;
			while (col != 0)
			{
				prim = aux;
				while (prim != 0)
				{
					if (prim->usuario->getDepartamento() == departamento && prim->usuario->getEmpresa() == empresa && prim->usuario->getPassword() == password && prim->nombre == usuario)
					{
						aux2 = prim;
						return aux2;
					}
					prim = prim->atras;
				}
				if (aux != 0)
					aux = aux->siguiente;
				col = col->siguiente;
			}
			fil = fil->abajo;
		}
		return aux2;
	}
	else
	{
		return 0;
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
	archivo.open("../Reportes/test.dot", ios::out);

	//Inicializando graphviz
	archivo << "digraph MatrizDispersa{node[shape=box]\n";
	//Cabecera Matriz
	archivo << "INIT[label=\"Emp/Dep\", width = 1.5, style = filled, fillcolor=yellow, group=1];\n";
	//Mostrar cabeceras de las filas
	Nodo *aux = cabecera->abajo;
	int contadorUno = 0;
	while (aux != 0)
	{
		cout << "\n" << aux->nombre;
		archivo << "y" << to_string(contadorUno) << "[label = " << aux->nombre << " width=1.5 style = filled, fillcolor=green, group=1];\n";
		contadorUno++;
		aux = aux->abajo;
	}
	if (contadorUno > 0) {
		archivo << "INIT->y0[dir=both];\n";
	}
	for (int i = 0; i < contadorUno - 1; i++) {
		archivo << "y" << to_string(i) << " -> y" << to_string(i + 1) << "[dir=both];\n";
	}

	//Mostrar cabeceras de las columnas
	aux = cabecera->siguiente;
	int contadorDos = 0;
	while (aux != 0)
	{
		cout << aux->nombre << " ";
		archivo << "x" << to_string(contadorDos) << "[label = " << aux->nombre << " width=1.5 style=filled, fillcolor=skyblue, group=" << to_string(contadorDos + 2) << "];\n";
		contadorDos++;
		aux = aux->siguiente;
	}
	if (contadorDos > 0) {
		archivo << "INIT->x0[dir=both];\n";
		archivo << "{rank=same;INIT;x0;x" << to_string(contadorDos - 1) << "}";
	}

	for (int i = 0; i < contadorDos - 1; i++) {
		archivo << "x" << to_string(i) << " -> x" << to_string(i + 1) << "[dir=both];\n";

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

	int  xx = 0;
	while (auxi1 != 0)
	{
		while (auxi2 != 0) {
			if (auxi3->usuario->getDepartamento() == auxi2->nombre)
			{
				if (auxi3->atras != 0)
					archivo << "\nnode[shape = box3d]\n";
				else
					archivo << "\nnode[shape = box]\n";
				archivo << "x" << to_string(y) << "_y" << to_string(x) << "[label=" << auxi3->nombre << " width=1.5, group=" << to_string(y) << "];\n";
				temp[y][x] = "x" + to_string(y) + "_y" + to_string(x);

				cout << "\n" << auxi3->nombre;
				if (auxi3->siguiente != 0) {
					auxi3 = auxi3->siguiente;
				}

			}
			if (x == contadorDos - 1) {
				if (auxi1->abajo != 0) {
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
			auxi3 = auxi4;
		}
		y++;
		auxi1 = auxi1->abajo;
	}
	x = 0;
	while (auxi2 != 0) {
		x++;
		auxi2 = auxi2->siguiente;
	}
	int account = 0;
	int account2 = 0;
	int a, b;
	//auxi1 = cabecera->abajo;
	//auxi2 = cabecera->siguiente;

	for (int i = 0; i < y; i++) {
		for (int j = 0; j < x; j++) {
			cout << " " << temp[i][j] << "";
			if (account < 1) {
				if (temp[i][j] != "") {
					account++;
					archivo << "y" << to_string(i) << "->" << temp[i][j] << "[dir=both];\n";
					archivo << "{rank = same; y" << to_string(i) << "; " << temp[i][j] << "; }\n";
					a = j;
				}
			}
			else {
				if (temp[i][j] != "") {
					archivo << temp[i][a] << "->" << temp[i][j] << ";[dir=both]\n";
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

	for (int j = 0; j < x; j++) {
		for (int i = 0; i < y; i++) {
			if (account2 < 1) {
				if (temp[i][j] != "") {
					account2++;
					archivo << "x" << to_string(j) << "->" << temp[i][j] << "[dir=both];\n";
					//archivo << "{rank = same; x" << to_string(j) << "; " << temp[i][j] << "; }\n";
					b = i;
				}
			}
			else {
				if (temp[i][j] != "") {
					archivo << temp[b][j] << "->" << temp[i][j] << "[dir=both];\n";
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

	system("dot.exe  -Tpng ../Reportes/test.dot -o ../Reportes/test.png");
	system("start ../Reportes/test.png");
}

Nodo* Matriz::buscarUsuario(string usuario, string departamento, string empresa)
{
	Nodo* col;
	Nodo* fil = cabecera->abajo;
	Nodo* prim;
	Nodo* aux;
	Nodo* aux2 = 0;
	if (fil != 0)
	{
		while (fil != 0)
		{
			col = cabecera->siguiente;
			aux = fil->siguiente;
			while (col != 0)
			{
				prim = aux;
				while (prim != 0)
				{
					if (prim->usuario->getDepartamento() == departamento && prim->usuario->getEmpresa() == empresa  && prim->nombre == usuario)
					{
						aux2 = prim;
						return aux2;
					}
					prim = prim->atras;
				}
				if (aux != 0)
					aux = aux->siguiente;
				col = col->siguiente;
			}
			fil = fil->abajo;
		}
		return aux2;
	}
	else
	{
		return 0;
	}
}

void Matriz::graficarDepa(Nodo* depa)
{	
	int contador = 0;
	int a;
	fstream archivo;
	archivo.open("../Reportes/ReporteDepartamento.dot", ios::out);
	archivo << "digraph ReporteDepartamento{node[shape=plaintext]\n";
	archivo << "INIT[label=\"Reporte Activos Departamtento\"];\n";
	Nodo* aux2 = depa->abajo;
	Nodo* aux3;
		while (aux2 != 0)
		{
			aux3 = aux2;
			while (aux3 != 0)
			{
				if (aux3->usuario->arbolito->raiz_ != 0)
				{
					a = aux3->usuario->arbolito->raiz_->dato;
					archivo << "node[shape=circle, style=filled, fillcolor=red];\n";
					archivo << "w"<<to_string(contador)<<"[label=" << aux3->nombre << "];\n";
					aux3->usuario->arbolito->cuadritoG(aux3->usuario->arbolito->raiz_, "", aux3->numero);
					aux3->usuario->arbolito->conexiones(aux3->usuario->arbolito->raiz_, "", aux3->numero);
					archivo << aux3->usuario->arbolito->dato;
					archivo << "\n" << aux3->usuario->arbolito->datoDos;
					archivo << "w" << to_string(contador) << "->X_" << to_string(aux3->numero) << to_string(a)<<";\n";
					aux3->usuario->arbolito->dato = "";
					aux3->usuario->arbolito->datoDos = "";
					contador += 1;
				}
				aux3 = aux3->atras;
			}
			aux2 = aux2->abajo;
		}
		archivo << "}";
		archivo.close();
		system("dot.exe  -Tpng ../Reportes/ReporteDepartamento.dot -o ../Reportes/ReporteDepartamento.png");
		system("start ../Reportes/ReporteDepartamento.png");

}

void Matriz::graficarEmp(Nodo* emp)
{
	int contador = 0;
	int a;
	fstream archivo;
	archivo.open("../Reportes/ReporteEmpresa.dot", ios::out);
	archivo<< "digraph ReporteEmpresa{node[shape=plaintext]\n";
	archivo << "INIT[label=\"Reporte Activos por Empresa\"];\n";
	Nodo* aux2 = emp->siguiente;
	Nodo* aux3;
	while (aux2 != 0)
	{
		aux3 = aux2;
		while (aux3 != 0)
		{
			if (aux3->usuario->arbolito->raiz_ != 0)
			{
				a = aux3->usuario->arbolito->raiz_->dato;
				a = aux3->usuario->arbolito->raiz_->dato;
				archivo << "node[shape=circle, style=filled, fillcolor=red];\n";
				archivo << "w" << to_string(contador) << "[label=" << aux3->nombre << "];\n";
				aux3->usuario->arbolito->cuadritoG(aux3->usuario->arbolito->raiz_, "", aux3->numero);
				aux3->usuario->arbolito->conexiones(aux3->usuario->arbolito->raiz_, "", aux3->numero);
				archivo << aux3->usuario->arbolito->dato;
				archivo << "\n" << aux3->usuario->arbolito->datoDos;
				archivo << "w" << to_string(contador) << "->X_" << to_string(aux3->numero) << to_string(a) << ";\n";
				aux3->usuario->arbolito->dato = "";
				aux3->usuario->arbolito->datoDos = "";
				contador += 1;
			}
			aux3 = aux3->atras;
		}
		aux2 = aux2->siguiente;
	}
	archivo << "}";
	archivo.close();
	system("dot.exe  -Tpng ../Reportes/ReporteEmpresa.dot -o ../Reportes/ReporteEmpresa.png");
	system("start ../Reportes/ReporteEmpresa.png");
}

void Matriz::imprimirActivos(Usuario* mio)
{
	Nodo* col;
	Nodo* fil = cabecera->abajo;
	Nodo* prim;
	Nodo* aux;
		while (fil != 0)
		{
			col = cabecera->siguiente;
			aux = fil->siguiente;
			while (col != 0)
			{
				prim = aux;
				while (prim != 0)
				{
					if (prim->nombre != mio->getUser())
					{
						prim->usuario->arbolito->imprimir(prim->usuario->arbolito->raiz_);
					}
					prim = prim->atras;
				}
				if(aux!=0)
					aux = aux->siguiente;
				col = col->siguiente;
			}
			fil = fil->abajo;
		}
}

Nodo_AVL* Matriz::rentarActivo(string ID)
{
	Nodo* col;
	Nodo* fil = cabecera->abajo;
	Nodo* prim;
	Nodo* aux;
	while (fil != 0)
	{
		col = cabecera->siguiente;
		aux = fil->siguiente;
		while (col != 0)
		{
			prim = aux;
			while (prim != 0)
			{
				prim->usuario->arbolito->buscarID(ID, prim->usuario->arbolito->raiz_);
				if (prim->usuario->arbolito->auxi!=0)
				{
					dep_ = prim->usuario->getDepartamento();
					emp_ = prim->usuario->getEmpresa();
					user_ = prim->usuario->getUser();
					return prim->usuario->arbolito->auxi;
				}
				prim = prim->atras;
			}
			if (aux != 0)
				aux = aux->siguiente;
			col = col->siguiente;
		}
		fil = fil->abajo;
	}
	return 0;
}