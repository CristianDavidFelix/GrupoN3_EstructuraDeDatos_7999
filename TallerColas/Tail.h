#pragma once
#if !defined(__UML_Class_Diagram_2_List_h)//CAMBIAR ESO
#define __UML_Class_Diagram_2_List_h  ///CAMBIAR ESO

class Nodo;



class Tail
{
public:

	void push(double _value);
	void pop(void);
	void printTail(void);
	Nodo* getActual(void);
	void setActual(Nodo* newActual);
	Nodo* getFirst(void);
	void setFirst(Nodo* newFirst);
	int getTam();
	Tail();
	~Tail();

protected:
private:
	bool emplyTail(void);

	Nodo* first;
	Nodo* actual;
	int tam = 0;


};

#endif