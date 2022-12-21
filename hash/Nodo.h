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

using namespace std;

class NodoCircular{
    private:
        string cadena;
        NodoCircular *sig;
    public:
        NodoCircular(string cad);
        ~NodoCircular();
        string getCadena();
        NodoCircular *getSig();
        void setSig(NodoCircular *sig);
};