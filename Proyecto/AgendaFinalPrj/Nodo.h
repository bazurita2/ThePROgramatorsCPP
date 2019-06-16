
//UNIVERSIDAD DE LAS FUERZAS ARMADAS "ESPE"
//ESTRUCTURAS DE DATOS
//VICTOR JIMENEZ, SEBASTIAN LANDAZURI, BRYAN ZURITA
//14/06/2019

#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <string.h>
#include <fstream>
#include <map>
#include "Validar.h"
//#include <jdbc/cppconn/driver.h>
//#include <jdbc/cppconn/exception.h>
//#include <jdbc/cppconn/resultset.h>
//#include <jdbc/mysql_connection.h>
//#include <jdbc/cppconn/statement.h>

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
		void cargarCSV();
		void sql();
		void qrgen(string, string);
	private:
		
};

Nodo *primero,*ultimo;

//void Nodo::sql(){
//	try 
//	{
//		sql::Driver *driver;
//  		sql::Connection *con;
//  		sql::Statement *stmt;
//  		sql::ResultSet *res;
//  		driver = get_driver_instance();
//  		con = driver->connect("tcp://127.0.0.1:3306", "root", "cedptmc04");
//  		con->setSchema("agenda");
//		stmt = con->createStatement();
// 		res = stmt->executeQuery("SELECT 'Hello World!' AS _message");
//  		while (res->next()) 
//		{
//    		cout << "\t... MySQL replies: ";
//    		cout << res->getString("_message") << endl;
//    		cout << "\t... MySQL says it again: ";
//    		cout << res->getString(1) << endl;
// 		 }
//  	delete res;
//  	delete stmt;
//  	delete con;
//  	} 
//	catch (sql::SQLException &e) 
//  	
//	{
//  		cout << "# ERR: SQLException in " << __FILE__;
//  		//cout << "(" << __FUNCTION__ << ") on line " »<< __LINE__ << endl;
//  		cout << "# ERR: " << e.what();
//  		cout << " (MySQL error code: " << e.getErrorCode();
//  		cout << ", SQLState: " << e.getSQLState() << " )" << endl;
//	}
//
//
//}
	
void Nodo::qrgen(string n, string a){
	string lineas="";
	string ao="\"";
	string tot=n+a+".png";
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
    cmd="qrcode.exe -o "+tot+" -s 10 -l H " +ao ;
    printf("\n");
    system(cmd.c_str());
    system(tot.c_str());

}

