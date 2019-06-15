#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <string.h>
#include <fstream>

#include "Persona.h"

using namespace std;

class Nodo{
	public:
		Nodo *sig;
		Nodo *ant;
		Persona persona;
		
		void insertarNodo();
		void mostrarListaPU();
		void mostrarListaUP();
		void modificarNodo();
		void eliminarNodo();
		void menuDinamico();
		void cargarCVS();
	private:
		
};

Nodo *primero,*ultimo;

void Nodo::insertarNodo(){
	string nombre,apellido,cedula,sueldo;
	string telefonoCasa,cumpleDia,cumpleMes,cumpleAnio,aniverDia,aniverMes,aniverAnio,celular,correo,nota,direccion;
	Nodo *nuevoNodo= new Nodo();
	cout<<endl<<endl;
	//Nombre
	cout<<"\tIngrese el nombre de la persona: ";
	cin>>nombre;
	nuevoNodo->persona.setNombre(nombre);
	//Apellido
	cout<<"\tIngrese el apellido de la persona: ";
	cin>>apellido;
	nuevoNodo->persona.setApellido(apellido);
	//Telefono Casa
	cout<<"\tIngrese el telefono de Casa: ";
	cin>>telefonoCasa;
	nuevoNodo->persona.setTelefonoCasa(telefonoCasa);
	//Celular
	cout<<"\tIngrese el celular: ";
	cin>>celular;
	nuevoNodo->persona.setCelular(celular);
	//Correo
	cout<<"\tIngrese el correo: ";
	cin>>correo;
	nuevoNodo->persona.setCorreo(correo);
	//Direccion
	cout<<"\tIngrese la direccion: ";
	cin>>direccion;
	nuevoNodo->persona.setDireccion(direccion);
	//Cedula
	cout<<"\tIngrese la cedula de la persona: ";
	cin>>cedula;
	nuevoNodo->persona.setCedula(cedula);
	//Cumpleaños
	cout<<"\tIngrese el cumple Dia: ";
	cin>>cumpleDia;
	nuevoNodo->persona.setCumpleDia(cumpleDia);
	cout<<"\tIngrese el cumple Mes: ";
	cin>>cumpleMes;
	nuevoNodo->persona.setCumpleMes(cumpleMes);
	cout<<"\tIngrese el cumple Anio: ";
	cin>>cumpleAnio;
	nuevoNodo->persona.setCumpleAnio(cumpleAnio);
	//Aniversario
	cout<<"\tIngrese el aniver Dia: ";
	cin>>aniverDia;
	nuevoNodo->persona.setAniverDia(aniverDia);
	cout<<"\tIngrese el aniver Mes: ";
	cin>>aniverMes;
	nuevoNodo->persona.setAniverMes(aniverMes);
	cout<<"\tIngrese el aniver Anio: ";
	cin>>aniverAnio;
	nuevoNodo->persona.setAniverAnio(aniverAnio);
	//Nota
	cout<<"\tIngrese una nota: ";
	cin>>nota;
	nuevoNodo->persona.setNota(nota);
	//CVS
	ofstream agregarTxt;
	fflush(stdin);
	agregarTxt.open("AgendaTemp.csv",ios::app);
	agregarTxt<<"\n"<<";"<<"Nombre: "<<";"<<nombre;
	agregarTxt<<"\n"<<";"<<"Apellido: "<<";"<<apellido;
	agregarTxt<<"\n"<<";"<<"Telefono de Casa: "<<";"<<telefonoCasa;
	agregarTxt<<"\n"<<";"<<"Celular: "<<";"<<celular;
	agregarTxt<<"\n"<<";"<<"Correo: "<<";"<<correo;
	agregarTxt<<"\n"<<";"<<"Direccion: "<<";"<<direccion;
	agregarTxt<<"\n"<<";"<<"Cedula: "<<";"<<cedula;
	agregarTxt<<"\n"<<";"<<"Cumpleanios: "<<";"<<cumpleDia+"/"+cumpleMes+
	"/"+cumpleAnio;
	agregarTxt<<"\n"<<";"<<"Aniversario: "<<";"<<aniverDia+"/"+aniverMes+
	"/"+aniverAnio;
	agregarTxt<<"\n"<<";"<<"Nota: "<<";"<<nota;
	agregarTxt<<"\n";
	agregarTxt.close();
	//
	if(primero==NULL){
		primero=nuevoNodo;
		primero->sig=NULL;
		primero->ant=NULL;
		ultimo=primero;
	}else{
		ultimo->sig=nuevoNodo;
		nuevoNodo->sig=NULL;
		nuevoNodo->ant=ultimo;
		ultimo=nuevoNodo;
	}
}
void Nodo::cargarCVS(){
	Nodo *actual = new Nodo();
	//Cargar CVS
	int lineas=0;
	ifstream archivo;
	string texto="",textoAcumulado="";
	archivo.open("AgendaTemp.csv",ios::in);
	if(archivo.fail()){
		cout<<"\tNo se pudo abrir el archivo...";
	}else{
		while(!archivo.eof()){
		lineas++;
		getline(archivo,texto);
		textoAcumulado+=texto;
		}
		cout<<endl;
		archivo.close();
		//split char[]
		string palabras[lineas*2];
		string palabrasCorreccion[(lineas*2)-1];
		string datosLista[lineas];
		const unsigned int stat = textoAcumulado.length() + 1;
		char* textoAcumChars;
		textoAcumChars=new char[stat];
		char *textoSeparado = strtok(textoAcumChars, ";");
		strcpy(textoAcumChars, textoAcumulado.c_str());
		int cont = 0,cont2 = 0,cont3 = 0;
		while (textoSeparado != NULL) {
			palabras[cont] = textoSeparado;
			if(cont>0){
				palabrasCorreccion[cont3]=palabras[cont];
				if(!(cont3%2==0)){
				datosLista[cont2]=palabrasCorreccion[cont3];
				cout << datosLista[cont2] << cont2<<endl;
				cont2++;
				}
				cont3++;
			}
			textoSeparado = strtok(NULL, ";");
			cont++;
		}
		//Llenando lista
		int contPersonas=0,totalPersonas=0;
		for(int i=1;i<=cont2;i++){
			cout<<"\n -> "<<i<<endl;
			//Conteo personas
			if(i%10==0){
				cout<<"entro"<<endl;
				contPersonas++;
			}
		}
		//Mini vevctores de cada atributo para n Personas
		totalPersonas=contPersonas;
		string nombrePersonas[totalPersonas],apellidoPersonas[totalPersonas],cedulaPersonas[totalPersonas],sueldoPersonas[totalPersonas];
		string telefonoCasaPersonas[totalPersonas],cumpleDiaPersonas[totalPersonas],cumpleMesPersonas[totalPersonas],
		cumpleAnioPersonas[totalPersonas],aniverDiaPersonas[totalPersonas],aniverMesPersonas[totalPersonas],aniverAnioPersonas[totalPersonas],
		celularPersonas[totalPersonas],correoPersonas[totalPersonas],notaPersonas[totalPersonas],direccionPersonas[totalPersonas];
		int j=0,acum2=0;
		for(int i=1;i<=cont2;i++){
			//Otra persona
			if(i%10==0){
				nombrePersonas[j]=datosLista[1+acum2];
				apellidoPersonas[j]=datosLista[2+acum2];
				telefonoCasaPersonas[j]=datosLista[3+acum2];
				celularPersonas[j]=datosLista[4+acum2];
				correoPersonas[j]=datosLista[5+acum2];
				direccionPersonas[j]=datosLista[6+acum2];
				cedulaPersonas[j]=datosLista[7+acum2];
				cumpleAnioPersonas[j]=datosLista[8+acum2];
				aniverAnioPersonas[j]=datosLista[9+acum2];
				notaPersonas[j]=datosLista[10+acum2];
				j++;
				acum2+=10;
			}
		}
		int numNodos=0;
		string nombre,apellido,cedula,sueldo;
		string telefonoCasa,cumpleDia,cumpleMes,cumpleAnio,
		aniverDia,aniverMes,aniverAnio,celular,correo,nota,direccion;
		while(numNodos!=totalPersonas){
			Nodo *nuevoNodo= new Nodo();
			nombre=nombrePersonas[numNodos];
			nuevoNodo->persona.setNombre(nombre);
			apellido=apellidoPersonas[numNodos];
			nuevoNodo->persona.setApellido(apellido);
			telefonoCasa=telefonoCasaPersonas[numNodos];
			nuevoNodo->persona.setTelefonoCasa(telefonoCasa);
			celular=celularPersonas[numNodos];
			nuevoNodo->persona.setCelular(celular);
			correo=correoPersonas[numNodos];
			nuevoNodo->persona.setCorreo(correo);
			direccion=direccionPersonas[numNodos];
			nuevoNodo->persona.setDireccion(direccion);
			cedula=cedulaPersonas[numNodos];
			nuevoNodo->persona.setCedula(cedula);
			cumpleAnio=cumpleAnioPersonas[numNodos];
			nuevoNodo->persona.setCumpleAnio(cumpleAnio);
			aniverAnio=aniverAnioPersonas[numNodos];
			nuevoNodo->persona.setAniverAnio(aniverAnio);
			nota=notaPersonas[numNodos];
			nuevoNodo->persona.setNota(nota);
			if(primero==NULL){
			primero=nuevoNodo;
			primero->sig=NULL;
			primero->ant=NULL;
			ultimo=primero;
			}else{
				ultimo->sig=nuevoNodo;
				nuevoNodo->sig=NULL;
				nuevoNodo->ant=ultimo;
				ultimo=nuevoNodo;
			}
			numNodos++;
		}
	}
}

