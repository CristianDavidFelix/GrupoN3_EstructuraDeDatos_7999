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
#include <conio.h>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "List.h"

#ifndef _MENU_H_
#define _MUNU_H_
using namespace std;

class Menu
{
public:
    int menu(string[], string, int, int, List*);
    void menu_keyboard(string[], int, int, List*);
};

#endif
