#include <conio.h>
#include <fstream>
#include <stdio.h>
#include <string>
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

#include "Diccionario.h"

#define ARRIBA 72
#define ABAJO 80
#define ENTER 13

using namespace std;

class Archivo{
    public:
        Archivo();
        void lectura();
        void aniadir(Diccionario);
		void buscar();
};

Archivo::Archivo(){

}

void Archivo::lectura(){
     string txt;
     ifstream mostrarArchivo;
     mostrarArchivo.open("diccionario.txt",ios::out);

    while(!mostrarArchivo.eof()){
        getline(mostrarArchivo,txt);
        cout<<txt<<endl;
    }
     mostrarArchivo.close();
}

void Archivo::buscar(){
    fstream archivo;
    string linea1,linea2,palabraBuscar;
    int res=0;
    string wav=".wav";
    char *busca;
    char *unir;
    char *cadena;
    char *soundfile;
    cout<<"Digite la palabra a buscar: ";
    cin>>palabraBuscar;
    cadena=(char*)wav.c_str();
    busca=(char*)palabraBuscar.c_str();
    strcpy(unir,busca);
    strcat(unir,cadena);
    cout<<PlaySound((LPCSTR)unir,NULL,SND_FILENAME|SND_ASYNC)<<endl;
    
    if(!archivo.is_open()){
        archivo.open("diccionario.txt",ios::in);
    }
 
    while(getline(archivo,linea1)){
        if(linea1.find(palabraBuscar)!=string::npos){
            cout<<linea1<<endl;
            getline(archivo,linea2);
            cout<<linea2<<endl;
            res=1;
        }
    }
    if(res==0){
        cout<<"Palabra no encontrada"<<endl;
    }
    ofstream agregarTxtLog;
    fflush(stdin);
	agregarTxtLog.open("log.txt",ios::app);
	time_t tiempoAhora;
	time(&tiempoAhora);
	agregarTxtLog<<"Se busco la palabra: "<<busca<<" en la fecha: "<<ctime(&tiempoAhora)<<endl;
	agregarTxtLog.close();
}

void gotoxy(int x,int y){
	HANDLE hcon;
	hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y= y;
	SetConsoleCursorPosition(hcon,dwPos);
}

void menu(){
	gotoxy(0,3);
	cout<<"\t ********        *  *********  *********  *  *********  *      *  *********  *********   *  *********"<<endl
	    <<"\t *        *      *  *          *          *  *       *  * *    *  *       *  *        *  *  *       *"<<endl
		<<"\t *          *    *  *          *          *  *       *  * *    *  *       *  *        *  *  *       *"<<endl
		<<"\t *           *   *  *          *          *  *       *  *  *   *  *       *  *        *  *  *       *"<<endl
		<<"\t *            *  *  *          *          *  *       *  *  *   *  *********  *********   *  *       *"<<endl
		<<"\t *           *   *  *          *          *  *       *  *   *  *  *       *  *     *     *  *       *"<<endl
		<<"\t *          *    *  *          *          *  *       *  *   *  *  *       *  *      *    *  *       *"<<endl
		<<"\t *        *      *  *          *          *  *       *  *    * *  *       *  *       *   *  *       *"<<endl
		<<"\t ********        *  *********  *********  *  *********  *      *  *       *  *        *  *  *********"<<endl;
	cout<<endl<<endl;
	cout<<"\t\t\t\t ******   ******                 ******  *     *"<<endl
	    <<"\t\t\t\t *       *            *    *     *       * *   *"<<endl
	    <<"\t\t\t\t ******   ******     ********    ******  *  *  *"<<endl
	    <<"\t\t\t\t *              *     *    *     *       *   * *"<<endl
	    <<"\t\t\t\t ******   ******                 ******  *     *"<<endl;
    gotoxy(47,21);
	cout<<"\t\tMENU"<<endl;
	gotoxy(47,23);
	cout<<" Buscar";
	gotoxy(47,24);
	cout<<" Ayuda";
	gotoxy(47,25);
	cout<<" Salir";
}

void Selector(int i){
	gotoxy(45,23+i);
}

void menuDinamico(){
	Archivo arch = Archivo();
    Diccionario di = Diccionario();
	int i = 0;
	char tecla;
	menu();
	Selector(i);
	while(true){
		tecla = getch();
		switch(tecla){
			case ARRIBA:
				i--;
				if(i < 0){
					i = 2;
				}
				Selector(i);
				break;
			case ABAJO:
				i++;
				if(i == 0){
					i = 1;
				}
				if(i == 3){
					i = 0;
				}
				Selector(i);
				break;
			case ENTER:
				Selector(5);
				switch(i){
					case 0:
						system("cls");
						cout<<"Buscar una palabra"<<endl;
						arch.buscar();
						cout<<endl;
						system("pause");
						system("cls");
						menuDinamico();
						break;
					case 1:
						system("cls");
						cout<<"Ayuda"<<endl;
						system("ayuda.chm");
						system("pause");
						system("cls");
						menuDinamico();
						break;
					case 2:
						system("cls");
						cout<<"Salir"<<endl;
						exit(0);
						break;
				}

				break;
		}
	}
}

int main(){
    menuDinamico();
	system("pause");
	return 0;
}

//void Archivo::aniadir(Diccionario di){
//    ofstream agregarTxt;
//    ofstream agregarTxtAux;
//    fflush(stdin);
//    agregarTxt.open("diccionario.txt",ios::app);
//    string palabra = di.agregarPalabra();
//    string definicion = di.agregarDefinicion();
//    agregarTxt<<"\n\tPalabra: "<<palabra<<endl;
//    agregarTxt<<"\tDefinicion: "<<definicion<<endl;
//	agregarTxt.close();
//	fflush(stdin);
//	agregarTxtAux.open("diccionarioPalabras.txt",ios::app);
//	agregarTxtAux<<palabra<<endl;
//    agregarTxtAux<<definicion<<endl;
//	agregarTxtAux.close();
//}
