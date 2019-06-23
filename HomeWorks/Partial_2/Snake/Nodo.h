//UNIVERSIDAD DE LAS FUERZAS ARMADAS "ESPE"
//ESTRUCTURA DE DATOS
//VICTOR JIMENEZ, SEBASTIAN LANDAZURI, BRYAN ZURITA
//27/05/2019
#include <iostream>
#include <stdlib.h>
using namespace std;
class Nodo
{		
	public:
		int dato;
		Nodo *sig;
		Nodo ();
		void insertarInicio(Nodo *&,int);
		void mostrar(Nodo*);
				
		int getDato()
		{
			return dato;
		}
		Nodo *getSig()
		{
			return sig;
		}
		
		void setDato(int dat)
		{
			dato=dat;
		}
		void setSig(Nodo *s)
		{
			sig = s;
		}
		
};

void Nodo::insertarInicio(Nodo *&lista,int n)
{
	Nodo *nuevo = new Nodo();
	nuevo->dato=n;
	nuevo->sig=lista;
	lista=nuevo;
}
void Nodo::mostrar(Nodo *lista){	
	Nodo *actual = new Nodo();
	
	actual = lista;
	while(actual != NULL){ 
		cout<<" - "<<actual->dato;
		actual = actual->sig; 
	}
}

Nodo::Nodo()
{
	
}
