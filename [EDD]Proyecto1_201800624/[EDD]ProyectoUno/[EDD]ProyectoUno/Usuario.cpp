#include "pch.h"
#include "Usuario.h"

string Usuario::getUser()
{
	return user;
}
string Usuario::getPassword()
{
	return password;
}
string Usuario::getDepartamento()
{
	return departamento;
}
string Usuario::getEmpresa()
{
	return empresa;
}
string Usuario::getName()
{
	return name;
}
void Usuario::setName(string name_)
{
	name = name_;
}
void Usuario::setUser(string user_)
{
	user = user_;
}
void Usuario::setPassword(string passwrod_)
{
	password = passwrod_;
}
void Usuario::setDepartamento(string departamento_)
{
	departamento = departamento_;
}
void Usuario::setEmpresa(string empresa_)
{
	empresa = empresa_;
}

