#include <iostream>
#include "Menu.h"
#include "OnlyNumbers_Validation.h"

using namespace std;

/**
 * @brief Menu de options del programa utilizando el teclado para desplazarse
 * @param options Arreglo de mensajes para mostrar en pantalla las options
 * @param number Numero de options
 * @param size tamanio del menu
 *
 */
int Menu::menu(string options[], string order, int number, int size, List *list)
{
    int cursor = 0;
    char key;
    int option;
    system("cls");
    for (;;)
    {
        system("cls");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
        cout << order << endl;
        for (int i = 0; i < number; i++)
        {
            if (cursor == i)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
                cout << "\t\t> " << options[i] << endl;
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
            }
            else
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
                cout << "\t\t" << options[i] << endl;
            }
        }
        for (;;)
        {
            key = _getch();
            if (key == 80)
            {
                cursor++;
                if (cursor == number)
                {
                    cursor = 0;
                }
                break;
            }
            if (key == 72)
            {
                cursor--;
                if (cursor == -1)
                {
                    cursor = number - 1;
                }
                break;
            }
            if (key == 13)
            {
                return cursor;
            }
        }
    }
}

/**
 * @brief Menu para seleccion de options
 * @param options Arreglo de mensajes para mostrar en pantalla las options
 * @param number Numero de options
 * @param size tamanio del menu
 */
