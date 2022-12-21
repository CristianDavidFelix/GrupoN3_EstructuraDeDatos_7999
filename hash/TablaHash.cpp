
#pragma once 
#include <iostream>
#include "Nodo.h"
#include "Nodo.cpp"
#include <cstring>
#include "TablaHash.h"
#define nroCasillas 2

TablaHashAbierto::TablaHashAbierto(){
    tabla = new NodoCircular*[nroCasillas];
    for(int i = 0; i < nroCasillas; i++){
        tabla[i] = NULL;
    }
}

TablaHashAbierto::~TablaHashAbierto(){
    for(int i = 0; i < nroCasillas; i++){
        NodoCircular *aux = tabla[i];
        aux = tabla[i];
        while(aux != NULL){
            tabla[i] = tabla[i]->getSig();
            delete(aux);
            aux = tabla[i];
        }
    }
    delete[] tabla;
}

void TablaHashAbierto::insertar(string cad){
    int pos = hash(cad);
    NodoCircular *aux = tabla[pos];
    if(tabla[pos] == NULL){
        tabla[pos] = new NodoCircular(cad);
    }
    else{
        aux = tabla[pos];
        while(aux->getSig() != NULL){
            aux = aux->getSig();
        }
        aux->setSig(new NodoCircular(cad));
    }
}
void TablaHashAbierto::eliminar(string cad){
    int pos = hash(cad);
    NodoCircular *aux = tabla[pos];
    if(aux->getCadena() == cad){
        cout<<"El elemento se ha eliminado"<< pos;
        delete(tabla[pos]);
        tabla[pos] = tabla[pos]->getSig();
    }else{
        cout<<"No se ha encontrado el elemento";
    }
}
void TablaHashAbierto::imprimir(){
    for(int i = 0; i < nroCasillas; i++){
        NodoCircular *aux = tabla[i];
        aux = tabla[i];
        while(aux != NULL){
            cout << i <<"<-"<<aux->getCadena() <<" ";
            aux = aux->getSig();
        }
        cout << endl;
    }
}

void TablaHashAbierto::buscar(string cad){
    int pos = hash(cad);
    NodoCircular *aux = tabla[pos];
    if(aux->getCadena() == cad){
        cout<<"Elemento encontado en la posiscion  "<< pos;
        tabla[pos] = tabla[pos]->getSig();
    }else{
        cout<<"No se ha encontrado el elemento";
    }
}

int TablaHashAbierto::hash(string cad){
    int suma = 0;
    for(int i = 0; i < cad.length(); i++){
        suma += cad[i];
    }
    return suma % nroCasillas;
}