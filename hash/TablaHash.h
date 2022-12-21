	/*	UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
			DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION
		    INGENIERA DE SOFTWARE
		                
			AUTORES:    Luca Manuel de Veintemilla - lmde2@espe.edu.ec
						Kevin Alexander Vargas - kavargas7@espe.edu.ec
						#Grupo 12
			FECHA DE CREACION:        27-06-2022 	
			FECHA DE MODIFICACION:    27-06-2022*/
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