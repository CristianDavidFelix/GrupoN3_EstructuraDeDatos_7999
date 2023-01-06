// Insertion Sort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#define TAM 13
#include "hash.cpp"

int main()
{
	ListaSimple lista;
	TablaDispersa tabla;
	char* dato = new char[10];
	int datoInt=0;
	int opcion;
	do
	{
		std::cout << "Menu de opciones" << std::endl;
		std::cout << "\n1. Ingresar datos" << std::endl;
		std::cout << "\n2. Imprimir datos" << std::endl;
		std::cout << "\n3. Buscar datos" << std::endl;
		std::cout << "\n5. Salir" << std::endl;

		opcion = ingresarDatoint("Ingrese la opcion:");
		switch (opcion)
		{
		case 1:
			system("cls");
			tabla.insertar(&lista);
			system("pause");
			fflush(stdin);
			break;
		case 2:
			system("cls");
			tabla.imprimir();
			lista.imprimir();
			system("pause");
			fflush(stdin);
			break;
		case 3:
			system("cls");
			
			lista.imprimir();
			lista.ordenar();
			lista.imprimir();
			fflush(stdin);
			dato = ingresarDato("Ingrese el numero a buscar : ");
			datoInt = atoi(dato);
			tabla.buscar(dato);
			lista.busquedaBinaria(datoInt);
			system("pause");
			break;
		case 4:
			dato = ingresarDato("Ingrese el numero a Eliminar : ");
			datoInt = atoi(dato);
			lista.eliminar(datoInt);
			lista.imprimir();
			//tabla.eliminar(dato);
			//tabla.imprimir();
			system("pause");
			break;
		case 5:
			break;
		default:
			std::cout << "Opcion no valida";
			break;
		}
		system("cls");
	} while (opcion != 5);
}
	




