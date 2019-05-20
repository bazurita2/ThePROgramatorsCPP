#include <iostream>
#include <conio.h>
#include <stdlib.h>
using namespace std;

class Nodo{
	public:
		int dato;
		Nodo *sig;
	private:
		
};

void insertarLista(Nodo *&,int);
void mostrarLista(Nodo *);
void menu();

Nodo *lista=NULL;

int main (){
	menu();
	return 0;
}

void insertarFinLista(Nodo *&lista,int n){
	Nodo *nuevoNodo= new Nodo();
	nuevoNodo->dato=n;
	Nodo *aux1=lista;
	Nodo *aux2;
	while((aux1!=NULL)&&(aux1->dato<n)){
		aux2=aux1;
		aux1=aux1->sig;
	}
	if(lista == aux1){
		lista = nuevoNodo;
	}else{
		aux2->sig=nuevoNodo;
	}
	nuevoNodo->sig=aux1;
	cout<<"\tElemento "<<n;
}

void insertarIniLista(Nodo *&lista,int n){
	
}

void mostrarLista(Nodo *lista){
	Nodo *actual = new Nodo();
	actual = lista;
	cout<<endl<<endl;
	while(actual!=NULL){
		cout<<" -> "<<actual->dato;
		actual=actual->sig;
	}
	cout<<endl<<endl;
	getch();
}

void menu(){
	char op;
	do{
		cout<<"\n\t\tMenu "<<endl;
		cout<<"\n1.Insercion Inicio -> Final \n2.Insercion Final -> Inicio \n3.Mostrar "<<endl;
		cout<<"\nOprima \"esc\" para salir...."<<endl;
		cout<<"\nDigite la opcion: ";
		op=getch();
		switch (op){
		case 49:			
			int dato1;
			cout<<"\n\n\tDigite un numero: ";
			cin>>dato1;
			insertarFinLista(lista,dato1);
			cout<<endl;
			getch();
			break;
		case 50:
			int dato2;
			cout<<"\n\n\tDigite un numero: ";
			cin>>dato2;
			insertarIniLista(lista,dato2);
			cout<<endl;
			getch();
			break;
		case 51:
			mostrarLista(lista);
			break;
	}
	system("cls");
	}while(op!=27);
}
