#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <string.h>
#include <fstream>
#include <sstream>

#include "Nodo.h"

using namespace std;

class ArbolBinario{
	public:
		void insertarNodo(Nodo *&,string,Nodo *);
		void mostrarArbol(Nodo *,int);
		void preOrden(Nodo *);
		string randomNum();
		void menu();
	private:
		
};

Nodo *arbol=NULL;
Nodo *nodo=new Nodo();

void ArbolBinario::menu(){
	int op,cont;
	string num;
	do{
		cout<<"\t.:MENU:."<<endl;
		cout<<"1. Insertar nuevo nodo"<<endl;
		cout<<"2. Mostrar arbol"<<endl;
		cout<<"3. Mostrar arbol Pre-Orden"<<endl;
		cout<<"6. Salir\n"<<endl;
		cout<<"\t Opcion: ";
		cin>>op;
		switch(op){
			case 1:
				srand (time(NULL));
				cout<<"\n\tNumero ingresado: ";
				num=randomNum();
				cout<<" '"<<num<<"'";
				insertarNodo(arbol,num,NULL);
				cout<<endl<<endl;
				system("pause");
				break;
			case 2:
				cout<<"\n\tMostrar arbol"<<endl<<endl;
				mostrarArbol(arbol,cont);
				cout<<endl<<endl;
				system("pause");
				break;
			case 3:
				cout<<"\n\tMostrar arbol Pre-Orden (R->I->D)"<<endl<<endl;
				preOrden(arbol);				
				cout<<endl<<endl;
				system("pause");
				break;
			case 4:
//				cout<<"\nDigite un numero a modificar: ";
//				cin>>num;
//				insertarNodo(arbol,num);
				cout<<endl;
				system("pause");
				break;
			case 5:
//				cout<<"\nDigite un numero a eliminar: ";
//				cin>>num;
//				insertarNodo(arbol,num);
				cout<<endl;
				system("pause");
				break;
		}
		system("cls");
	}while(op!=6);
}

void ArbolBinario::insertarNodo(Nodo *&arbol,string num,Nodo *padre){
	if(arbol==NULL){
		Nodo *nuevoNodo=nodo->crearNodo(num,padre);
		arbol=nuevoNodo;
	}else{//2 o + nodos
		if(num<=arbol->dato.getNum()){
			insertarNodo(arbol->izq,num,arbol);
		}else{
			insertarNodo(arbol->der,num,arbol);
		}
	}
}

void ArbolBinario::mostrarArbol(Nodo *arbol,int cont){
	if(arbol==NULL){
		return;
	}else{
		mostrarArbol(arbol->der,cont+1);
		for(int i=0;i<cont;i++){
			cout<<"  ";
		}
		cout<<arbol->dato.getNum()<<endl;
		mostrarArbol(arbol->izq,cont+1);
	}
}

void ArbolBinario::preOrden(Nodo *arbol){
	if(arbol==NULL){
		return;
	}else{
		cout<<arbol->dato.getNum()<<" - ";
		preOrden(arbol->izq);
		preOrden(arbol->der);
	}
}

string ArbolBinario::randomNum(){
	int num = 1 + rand() % (10 - 1);
	std::string numStr;
	std::stringstream salida;
	salida<<num;
	numStr = salida.str();
	return numStr;
}

