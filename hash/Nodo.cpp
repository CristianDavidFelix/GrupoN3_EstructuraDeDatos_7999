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
#include <iostream>
#include <cstring>
#include <cstdlib>
#include "Nodo.h"

using namespace std;

NodoCircular :: NodoCircular(string cad){
    cadena = cad;
    sig = NULL;
}
NodoCircular :: ~NodoCircular(){
    delete sig;
}
string NodoCircular :: getCadena(){
    return cadena;
}
NodoCircular *NodoCircular :: getSig(){
    return sig;
}
void NodoCircular :: setSig(NodoCircular *sig){
    this->sig = sig;
}