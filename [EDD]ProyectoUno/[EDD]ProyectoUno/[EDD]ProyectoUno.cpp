#include "pch.h"
#include <iostream>
#include "Matriz.h"
#include "Usuario.h"
#include <conio.h>
#include <stdlib.h>
#include "ListaSimpleT.h"
using namespace std;

int main()
{
	Usuario *u1 = new Usuario("mynor", "mynor", "max", "Guatemala", "123");
	Usuario *u2 = new Usuario("susan", "susan", "hp", "jutiapa", "123");
	Usuario *u3 = new Usuario("susel", "susel", "hp", "jalapa", "123");
	Usuario *u4 = new Usuario("roxana", "roxana", "walmart", "jalapa", "123");
	Usuario *u5 = new Usuario("sebas", "sebas", "walmart", "jalapa", "123");
	Usuario *u6 = new Usuario("andrea", "andrea", "walmart", "jalapa", "123");
	Usuario *u7 = new Usuario("andres", "andres", "hp", "Guatemala", "123");
	Usuario *u8 = new Usuario("willy", "willy", "max", "jalapa", "123");
	cout << "Hello world!" << endl;
	Matriz *m = new Matriz();
	m->insertarElemento("mynor", 1, "max", "Guatemala", u1);//
	m->insertarElemento("susan", 2, "hp", "jutiapa", u2);//
	m->insertarElemento("susel", 3, "hp", "jalapa", u3);//
	m->insertarElemento("roxana", 4, "walmart", "jalapa", u4);
	m->insertarElemento("sebas", 6, "walmart", "jalapa", u5);
	m->insertarElemento("andrea", 5, "walmart", "jalapa", u6);
	m->insertarElemento("andres", 7, "hp", "Guatemala", u7);//
	m->insertarElemento("willy", 8, "max", "jalapa", u8);//
	cout << "H";
	m->graficar();
	cout << "A";



	system("pause");
	return 0;
}
