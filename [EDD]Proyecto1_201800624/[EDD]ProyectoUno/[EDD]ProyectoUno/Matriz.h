#pragma once
#include "Nodo.h"
#include <iostream>
#include "Usuario.h"
#include "Nodo_AVL.h"
#include <string>
using namespace std;
class Matriz
{
	Usuario *admin = new Usuario("admin", "admin", "", "", "ADMIN");
public:
	Nodo *cabecera;
	Matriz()
	{
		cabecera = new Nodo("admin", -1, admin);
	}
	void insertarElemento(string usuario, int numero, string empresa, string departamento, Usuario *user);
	Nodo *crearEmpresa(string departamento);
	Nodo *crearDepartamento(string empresa);
	Nodo *buscarEmpresa(string empresa, Nodo *inicio);
	Nodo *buscarDepa(string departamento, Nodo *inicio);
	bool verificarEmpresa(string empresa, Nodo *inicio, Nodo *USER);
	bool verificarDepa(string departamento, Nodo *inicio, Nodo *USER);
	void graficar();
	Nodo *buscarUsuario(string usuario, string password, string departamento, string empresa);
	Nodo *buscarUsuario(string usuario, string departamento, string empresa);
	void graficarDepa(Nodo* depa);
	void graficarEmp(Nodo* emp);
	void imprimirActivos(Usuario* mio);
	Nodo_AVL* rentarActivo(string ID);
	string emp_, dep_, user_;
};

