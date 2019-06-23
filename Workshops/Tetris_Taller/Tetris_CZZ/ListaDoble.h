#pragma once
#include "NodoDoble.h"
#include <iostream>
#include <math.h>
#include "Position.h"
class ListaDoble
{
private:
	NodoDoble* head;
	NodoDoble* tail;
public:
	//Constructor
	ListaDoble();
	//Destructor
	~ListaDoble();
	//Funciones
	bool insertarDato(int dato);
	void listaDobleTetris(int tama�o);
	void imprimirLista();
	void archivo(int);
	void insertarEnLista(Position* pos, int num,int limVer,int limHor);
	bool perdio(int elementos);
	bool gano(int elementos);
};

