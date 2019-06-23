#include <cstdlib>
#include <iostream>
#include <string>
#include <cstring>
#include "Hash.h"

using namespace std;

int main(int argc, char** argv)
{
	string placaSerial,buscarSerial,pregunta;
	int indiceBuscar;
	Hash hashObj;
	for(int i=0;i<2;i++)
	{
		cout<<"Ingrese una placa ["<<i<<"]: ";
		if(i<3)
		{
			char cstr[placaSerial.size() + 1];
			do
			{
				cin>>placaSerial;
				strcpy(cstr, placaSerial.c_str());
				system("cls");
				cout<<"Verifique que los 3 primeros digitos que sean letras \nPor favor ingrese nuevamente su placa: ";
				
			}while(cstr[i] >= '1' &&  cstr[i] <= '9');
		}
		else
		{
			char cstr[placaSerial.size() + 1];
			do
			{
				cin>>placaSerial;
				strcpy(cstr, placaSerial.c_str());
				system("cls");
				cout<<"Verifique que los 4 ultimos digitos que sean numeros \nPor favor ingrese nuevamente su placa:  ";
			}while(cstr[i] >= 'A' &&  cstr[i] <= 'Z');
		}
	}
	cin>>placaSerial;
	hashObj.insertarPlaca(placaSerial);
	hashObj.imprimirTabla();
	cout<<"Ingrese la placa por indice que desea buscar: ";
	cin>>indiceBuscar;
	hashObj.buscarPorIndice(indiceBuscar);
	cout<<"Remover: ";
    cin>>buscarSerial;
	if(buscarSerial != "exit"){
		hashObj.eliminarPlaca(buscarSerial);
	}
	hashObj.imprimirTabla();
	return 0;
}
