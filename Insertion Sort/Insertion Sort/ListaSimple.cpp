#include "ListaSimple.h"
void ListaSimple::insertar(int num)
{
	Nodo* nuevo = new Nodo(num, NULL, NULL);
	Primero();
	// Si la lista está vacía
	if (ListaVacia()) {
		if (!plista) plista = nuevo;
		else plista->anterior = nuevo;
	}
	else {
		while (plista->siguiente) Siguiente();
		nuevo = new Nodo(num, plista->siguiente, plista);
		plista->siguiente = nuevo;
		if (nuevo->siguiente) nuevo->siguiente->anterior = nuevo;
	}
}
void ListaSimple::imprimirHash()
{
	Nodo* aux = plista;
	while (aux && aux->anterior) aux = aux->anterior;
	while (aux) {
		std::cout << aux->valor << " ";
		aux = aux->siguiente;
	}
}
void ListaSimple::imprimir()
{
	Nodo* aux = plista;
	while (aux && aux->anterior) aux = aux->anterior;
	std::cout << "\n\nLista Doble";
	while (aux) {
		std::cout <<"\n" << aux->valor << " ";
		aux = aux->siguiente;
	}
	std::cout << std::endl;

}
void ListaSimple::buscar(int num) {
	Primero();
	while (plista) {
		if (plista->valor == num) {
			std::cout << "\nEl numero " << num << " se encuentra en la lista" << std::endl;
			return;
		}
		Siguiente();
	}
	std::cout << "\nEl numero " << num << " no se encuentra en la lista" << std::endl;	
}
void ListaSimple::ordenar()
{
	Nodo* aux = plista;
	Nodo* aux2 = plista;
	int temp=0;
	while (aux && aux->anterior) aux = aux->anterior;
	while (aux2 && aux2->anterior) aux2 = aux2->anterior;
	while (aux)
	{
		aux2 = aux->siguiente;
		while (aux2)
		{
			if (aux->valor > aux2->valor)
			{
				temp = aux->valor;
				aux->valor = aux2->valor;
				aux2->valor = temp;
			}
			aux2 = aux2->siguiente;
		}	
		aux = aux->siguiente;
	}
}
void ListaSimple::eliminar(int num)
{
	Primero();
	while (plista) {
		if (plista->valor == num) {
			if (plista->anterior == NULL) {
				plista = plista->siguiente;
				plista->anterior = NULL;
				break;
			}
			else if (plista->siguiente == NULL) {
				plista = plista->anterior;
				plista->siguiente = NULL;
				break;
			}
			if (plista->anterior != NULL) {
				plista->anterior->siguiente = plista->siguiente;
				plista->siguiente->anterior = plista->anterior;
				break;
			}
		}
		else Siguiente();
	}
}
//void ListaSimple::ordenar()
//{
//	Nodo* aux = plista;
//	Nodo* aux2 = plista;
//	int temp;
//	while (aux && aux->anterior) aux = aux->anterior;
//	while (aux2 && aux2->anterior) aux2 = aux2->anterior;
//	//while (aux2 && aux2->siguiente) aux2 = aux2->siguiente;
//	while (aux)
//	{
//		aux2 = aux->siguiente;
//		temp = aux->valor;
//
//		while (aux2 && aux->valor>aux2->valor)
//		{
//			
//			aux->valor = aux2->valor;
//			aux2->valor = temp;
//			aux2 = aux2->siguiente;
//		}
//		aux = aux->siguiente;
//	}
//	
//
//}
void ListaSimple::ingreso()
{
	int num;
	std::cout << "Ingrese un numero: ";
	std::cin >> num;
	while (num != 0)
	{
		insertar(num);
		std::cout << "Ingrese un numero: ";
		std::cin >> num;
	}
}
void ListaSimple::Siguiente()
{
	if (plista) plista = plista->siguiente;
}
void ListaSimple::Anterior()
{
	if (plista) plista = plista->anterior;
}
void ListaSimple::Primero()
{
	while (plista && plista->anterior) plista = plista->anterior;
}
void ListaSimple::Ultimo()
{
	while (plista && plista->siguiente) plista = plista->siguiente;
}
/* @param num: numero a buscar
	* @return: posicion del numero en la lista
*/
void ListaSimple::busquedaBinaria(int valorBuscar) {
	//determinar si el valor a buscar es mayor o menor al valor central
	int inf, sup, mitad, dato;
	int valorlista = 0;
	bool flag=false;
	inf = 0;
	dato = 0;
	sup = numelementos();
	if (plista != NULL)
	{
		//std::cout << "Ingrese el valor a buscar: ";
		//std::cin >> valorBuscar;
		fflush(stdin);
	while (sup!=(inf-1))
	{
		mitad = (inf + sup) / 2;
		valorlista = elementoCentral(mitad);
		if (valorlista == valorBuscar)
		{
			flag = true;
			break;
		}
		if (valorlista > valorBuscar )sup = mitad;
		if (valorlista < valorBuscar)inf = mitad;
	}
	if (flag)std::cout << "\nEl valor fue encontrado en la posicion: " << mitad << std::endl;
	else std::cout << "\nEl valor no fue encontrado" << std::endl; {
		bool flag = false;
		inf = 0;
		dato = 0;
	}
	}
	else {
		std::cout << "\nLista Vacia\n";
		return;
	}
}
int ListaSimple::elementoCentral(int elemento) {
	Nodo* aux = plista;
	aux = plista;
	int valorCentral = 0;
	int i = 0;
	while (aux && aux->anterior) aux = aux->anterior;
	for (int i = 0; i < elemento; i++)
	{
		aux = aux->siguiente;
	}
	valorCentral = aux->valor;
	return valorCentral;
}
int ListaSimple::numelementos()
{
	int numElementos = 0;
	Nodo* aux = plista;
	while (aux && aux->anterior) aux = aux->anterior;
	while (aux)
	{
		numElementos++;
		aux = aux->siguiente;
	}
	return numElementos;
}
