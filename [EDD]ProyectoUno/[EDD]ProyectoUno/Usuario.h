#pragma once
#include <iostream>
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

protected:

private:
	std::string name, user, password, empresa, departamento;
};
