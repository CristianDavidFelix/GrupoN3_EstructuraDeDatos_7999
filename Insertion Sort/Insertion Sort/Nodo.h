#pragma once
#include "Librerias.h"
#ifndef NULL
#define NULL 0
#endif 

class Nodo
{
public:
	Nodo(int, Nodo*,Nodo*);
	~Nodo();
	friend class ListaSimple;
private:
	int valor;
	Nodo* siguiente;
	Nodo* anterior;
};