void Nodo::mostrarListaPU(){
	Nodo *actual = new Nodo();
	actual = primero;
	cout<<endl<<endl;
	int i=0;
	if(primero!=NULL){
		while(actual!=NULL){
		i++;
		cout<<"----------------------\n";
		cout<<"Nombre: "<<actual->persona.getNombre()<<endl;
		cout<<"Apellido: "<<actual->persona.getApellido()<<endl;
		cout<<"Telefono de Casa: "<<actual->persona.getTelefonoCasa()<<endl;
		cout<<"Celular: "<<actual->persona.getCelular()<<endl;
		cout<<"Correo: "<<actual->persona.getCorreo()<<endl;
		cout<<"Direccion: "<<actual->persona.getDireccion()<<endl;
		cout<<"Cedula: "<<actual->persona.getCedula()<<endl;
		cout<<"Cumpleanios: "<<actual->persona.getCumpleanios()<<endl;
		cout<<"Aniversario: "<<actual->persona.getAniversario()<<endl;
		cout<<"Nota: "<<actual->persona.getNota()<<endl;
		cout<<"----------------------\n";
		actual=actual->sig;
		}
	}else{
		cout<<"\tLista vacia..."<<endl;
	}
	cout<<endl<<endl;
	getch();
}

void Nodo::mostrarListaUP(){
	Nodo *actual = new Nodo();
	actual = ultimo;
	cout<<endl<<endl;
	if(primero!=NULL){
		while(actual!=NULL){
		cout<<"----------------------\n";
		cout<<"Nombre: "<<actual->persona.getNombre()<<endl;
		cout<<"Apellido: "<<actual->persona.getApellido()<<endl;
		cout<<"Telefono de Casa: "<<actual->persona.getTelefonoCasa()<<endl;
		cout<<"Celular: "<<actual->persona.getCelular()<<endl;
		cout<<"Correo: "<<actual->persona.getCorreo()<<endl;
		cout<<"Direccion: "<<actual->persona.getDireccion()<<endl;
		cout<<"Cedula: "<<actual->persona.getCedula()<<endl;
		cout<<"Cumpleanios: "<<actual->persona.getCumpleDia()+"/"+actual->persona.getCumpleMes()+
		"/"+actual->persona.getCumpleAnio()<<endl;
		cout<<"Aniversario: "<<actual->persona.getAniverDia()+"/"+actual->persona.getAniverMes()+
		"/"+actual->persona.getAniverAnio()<<endl;
		cout<<"Nota: "<<actual->persona.getNota()<<endl;
		cout<<"----------------------\n";
		actual=actual->ant;
		}
	}else{
		cout<<"\tLista vacia...";
	}
	cout<<endl<<endl;
	getch();
}

