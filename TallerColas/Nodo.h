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
#include <cstddef>


#if !defined(__UML_Class_Diagram_2_Nodo_h)
#define __UML_Class_Diagram_2_Nodo_h

class Nodo
{
public:
	~Nodo();
	double getDate(void);
	void setDate(double newDate);
	Nodo* getNext(void);
	void setNext(Nodo* newNext);
	Nodo(double value);


protected:
private:
	double date;
	Nodo* next;


};

#endif