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

class Node
{
private:
    int data;

    Node *next;

    int data_;

    Node *next_;

public:
    Node(int data) : data_(data), next_(NULL) {}

    Node();

    Node(int, Node *);

    int getData();

    Node *getNext();

    void setData(int);

    void setNext(Node *);
};
