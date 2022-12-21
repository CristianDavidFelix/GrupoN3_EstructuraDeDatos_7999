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
#include <stdlib.h>
#include <windows.h>
#include "Node.h"
#define TABLE_SIZE 10 // Tamaño de la tabla hash


using namespace std;

class List
{
private:
    Node* first_node;
    Node* last_node;
    Node* hashTable[TABLE_SIZE];
    int hashFunction(int data);
public:
    List();

    List(Node*, Node*);

    Node* getFirstNode();

    Node* getLastNode();

    void setFirstNode(Node*);

    void setLastNode(Node*);

    bool verify(List*);

    Node* createNode(int);

    List* add_at_the_end(List*, int);

    List* add_to_start(List*, int);

    void print(List*);

    List* deleteNode(List*);

    Node* searchDisorder(List*, int);

    void search(List*, int);

    List* addBefore(List*, int, int);

    List* addAfter(List*, int, int);

    int size_List(List*);

    List* deleteLast(List*);

    List* delete_X_node(List*, int);

    void operations(List*);

    List* delete_after_to(List*);

    List* delete_before_to(List*);

    void MaximComunDivisor(List* List_);

    void MinimComunMult(List* List_);

    void sum_digits(List* List_);

    void binary_search(List* List_);

    void sort(List* List_);

    Node* binarySearch(Node* , int , int&);

    void sequential_search(List* List_);

    Node* sequentialSearch(Node* , int );

    Node* hashSearch(int data);

    void hash_search(List* List_);

    void hashInsert(int data);

    void hash_insert_all(List* List_);
};
