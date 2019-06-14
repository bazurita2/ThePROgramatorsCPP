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

	Nodo *inicio= NULL;
	Nodo *ultimo= NULL;
	Nodo obj = Nodo();


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
    
	bool ext=false;

	
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
      			cin>>teleCasa;
      			fflush(stdin);    
      			cout<<"\nDigite su celular: ";
      			cin>>celular;
      			fflush(stdin);    
      			obj.insertarInicio(inicio,ultimo,teleCasa,celular,nombre,apellido);
                
                /*
                
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
				getline(cin,nota);
				fflush(stdin);    
				ext=true;
				
					
				lista[p]->insertarInicioExtra(p,lista,cedula, cumpleDia, cumpleMes, cumpleAnio, correo, direccion, aniverDia, aniverMes, aniverAnio, nota);
				cout<<"\nContacto guardado"<<endl;	
			
				}else{
					cout<<"\nContacto guardado"<<endl;
				}
					p++;*/
				system("pause");
			break;	                
             }
         case 2:{
            /* string nombre1;
             p=0;
             bool auxiliar=false;
             int p1=0;
                system("cls");
                
              cout<<"\n\t\tDigite el nombre del contacto a eliminar: ";
              nombre1=ingresarLetras();
            

           	do{   	
              	if(lista[p1]->buscar(p1,lista,nombre1)==true){
              	auxiliar=true;
              	p=p1;
				}
				  p1++;
			  }while(p1<50);
			  
              if(auxiliar==true){
              	cout<<"\nContacto existente"<<endl;
              	
              	
              	while(lista[p]!=NULL){
				  lista[p]->eliminarElemento(p,lista,teleCasa,celular,nombre,apellido,cedula,cumpleDia,cumpleMes,cumpleAnio,correo,direccion,aniverDia,aniverMes,aniverAnio,nota);			  
			}
              	
           			
		   
		   }else{
		   	system("cls");
		   	cout<<"\nContacto No resgistrado";
		   }
                
                system("pause");
                */
                break;
         }
         case 3:{
         	/*
         			p=0;
         			bool auxiliar=false;
         			int p1=0;	
         
         			int cumpleDia1,cumpleMes1,cumpleAnio1,aniverDia1,aniverMes1,aniverAnio1;
   					string nombre1,nombre2,apellido1,correo1,nota1,direccion1;
					long int teleCasa1,celular1,cedula1;
         	
              system("cls");
              cout<<"\n\t\tDigite el nombre del contacto a modificar: ";
              nombre1=ingresarLetras();
            

           	do{   	
              	if(lista[p1]->buscar(p1,lista,nombre1)==true){
              	auxiliar=true;
              	p=p1;
				}
				  p1++;
			  }while(p1<50);
			  
              if(auxiliar==true){
              	cout<<"\nContacto existente"<<endl;
              	system("pause");
              	system("cls");
              	fflush(stdin); 
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
					
					cout<<"Ingrese el nuevo nombre: ";
					nombre2=ingresarLetras();
					lista[p]->modificarNombre(p,lista,nombre2);
						cout<<"\nContacto modificado";
              		system("pause");
              		fflush(stdin); 
              		break;
              		
              		case 2:
              		system("cls");
					
					cout<<"Ingrese el nuevo apellido: ";
					apellido1=ingresarLetras();
					lista[p]->modificarApellido(p,lista,apellido1);
						cout<<"\nContacto modificado";
              		system("pause");
              		fflush(stdin); 
              		break;
              		
              		case 3:
              		system("cls");
						cout<<"Ingrese el nuevo telefono de casa: ";
					cin>>teleCasa1;
					lista[p]->modificarTeleCasa(p,lista,teleCasa1);
						cout<<"\nContacto modificado";
              		system("pause");
              		fflush(stdin); 
              		break;
              		
              		case 4:
              		system("cls");
						cout<<"Ingrese el nuevo celular: ";
					cin>>celular1;
					lista[p]->modificarCelular(p,lista,celular1);
						cout<<"\nContacto modificado";
              		system("pause");
              		fflush(stdin); 
              		break;
              		
              		case 5:
              		system("cls");
					cedula1=validarCedula();
					lista[p]->modificarCedula(p,lista,cedula1);
						cout<<"\nContacto modificado";
              		system("pause");
              		fflush(stdin); 
              		break;
              		
              		case 6:
              		system("cls");
						cout<<"Ingrese el nuevo dia de cumpleanios: ";
					cin>>cumpleDia1;
					cout<<"Ingrese el nuevo mes de cumpleanios: ";
					cin>>cumpleMes1;
					cout<<"Ingrese el nuevo anio de cumpleanios: ";
					cin>>cumpleAnio1;
					lista[p]->modificarCumpleanios(p,lista,cumpleDia1,cumpleMes1,cumpleAnio1);
						cout<<"\nContacto modificado";
              		system("pause");
              		fflush(stdin); 
              		break;
              		
              		case 7:
              		system("cls");
					cout<<"Ingrese el nuevo correo: ";
					getline(cin,correo1);
					lista[p]->modificarCorreo(p,lista,correo1); 
              		system("pause");
              		fflush(stdin); 
              		break;
              		
              		case 8:
              		system("cls");
					cout<<"Ingrese la nueva direccion: ";
					direccion1=ingresarLetras();
					lista[p]->modificarDireccion(p,lista,direccion1);
              		system("pause");
              		fflush(stdin); 
              		break;
              		
              		case 9:
              		system("cls");
					cout<<"Ingrese el nuevo dia de aniversario: ";
					cin>>aniverDia1;
					cout<<"Ingrese el nuevo mes de aniversario: ";
					cin>>aniverMes1;
					cout<<"Ingrese el nuevo anio de aniversario: ";
					cin>>aniverAnio1;
					lista[p]->modificarAniversario(p,lista,aniverDia1,aniverMes1,aniverAnio1);
              		system("pause");
              		fflush(stdin); 
              		break;
              		
              		case 10:
              		system("cls");
					cout<<"Ingrese la nueva nota: ";
					getline(cin,nota1);
					lista[p]->modificarNota(p,lista,nota1);
              		system("pause");
              		fflush(stdin); 
              		break;
              		
              		case 11:
              		repite2=false;
              		break;
				  }
	
			  }while(repite2);              	
			}else{
			  	cout<<"\nContacto no registrado"<<endl;
			  }
              
              cout<<endl;
              
            system("pause");
            */
         break;
         }
        case 4: {
        	
        	
                 system("cls");
                
                cout<<endl<<"==================================================================================================";
                cout<<"\t\t\tLISTA DE CONTACTOS "<<endl;
                cout<<"=================================================================================================="<<endl<<endl;
                cout<<endl<<endl;
                
				obj.mostrarLista(inicio);
                //if(ext==true) lista->mostrarExtra(p,lista);
                cout<<endl;
                fflush(stdin); 
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












