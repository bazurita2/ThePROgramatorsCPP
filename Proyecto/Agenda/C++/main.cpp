#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "Nodo.h"
#include "Validacion.h"
using namespace std;
#define ARRIBA 72
#define ABAJO 80
#define ENTER 13
#define TAM 100

Nodo *lista = new Nodo();
bool ext=false;

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
      gotoxy(25,25); cout<<"=============================================";

      for (int i = 0; i < 17; ++i) {
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
   int opcion,cumpleDia,cumpleMes,cumpleAnio,aniverDia,aniverMes,aniverAnio;
   string nombre,apellido,op,correo,nota,direccion;
	long int teleCasa,celular,cedula;
	
	system("cls");
   setlocale(LC_CTYPE,"Spanish");
   const char *titulo = "-------< AGENDA TELEFONICA >---------";
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
      			nombre=ingresarLetras();
      			fflush(stdin);    
      			cout<<"\nIngrese su apellido: ";
      			apellido=ingresarLetras();
      			fflush(stdin);    
      			cout<<"\nDigite su telefono de casa: ";
      			teleCasa=entero2();
      			fflush(stdin);    
      			cout<<"\nDigite su celular: ";
      			celular=entero2();
      			fflush(stdin);    
      			lista->insertarInicio(lista,teleCasa,celular,nombre,apellido);
                
                
                cout<<"\nAgregar mas campo de contacto? (S/N)";
                getline(cin,op);
                
                if(op=="s"||op=="S"){
                
				cedula=validarCedula();
				do{
				fflush(stdin);    
				cout<<"\nDigite el dia de su cumpleaños: ";
				cin>>cumpleDia;
				}while(cumpleDia<1||cumpleDia>31);
				do{
				fflush(stdin);    
				cout<<"\nDigite el mes de su cumpleaños: ";
				cin>>cumpleMes;
				}while(cumpleMes<1||cumpleMes>12);
				do{
				fflush(stdin);    
				cout<<"\nDigite el anio de su cumpleaños: ";
				cin>>cumpleAnio;
				}while(cumpleAnio<1900||cumpleAnio>2019);
				fflush(stdin);    
				cout<<"\nDigite su correo: ";
				getline(cin,correo);
				fflush(stdin);    
				cout<<"\nDigite su direccion: ";
				direccion=ingresarLetras();
				do{
				fflush(stdin);    
				cout<<"\nDigite el dia de su aniversario: ";
				cin>>aniverDia;
				}while(aniverDia<1||aniverDia>31);
				do{
				fflush(stdin);    
				cout<<"\nDigite el mes de su aniversario: ";
				cin>>aniverMes;
				}while(aniverMes<1||aniverMes>12);
				do{
				fflush(stdin);    
				cout<<"\nDigite el anio de su aniversario: ";
				cin>>aniverAnio;
				}while(aniverAnio<1900||aniverAnio>2019);
				fflush(stdin);    
				cout<<"\nDigite una nota para el contacto: ";
				nota=ingresarLetras();
				fflush(stdin);    
				ext=true;
				
				lista->insertarInicioExtra(lista,cedula, cumpleDia, cumpleMes, cumpleAnio, correo, direccion, aniverDia, aniverMes, aniverAnio, nota);	
			
				}else{
					cout<<"\nContacto guardado"<<endl;
				}
				
				system("pause");
				                
             }break;
         case 2:{
             
                system("cls");
                
                
                
                
                system("pause");
                break;
         }
         case 3:{
              system("cls");
              const char *titulo2 = "-------< MODIFICAR CONTACTO >---------";
              const char *opciones2[] = { "NOMBRE", "APELLIDO","TELEFONO DE CASA","CELULAR","CEDULA","CUMPLEANIOS","CORREO","DIRECCION","ANIVERSARIO","NOTA","SALIR"};
              int n2 = 11,op;
              bool repite2 = true;
              
			  
              
              do{
              	system("cls");
              	op = menuOp(titulo2, opciones2, n2);
              	
              	switch(op){
              		case 1:
              		system("cls");

              		system("pause");
              		break;
              		
              		case 2:
              		system("cls");

              		system("pause");
              		break;
              		
              		case 3:
              		system("cls");

              		system("pause");
              		break;
              		
              		case 4:
              		system("cls");

              		system("pause");
              		break;
              		
              		case 5:
              		system("cls");

              		system("pause");
              		break;
              		
              		case 6:
              		system("cls");

              		system("pause");
              		break;
              		
              		case 7:
              		system("cls");

              		system("pause");
              		break;
              		
              		case 8:
              		system("cls");

              		system("pause");
              		break;
              		
              		case 9:
              		system("cls");

              		system("pause");
              		break;
              		
              		case 10:
              		system("cls");

              		system("pause");
              		break;
              		
              		case 11:
              		repite2=false;
              		break;
				  }
              	
              		
              	
              	
			  }while(repite2);
              
              cout<<endl;
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
                if(ext==true) lista->mostrarExtra(lista);
                cout<<endl;
                system("pause");
         break;
        }
        case 5:
            repite = false;
            break;
      }

   } while(repite);

}

void portada(){
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



int main(){
	
	portada();
	
	menuPila(); 
	
	
}












