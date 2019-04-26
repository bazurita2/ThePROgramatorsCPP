#include <cstdlib>
#include <iostream>
#include <string>

#include "Hash.h"

using namespace std;

int main(int argc, char** argv){
	string placaSerial,buscarSerial,pregunta;
	int indiceBuscar;
	Hash hashObj;
	for(int i=0;i<2;i++){
		cout<<"Ingrese una placa ["<<i<<"]: ";
		cin>>placaSerial;
		hashObj.insertarPlaca(placaSerial);
	}
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