void Menu::menu_keyboard(string options[], int number, int size, List *list_)
{
    string order = "\t\t    LISTAS SIMPLES!\n";
    int cursor = menu(options, order, number, size, list_);
    int value = 0, node_position = 0;
    char ar_nums[5];
    OnlyNumbers_Validation obj_validate;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    switch (cursor)
    {
    case 0: // Agregar nodo al inicio
        system("cls");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
        cout << "\n\t\tAgregar nodo al inicio\n"
             << endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        cout << "\t   Ingrese el numero: ";
        obj_validate.natural_numbers(ar_nums);
        value = atoi(ar_nums);
        cout << endl;
        // cin >> value;
        list_ = list_->add_to_start(list_, value);
        cout << endl;
        system("pause");
        menu_keyboard(options, number, size, list_);
        break;

    case 1: // Agregar nodo al final
        system("cls");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
        cout << "\n\t\tAgregar nodo al final\n"
             << endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        cout << "\t   Ingrese el numero: ";
        // cin >> value;
        obj_validate.natural_numbers(ar_nums);
        value = atoi(ar_nums);
        cout << endl;
        list_ = list_->add_at_the_end(list_, value);
        cout << endl;
        system("pause");
        menu_keyboard(options, number, size, list_);
        break;

    case 2: // Agregar nodo antes de un nodo
        system("cls");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
        cout << "\n\t\tAgregar antes de un nodo\n"
             << endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        list_->print(list_);
        cout << endl;
        if (list_->getFirstNode() != NULL)
        {
            cout << "\t   Ingrese el dato: ";
            // cin >> value;
            obj_validate.natural_numbers(ar_nums);
            value = atoi(ar_nums);
            cout << endl;
            cout << "\t   Ingresar antes del nodo N: ";
            // cin >> node_position;
            obj_validate.natural_numbers(ar_nums);
            node_position = atoi(ar_nums);
            cout << endl;
        }
        else
        {
            cout << "\t   Ingrese el dato: ";
            obj_validate.natural_numbers(ar_nums);
            value = atoi(ar_nums);
            cout << endl;
            // cin >> value;
            node_position = 0;
        }
        list_ = list_->addBefore(list_, value, node_position - 1);
        cout << endl;
        system("pause");
        menu_keyboard(options, number, size, list_);
        break;

    case 3: // Agregar nodo despues de un nodo
        system("cls");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
        cout << "\n\t\tAgregar despues de un nodo\n"
             << endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        list_->print(list_);
        cout << endl;
        if (list_->getFirstNode() != NULL)
        {
            cout << "\t   Ingrese el dato: ";
            // cin >> value;
            obj_validate.natural_numbers(ar_nums);
            value = atoi(ar_nums);
            cout << endl;
            cout << "\t   Ingresar despues del nodo N: ";
            cin >> node_position;
        }
        else
        {
            cout << "\t   Ingrese el dato: ";
            // cin >> value;
            obj_validate.natural_numbers(ar_nums);
            value = atoi(ar_nums);
            cout << endl;
            node_position = 0;
        }
        list_ = list_->addAfter(list_, value, node_position);
        cout << endl;
        system("pause");
        menu_keyboard(options, number, size, list_);
        break;

    case 4: // Eliminar primer nodo
        system("cls");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
        cout << "\n\t\tEliminar primer nodo\n"
             << endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        list_ = list_->deleteNode(list_);
        cout << endl;
        system("pause");
        menu_keyboard(options, number, size, list_);
        break;

    case 5: // Eliminar ultimo nodo
        system("cls");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
        cout << "\n\t\tEliminar ultimo nodo\n"
             << endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        list_ = list_->deleteLast(list_);
        cout << endl;
        system("pause");
        menu_keyboard(options, number, size, list_);
        break;

    case 6: // Eliminar un nodo X
        system("cls");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
        cout << "\n\t\tEliminar un nodo X\n"
             << endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        list_->print(list_);
        cout << endl;
        if (list_->getFirstNode() != NULL)
        {
            cout << "\t Ingrese el nodo a eliminar: ";
            // cin >> value;
            obj_validate.natural_numbers(ar_nums);
            value = atoi(ar_nums);
            cout << endl;
            list_ = list_->delete_X_node(list_, value);
        }
        cout << endl;
        system("pause");
        menu_keyboard(options, number, size, list_);
        break;

    case 7: // Eliminar antes de un nodo
        system("cls");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
        cout << "\n\t\tEliminar antes de un nodo\n"
             << endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        list_ = list_->delete_before_to(list_);
        cout << endl;
        system("pause");
        menu_keyboard(options, number, size, list_);
        break;

    case 8: // Eliminar despues de un nodo
        system("cls");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
        cout << "\n\t\tEliminar despues de un nodo\n"
             << endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        list_ = list_->delete_after_to(list_);
        cout << endl;
        system("pause");
        menu_keyboard(options, number, size, list_);
        break;

    case 9: // Buscar un nodo X
        system("cls");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
        cout << "\n\t\tBuscar un nodo\n"
             << endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        cout << "\t Ingrese el numero a buscar: ";
        // cin >> value;
        obj_validate.natural_numbers(ar_nums);
        value = atoi(ar_nums);
        cout << endl;
        list_->search(list_, value);
        system("pause");
        menu_keyboard(options, number, size, list_);
        break;

    case 10: // Imprimir
        system("cls");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
        cout << "\n\t\t  LISTA " << endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        list_->print(list_);
        cout << endl;
        system("pause");
        menu_keyboard(options, number, size, list_);
        break;

    case 11: // Operaciones
        system("cls");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
        cout << "\n\t\t  LISTA " << endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        list_->operations(list_);
        cout << endl;
        system("pause");
        menu_keyboard(options, number, size, list_);
        break;

    case 12: // calculo MaximComunDivisor
        system("cls");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
         SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
         list_->binary_search(list_);
        cout << endl;
        system("pause");
        menu_keyboard(options, number, size, list_);
        break;
        
        /*
        system("cls");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
        cout << "\n\t\t  LISTA " << endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        list_->MaximComunDivisor(list_);
        cout << endl;
        system("pause");
        menu_keyboard(options, number, size, list_);
        break;
*/
    case 13: // suma de los elementos de la lista
        system("cls");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        list_->sequential_search(list_);
        cout << endl;
        system("pause");
        menu_keyboard(options, number, size, list_);
        break;
        /*
        system("cls");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
        cout << "\n\t\t  LISTA " << endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        list_->sum_digits(list_);
        cout << endl;
        system("pause");
        menu_keyboard(options, number, size, list_);
        break;
        */

    case 14: // least common multiple
        system("cls");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        list_->hash_search(list_);
        cout << endl;
        system("pause");
        menu_keyboard(options, number, size, list_);
        break;
         /*
        system("cls");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
        cout << "\n\t\t  LISTA " << endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        list_->MinimComunMult(list_);
        cout << endl;
        system("pause");
        menu_keyboard(options, number, size, list_);
        break;
         */

    case 15: // Cerrar el Programa
        system("cls");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
        cout << "\n\t\t...Gracias por usar mi programa...\n"
             << endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        system("pause");
        exit(1);
        break;
    }
}