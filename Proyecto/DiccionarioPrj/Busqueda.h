//UNIVERSIDAD DE LAS FUERZAS ARMADAS "ESPE"
//ESTRUCTURA DE DATOS
//AUTORES: BRYAN ZURITA, VICTOR JIMENEZ, SEBASTIAN LANDAZURI
//FECHA: 6/5/2019

#include <iostream>
#include <stdlib.h>
#include <string>
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <fstream>

#define TAM 10

using namespace std;


class Busqueda
{
	public:
		void leerArchivo();
		int numero;
		string outline;
		int recursivo(string palabras[], string buscarPalabra, int inferior, int superior);
		Busqueda(string linea)
		{
			outline = linea;
		}

};

int Busqueda::recursivo(string palabras[], string buscarPalabra, int inferior, int superior) {
	if (inferior>superior) {
		return -1;
	}

	int mitad = (inferior + superior) / 2;

	if (palabras[mitad] == buscarPalabra) {
		return mitad;
	}

	if (palabras[mitad]>buscarPalabra) {
		return recursivo(palabras, buscarPalabra, inferior, (mitad - 1));
	}

	if (palabras[mitad]<buscarPalabra) {
		return recursivo(palabras, buscarPalabra, mitad + 1, superior);
	}
}

void  Busqueda::leerArchivo() {
	ifstream fileRead;
	string textoRecuperado[10];
	for (int i = 0; i<10; i++)
	{
		textoRecuperado[i] = "";
	}
	string textoAcumulado;
	fileRead.open("diccionarioPalabras.txt", ios::in);
	if (fileRead.is_open()) {
		int i = 0;
		while (!fileRead.eof()) {
			getline(fileRead, textoRecuperado[i]);
			textoAcumulado += textoRecuperado[i] + ";";
			i++;
		}
	}
	fileRead.close();
	//Valores para busqueda recursiva
	string palabras[TAM];
	string buscarPalabra = outline;
	int inferior = 0;
	int superior = TAM - 1;
	const unsigned int stat = textoAcumulado.length() + 1;
	char* textoAcumChars;
	textoAcumChars = new char[stat];
	strcpy(textoAcumChars, textoAcumulado.c_str());
	//split char[]
	char *textoSeparado = strtok(textoAcumChars, ";");
	int cont = 0;
	while (textoSeparado != NULL) {
		palabras[cont] = textoSeparado;
		cout << palabras[cont] << cont << endl;
		textoSeparado = strtok(NULL, ";");
		cont++;
	}
	//
	numero = recursivo(palabras, buscarPalabra, inferior, superior);
	cout << "se encuentra " << buscarPalabra << " en la linea : " << recursivo(palabras, buscarPalabra, inferior, superior);
	cout << "\n";
	system("pause");

}



