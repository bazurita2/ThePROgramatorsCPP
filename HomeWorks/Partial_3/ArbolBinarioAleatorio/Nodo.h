#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <string.h>
#include <fstream>

#include "Dato.h"

using namespace std;

class Nodo{
	public:
		Dato dato;
		Nodo *izq;
		Nodo *der;
		Nodo *padre;
		
		Nodo *crearNodo(string,Nodo *);
	private:
};

Nodo* Nodo::crearNodo(string num,Nodo *padre){
	Nodo *nuevoNodo = new Nodo();
	nuevoNodo->dato.setNum(num);
	nuevoNodo->der=NULL;
	nuevoNodo->izq=NULL;
	nuevoNodo->padre=padre;
	return nuevoNodo;
}

