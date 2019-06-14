
//UNIVERSIDAD DE LAS FUERZAS ARMADAS "ESPE"
//ESTRUCTURAS DE DATOS
//VICTOR JIMENEZ, SEBASTIAN LANDAZURI, BRYAN ZURITA
//14/06/2019

#include "Nodo.h"
#include "Validacion.h"
#include <windows.h>
#include <stdio.h>
#include <fstream>
#include <iostream>
#define ARRIBA 72
#define ABAJO 80
#define DERECHA 77
#define IZQUIERDA 75
#define ENTER 13

using namespace std;

int seleccionar2(const char *[],int);

void menu(Nodo *,Nodo *,int);
//void menuPila();
void gotoxy(int,int);
ifstream f;
ofstream temp;
int menuOp(const char titulo[], const char *opciones[], int n);
Nodo *inicio= NULL;
Nodo *ultimo= NULL;
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
//menuPila();
menu(inicio,ultimo,0);
cout<<endl;
system("pause");
return 0;
}

int seleccionar2(const char *opciones2[],int n)
{
	int tecla;
	bool repetir = true;
	int opcselec = 2; //vertical y=2
	do
	{
		system("cls");
		gotoxy(5,1);
		printf("================================================");
		gotoxy(5,opcselec);
		printf(">");
		for(int i=0; i<n; i++)
		{
			gotoxy(7,2+(i*1));
			printf("%s",*(opciones2+i));
		}
		gotoxy(5,10);
	//	color(158);
		printf("================================================");
		do
		{
			tecla = getch();
		}while((tecla != ARRIBA) && (tecla != ABAJO) && (tecla != ENTER)&& (tecla != 59));

		switch(tecla)
			{
			case ABAJO:
				opcselec += 1;
				if(opcselec > (n+1))
					opcselec = 2;
				break;
			case ARRIBA:
				opcselec -= 1;
				if(opcselec < 2)
					opcselec = (n+1);
				break;
			case ENTER:
				repetir = false;
				break;
			case 59:
				system("cls");
				cout<<"Ayuda"<<endl;
				system("ayuda.chm");
				system("pause");
				system("cls");
				menu(inicio,ultimo,0);
				repetir = false;
				break;
			}
	}while(repetir);
	return opcselec;
}

void gotoxy(int x, int y) //referencia: https://www.youtube.com/watch?v=evmIH4nyTgE
{
	HANDLE hCon;
	hCon=GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X=x;
	dwPos.Y=y;
	SetConsoleCursorPosition(hCon,dwPos);
}


void qrgen1(char* n, char* a)
{
	string lineas="";
	string ao="\"";
	printf(ao.c_str());
	string na=string(n);
	string ap=string(a);
	string tot=na+ap+".png";
	string cmd;
	ifstream fe("temp.txt");
   	while(!fe.eof()) 
   	{
   		getline (fe,lineas);
   		ao=ao+lineas+" ";
   	}
   	ao=ao +"\"";
   	fe.close();
   	system("del temp.txt");
   	printf(ao.c_str());
   	printf("\n");
    cmd="qrcode.exe -o "+tot+" -s 10 -l H " +ao ;
    printf(cmd.c_str());
    printf("\n");
    system(cmd.c_str());
    system(tot.c_str());
    
}
void qrgen2(char* m)
{
	string lineas="";
	string ao="\"";
	printf(ao.c_str());
	string na=string(m);
	string tot=na+".png";
	string cmd;
	ifstream fe("temp.txt");
   	while(!fe.eof()) 
   	{
   		getline (fe,lineas);
   		ao=ao+lineas+" ";
   	}
   	ao=ao +"\"";
   	fe.close();
   	system("del temp.txt");
   	printf(ao.c_str());
   	printf("\n");
    cmd="qrcode.exe -o "+tot+" -s 10 -l H " +ao ;
    printf(cmd.c_str());
    printf("\n");
    system(cmd.c_str());
    system(tot.c_str());
    
}