void Nodo::modificarNodo(){
	string nombre,apellido,cedula,sueldo;
	Nodo *actual = new Nodo();
	actual = primero;
	bool band=false;
	string cmpNombreStr;
	cout<<endl<<endl;
	cout<<"\tIngrese el nombre de la persona a modificar: ";
	cin>>cmpNombreStr;
	if(primero!=NULL){
		while(actual!=NULL&&band!=true){
			if(actual->persona.getNombre()==cmpNombreStr){
				cout<<"\tPersona "<<cmpNombreStr<<" encontrada"<<endl<<endl;
					cout<<"----------------------\n";
					cout<<"Nombre: "<<actual->persona.getNombre()<<endl;
					cout<<"Apellido: "<<actual->persona.getApellido()<<endl;
					cout<<"Telefono de Casa: "<<actual->persona.getTelefonoCasa()<<endl;
					cout<<"Celular: "<<actual->persona.getCelular()<<endl;
					cout<<"Correo: "<<actual->persona.getCorreo()<<endl;
					cout<<"Direccion: "<<actual->persona.getDireccion()<<endl;
					cout<<"Cedula: "<<actual->persona.getCedula()<<endl;
					cout<<"Cumpleanios: "<<actual->persona.getCumpleDia()+"/"+actual->persona.getCumpleMes()+
					"/"+actual->persona.getCumpleAnio()<<endl;
					cout<<"Aniversario: "<<actual->persona.getAniverDia()+"/"+actual->persona.getAniverMes()+
					"/"+actual->persona.getAniverAnio()<<endl;
					cout<<"Nota: "<<actual->persona.getNota()<<endl;
					cout<<"----------------------\n";
				cout<<"\tPersona modificada... ";
				band=true;
			}
			actual=actual->sig;
		}
		if(!band){
			cout<<"\tPersona no encontrada...";
		}
	}else{
		cout<<"\tLista vacia...";
	}
	cout<<endl<<endl;
	
}

void Nodo::eliminarNodo(){
	Nodo *actual = new Nodo();
	actual = primero;
	Nodo *anterior = new Nodo();
	anterior = NULL;
	bool band=false;
	string cmpNombreStr;
	cout<<endl<<endl;
	cout<<"\tIngrese el nombre de la persona a eliminar: ";
	cin>>cmpNombreStr;
	if(primero!=NULL){
		while(actual!=NULL&&band!=true){
			if(actual->persona.getNombre()==cmpNombreStr){
				cout<<"\tPersona "<<cmpNombreStr<<" encontrada"<<endl<<endl;
				if(actual==primero){
					primero=primero->sig;
					primero->ant=NULL;
				}else if(actual==ultimo){
					anterior->sig=NULL;
					ultimo=anterior;
				}else{
					anterior->sig=actual->sig;
					actual->sig->ant=anterior;
				}
				cout<<endl<<endl;
				cout<<"\tPersona eliminada... ";
				band=true;
			}
			anterior=actual;
			actual=actual->sig;
		}
		if(!band){
			cout<<"\tPersona no encontrada...";
		}
	}else{
		cout<<"\tLista vacia...";
	}
	cout<<endl<<endl;
	
}
