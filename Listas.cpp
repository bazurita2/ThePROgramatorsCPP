
#include<iostream>
#include<stdlib.h>
#include<conio.h>
using namespace std;

class Nodo{
	private:
		int dato;
		Nodo *sig;
	public:
		Nodo (){
		}
		Nodo (int _dato, Nodo *_sig){
			dato = _dato;
			sig = _sig;
		}
		int getDato(){
			return dato;
		}
		Nodo *getSig(){
			return sig;
		}
		void setNum(int dat){
			dato=dat;
		}
		void setSig(Nodo *s){
			sig = s;
		}
};

class Lista{
	private:
		Nodo *nuevo_nodo;
	public:
		Lista();
		void insertarLista(Nodo *,int);
		void mostrarLista();
};

Lista::Lista(){
}

void Lista::insertarLista(Nodo *lista,int n){
	nuevo_nodo= new Nodo(n,lista);
	Nodo *aux;
	
	
	if(lista == NULL){
		lista = nuevo_nodo;
	}
	else{
		aux = lista;
		while(aux->getSig() != NULL){
			aux = aux->getSig();
		}
		nuevo_nodo=aux->getSig();
	}
	cout<<"\tElemento "<<nuevo_nodo->getDato()<<" agregado a lista correctamente\n";
}


void Lista::mostrarLista(){	
	Nodo *aux = new Nodo();
	
	aux = nuevo_nodo;
	while(aux != NULL){ 
		cout<<aux->getDato()<<" -> "; 
		aux = aux->getSig(); 
	}
}


int main(){
	Nodo *lista = NULL;
	int dato;
	char opcion;
	Lista lis = Lista();
	
	do{
		cout<<"Digite un numero para agregarlo a lista: ";
		cin>>dato;
		lis.insertarLista(lista,dato);
		
		cout<<"\nDesea agregar un nuevo numero(s/n): ";
		cin>>opcion;
	}while(opcion == 's' || opcion == 'S');
	
	cout<<"\nElementos de la lista: \n";
	lis.mostrarLista();
	
	
	
	getch();
	return 0;
}

