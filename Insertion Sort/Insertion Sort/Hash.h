#include "ListaSimple.h"
class TablaDispersa
{
protected:
	ListaSimple** tabla;
public:
	TablaDispersa(); // constructor
	void insertar(ListaSimple*);
	void buscar(const char*);
	void imprimir();
	void eliminar(const char*);

};
//class TablaDispersa {
//protected:
//	int final;
//	int numElementos;
//	Elemento** tabla;
//public:
//	TablaDispersa(int n);
//	void insertar(TipoSocio s);
//	Elemento* buscar(int codigo);
//	void eliminar(int codigo);
//private:      // operaciones para obtener índices dispersos      
//	int dispersion(long x);
//};
//struct Fecha {
//	int dia;
//	int mes;
//	int anno;
//};
//class TipoSocio {
//protected:
//	int codigo;
//	char* nombre;
//	int edad;
//	Fecha f;
//public:
//	TipoSocio() {};
//	TipoSocio(int c, char* nom, int ed, Fecha fech) { codigo = c; nombre = nom; edad = ed; f = fech; }
//	int Ocodigo() { return codigo; }
//	void Pcodigo(int c) { codigo = c; }
//	void Pedad(int e) { edad = e; }
//	int Oedad() { return edad; }
//	void Pnombre(char* nom) { nombre = nom; }
//	char* Onombre() { return nombre; }
//	void PFecha(Fecha fech) { f = fech; }
//	Fecha OFecha() { return f; }
//};
//class Elemento {
//protected:    
//TipoSocio socio;   
//Elemento* sgte;
//public:   
//	Elemento(TipoSocio e) { socio = e;      sgte = NULL; };   
//	Elemento() {};   
//	Elemento* Osgte() { return sgte; }    
//	void Psgte(Elemento* sig) { sgte = sig; }    
//	TipoSocio Osocio() { return socio; }    
//	void Psocio(TipoSocio s) { socio = s; } 
//};
//int TablaDispersa::dispersion(long x) { 
//	double t, R = 0.618034;   
//	int v;   
//	t = R * x - floor(R * x);    
//	v = (int)(final * t);   
//	return v; 
//}
//TablaDispersa::TablaDispersa(int n) // constructor
//{
//	tabla = new Elemento*[n];
//	final = n;
//	for (int k = 0; k < final; k++)
//		tabla[k] = NULL;
//	numElementos = 0;
//}
//void TablaDispersa::insertar(TipoSocio s) {
//	int posicion;  
//	Elemento* nuevo, * p;  
//	posicion = dispersion(s.Ocodigo());  
//	p = buscar(s.Ocodigo());   
//	if (!p)// el código no se encuentra en la tabla  
//	{      nuevo = new Elemento(s);      
//	nuevo->Psgte(tabla[posicion]);     
//	tabla[posicion] = nuevo;     
//	numElementos++;  
//	}   else      
//		throw "repetición de socio"; 
//}
//bool conforme(TipoSocio cod) { }
//void TablaDispersa::eliminar(int codigo)
//{
//	int posicion;
//	posicion = dispersion(codigo);
//	if (tabla[posicion] != NULL) // no está vacía
//	{
//		Elemento* anterior, * actual;
//		anterior = NULL;
//		actual = tabla[posicion];
//		while ((actual->Osgte() != NULL)
//			&& actual->Osocio().Ocodigo() != codigo)
//		{
//			anterior = actual;
//			actual = actual->Osgte();
//		}
//		if (actual->Osocio().Ocodigo() != codigo)
//			std::cout << "No se encuentra en la tabla el socio \n";
//		else if (conforme(actual->Osocio())) { //se retira el nodo
//			if (anterior == NULL) // primer nodo
//				tabla[posicion] = actual->Osgte();
//			else
//				anterior->Psgte(actual->Osgte());
//			delete actual;
//			numElementos--;
//			{
//			}
//		}
//	}
//}
//Elemento* TablaDispersa::buscar(int codigo)
//{
//	Elemento* p = NULL;
//	int posicion;
//	posicion = dispersion(codigo);
//	if (tabla[posicion] != NULL)
//	{
//		p = tabla[posicion];
//		while ((p->Osgte() != NULL)
//			&& p->Osocio().Ocodigo() != codigo)
//			p = p->Osgte();
//		if (p->Osocio().Ocodigo() != codigo)
//			p = NULL;
//	}
//	return p;
//}