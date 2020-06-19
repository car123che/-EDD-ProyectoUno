#include "pch.h"
#include "Activo.h"
#include <iostream>

std::string Activo::getNombre()
{
	return nombre;
}


std::string Activo::getDescripcion()
{
	return descripcion;
}

std::string Activo::getID()
{
	return ID;
}

void Activo::setNombre(std::string nombre_) {
	nombre = nombre_;
}

void Activo::setDescripcion(std::string descripcion_)
{
	descripcion = descripcion_;
}

void Activo::setID(std::string ID_)
{
	ID = ID_;
}
