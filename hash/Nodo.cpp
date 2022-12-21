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