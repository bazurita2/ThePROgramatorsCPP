#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <fstream>
using namespace std;


class Nodo{
	private:
		long int cedula;
		long int telefonoCasa;
		int cumpleDia;
		int cumpleMes;
		int cumpleAnio;
		int aniverDia;
		int aniverMes;
		int aniverAnio;
		long int celular;
		string nombre;
		string apellido;
		string correo;
		string nota;
 		string direccion;
		Nodo *sig;
		
	public:
		
		Nodo ();
		
		long int getCedula(){
			return cedula;
		}
		long int getTelefonoCasa(){
			return telefonoCasa;
		}
		int getCumpleDia(){
			return cumpleDia;
		}
		int getCumpleMes(){
			return cumpleMes;
		}
		int getCumpleAnio(){
			return cumpleAnio;
		}
		int getAniverDia(){
			return aniverDia;
		}
		int getAniverMes(){
			return aniverMes;
		}
		int getAniverAnio(){
			return aniverAnio;
		}
		long int getCelular(){
			return celular;
		}
		string getNombre(){
			return nombre;
		}
		string getApellido(){
			return apellido;
		}
		string getCorreo(){
			return correo;
		}
		string getNota(){
			return nota;
		}
		string getDireccion(){
			return direccion;
		}
		
		void setCedula(long int cedula){
			this->cedula=cedula;
		}
		void setTelefonoCasa(int telefonoCasa){
			this->telefonoCasa=telefonoCasa;
		}
		void setCumpleDia(int cumpleDia){
			this->cumpleDia=cumpleDia;
		}
		void setCumpleMes(int cumpleMes){
			this->cumpleMes=cumpleMes;
		}
		void setCumpleAnio(int cumpleAnio){
			this->cumpleAnio=cumpleAnio;
		}
		int setAniverDia(int aniverDia){
			this->aniverDia=aniverDia;
		}
		void setAniverMes(int aniverMes){
			this->aniverMes=aniverMes;
		}
		void setAniverAnio(int aniverAnio){
			this->aniverAnio=aniverAnio;
		}
		void setCelular(long int celular){
			this->celular=celular;
		}
		void setNombre(string nombre){
			this->nombre=nombre;
		}
		void setApellido(string apellido){
			this->apellido=apellido;
		}
		void setCorreo(string correo){
			this->correo=correo;
		}
		void setNota(string nota){
			this->nota=nota;
		}
		void setDireccion(string direccion){
			this->direccion=direccion;
		}
		
		void insertarInicio(Nodo *&,long int, long int, string,string);
		void insertarInicioExtra(Nodo *&,long int ,int ,int ,int ,string ,string ,int ,int ,int ,string);
		void mostrar(Nodo *);
		void mostrarExtra(Nodo *);
		bool eliminarElemento(Nodo*& );
		bool modificarNombre(Nodo *&,string,string);
		bool modificarApellido(Nodo *&,string,string);
		bool modificarTeleCasa(Nodo *&,long int,long int);
		bool modificarCelular(Nodo *&,long int,long int);
		bool modificarCedula(Nodo *&,long int,long int);
		bool modificarCumpleanios(Nodo *&,int,int,int,int,int,int);
		bool modificarCorreo(Nodo *&,string,string);
		bool modificarDireccion(Nodo *&,string,string);
		bool modificarAniversario(Nodo *&,int,int,int,int,int,int);
		
		Nodo *getSig(){
			return sig;
		}

		void setSig(Nodo *s){
			sig = s;
		}
	
};

Nodo::Nodo(){
}

void Nodo::insertarInicio(Nodo *&lista,long int teleCasa,long int celu,string nomb,string apell){
	Nodo *nuevo = new Nodo();
	
	ofstream agregarTxt;
    fflush(stdin);
    agregarTxt.open("Agenda.csv",ios::app);
    agregarTxt<<"\nNombre: "<<";"<<nomb;
    agregarTxt<<"\nApellido: "<<";"<<apell;
    agregarTxt<<"\nTelefono de casa: "<<";"<<teleCasa;
    agregarTxt<<"\nCelular: "<<";"<<"0"<<celu;
    agregarTxt<<"\n"<<";";
    agregarTxt.close();
	
	nuevo->nombre=nomb;
	nuevo->telefonoCasa=teleCasa;
	nuevo->celular=celu;
	nuevo->nombre=nomb;
	nuevo->apellido=apell;
	
		nuevo->sig=lista;
		lista=nuevo;	
	
}

void Nodo::insertarInicioExtra(Nodo *&lista,long int cedula,int cumpleDia,int cumpleMes,int cumpleAnio,string correo,string direccion,int aniverDia,int aniverMes,int aniverAnio,string nota){
	Nodo *nuevo = new Nodo();

	ofstream agregarTxt;
    fflush(stdin);
    agregarTxt.open("Agenda.csv",ios::app);
    agregarTxt<<"\nCedula: "<<";"<<cedula;
    agregarTxt<<"\nCumpleanios: "<<";"<<cumpleDia<<"/"<<cumpleMes<<"/"<<cumpleAnio;
    agregarTxt<<"\nCorreo: "<<";"<<correo;
    agregarTxt<<"\nDireccion: "<<";"<<direccion;
    agregarTxt<<"\nAniversario: "<<";"<<aniverDia<<"/"<<aniverMes<<"/"<<aniverAnio;
    agregarTxt<<"\nNota: "<<";"<<nota;
    agregarTxt<<"\n"<<";";
    agregarTxt.close();
	
	nuevo->cedula=cedula;
	nuevo->cumpleDia=cumpleDia;
	nuevo->cumpleMes=cumpleMes;
	nuevo->cumpleAnio=cumpleAnio;
	nuevo->correo=correo;
	nuevo->direccion=direccion;
	nuevo->aniverDia=aniverDia;
	nuevo->aniverMes=aniverMes;
	nuevo->aniverAnio=aniverAnio;
	nuevo->nota=nota;
	
		nuevo->sig=lista;
		lista=nuevo;	
	
}


