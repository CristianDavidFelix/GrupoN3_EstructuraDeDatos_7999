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