void menu(Nodo *inicio,Nodo *ultimo,int opcion)
{
    int pos=1;
    
    		int cumpleDia1,cumpleMes1,cumpleAnio1,aniverDia1,aniverMes1,aniverAnio1,opc1;
  	 char *correo1,*nota1,*direccion1;
     int cedula1;
     	char *nombre1,*nombre2;
	nombre1=(char*)malloc(15*sizeof(char));
	nombre2=(char*)malloc(15*sizeof(char));
	correo1=(char*)malloc(50*sizeof(char));
	nota1=(char*)malloc(50*sizeof(char));
	direccion1=(char*)malloc(20*sizeof(char));
	char *apellido1;
    apellido1=(char*)malloc(15*sizeof(char));
    int celular1;
	int teleCasa1;
	int nu=11;
    
    
    
    int cumpleDia,cumpleMes,cumpleAnio,aniverDia,aniverMes,aniverAnio;
  	 char *correo,*nota,*direccion;
     int cedula;
    
    bool ext=false;
  
	int opc,tecla,n=7;
	char *nombre;
	nombre=(char*)malloc(15*sizeof(char));
	correo=(char*)malloc(50*sizeof(char));
	nota=(char*)malloc(50*sizeof(char));
	direccion=(char*)malloc(20*sizeof(char));
	char *apellido;
    apellido=(char*)malloc(15*sizeof(char));
    Nodo p = Nodo();
	int celular;
	int teleCasa;
	int elemento=0;
	bool repetir = true;
	bool repite2 = true;
	system("cls");
	const char *opciones[]={"INGRESAR CONTACTO","INGRESAR DATOS EXTRAS","MODIFICAR CONTACTO","ELIMINAR PERSONA","MOSTRAR CONTACTOS","GENERAR PDF DE CONTACTOS","SALIR"};
	do
	{
		opc = seleccionar2(opciones,n);
		switch(opc)
		{
			case 2:
				//INSERTAR
				fflush(stdin);
				printf("\nIngrese el nombre de la persona: ");
				nombre = ingresarLetras();
				printf("\nIngrese el apellido de la persona: ");
				apellido = ingresarLetras();
				printf("\nCelular: ");
                cin>>celular;
                printf("\nCasa: ");
                cin>>teleCasa;

				temp.open("temp.txt",ios::app);
    			temp<<"Nombre: "<<nombre;
    			temp<<"\nApellido: "<<apellido;
    			temp<<"\nTelefono de casa: "<<teleCasa;
    			temp<<"\nCelular: "<<"0"<<celular;
    			temp<<"\n";
				temp.close();
				qrgen1(nombre,apellido);
				p.insertarInicio(inicio,ultimo,nombre,apellido,celular,teleCasa);
				
                cout<<endl;
				system("Pause");
                break;
            case 3:
				//INSERTAR
				fflush(stdin);
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
				correo=ingresarLetras();
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
				temp.open("temp.txt",ios::app);
   				temp<<"\nCumpleanios: "<<";"<<cumpleDia<<"/"<<cumpleMes<<"/"<<cumpleAnio;
    			temp<<"\nCorreo: "<<";"<<correo;
    			temp<<"\nDireccion: "<<";"<<direccion;
    			temp<<"\nAniversario: "<<";"<<aniverDia<<"/"<<aniverMes<<"/"<<aniverAnio;
    			temp<<"\nNota: "<<";"<<nota;
    			temp.close();
    			qrgen2(correo);
				p.insertarExtra(inicio,ultimo,cedula, cumpleDia, cumpleMes, cumpleAnio, correo, direccion, aniverDia, aniverMes, aniverAnio, nota);
				cout<<endl;
				system("Pause");
				
                break;


			case 4:
				
				fflush(stdin);
				system("cls");

			
			cout<<"\n\t\tDigite el nombre del contacto a modificar: ";
			nombre1=ingresarLetras();
				
				if(p.buscar(inicio,nombre1)==true){
					
				
			const char *opcion[]={"NOMBRE", "APELLIDO","TELEFONO DE CASA","CELULAR","CEDULA","CUMPLEANIOS","CORREO","DIRECCION","ANIVERSARIO","NOTA","SALIR"};
			
			do{

			
			opc1 = seleccionar2(opcion,nu);
			
			switch(opc1){
				case 2:
              		system("cls");
					
					
					
					cout<<"Ingrese el nuevo nombre: ";
					nombre2=ingresarLetras();
					p.modificarNombre(inicio,nombre2);
						cout<<"\nContacto modificado";
              		system("pause");
              		break;
              		
              		case 3:
              		system("cls");
					
					cout<<"Ingrese el nuevo apellido: ";
					apellido1=ingresarLetras();
					p.modificarApellido(inicio,apellido1);
						cout<<"\nContacto modificado";
              		system("pause");
              		break;
              		
              		case 4:
              		system("cls");
						cout<<"Ingrese el nuevo telefono de casa: ";
					cin>>teleCasa1;
					p.modificarTeleCasa(inicio,teleCasa1);
						cout<<"\nContacto modificado";
              		system("pause");
              		break;
              		
              		case 5:
              		system("cls");
						cout<<"Ingrese el nuevo celular: ";
					cin>>celular1;
					p.modificarCelular(inicio,celular1);
						cout<<"\nContacto modificado";
              		system("pause");
              		break;
              		
              		case 6:
              		system("cls");
					cedula1=validarCedula();
					p.modificarCedula(inicio,cedula1);
						cout<<"\nContacto modificado";
              		system("pause");
              		break;
              		
              		case 7:
              		system("cls");
						cout<<"Ingrese el nuevo dia de cumpleanios: ";
					cin>>cumpleDia1;
					cout<<"Ingrese el nuevo mes de cumpleanios: ";
					cin>>cumpleMes1;
					cout<<"Ingrese el nuevo anio de cumpleanios: ";
					cin>>cumpleAnio1;
					p.modificarCumpleanios(inicio,cumpleDia1,cumpleMes1,cumpleAnio1);
						cout<<"\nContacto modificado";
              		system("pause");
              		break;
              		
              		case 8:
              		system("cls");
					cout<<"Ingrese el nuevo correo: ";
					correo1=ingresarLetras();
					p.modificarCorreo(inicio,correo1); 
              		system("pause");
              		break;
              		
              		case 9:
              		system("cls");
					cout<<"Ingrese la nueva direccion: ";
					direccion1=ingresarLetras();
					p.modificarDireccion(inicio,direccion1);
              		system("pause");
              		break;
              		
              		case 10:
              		system("cls");
					cout<<"Ingrese el nuevo dia de aniversario: ";
					cin>>aniverDia1;
					cout<<"Ingrese el nuevo mes de aniversario: ";
					cin>>aniverMes1;
					cout<<"Ingrese el nuevo anio de aniversario: ";
					cin>>aniverAnio1;
					p.modificarAniversario(inicio,aniverDia1,aniverMes1,aniverAnio1);
              		system("pause");
              		break;
              		
              		case 11:
              		system("cls");
					cout<<"Ingrese la nueva nota: ";
					nota1=ingresarLetras();
					p.modificarNota(inicio,nota1);
              		system("pause");
              		break;
              		
              		case 12:
              		repite2=false;
              		break;
				  }

			}while(repite2);
			
		}else{
			cout<<"\nContacto no registrado"<<endl;
		}
				fflush(stdin);
				cout<<endl;
				system("Pause");
				
                break;
			
            case 5:
				fflush(stdin);
				if(inicio!=NULL){
                cout<<"\n\nDigite el nombre de la persona que desea eliminar: ";
                nombre=ingresarLetras();
				p.eliminarPersonaNodo(inicio,ultimo,nombre);
				fflush(stdin);
				}else{
                    cout<<"\nLa lista se encuentra vacia!!!!";
				}
				fflush(stdin);
				cout<<endl;
				system("Pause");
				
				break;
            case 6:
                fflush(stdin);
				p.mostrarLista(inicio);
				if(ext==true) p.mostrarExtra(inicio);
				cout<<endl;
				system("Pause");
				break;
             case 7:
                
                f.open("Agenda.csv", std::fstream::in);
                
              	if(!f.good())
              	{
              		system("cls");
              		cout<<"ERROR: El archivo de agenda no esta creado\n";
              		system("pause");
				}
				else
				{
					f.close();
					system("cls");
					system("txt2pdf.exe Agenda.csv Agenda.pdf -oao -ptc255 -pps43 -width2000 -height1000");
              		cout<<"Archivo generado exitosamente\n";
              		system("pause");
						
				}
				break;
			 case 8:
                //SALIR
				repetir = false;
				break;
		}
	}while(repetir);
}

