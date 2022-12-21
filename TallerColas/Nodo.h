#pragma once
#include <cstddef>

/*Universidad de las Fuerzas Armadas "ESPE"
Software
Autores : Cantuna Michelle, Medina Martin, Perez Hamilton, Romero Jorge y Valarezo Andres
Taller
Fecha creacion : 13 / 06 / 2021
Fecha de modificacion : 21 / 06 / 2021 */

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