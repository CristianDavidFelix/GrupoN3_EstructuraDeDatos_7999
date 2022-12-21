/*	UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
			DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION
			INGENIERA DE SOFTWARE

			AUTORES:   Sebastian Paucar
					   Matthew Salazar
					   Danilo Widinson
					   Sebastian Solano
					   Cristian Felix
			FECHA DE CREACION:        20-12-2022
			FECHA DE MODIFICACION:    21-12-2022*/

#pragma once
#include <iostream>
#include <windows.h>
#include <thread>
#define ARRIBA 'w'
#define ABAJO 's'
#define ENTER 13
/*
* @brief Clase Control que contiene el Menu del aplicativo
*/

class Control
{
public:
	/**
	  * @brief viewMenu Muestrael menu
	  * @param void
	  */
	static void viewMenu(void);//menu
	/**
	  * @brief gotoxy Mueve el cursor tipo flecha
	  * @param x, y Coordenadas de ubicacion de la flecha
	  */
	int gotoxy(USHORT x, USHORT y);
	/**
	  * @brief useMenu Despliega las opciones que contiene el Menu
	  * @param titulo, opciones Son los nombres de las opciones que contiene el Menu
	  */
	int useMenu(const char titulo[], const char* opciones[], int n);
	/**
	  * @brief onlyIntControl Valida los numeros enteros ingresados desde teclado
	  * @param char Solo admite numeros
	  */
	char* onlyIntControl(const char*);//validacion enteros
	/**
	  * @brief onlyCharControl Permite que el cursos se mueva de arriba hacia abajo
	  * @param void
	  */
	char onlyCharControl(void);//sube baja 

	static void marquesina();

	static void activar();

protected:
private:

};