void Nodo::mostrar(Nodo *lista){	
	Nodo *actual = new Nodo();
	actual = lista;
	while(actual != NULL){ 
		cout<<endl;
		cout<<"Nombre: "<<actual->nombre<<"\nApellido: "<<actual->apellido<<"\nTelefono casa: "<<actual->telefonoCasa<<"\nCelular: 0"<<actual->celular<<endl;
		actual = actual->sig; 
	}

}

void Nodo::mostrarExtra(Nodo *lista){	
	Nodo *actual = new Nodo();
	actual = lista;
	while(actual != NULL){ 
		cout<<endl;
		cout<<"Cedula: "<<actual->cedula<<"\nCumpleanios: "<<actual->cumpleDia<<"/"<<cumpleMes<<"/"<<cumpleAnio<<"\nCorreo: "<<actual->correo
		<<"\nDireccion: "<<actual->direccion<<"\nAniversario: "<<actual->aniverDia<<"/"<<actual->aniverMes<<"/"<<actual->aniverAnio<<"\nNota: "<<actual->nota<<endl;	
		actual = actual->sig; 
	}

}


  //valor2 = modificar
	//valor1 = dato en lista

bool Nodo::modificarNombre(Nodo*& _lista,string nombre1,string nombre2){
	  bool aux=false;
    Nodo *actual =new Nodo();
    actual=_lista;
    while(actual!=NULL){
        if((actual->dato)==valor1){
            actual->dato=valor2;
            aux=true;
        }
        actual=actual->sig;
    }
    return aux;
}

bool Nodo::modificarApellido(Nodo*& _lista,string apellido1,string apellido2){
	  bool aux=false;
    Nodo *actual =new Nodo();
    actual=_lista;
    while(actual!=NULL){
        if((actual->dato)==valor1){
            actual->dato=valor2;
            aux=true;
        }
        actual=actual->sig;
    }
    return aux;
}
bool Nodo::modificarTeleCasa(Nodo*& _lista,long int teleCasa1,long int teleCasa2){
	  bool aux=false;
    Nodo *actual =new Nodo();
    actual=_lista;
    while(actual!=NULL){
        if((actual->dato)==valor1){
            actual->dato=valor2;
            aux=true;
        }
        actual=actual->sig;
    }
    return aux;
}
bool Nodo::modificarCelular(Nodo*& _lista,long int celular1,long int celular2){
	  bool aux=false;
    Nodo *actual =new Nodo();
    actual=_lista;
    while(actual!=NULL){
        if((actual->dato)==valor1){
            actual->dato=valor2;
            aux=true;
        }
        actual=actual->sig;
    }
    return aux;
}
bool Nodo::modificarCedula(Nodo*& _lista,long int cedula1,long int cedula2){
	  bool aux=false;
    Nodo *actual =new Nodo();
    actual=_lista;
    while(actual!=NULL){
        if((actual->dato)==valor1){
            actual->dato=valor2;
            aux=true;
        }
        actual=actual->sig;
    }
    return aux;
}
bool Nodo::modificarCumpleanios(Nodo*& _lista,int dia1,int mes1,int anio1,int dia2,int mes2,int anio2){
	  bool aux=false;
    Nodo *actual =new Nodo();
    actual=_lista;
    while(actual!=NULL){
        if((actual->dato)==valor1){
            actual->dato=valor2;
            aux=true;
        }
        actual=actual->sig;
    }
    return aux;
}
bool Nodo::modificarCorreo(Nodo*& _lista,string correo1,string correo2){
	  bool aux=false;
    Nodo *actual =new Nodo();
    actual=_lista;
    while(actual!=NULL){
        if((actual->dato)==valor1){
            actual->dato=valor2;
            aux=true;
        }
        actual=actual->sig;
    }
    return aux;
}

bool Nodo::modificarDireccion(Nodo*& _lista,string direccion1,string direccion2){
	  bool aux=false;
    Nodo *actual =new Nodo();
    actual=_lista;
    while(actual!=NULL){
        if((actual->dato)==valor1){
            actual->dato=valor2;
            aux=true;
        }
        actual=actual->sig;
    }
    return aux;
}

bool Nodo::modificarAniversario(Nodo*& _lista,int dia1,int mes1,int anio1,int dia2,int mes2,int anio2){
	  bool aux=false;
    Nodo *actual =new Nodo();
    actual=_lista;
    while(actual!=NULL){
        if((actual->dato)==valor1){
            actual->dato=valor2;
            aux=true;
        }
        actual=actual->sig;
    }
    return aux;
}


