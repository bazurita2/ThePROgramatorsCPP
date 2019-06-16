
//UNIVERSIDAD DE LAS FUERZAS ARMADAS "ESPE"
//ESTRUCTURAS DE DATOS
//VICTOR JIMENEZ, SEBASTIAN LANDAZURI, BRYAN ZURITA
//14/06/2019

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
void portada();
Nodo *listaDoble;
ifstream f;

void portada()
{
	cout<<"\n\n\n"<<endl;
	cout<<"\t\t:::::::::::     :::::::::      :::::::::      ::::: ::      :::    :::::::       :::::::::::   "<<endl;
	cout<<"\t\t:::::::::::     :::            ::   	      ::::   ::	    :::	   :: 	 ::	 :::	 :::    "<<endl;
	cout<<"\t\t:::     :::     :::            ::    	      ::::    ::    :::	   :: 	 ::	 :::	 :::    "<<endl;
	cout<<"\t\t:::     :::     :::            :::::::::      ::::     ::   :::	   :: 	 ::	 :::	 :::    "<<endl;
	cout<<"\t\t:::::::::::     :::    :::::   ::             ::::      ::  :::    :: 	 ::	 :::::::::::   "<<endl;
	cout<<"\t\t:::     :::     ::::::::::     ::             ::::       :: :::    :: 	 ::	 :::	 :::   "<<endl;
	cout<<"\t\t:::     :::     ::::::::::     :::::::::      ::::        :::::    :::::::	 :::	 :::   "<<endl;
	cout<<"\n\n\n"<<endl;
	system("pause");
}
int main()
{
	portada();
	system("cls");
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
	printf("================================================\n");
	gotoxy(5,1);
	cout<<"\t\tMENU"<<endl;
	gotoxy(5,2);
	cout<<" Insertar Nodo";
	gotoxy(5,3);
	cout<<" Eliminar Nodo";
	gotoxy(5,4);
	cout<<" Modificar Nodo";
	gotoxy(5,5);
	cout<<" Imprimir Lista P->U";
	gotoxy(5,6);
	cout<<" Imprimir Lista U->P";
	gotoxy(5,7);
	cout<<" Generar PDF de Contactos";
	gotoxy(5,8);
	cout<<" Salir\n";
	printf("================================================");
}

void Selector(int i)
{
	gotoxy(5,2+i);
}

void menuDinamico()
{
	int i = 0;
	char tecla;
	menuInicio();
	Selector(i);
	while(true){
		tecla = getch();
		switch(tecla)
		{
			case ARRIBA:
				i--;
				if(i < 0)
				{
					i = 5;
				}
				Selector(i);
				break;
			case 59:
				system("cls");
				cout<<"Ayuda"<<endl;
				system("ayuda.chm");
				system("pause");
				system("cls");
				menuDinamico();
				break;
			case ABAJO:
				i++;
				if(i == 0)
				{
					i = 1;
				}
				if(i == 7)
				{
					i = 0;
				}
				Selector(i);
				break;
			case ENTER:
				Selector(7);
				switch(i)
				{
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
						f.open("Agenda.csv", std::fstream::in);
              			if(!f.good())
              			{
              				system("cls");
              				cout<<"ERROR: El archivo de agenda no esta creado\n";
              				system("pause");
              				menuDinamico();
						}
						else
						{
							f.close();
							system("cls");
							system("txt2pdf.exe AgendaTemp.csv Agenda.pdf -oao -ptc255 -pps43 -width2000 -height1000");
              				cout<<"Archivo generado exitosamente\n";
              				system("pause");
              				menuDinamico();
						
						}
						break;
					default:
						exit(0);
				}
		}
	}
}
