#pragma once
#include "Nodo.h"
typedef Nodo* pnodo;
class ListaSimple
{
public:
	ListaSimple() : plista(NULL) {}
	bool ListaVacia() {
		return plista == NULL;
	}
	void buscar(int num);
	void eliminar(int num);
	void ingreso();
	void insertar(int);
	void imprimir();
	void imprimirHash();
	void ordenar();
	void Siguiente();
	void Anterior();
	void Primero();
	void Ultimo();
	void busquedaBinaria(int);
	int elementoCentral(int);
	int numelementos();
private:
	
	pnodo plista;
};




