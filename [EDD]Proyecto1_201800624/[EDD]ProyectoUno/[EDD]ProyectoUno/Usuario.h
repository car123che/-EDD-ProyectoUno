#pragma once
#include <iostream>
#include "Arbol_AVL.h"
#include "ListaSimple.h"
using namespace std;
class Usuario
{
public:
	Usuario(string name_, string user_, string empresa_, string departamento_, string password_)
	{
		name = name_;
		user = user_;
		password = password_;
		empresa = empresa_;
		b = 0;
		departamento = departamento_;
	}
	string getName();
	string getUser();
	string getPassword();
	string getEmpresa();
	string getDepartamento();
	void setName(string name_);
	void setUser(string user_);
	void setPassword(string password_);
	void setEmpresa(string empresa_);
	void setDepartamento(string departamento_);
	Arbol_AVL *arbolito = new Arbol_AVL();
	ListaSimple* lista = new ListaSimple();
	int b;
protected:

private:
	std::string name, user, password, empresa, departamento;
	
};
