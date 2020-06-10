#include "pch.h"
#include <iostream>
#include "Matriz.h"
#include "Usuario.h"
#include <stdlib.h>
#include <string>
using namespace std;

void logIn();
void menuAdmin();
void agregarUsuario();//1
void reporteMatriz();//2
void reporteActivosDepa();//3
void reporteActivosEmp();//4
void reporteTransacciones();//5
void activosUsuario();//6
void activosRentadosUsuario();//7
void ordenarTransacciones();//8

Matriz *m = new Matriz();

int main()
{
	/*Usuario *u1 = new Usuario("mynor", "mynor", "max", "Guatemala", "123");
	Usuario *u2 = new Usuario("susan", "susan", "hp", "jutiapa", "123");
	Usuario *u3 = new Usuario("susel", "susel", "hp", "jalapa", "123");
	Usuario *u4 = new Usuario("roxana", "roxana", "walmart", "jalapa", "123");
	Usuario *u5 = new Usuario("sebas", "sebas", "walmart", "jalapa", "123");
	Usuario *u6 = new Usuario("andrea", "andrea", "walmart", "jalapa", "123");
	Usuario *u7 = new Usuario("andres", "andres", "hp", "Guatemala", "123");
	Usuario *u8 = new Usuario("willy", "willy", "max", "jalapa", "123");
	cout << "Hello world!" << endl;
	
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
	cout << "A";*/
	logIn();


	system("pause");
	return 0;
}

//LogIn de la app, da acceso al administrador o usuario dependientod de los datos ingresados
void logIn()
{
	bool ingreso = true;
	char user_[30], password_[30], depa_[30], emp_[30];
	string user, password, depa, emp;
	do {
		system("cls");
		cout << "********************RENTA DE ACTIVOS********************\n\n";
		cout << "___Ingresar Usuario___: ";
		cin.getline(user_, 30, '\n');
		user += user_;
		cout << "__Ingresar Contrasena__: ";
		cin.getline(password_, 30, '\n');
		password += password_;
		if (user == "admin" && password == "admin")
		{
			ingreso = false;
			menuAdmin();
		}
		else
		{
			cout << "__Ingresar Departamento__: ";
			cin.getline(depa_, 30, '\n');
			depa += depa_;
			cout << "__Ingresar Empresa__: ";
			cin.getline(emp_, 30, '\n');
			emp += emp_;
		}
		
	} while (ingreso);
}

//Despliega el menu principal del Administrador
void menuAdmin() {
	int opcion;
	do {
		system("cls");
		cout << "***************BIENVENIDO ADMINISTRADOR***************\n\n";
		cout << "**1. Registrar Usuario" << endl;
		cout << "**2. Reporte Matriz Dispersa" << endl;
		cout << "**3. Reporte Activos disponibles de un Departamento" << endl;
		cout << "**4. Reporte Activos disponibles de una Empresa" << endl;
		cout << "**5. Reporte Transacciones" << endl;
		cout << "**6. Reporte Activos de un Usuario" << endl;
		cout << "**7. Activos Rentados por un Usuario" << endl;
		cout << "**8. Ordenar Transacciones" << endl;
		cout << "**9. Salir" << endl;
		cin >> opcion;

		switch (opcion)
		{
			case 1: 
			{
				void agregarUsuario();
				break;
			}

			case 2:
			{
				void reporteMatriz();
				break;
			}

			case 3:
			{
				void reporteActivosDepa();
				break;
			}

			case 4:
			{
				void reporteActivosEmp();
				break;
			}

			case 5:
			{
				void reporteTransacciones();
				break;
			}

			case 6:
			{
				void activosUsuario();
				break;
			}

			case 7:
			{
				void activosRentadosUsuario();
				break;
			}

			case 8:
			{
				void ordenarTransacciones();
				break;
			}
		}
	} while (opcion != 9);
}

//Opcion uno del administrador, Agregar Usuarios
void agregarUsuario() {

}

//Opcion dos del administrador, ver matriz de usuarios
void reporteMatriz()

{

} 

//Opcion tres del administrador, ver activos disponibles de un Departamento
void reporteActivosDepa()
{

}

//Opcion cuatro del administrador, ver activos disponibles de una Empresa
void reporteActivosEmp()
{


}

//Opcion cinco del administrador, reporte Transacciones
void reporteTransacciones()
{


}

//Opcion seis del administrador, reporte activos de un usuario
void activosUsuario()

{

}

//Opcion siete del administrador, reporte de activos rentados por un usuario
void activosRentadosUsuario()
{

}

//Opcion ocho del administrador, ordenar Transacciones
void ordenarTransacciones()
{

}