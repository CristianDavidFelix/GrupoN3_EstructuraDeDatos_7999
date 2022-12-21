#include <iostream>
#include "Menu.h"

using namespace std;

int main()
{
    Menu objMenu;
    List *list = new List();
    int size = 0;
    string options[] = {
        "Insertar nodo al inicio",
        "Insertar nodo al final",
        "Insertar antes de un nodo",
        "Insertar despues de un nodo",
        "Eliminar primer nodo",
        "Eliminar ultimo nodo",
        "Eliminar nodo X",
        "Eliminar antes de un nodo",
        "Eliminar despues de un nodo",
        "Buscar nodo",
        "Imprimir lista",
        "Operaciones",
        //"Maximo comun divisor",
        "Busqueda binaria",
        //"Suma de digitos",
        "Busqueda secuencial",
        //"Minimo comun multiplo",
        "Busqueda por hash",
        
        "Salir",
    };
    objMenu.menu_keyboard(options, 15, size, list);
    system("pause");
    return 0;
}