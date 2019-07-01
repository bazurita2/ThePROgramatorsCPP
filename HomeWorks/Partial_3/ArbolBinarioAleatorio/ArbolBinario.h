#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <string.h>
#include <fstream>
#include <sstream>
#include <windows.h>
#define ARRIBA 72
#define ABAJO 80
#define ENTER 13
#define TAM 100
#include "Nodo.h"

using namespace std;

class ArbolBinario{
	public:
		void insertarNodo(Nodo *&,string,Nodo *);
		void mostrarArbol(Nodo *,int);
		void preOrden(Nodo *);
		void postOrden(Nodo *);
		void inOrden(Nodo *);
		string randomNum();
		void menuArbol();
		void gotoxy(int,int);
		int menuOp(const char titulo[], const char *opciones[], int n);
	private:
		
};

Nodo *arbol=NULL;
Nodo *nodo=new Nodo();

void ArbolBinario::gotoxy(int x,int y){
      HANDLE hcon;
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);
      COORD dwPos;
      dwPos.X = x;
      dwPos.Y= y;
      SetConsoleCursorPosition(hcon,dwPos);
 }
int ArbolBinario::menuOp(const char titulo[], const char *opciones[], int n){
   int opcionSeleccionada = 1;  // Indica la opcionSeleccionada

   int tecla;

   bool repite = true; // controla el bucle para regresar a la rutina que lo llamo, al presionar ENTER

   do {
system("cls");
      gotoxy(25,8); cout<<"=============================================";
      gotoxy(25,18); cout<<"=============================================";

      for (int i = 0; i < 10; ++i) {
         gotoxy(25, 8 + i); cout<< "=";
         gotoxy(69, 8 + i); cout<< "=";
      }

      gotoxy(27, 11 + opcionSeleccionada); cout << "==>" << endl;

      gotoxy(31, 10); cout << titulo;

      for (int i = 0; i < n; ++i) {
         gotoxy(33, 12 + i); cout << (i + 1) << ") " << opciones[i];
      }

      // Solo permite que se ingrese ARRIBA, ABAJO o ENTER

      do {
         tecla = getch();
         // clreol(); gotoxy(15, 15); cout << "tecla presionada: " << (char)tecla << " = " << tecla;
      } while (tecla != ARRIBA && tecla != ABAJO && tecla != ENTER);

      switch (tecla) {

         case ARRIBA:   // En caso que se presione ARRIBA

            opcionSeleccionada--;

            if (opcionSeleccionada < 1) {
               opcionSeleccionada = n;
            }

            break;

         case ABAJO:
            opcionSeleccionada++;

            if (opcionSeleccionada > n) {
               opcionSeleccionada = 1;
            }

            break;

         case ENTER:
            repite = false;
            break;
      }



   } while (repite);

   return opcionSeleccionada;
}


void ArbolBinario::menuArbol(){setlocale(LC_CTYPE,"Spanish");
    char* plbr;
        char* aux2;
        char* aux3;
      plbr=new char[20];
    aux2=new char[20];
    aux3=new char[20];
    bool repite = true;
   int opcion,cont;
   string num;
   // Titulo del menú y nombres de las opciones
   setlocale(LC_CTYPE,"Spanish");
   const char *titulo = "\t  -------< MENU >---------";
   const char *opciones[] = { " Insertar nuevo nodo", " Mostrar arbol"," Mostrar arbol Pre-Orden"," Mostrar arbol Post-Orden"," Mostrar arbol In-Orden"," SALIR"};
   int n = 6;  // Numero de opciones

   do {

      system("cls");
      opcion = menuOp(titulo, opciones, n);

      switch (opcion) {
       case 1:
       		system("cls");
				srand (time(NULL));
				cout<<endl;
				cout<<endl;
				cout<<"\n\tNumero ingresado: ";
				num=randomNum();
				cout<<" '"<<num<<"'";
				insertarNodo(arbol,num,NULL);
				cout<<endl<<endl;
				system("pause");
				break;
         	case 2:
         		system("cls");
				cout<<"\n\tMostrar arbol"<<endl<<endl;
				cout<<endl;
				mostrarArbol(arbol,cont);
				cout<<endl<<endl;
				system("pause");
				break;
        case 3:
        	system("cls");
				cout<<"\n\tMostrar arbol Pre-Orden (R->I->D)"<<endl<<endl;
				cout<<endl;
				preOrden(arbol);				
				cout<<endl<<endl;
				system("pause");
				break;
			case 4:
				system("cls");
				cout<<"\n\tMostrar arbol Post-Orden (I->D->R)"<<endl<<endl;
				cout<<endl;
				postOrden(arbol);				
				cout<<endl<<endl;
		        system("pause");
				break;
			case 5:
				system("cls");
				cout<<"\n\tMostrar arbol In-Orden (I->R->D)"<<endl<<endl;
				cout<<endl;
				cout<<endl;
				inOrden(arbol);
				cout<<endl<<endl;
				system("pause");
				break;
        	case 6:
            	repite = false;
            	break;
      }

   } while(repite);

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
		cout<<"("<<arbol->dato.getNum()<<")"<<endl;
		mostrarArbol(arbol->izq,cont+1);
	}
}

void ArbolBinario::preOrden(Nodo *arbol){
	if(arbol==NULL){
		return;
	}else{
		cout<<arbol->dato.getNum()<<" , ";
		preOrden(arbol->izq);
		preOrden(arbol->der);
	}
}

void ArbolBinario::inOrden(Nodo *arbol){
	if(arbol==NULL){
		return;
	}else{
		inOrden(arbol->izq);
		cout<<arbol->dato.getNum()<<" , ";
		inOrden(arbol->der);
	}
}
void ArbolBinario::postOrden(Nodo *arbol){
	if(arbol==NULL){ 
		return;
	}else{
		postOrden(arbol->izq);
		postOrden(arbol->der);
		cout<<arbol->dato.getNum()<<" , ";
	
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

