//UNIVERSIDAD DE LAS FUERZAS ARMADAS "ESPE"
//ESTRUCTURA DE DATOS
//INTEGRANTES: VICTOR JIMENEZ, BRYAN ZURITA, SEBASTIAN LANDAZURI
//FECHA 08/05/2019


#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <iostream>
#include <cctype>
#include <string>
#include <string.h>
#include <sstream>
#pragma comment(lib,"d3d11.lib")

class Validacion
{
	
	public:	
		bool validarPlaca(char c);
		int registro(std::string n, std::string a);
		char firstCharGet(std::string get);
		std::string null="";
		std::string nombre[5];
		std::string apellido[5];
		Validacion()
		{
			nombre[0] = "Juan";
			nombre[1] = "Jose";
			nombre[2] = "Ana";
			nombre[3] = "Juana";
			nombre[4] = "Valentina";
			apellido[0] = "perez";
			apellido[1] = "perez";
			apellido[2] = "juarez";
			apellido[3] = "jimenez";
			apellido[4] = "jimenez";
		}
	private:
		int counter = 1;

};


bool Validacion::validarPlaca(char c)
{
	int i = 0;
	while (c != 13) {
		if (i<3)
		{
			if (c >= 'A' && c <= 'Z' && c != 255) {
				return true;
				printf("%c", c);
			}

		}
		else
			if (c >= '0' && c <= '9') {
				return true;
				printf("%c", c);
				
			}
		if (i == 6)
		{
			i++;
			break;
		}
		i++;
	}
	return false;

}
/*int Validacion::registro(std::string n, std::string a)
{
	

	std::string primero;
	std::string prim1;
	primero = (1, firstCharGet(n));
	for (int i = 0; i<5; i++)
	{
		if (!nombre[i].compare(null)){}
		else
		{
			prim1 = (1, firstCharGet(nombre[i]));
			if (!a.compare(apellido[i]))
			{
				if (!prim1.compare(primero))
					counter++;
			}
		}

	}
	return counter;
}*/

char firstCharGet(std::string get)
{
	return tolower(get.at(0));
}
