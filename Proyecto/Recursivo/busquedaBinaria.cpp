#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <fstream>

#define TAM 10
using namespace std;


int recursivo(string palabras[], string buscarPalabra,int inferior,int superior);
void leerArchivo();

int main (){
	leerArchivo();
	return 0;
}
	
int recursivo(string palabras[],string buscarPalabra,int inferior,int superior){
	if(inferior>superior){
		return -1;
	}
	int mitad=(inferior+superior)/2;
	if(palabras[mitad]==buscarPalabra){
		return mitad;
	}
	if(palabras[mitad]>buscarPalabra){
		return recursivo(palabras,buscarPalabra,inferior,(mitad-1));
	}
	if(palabras[mitad]<buscarPalabra){
		return recursivo(palabras,buscarPalabra,mitad+1,superior);
	}
}

void leerArchivo(){
	ifstream fileRead;
	string textoRecuperado[16];
	string textoAcumulado;
	fileRead.open("diccionarioPalabras.txt",ios::in);
	if(fileRead.is_open()){
		int i=0;
		while(!fileRead.eof()){
			getline(fileRead,textoRecuperado[i]);
			textoAcumulado+=textoRecuperado[i]+";";
			i++;
		}
	}
	fileRead.close();
	//Valores para busqueda recursiva
	string palabras[TAM];
	string buscarPalabra="light";
	int inferior=0;
	int superior=TAM-1;
	//
	//string to char[]
	char textoAcumChars[textoAcumulado.length()+1];
	strcpy(textoAcumChars,textoAcumulado.c_str());
	//split char[]
	char *textoSeparado = strtok(textoAcumChars,";");
	int cont=0;
	while(textoSeparado!=NULL){
		palabras[cont]=textoSeparado;
		cout<<palabras[cont]<<cont<<endl;
		textoSeparado=strtok(NULL,";");
		cont++;
	}
	//
	cout<<"se encuentra "<<buscarPalabra<<" en la linea : "<<recursivo(palabras,buscarPalabra,inferior,superior);
}

