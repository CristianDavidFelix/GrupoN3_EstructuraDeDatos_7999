#include <iostream>
#include "Node.h"

using namespace std;
/**
 * @brief Metodo constructor de Node con sus atributos inicializados NULL
 *
 *
 */
Node::Node()
{
    data = NULL;
    next = NULL;
}

/**
 * @brief Metodo constructor de Node
 * @param data_ valor que almacena el nodo
 * @param *next el puntero del nodo
 *
 */

Node::Node(int data_, Node* next_) {
    data = data_;
    next = next_;
}
/**
 * @brief metod getter del dato almacenado en el nodo
 *
 *
 */

int Node::getData()
{
    return data;
}

/**
 * @brief metod getter del puntero correspondiente al nodo
 *
 *
 */

Node* Node::getNext()
{
    return next;
}

/**
 * @brief metod setter del dato almacenado en el nodo
 *
 *
 */
void Node::setData(int data_)
{
    data = data_;
}

/**
 * @brief metod setter del puntero almacenado en el nodo
 *
 *
 */
void Node::setNext(Node* next_)
{
    next = next_;
}