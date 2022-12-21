
#include <iostream>
#include "Nodo.h"
#include "Nodo.cpp"
#include "TablaHash.cpp"

using namespace std;

TablaHashAbierto tabla;

int main()
{

    string cad, opcion;
    int op;
    do
    {
        system("cls");
        cout << "[1] Insertar String" << endl;
        cout << "[2] Insertar Entero" << endl;
        cout << "[3] Eliminar" << endl;
        cout << "[4] Buscar" << endl;
        cout << "[5] Mostrar" << endl;
        cout << "[6] Salir" << endl;
        cout << "Ingrese una opcion: ";
        cin >> op;
        switch (op)
        {
        case 1:
        	do
            {
                cout << "Ingrese una letra" << endl;
                cin >> cad;
                tabla.insertar(cad);
                cout << "Desea ingresar otra letra? (s/n)" << endl;
                cin >> opcion;
            } while (opcion == "s");
            break;
           
        case 2:
			 do
            {
             cout << "Ingrese un numero: " << endl;
             cin >> cad;
        	tabla.insertar(cad);
             cout << "Desea ingresar otro numero? (s/n): " << endl;
             cin >> opcion;
            } while (opcion == "s");
            cout << "Tabla hash cerrada: " << endl;
            tabla.imprimir();
            break;
        case 3:
            cout << "Ingrese el elemento a eliminar" << endl;
            cin >> cad;
            tabla.eliminar(cad);
            system("pause");
            break;
        case 4:
            cout << "Ingrese el elemento a buscar" << endl;
            cin >> cad;
            tabla.buscar(cad);
            system("pause");
            break;
        case 5:
            cout << "Tabla Hash Abierta: \n";
            tabla.imprimir();
            system("pause");
            break;
        default:
            cout << "Opcion no valida" << endl;
            break;
        }
    } while (opcion != "6");

    return 0;
}