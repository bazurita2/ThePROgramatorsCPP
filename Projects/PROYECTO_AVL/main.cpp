//UNIVERSIDAD DE LAS FUERZAS ARMADAS "ESPE"
//ESTRUCTURA DE DATOS
//VICTOR JIMENEZ, SEBASTIAN LANDAZURI, BRYAN ZURITA
//19/07/2019


#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <string.h>
#include <windows.h>
#include "ArbolAVL.h"
#define ARRIBA 72
#define ABAJO 80
#define ENTER 13
#define TAM 100

void gotoxy(int x,int y){
      HANDLE hcon;
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);
      COORD dwPos;
      dwPos.X = x;
      dwPos.Y= y;
      SetConsoleCursorPosition(hcon,dwPos);
 }
int menuOp(const char titulo[], const char *opciones[], int n){
   int opcionSeleccionada = 1;  // Indica la opcionSeleccionada

   int tecla;

   bool repite = true; // controla el bucle para regresar a la rutina que lo llamo, al presionar ENTER

   do {
system("cls");
      gotoxy(25,8); cout<<"=============================================";
      gotoxy(25,25); cout<<"=============================================";

      for (int i = 0; i < 18; ++i) {
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


void menuArbol(){setlocale(LC_CTYPE,"Spanish");
    system("color 9f");
	char* plbr;
    string buscar;
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
   const char *opciones[] = { " Insertar nuevo nodo"," Buscar nodo"," Eliminar nodo"," Mostrar Arbol"," Generar PDF"," SALIR"};
   int n = 6;  // Numero de opciones
   int c,i,resp;
   ArbolAVL avl;

   do {

//system("ayuda,chm");
      system("cls");
      opcion = menuOp(titulo, opciones, n);

      switch (opcion) {
       case 1:
       		system("cls");
				cout << "Ingresa el valor a insertar: ";
	            cin >> i;
	            raiz=avl.Insertar(raiz,i);
				cout<<endl<<endl;
				system("pause");
				break;
         	case 2:
         		system("cls");
                cout<<"Ingresa el valor a buscar: ";
                cin>>i;
                cout<<endl;
                avl.buscar(i);
				cout<<endl<<endl;
				system("pause");
				break;
        case 3:
        	system("cls");
	       	cout<<"Ingresa el valor a eliminar: ";
                cin>>i;
                cout<<endl;
                raiz=avl.eliminarNodo(raiz,i);
				cout<<endl<<endl;
				system("pause");
				break;
		case 4:
        	system("cls");
                cout<<endl;
               	if (raiz == NULL){
	                cout<<"El arbol se encuentra vacio "<<endl;
	            }
	            //avl.imprimir(raiz, 1);
				avl.Dibujar(raiz,15,3,7,0);
				cout<<endl<<endl;
				system("pause");
				break;
		case 5: 
			system("cls");
			system("txt2pdf.exe AVL.txt AVL.pdf -oao -pfs60 -pps43 -ptc0 -width3000 -height2000");
            cout<<"Archivo generado exitosamente\n";
            cout<<endl<<endl;
            system("pause");
				break;						
		case 6:
				repite = false;
				cout<<"\n\n\n\n"<<endl<<endl;
            	break;
	}

   } while(repite);

}




int main()
{
    menuArbol();
    cout<<endl<<endl;
    return 0;
}
 
