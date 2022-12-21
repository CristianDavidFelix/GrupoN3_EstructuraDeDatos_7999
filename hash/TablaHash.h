	/*	UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
			DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION
		    INGENIERA DE SOFTWARE
		                
			AUTORES:   Sebastian Paucar 
					   Matthew Salazar
					   Danilo Widinson
					   Sebastian Solano 
					   Cristian Felix 
			FECHA DE CREACION:        20-12-2022 	
			FECHA DE MODIFICACION:    21-12-2022*/
#pragma once 
#pragma once 
#include <iostream>
#include "Nodo.h"
#include "Nodo.cpp"

class TablaHashAbierto{
    private:
        NodoCircular **tabla;
    public:
        TablaHashAbierto();
        ~TablaHashAbierto();
        void insertar(string cad);
        void eliminar(string cad);
        void buscar(string cad);
        void imprimir();
        int hash(string cad);     
};