void Nodo::insertarNodo(){
	string nombre,apellido,telefonoCasa,celular,correo,
	direccion,cedula,cumpleDia,cumpleMes,cumpleAnio,cumpleanios,
	aniverDia,aniverMes,aniverAnio,aniversario,nota;
	
	Nodo *nuevoNodo= new Nodo();
	cout<<endl<<endl;
	//Nombre
	cout<<"\n\tIngrese el nombre de la persona: ";
	nombre=ingresarLetras();
	nuevoNodo->persona.setNombre(nombre);
	//Apellido
	cout<<"\n\tIngrese el apellido de la persona: ";
	apellido=ingresarLetras();
	nuevoNodo->persona.setApellido(apellido);
	//Telefono Casa
	cout<<"\n\tIngrese el telefono de Casa: ";
	telefonoCasa=ingresarCasa();
	nuevoNodo->persona.setTelefonoCasa(telefonoCasa);
	//Celular
	cout<<"\n\tIngrese el celular: ";
	celular=ingresarCelular();
	nuevoNodo->persona.setCelular(celular);
	//Correo
	cout<<"\n\tIngrese el correo: ";
	cin>>correo;
	nuevoNodo->persona.setCorreo(correo);
	//Direccion
	cout<<"\n\tIngrese la direccion: ";
	cin>>direccion;
	nuevoNodo->persona.setDireccion(direccion);
	//Cedula
	cedula=validarCedula();
	nuevoNodo->persona.setCedula(cedula);
	//Cumpleaños
	do{
	cout<<"\n\tIngrese el cumple Dia: ";
	cumpleDia=ingresarDia();
	}while(cumpleDia<"01"||cumpleDia>"31");
	nuevoNodo->persona.setCumpleDia(cumpleDia);
	do{
	cout<<"\n\tIngrese el cumple Mes: ";
	cumpleMes=ingresarMes();
	}while(cumpleMes<"01"||cumpleMes>"12");
	nuevoNodo->persona.setCumpleMes(cumpleMes);
	do{
	cout<<"\n\tIngrese el cumple Anio: ";
	cumpleAnio=ingresarAnio();
	}while(cumpleAnio<"1900"||cumpleAnio>"2019");
	nuevoNodo->persona.setCumpleAnio(cumpleAnio);
	cumpleanios=nuevoNodo->persona.getCumpleDia()+"/"+nuevoNodo->persona.getCumpleMes()+"/"+nuevoNodo->persona.getCumpleAnio();
	nuevoNodo->persona.setCumpleanios(cumpleanios);
	//Aniversario
	do{
	cout<<"\n\tIngrese el aniver Dia: ";
	aniverDia=ingresarDia();
	}while(aniverDia<"01"||aniverDia>"31");
	nuevoNodo->persona.setAniverDia(aniverDia);
	do{
	cout<<"\n\tIngrese el aniver Mes: ";
	aniverMes=ingresarMes();
	}while(aniverMes<"01"||aniverMes>"12");
	nuevoNodo->persona.setAniverMes(aniverMes);
	do{
	cout<<"\n\tIngrese el aniver Anio: ";
	aniverAnio=ingresarAnio();
	}while(aniverAnio<"1900"||aniverAnio>"2019");
	nuevoNodo->persona.setAniverAnio(aniverAnio);
	aniversario=nuevoNodo->persona.getAniverDia()+"/"+nuevoNodo->persona.getAniverMes()+"/"+nuevoNodo->persona.getAniverAnio();
	nuevoNodo->persona.setAniversario(aniversario);
	//Nota
	cout<<"\n\tIngrese una nota: ";
	cin>>nota;
	nuevoNodo->persona.setNota(nota);
	//CVS
	ofstream agregarTxt;
	ofstream temp;
	fflush(stdin);
	agregarTxt.open("Agenda.csv",ios::app);
	agregarTxt<<"\n"<<";"<<"Nombre: "<<";"<<nuevoNodo->persona.getNombre();
	agregarTxt<<"\n"<<";"<<"Apellido: "<<";"<<nuevoNodo->persona.getApellido();
	agregarTxt<<"\n"<<";"<<"Telefono de Casa: "<<";"<<nuevoNodo->persona.getTelefonoCasa();
	agregarTxt<<"\n"<<";"<<"Celular: "<<";"<<nuevoNodo->persona.getCelular();
	agregarTxt<<"\n"<<";"<<"Correo: "<<";"<<nuevoNodo->persona.getCorreo();
	agregarTxt<<"\n"<<";"<<"Direccion: "<<";"<<nuevoNodo->persona.getDireccion();
	agregarTxt<<"\n"<<";"<<"Cedula: "<<";"<<nuevoNodo->persona.getCedula();
	agregarTxt<<"\n"<<";"<<"Cumpleanios: "<<";"<<nuevoNodo->persona.getCumpleanios();
	agregarTxt<<"\n"<<";"<<"Aniversario: "<<";"<<nuevoNodo->persona.getAniversario();
	agregarTxt<<"\n"<<";"<<"Nota: "<<";"<<nuevoNodo->persona.getNota();
	agregarTxt<<"\n";
	agregarTxt.close();
	fflush(stdin);
	temp.open("temp.txt",ios::out);
	temp<<"\n"<<"Nombre: "<<nuevoNodo->persona.getNombre();
	temp<<"\n"<<"Apellido: "<<nuevoNodo->persona.getApellido();
	temp<<"\n"<<"Telefono de Casa: "<<nuevoNodo->persona.getTelefonoCasa();
	temp<<"\n"<<"Celular: "<<nuevoNodo->persona.getCelular();
	temp<<"\n"<<"Correo: "<<nuevoNodo->persona.getCorreo();
	temp<<"\n"<<"Direccion: "<<nuevoNodo->persona.getDireccion();
	temp<<"\n"<<"Cedula: "<<nuevoNodo->persona.getCedula();
	temp<<"\n"<<"Cumpleanios: "<<nuevoNodo->persona.getCumpleanios();
	temp<<"\n"<<"Aniversario: "<<nuevoNodo->persona.getAniversario();
	temp<<"\n"<<"Nota: "<<nuevoNodo->persona.getNota();
	temp<<"\n";
	temp.close();
	qrgen(nuevoNodo->persona.getNombre(),nuevoNodo->persona.getApellido());

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

void Nodo::cargarCSV(){
	Nodo *actual = new Nodo();
	//Cargar CSV
	int lineas=0;
	ifstream archivo;
	string texto="",textoAcumulado="";
	archivo.open("Agenda.csv",ios::in);
	if(archivo.fail()){
		cout<<"\n\n\tNo se pudo abrir el archivo...\n";
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
			//Conteo personas
			if(i%10==0){
				contPersonas++;
			}
		}
		//Mini vectores de cada atributo para n Personas
		totalPersonas=contPersonas;
		string nombrePersonas[totalPersonas],apellidoPersonas[totalPersonas],telefonoCasaPersonas[totalPersonas],celularPersonas[totalPersonas],
		correoPersonas[totalPersonas],direccionPersonas[totalPersonas],cedulaPersonas[totalPersonas],cumpleaniosPersonas[totalPersonas],
		aniversarioPersonas[totalPersonas],notaPersonas[totalPersonas];
		int j=0,acum2=0;
		for(int i=1;i<=cont2;i++){
			//Otra persona
			if(i%10==0){
				nombrePersonas[j]=datosLista[0+acum2];
				apellidoPersonas[j]=datosLista[1+acum2];
				telefonoCasaPersonas[j]=datosLista[2+acum2];
				celularPersonas[j]=datosLista[3+acum2];
				correoPersonas[j]=datosLista[4+acum2];
				direccionPersonas[j]=datosLista[5+acum2];
				cedulaPersonas[j]=datosLista[6+acum2];
				cumpleaniosPersonas[j]=datosLista[7+acum2];
				aniversarioPersonas[j]=datosLista[8+acum2];
				notaPersonas[j]=datosLista[9+acum2];
				j++;
				acum2+=10;
			}
		}
		int numNodos=0;
		string nombre,apellido,telefonoCasa,celular,
		correo,direccion,cedula,cumpleanios,aniversario,nota;
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
			cumpleanios=cumpleanios[numNodos];
			nuevoNodo->persona.setCumpleanios(cumpleanios);
			aniversario=aniversario[numNodos];
			nuevoNodo->persona.setAniversario(aniversario);
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
		cout<<"Cumpleanios: "<<actual->persona.getCumpleanios()<<endl;
		cout<<"Aniversario: "<<actual->persona.getAniversario()<<endl;
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
	string nombre,apellido,telefonoCasa,celular,correo,
	direccion,cedula,cumpleDia,cumpleMes,cumpleAnio,cumpleanios,
	aniverDia,aniverMes,aniverAnio,aniversario,nota;
	
	Nodo *actual = new Nodo();
	actual = primero;
	bool band=false;
	string cmpNombreStr;
	cout<<endl<<endl;
	cout<<"\n\tIngrese el nombre de la persona a modificar: ";
	cmpNombreStr=ingresarLetras();
	if(primero!=NULL){
		while(actual!=NULL&&band!=true){
			if(actual->persona.getNombre()==cmpNombreStr){
				cout<<"\n\tPersona "<<cmpNombreStr<<" encontrada"<<endl<<endl;
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
				cout<<"\t\nModificar esta persona:\n";
				//Nombre
				cout<<"\n\tIngrese el nombre de la persona: ";
				nombre=ingresarLetras();
				actual->persona.setNombre(nombre);
				//Apellido
				cout<<"\n\tIngrese el apellido de la persona: ";
				apellido=ingresarLetras();
				actual->persona.setApellido(apellido);
				//Telefono Casa
				cout<<"\n\tIngrese el telefono de Casa: ";
				telefonoCasa=ingresarCasa();
				actual->persona.setTelefonoCasa(telefonoCasa);
				//Celular
				cout<<"\n\tIngrese el celular: ";
				celular=ingresarCelular();
				actual->persona.setCelular(celular);
				//Correo
				cout<<"\n\tIngrese el correo: ";
				cin>>correo;
				actual->persona.setCorreo(correo);
				//Direccion
				cout<<"\n\tIngrese la direccion: ";
				cin>>direccion;
				actual->persona.setDireccion(direccion);
				//Cedula
				cedula=validarCedula();
				actual->persona.setCedula(cedula);
				//Cumpleaños
				do{
				cout<<"\n\tIngrese el cumple Dia: ";
				cumpleDia=ingresarDia();
				}while(cumpleDia<"01"||cumpleDia>"31");
				actual->persona.setCumpleDia(cumpleDia);
					do{
				cout<<"\n\tIngrese el cumple Mes: ";
				cumpleMes=ingresarMes();
				}while(cumpleMes<"01"||cumpleMes>"12");
				actual->persona.setCumpleMes(cumpleMes);
				do{
				cout<<"\n\tIngrese el cumple Anio: ";
				cumpleAnio=ingresarAnio();
				}while(cumpleAnio<"1900"||cumpleAnio>"2019");
				actual->persona.setCumpleAnio(cumpleAnio);
				cumpleanios=actual->persona.getCumpleDia()+"/"+actual->persona.getCumpleMes()+"/"+actual->persona.getCumpleAnio();
				actual->persona.setCumpleanios(cumpleanios);
				//Aniversario
				do{
				cout<<"\n\tIngrese el aniver Dia: ";
				aniverDia=ingresarDia();
				}while(aniverDia<"01"||aniverDia>"31");
				actual->persona.setAniverDia(aniverDia);
					do{
				cout<<"\n\tIngrese el aniver Mes: ";
				aniverMes=ingresarMes();
				}while(aniverMes<"01"||aniverMes>"12");
				actual->persona.setAniverMes(aniverMes);
					do{
				cout<<"\n\tIngrese el aniver Anio: ";
				aniverAnio=ingresarAnio();
				}while(aniverAnio<"1900"||aniverAnio>"2019");
				actual->persona.setAniverAnio(aniverAnio);
				aniversario=actual->persona.getAniverDia()+"/"+actual->persona.getAniverMes()+"/"+actual->persona.getAniverAnio();
				actual->persona.setAniversario(aniversario);
				//Nota
				cout<<"\n\tIngrese una nota: ";
				cin>>nota;
				actual->persona.setNota(nota);
				cout<<"\n\tPersona modificada... ";
				band=true;
			}
			actual=actual->sig;
		}
		if(!band){
			cout<<"\n\tPersona no encontrada...";
		}
		
		//Archivo CSV Modificar Persona
		ifstream originalArchivo;
		originalArchivo.open("Agenda.csv",ios::in);
		
		ofstream copiaArchivo;
		copiaArchivo.open("AgendaTemp.csv",ios::out);
		
		if(originalArchivo.fail()){
			cout<<"\n\n\tNo se pudo abrir el archivo...\n";
		}else{
			string texto="",textoAcumulado="";
			int lineas=0;
			while(!originalArchivo.eof()){
				lineas++;
				getline(originalArchivo,texto);
				textoAcumulado+=texto;
			}
			cout<<endl;
			originalArchivo.close();
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
				//Conteo personas
				if(i%10==0){
					contPersonas++;
				}
			}
			//Mini vectores de cada atributo para n Personas
			totalPersonas=contPersonas;
			string nombrePersonas[totalPersonas],apellidoPersonas[totalPersonas],telefonoCasaPersonas[totalPersonas],celularPersonas[totalPersonas],
			correoPersonas[totalPersonas],direccionPersonas[totalPersonas],cedulaPersonas[totalPersonas],cumpleaniosPersonas[totalPersonas],
			aniversarioPersonas[totalPersonas],notaPersonas[totalPersonas];
			
			int j=0,acum2=0;
			for(int i=1;i<=cont2;i++){
				//Otra persona
				if(i%10==0){
					nombrePersonas[j]=datosLista[0+acum2];
					apellidoPersonas[j]=datosLista[1+acum2];
					telefonoCasaPersonas[j]=datosLista[2+acum2];
					celularPersonas[j]=datosLista[3+acum2];
					correoPersonas[j]=datosLista[4+acum2];
					direccionPersonas[j]=datosLista[5+acum2];
					cedulaPersonas[j]=datosLista[6+acum2];
					cumpleaniosPersonas[j]=datosLista[7+acum2];
					aniversarioPersonas[j]=datosLista[8+acum2];
					notaPersonas[j]=datosLista[9+acum2];
					j++;
					acum2+=10;
				}
			}
			
			string nombreDato,apellidoDato,telefonoCasaDato,celularDato,
			correoDato,direccionDato,cedulaDato,cumpleaniosDato,aniversarioDato,notaDato;
			
			ofstream datosArchivo;
			datosArchivo.open("AgendaDatosTemp.txt",ios::out);
			
			for(int i=0;i<totalPersonas;i++){
				nombreDato=nombrePersonas[i];
				apellidoDato=apellidoPersonas[i];
				telefonoCasaDato=telefonoCasaPersonas[i];
				celularDato=celularPersonas[i];
				correoDato=correoPersonas[i];
				direccionDato=direccionPersonas[i];
				cedulaDato=cedulaPersonas[i];
				cumpleaniosDato=cumpleaniosPersonas[i];
				aniversarioDato=aniversarioPersonas[i];
				notaDato=notaPersonas[i];
				//
				cout<<nombreDato<<" "<<apellidoDato<<" "<<telefonoCasaDato<<" "<<celularDato<<" "<<
				correoDato<<" "<<direccionDato<<" "<<cedulaDato<<" "<<cumpleaniosDato<<" "<<aniversarioDato<<" "<<
				notaDato<<"\n";
				//
				datosArchivo<<nombreDato<<" "<<apellidoDato<<" "<<telefonoCasaDato<<" "<<celularDato<<" "<<
				correoDato<<" "<<direccionDato<<" "<<cedulaDato<<" "<<cumpleaniosDato<<" "<<aniversarioDato<<" "<<
				notaDato<<"\n";
			}
			
			datosArchivo.close();
			
			//Abrir de nuevo el archivo
			ifstream datosArchivoTemp;
			datosArchivoTemp.open("AgendaDatosTemp.txt",ios::in);
			
			if(datosArchivoTemp.fail()){
				cout<<"\n\n\tNo se pudo abrir el archivo...\n";
			}else{
				//Archivo Modificado
				
				string nombreNoMod,apellidoNoMod,telefonoCasaNoMod,celularNoMod,
				correoNoMod,direccionNoMod,cedulaNoMod,cumpleaniosNoMod,aniversarioNoMod,notaNoMod;
				
				string nombreMod=nombre,apellidoMod=apellido,telefonoCasaMod=telefonoCasa,celularMod=celular,correoMod=correo,
				direccionMod=direccion,cedulaMod=cedula,cumpleDiaMod=cumpleDia,cumpleMesMod=cumpleMes,cumpleAnioMod=cumpleAnio,cumpleaniosMod=cumpleanios,
				aniverDiaMod=aniverDia,aniverMesMod=aniverMes,aniverAnioMod=aniverAnio,aniversarioMod=aniversario,notaMod=nota;
				
				datosArchivoTemp>>nombreNoMod;
				
				while(!datosArchivoTemp.eof()){
					
					datosArchivoTemp>>apellidoNoMod>>telefonoCasaNoMod>>celularNoMod>>correoNoMod>>direccionNoMod>>cedulaNoMod>>
						cumpleaniosNoMod>>aniversarioNoMod>>notaNoMod;
						
					if(cmpNombreStr==nombreNoMod){
						cout<<"\nContacto "<<cmpNombreStr<<" modificar...\n";					
						cout<<"\tModificar esta persona:\n";
						//Cambiar en CSV
						copiaArchivo<<"\n"<<";"<<"Nombre: "<<";"<<nombreMod;
						copiaArchivo<<"\n"<<";"<<"Apellido: "<<";"<<apellidoMod;
						copiaArchivo<<"\n"<<";"<<"Telefono de Casa: "<<";"<<telefonoCasaMod;
						copiaArchivo<<"\n"<<";"<<"Celular: "<<";"<<celularMod;
						copiaArchivo<<"\n"<<";"<<"Correo: "<<";"<<correoMod;
						copiaArchivo<<"\n"<<";"<<"Direccion: "<<";"<<direccionMod;
						copiaArchivo<<"\n"<<";"<<"Cedula: "<<";"<<cedulaMod;
						copiaArchivo<<"\n"<<";"<<"Cumpleanios: "<<";"<<cumpleaniosMod;
						copiaArchivo<<"\n"<<";"<<"Aniversario: "<<";"<<aniversarioMod;
						copiaArchivo<<"\n"<<";"<<"Nota: "<<";"<<notaMod;
						copiaArchivo<<"\n";
					}else{
						copiaArchivo<<"\n"<<";"<<"Nombre: "<<";"<<nombreNoMod;
						copiaArchivo<<"\n"<<";"<<"Apellido: "<<";"<<apellidoNoMod;
						copiaArchivo<<"\n"<<";"<<"Telefono de Casa: "<<";"<<telefonoCasaNoMod;
						copiaArchivo<<"\n"<<";"<<"Celular: "<<";"<<celularNoMod;
						copiaArchivo<<"\n"<<";"<<"Correo: "<<";"<<correoNoMod;
						copiaArchivo<<"\n"<<";"<<"Direccion: "<<";"<<direccionNoMod;
						copiaArchivo<<"\n"<<";"<<"Cedula: "<<";"<<cedulaNoMod;
						copiaArchivo<<"\n"<<";"<<"Cumpleanios: "<<";"<<cumpleaniosNoMod;
						copiaArchivo<<"\n"<<";"<<"Aniversario: "<<";"<<aniversarioNoMod;
						copiaArchivo<<"\n"<<";"<<"Nota: "<<";"<<notaNoMod;
						copiaArchivo<<"\n";
					}
					
					datosArchivoTemp>>nombreNoMod;
				}
			}
			
			copiaArchivo.close();
			originalArchivo.close();
			datosArchivoTemp.close();
			
			remove("Agenda.csv");
			remove("AgendaDatosTemp.txt");
			rename("AgendaTemp.csv","Agenda.csv");
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
	cout<<"\n\tIngrese el nombre de la persona a eliminar: ";
	cin>>cmpNombreStr;
	if(primero!=NULL){
		while(actual!=NULL&&band!=true){
			if(actual->persona.getNombre()==cmpNombreStr){
				cout<<"\n\tPersona "<<cmpNombreStr<<" encontrada"<<endl<<endl;
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
			cout<<"\n\tPersona no encontrada...";
		}
	}else{
		cout<<"\tLista vacia...";
	}
	cout<<endl<<endl;
	
	//Archivo CSV Eliminar Persona
	ifstream originalArchivo;
	originalArchivo.open("Agenda.csv",ios::in);
	
	ofstream copiaArchivo;
	copiaArchivo.open("AgendaTemp.csv",ios::out);
	
	if(originalArchivo.fail()){
		cout<<"\n\n\tNo se pudo abrir el archivo...\n";
	}else{
		string texto="",textoAcumulado="";
		int lineas=0;
		while(!originalArchivo.eof()){
			lineas++;
			getline(originalArchivo,texto);
			textoAcumulado+=texto;
		}
		cout<<endl;
		originalArchivo.close();
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
			//Conteo personas
			if(i%10==0){
				contPersonas++;
			}
		}
		//Mini vectores de cada atributo para n Personas
		totalPersonas=contPersonas;
		string nombrePersonas[totalPersonas],apellidoPersonas[totalPersonas],telefonoCasaPersonas[totalPersonas],celularPersonas[totalPersonas],
		correoPersonas[totalPersonas],direccionPersonas[totalPersonas],cedulaPersonas[totalPersonas],cumpleaniosPersonas[totalPersonas],
		aniversarioPersonas[totalPersonas],notaPersonas[totalPersonas];
		
		int j=0,acum2=0;
		for(int i=1;i<=cont2;i++){
			//Otra persona
			if(i%10==0){
				nombrePersonas[j]=datosLista[0+acum2];
				apellidoPersonas[j]=datosLista[1+acum2];
				telefonoCasaPersonas[j]=datosLista[2+acum2];
				celularPersonas[j]=datosLista[3+acum2];
				correoPersonas[j]=datosLista[4+acum2];
				direccionPersonas[j]=datosLista[5+acum2];
				cedulaPersonas[j]=datosLista[6+acum2];
				cumpleaniosPersonas[j]=datosLista[7+acum2];
				aniversarioPersonas[j]=datosLista[8+acum2];
				notaPersonas[j]=datosLista[9+acum2];
				j++;
				acum2+=10;
			}
		}
		
		string nombreDato,apellidoDato,telefonoCasaDato,celularDato,
		correoDato,direccionDato,cedulaDato,cumpleaniosDato,aniversarioDato,notaDato;
		
		ofstream datosArchivo;
		datosArchivo.open("AgendaDatosTemp.txt",ios::out);
		
		for(int i=0;i<totalPersonas;i++){
			nombreDato=nombrePersonas[i];
			apellidoDato=apellidoPersonas[i];
			telefonoCasaDato=telefonoCasaPersonas[i];
			celularDato=celularPersonas[i];
			correoDato=correoPersonas[i];
			direccionDato=direccionPersonas[i];
			cedulaDato=cedulaPersonas[i];
			cumpleaniosDato=cumpleaniosPersonas[i];
			aniversarioDato=aniversarioPersonas[i];
			notaDato=notaPersonas[i];
			//
			cout<<nombreDato<<" "<<apellidoDato<<" "<<telefonoCasaDato<<" "<<celularDato<<" "<<
			correoDato<<" "<<direccionDato<<" "<<cedulaDato<<" "<<cumpleaniosDato<<" "<<aniversarioDato<<" "<<
			notaDato<<"\n";
			//
			datosArchivo<<nombreDato<<" "<<apellidoDato<<" "<<telefonoCasaDato<<" "<<celularDato<<" "<<
			correoDato<<" "<<direccionDato<<" "<<cedulaDato<<" "<<cumpleaniosDato<<" "<<aniversarioDato<<" "<<
			notaDato<<"\n";
		}
		
		datosArchivo.close();
		
		//Abrir de nuevo el archivo
		ifstream datosArchivoTemp;
		datosArchivoTemp.open("AgendaDatosTemp.txt",ios::in);
		
		if(datosArchivoTemp.fail()){
			cout<<"\n\n\tNo se pudo abrir el archivo...\n";
		}else{
			//Archivo Modificado
			
			string nombre,apellido,telefonoCasa,celular,
			correo,direccion,cedula,cumpleanios,aniversario,nota;
			
			datosArchivoTemp>>nombre;
			
			while(!datosArchivoTemp.eof()){
				
				datosArchivoTemp>>apellido>>telefonoCasa>>celular>>correo>>direccion>>cedula>>
					cumpleanios>>aniversario>>nota;
					
				if(cmpNombreStr==nombre){
					cout<<"\nContacto "<<cmpNombreStr<<" eliminado...\n";
					getch();
				}else{
					copiaArchivo<<"\n"<<";"<<"Nombre: "<<";"<<nombre;
					copiaArchivo<<"\n"<<";"<<"Apellido: "<<";"<<apellido;
					copiaArchivo<<"\n"<<";"<<"Telefono de Casa: "<<";"<<telefonoCasa;
					copiaArchivo<<"\n"<<";"<<"Celular: "<<";"<<celular;
					copiaArchivo<<"\n"<<";"<<"Correo: "<<";"<<correo;
					copiaArchivo<<"\n"<<";"<<"Direccion: "<<";"<<direccion;
					copiaArchivo<<"\n"<<";"<<"Cedula: "<<";"<<cedula;
					copiaArchivo<<"\n"<<";"<<"Cumpleanios: "<<";"<<cumpleanios;
					copiaArchivo<<"\n"<<";"<<"Aniversario: "<<";"<<aniversario;
					copiaArchivo<<"\n"<<";"<<"Nota: "<<";"<<nota;
					copiaArchivo<<"\n";
				}
				
				datosArchivoTemp>>nombre;
			}
		}
		
		copiaArchivo.close();
		originalArchivo.close();
		datosArchivoTemp.close();
		
		remove("Agenda.csv");
		remove("AgendaDatosTemp.txt");
		rename("AgendaTemp.csv","Agenda.csv");
		}
	
}
