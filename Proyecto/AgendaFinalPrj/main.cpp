#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>

#include "Nodo.h"

#define ARRIBA 72
#define ABAJO 80
#define ENTER 13

using namespace std;

void menuDinamico();
Nodo *listaDoble;

int main (){
	menuDinamico();
	return 0;
}

void gotoxy(int x,int y){
	HANDLE hcon;
	hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y= y;
	SetConsoleCursorPosition(hcon,dwPos);
}

void menuInicio(){
	gotoxy(0,3);
	cout<<"\t\t *        *   *********  *********  *********   *********"<<endl
	    <<"\t\t *        *  *               *      *       *  *         "<<endl
		<<"\t\t *        *  *               *      *       *  *         "<<endl
		<<"\t\t *        *    *             *      *       *    *       "<<endl
		<<"\t\t *        *       *          *      *********       *    "<<endl
		<<"\t\t *        *          *       *      *       *          * "<<endl
		<<"\t\t *        *           *      *      *       *           *"<<endl
		<<"\t\t *        *           *      *      *       *           *"<<endl
		<<"\t\t ******** *  *********       *      *       *  ********* "<<endl;
	cout<<endl<<endl;
	cout<<"\t\t\t\t\t\t *****  ****** *****  *      ******  ******"<<endl
	    <<"\t\t\t\t\t\t *    * *    * *    * *      *      *"<<endl
	    <<"\t\t\t\t\t\t *    * *    * *****  *      ******  ******"<<endl
	    <<"\t\t\t\t\t\t *    * *    * *    * *      *             *"<<endl
	    <<"\t\t\t\t\t\t *****  ****** *****  ****** ******  ****** "<<endl;
    gotoxy(47,21);
	cout<<"\t\tMENU"<<endl;
	gotoxy(47,23);
	cout<<" Insertar Nodo";
	gotoxy(47,24);
	cout<<" Eliminar Nodo";
	gotoxy(47,25);
	cout<<" Modificar Nodo";
	gotoxy(47,26);
	cout<<" Imprimir Lista P->U";
	gotoxy(47,27);
	cout<<" Imprimir Lista U->P";
	gotoxy(47,28);
	cout<<" Cargar";
}

void Selector(int i){
	gotoxy(45,23+i);
}

void menuDinamico(){
	int i = 0;
	char tecla;
	menuInicio();
	Selector(i);
	while(true){
		tecla = getch();
		switch(tecla){
			case ARRIBA:
				i--;
				if(i < 0){
					i = 5;
				}
				Selector(i);
				break;
			case ABAJO:
				i++;
				if(i == 0){
					i = 1;
				}
				if(i == 6){
					i = 0;
				}
				Selector(i);
				break;
			case ENTER:
				Selector(5);
				switch(i){
					case 0:
						system("cls");
						cout<<"Insertando Nodo"<<endl;
						listaDoble->insertarNodo();
						cout<<endl;
						cout<<endl;
						system("pause");
						system("cls");
						menuDinamico();
						break;
					case 1:
						system("cls");
						cout<<"Eliminando Nodo"<<endl;
						listaDoble->eliminarNodo();
						cout<<endl;
						cout<<endl;
						system("pause");
						system("cls");
						menuDinamico();
						break;
					case 2:
						system("cls");
						cout<<"Modificando Nodo"<<endl;
						listaDoble->modificarNodo();
						system("pause");
						system("cls");
						menuDinamico();
						break;
					case 3:
						system("cls");
						cout<<"Imprimiendo Lista P->U"<<endl;
						listaDoble->mostrarListaPU();
						system("pause");
						system("cls");
						menuDinamico();
						break;
					case 4:
						system("cls");
						cout<<"Imprimiendo Lista U->P"<<endl;
						listaDoble->mostrarListaUP();
						system("pause");
						system("cls");
						menuDinamico();
						break;
					case 5:
						system("cls");
						cout<<"Cargando"<<endl;
						listaDoble->cargarCVS();
						system("pause");
						system("cls");
						menuDinamico();
						break;
					default:
						exit(0);
				}
		}
	}
}
