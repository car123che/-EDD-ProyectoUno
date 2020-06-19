#pragma once
#include <iostream>
class Transaccion
{
public:
	Transaccion()
	{
		IDTransaccion = "";
		IDActivo = "";
		usuario = "";
		departmaneto = "";
		empresa = "";
		fecha = "";
		tiempo = 0;
	}
	Transaccion(std::string IDT, std::string IDA, std::string usu, std::string depa, std::string emp, std::string fech, int time)
	{
		IDTransaccion = IDT;
		IDActivo = IDA;
		usuario = usu;
		departmaneto = depa;
		empresa = emp;
		fecha = fech;
		tiempo = time;
	}

	std::string IDTransaccion, IDActivo, usuario, departmaneto, empresa, fecha;
	int tiempo;
};

