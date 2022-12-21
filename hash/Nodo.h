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