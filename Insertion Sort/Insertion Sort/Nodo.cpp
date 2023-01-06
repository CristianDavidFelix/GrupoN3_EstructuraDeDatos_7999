#include "Nodo.h"

Nodo::Nodo(int valor, Nodo* siguiente = NULL, Nodo* anterior = NULL)
{
	this->valor = valor;
	this->siguiente = siguiente;
	this->anterior = anterior;
}
Nodo::~Nodo()
{
}

	