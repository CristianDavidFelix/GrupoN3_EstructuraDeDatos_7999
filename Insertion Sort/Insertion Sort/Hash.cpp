#include "Hash.h"
#include "Validaciones.h"

//Tabla Hash
TablaDispersa::TablaDispersa() // constructor
{
	tabla = new ListaSimple * [TAM];
	for (int k = 0; k < TAM; k++)
		tabla[k] = new ListaSimple();
}
//Guarda el tamano del arreglo en NULL
int transformaClave(const char* clave, int tam) {
	int j;
	int d;
	d = 0;
	for (j = 0; j < strlen(clave); j++)
	{
		d = d * 27 + clave[j];
	}
	d = (int)(d % tam);
	return d;
}
void TablaDispersa::insertar(ListaSimple* lista)
{
	int pos;
	const char* opc;
	const char* valor;
	do
	{
		valor = ingresarDato("Ingrese el numero:");
		lista->insertar(atoi(valor));
		pos = transformaClave(valor, TAM);
		//combertir char a int
		tabla[pos]->insertar(atoi(valor));
		//tabla[pos].insertar(atoi(valor));
		opc = ingresarDatosChar("Desea ingresar otro dato? si/no");
	} while (strcmp(opc, "si") == 0);
}
void TablaDispersa::imprimir()
{
	if (tabla != NULL)
	{
		for (int i = 0; i < TAM; i++)
		{
			std::cout << "\nPosicion " << i << ": ";
			tabla[i]->imprimirHash();
		}
	}
	else
	{
		std::cout << "No hay datos para imprimir" << std::endl;
	}
}
void TablaDispersa::buscar(const char* valor)
{

	int pos = transformaClave(valor, TAM);
	tabla[pos]->buscar(atoi(valor));
}
void TablaDispersa::eliminar(const char* valor)
{
	int pos = transformaClave(valor, TAM);
	tabla[pos]->eliminar(atoi(valor));
}





