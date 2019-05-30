#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "Nodo.h"
using namespace std;
#define ARRIBA 72
#define ABAJO 80
#define ENTER 13
#define TAM 100

Nodo *lista = new Nodo();




void gotoxy(int x,int y){
      HANDLE hcon;
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);
      COORD dwPos;
      dwPos.X = x;
      dwPos.Y= y;
      SetConsoleCursorPosition(hcon,dwPos);
 }

int menuOp(const char titulo[], const char *opciones[], int n){
   int opcionSeleccionada = 1;  

   int tecla;

   bool repite = true; 

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



      do {
         tecla = getch();

      } while (tecla != ARRIBA && tecla != ABAJO && tecla != ENTER);

      switch (tecla) {

         case ARRIBA: 

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



 void menuPila(){setlocale(LC_CTYPE,"Spanish");
    char* plbr;
        char* aux2;
        char* aux3;
      plbr=new char[20];
    aux2=new char[20];
    aux3=new char[20];
    bool repite = true;
   int opcion;
   string nombre,apellido;
	long int teleCasa,celular;

   setlocale(LC_CTYPE,"Spanish");
   const char *titulo = "-------< PILAS >---------";
   const char *opciones[] = { "AGREGAR CONTACTO", "ELIMINAR CONTACTO","MODIFICAR CONTACTO","MOSTRAR AGENDA","SALIR"};
   int n = 5;  

   do {

      system("cls");
      opcion = menuOp(titulo, opciones, n);

      switch (opcion) {
         case 1:
             {   system("cls");
                cout<<endl<<"==================================================================================================";
                cout<<"\t\t\tINGRESO DE CONTACTO"<<endl;
                cout<<"=================================================================================================="<<endl<<endl;
                cout<<endl<<endl;
                cout<<"Ingrese su nombre: ";
      			getline(cin,nombre);
      			fflush(stdin);    
      			cout<<"Ingrese su apellido: ";
      			getline(cin,apellido);
      			fflush(stdin);    
      			cout<<"Digite su telefono de casa: ";
      			cin>>teleCasa;
      			fflush(stdin);    
      			cout<<"Digite su celular: ";
      			cin>>celular;
      			fflush(stdin);    
      			lista->insertarInicio(lista,teleCasa,celular,nombre,apellido,"n");
                system("pause");
             }break;
         case 2:{
             char c;
                system("cls");
                
                system("pause");
                break;
         }
         case 3:{
              system("cls");
            system("pause");
         break;
         }
        case 4: {
                 system("cls");
                cout<<endl<<"==================================================================================================";
                cout<<"\t\t\tLISTA DE CONTACTOS "<<endl;
                cout<<"=================================================================================================="<<endl<<endl;
                cout<<endl<<endl;
                lista->mostrar(lista);
                system("pause");
         break;
        }
        case 5:
            repite = false;
            break;
      }

   } while(repite);

}





int main(){
	
	menuPila(); 
	
	
}
