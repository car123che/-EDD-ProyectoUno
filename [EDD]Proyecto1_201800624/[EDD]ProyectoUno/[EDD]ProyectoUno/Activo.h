#pragma once
#include <iostream>

class Activo
{
public:
	Activo(std::string nombre_, std::string descripcion_, std::string ID_)
	{
		nombre = nombre_;
		descripcion = descripcion_;
		ID = ID_;
		rentado = false;
	}
	std::string getNombre();
	std::string getDescripcion();
	std::string getID();
	void setNombre(std::string nombre_);
	void setDescripcion(std::string descripcion_);
	void setID(std::string ID_);
	bool rentado;
private:
	std::string nombre, descripcion, ID;
};

