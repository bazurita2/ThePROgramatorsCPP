#ifndef NODO_H
#define NODO_H
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <sstream>
#include <string>
#include "Persona.h"

using namespace std;
class Nodo
{
    private:
    	bool band=false;
        Persona *persona;
        Nodo *siguiente;
        Nodo *anterior;
    public:
        Nodo();
        void setNodo(Nodo *);
        Nodo* getNodo();
        bool validarNodo(Nodo *,Nodo *);
        int tamanioNodo(Nodo *);
        void insertarInicio(Nodo *&,Nodo *&,char *,char *,int,int);
        void insertarExtra(Nodo *&,Nodo *&,int cedula,int cumpleDia,int cumpleMes,int cumpleAnio,char *correo,char *direccion,int aniverDia,int aniverMes,int aniverAnio,char *nota);
        void mostrarLista(Nodo *);
        void mostrarExtra(Nodo *);
        bool buscar(Nodo *,char *);
        bool verificarCedulaRegistro(Nodo *&,char *);
        void borrarPrimerElemento(Nodo *&,Nodo *&);
        void borrarUltimoElemento(Nodo *&,Nodo *&);
        void eliminarPersonaNodo(Nodo *&,Nodo *&,char *);
        void modificarNombre(Nodo *&,char *);
		void modificarApellido(Nodo *&,char *);
		void modificarTeleCasa(Nodo *&,int);
		void modificarCelular(Nodo *&,int);
		void modificarCedula(Nodo *&,int);
		void modificarCumpleanios(Nodo *&,int,int,int);
		void modificarCorreo(Nodo *&,char *);
		void modificarDireccion(Nodo *&,char *);
		void modificarAniversario(Nodo *&,int,int,int);
		void modificarNota(Nodo *&,char *);
};

Nodo::Nodo(){
}

bool Nodo::validarNodo(Nodo *inicio,Nodo *ultimo){
    if(inicio== NULL && ultimo ==NULL){
            return true;
    }else return false;
}

int Nodo::tamanioNodo(Nodo *inicio){
int cont =0;
    while(inicio!=NULL){
    cont++;
    inicio= inicio->siguiente;
    }
    return cont+1;
}

void Nodo::insertarInicio(Nodo *&inicio,Nodo *&ultimo,char *nombre,char *apellido,int celular,int teleCasa){

	ofstream agregarTxt;
	ofstream temp;
    fflush(stdin);
    agregarTxt.open("Agenda.csv",ios::app);
    agregarTxt<<"\nNombre: "<<";"<<nombre;
    agregarTxt<<"\nApellido: "<<";"<<apellido;
    agregarTxt<<"\nTelefono de casa: "<<";"<<teleCasa;
    agregarTxt<<"\nCelular: "<<";"<<"0"<<celular;
    agregarTxt<<"\n"<<";";
    agregarTxt.close();
	Nodo *nuevo=new Nodo();
    //persona = new Persona(nombre,apellido,cedula,sueldo);
    persona = (Persona*)malloc(sizeof(Persona));
    persona->nom = nombre;
    persona->apell = apellido;
    persona->celular = celular;
    persona->telefonoCasa=teleCasa;
    nuevo->persona= persona;
    nuevo->siguiente = NULL;
    nuevo->anterior = NULL;
    if(validarNodo(inicio,ultimo)){
        inicio =nuevo;
        ultimo = nuevo;
    }else{
        nuevo->siguiente = inicio;
        inicio->anterior = nuevo;
        inicio = nuevo;
    }
}

void Nodo::insertarExtra(Nodo *&inicio,Nodo *&ultimo,int cedula,int cumpleDia,int cumpleMes,int cumpleAnio,char *correo,char *direccion,int aniverDia,int aniverMes,int aniverAnio,char *nota){
    
	ofstream agregarTxt;
	ofstream temp;
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
	
	
	Nodo *nuevo=new Nodo();
    //persona = new Persona(nombre,apellido,cedula,sueldo);
    persona = (Persona*)malloc(sizeof(Persona));
    
    
    persona->cedula=cedula;
	persona->cumpleDia=cumpleDia;
	persona->cumpleMes=cumpleMes;
	persona->cumpleAnio=cumpleAnio;
	persona->correo=correo;
	persona->direccion=direccion;
	persona->aniverDia=aniverDia;
	persona->aniverMes=aniverMes;
	persona->aniverAnio=aniverAnio;
	persona->nota=nota;
    
    nuevo->persona= persona;
    nuevo->siguiente = NULL;
    nuevo->anterior = NULL;
    if(validarNodo(inicio,ultimo)){
        inicio =nuevo;
        ultimo = nuevo;
    }else{
        nuevo->siguiente = inicio;
        inicio->anterior = nuevo;
        inicio = nuevo;
    }
}


void Nodo::mostrarLista(Nodo *lista){
    if(lista == NULL){
        cout<<"\nLa lista se encuentra vacia";
    }else{
        while(lista!= NULL){
        cout<<"\n---------------------------------";
        cout<<"\nNombre: "<<lista->persona->nom;
        cout<<"\nApellido: "<<lista->persona->apell;
        cout<<"\nCelular: "<<lista->persona->celular;
        cout<<"\nTelefono de Casa: "<<lista->persona->telefonoCasa;
        cout<<"\n---------------------------------";
        lista = lista->siguiente;
            }
        }
    }
    
bool Nodo::buscar(Nodo *lista,char *nombre){
	
		
    if(lista == NULL){
        cout<<"\nLa lista se encuentra vacia";
    }else{
        while(lista!= NULL){
        if(lista->persona->nom==nombre){
        	band=true;
		}
        lista = lista->siguiente;
            }
        }
   return band;
    }
    
void Nodo::mostrarExtra(Nodo *lista){
    if(lista == NULL){
        cout<<"\nLa lista se encuentra vacia";
    }else{
        while(lista!= NULL){
        cout<<"\n---------------------------------";
        cout<<"Cedula: "<<lista->persona->cedula<<"\nCumpleanios: "<<lista->persona->cumpleDia<<"/"<<lista->persona->cumpleMes<<"/"<<lista->persona->cumpleAnio<<"\nCorreo: "<<lista->persona->correo
		<<"\nDireccion: "<<lista->persona->direccion<<"\nAniversario: "<<lista->persona->aniverDia<<"/"<<lista->persona->aniverMes<<"/"<<lista->persona->aniverAnio<<"\nNota: "<<lista->persona->nota<<endl; 	
        cout<<"\n---------------------------------";
        lista = lista->siguiente;
            }
        }
    }    


bool Nodo::verificarCedulaRegistro(Nodo *&inicio,char *nombre){
    while(inicio!=NULL){
        if(inicio->persona->nom== nombre){
            return true;
        }
    }
    return false;
}


void Nodo::eliminarPersonaNodo(Nodo *&inicio,Nodo *&ultimo,char *nombre){
    Nodo *actual = new Nodo();
    actual = inicio;
    Nodo *nodo_anterior= new Nodo();
    nodo_anterior=NULL;
    bool encontrado =false;
    if(inicio!=NULL){
        while(actual!=NULL && encontrado != true){
            if(actual->persona->nom == nombre){
                if(actual == inicio){
                borrarPrimerElemento(inicio,ultimo);
                }else if(actual==ultimo){
                borrarUltimoElemento(inicio,ultimo);
                }else{
                nodo_anterior->siguiente= actual->siguiente;
                actual->siguiente->anterior = nodo_anterior;
                }
                cout<<"\nPersona Eliminada";
                encontrado=true;
            }
            nodo_anterior = actual;
            actual = actual->siguiente;
        }
        if(!encontrado){
                cout<<"\n La persona no se encuentra Registrada\n";
        }

    }else{
            cout<<"\nLa lista se encuentra vacia\n";
    }
}

void Nodo::borrarPrimerElemento(Nodo *&inicio,Nodo *&ultimo){
{
    Nodo *actual = new Nodo();
    actual =inicio;
    Nodo *actualUltimo = new Nodo();
    actualUltimo=ultimo;
        if(validarNodo(actual,actualUltimo)){
        cout<<"No se puede eliminar!! Lista vacia"<<endl;
        }else{
        if(inicio==ultimo){
                inicio=ultimo=NULL;
            }else{
            Nodo *temp=inicio;
            inicio=inicio->siguiente;
            inicio->anterior=NULL;
            delete temp;
            //cout<<"Elemento eliminado"<<endl;
            }
        }
    }
}

void Nodo::borrarUltimoElemento(Nodo *&inicio,Nodo *&ultimo){
    Nodo *actual = new Nodo();
    actual =inicio;
    Nodo *actualUltimo = new Nodo();
    actualUltimo=ultimo;
    if(validarNodo(actual,actualUltimo)){
    cout<<"No se puede eliminar!! Lista vacia"<<endl;
    }else{
        if(inicio==ultimo){
                inicio=ultimo=NULL;
            }else{
            Nodo *temp=ultimo;
            ultimo=ultimo->anterior;
            ultimo->siguiente=NULL;
            delete temp;
            //cout<<"Elemento eliminado"<<endl;
            }
        }
    }
    
    void Nodo::modificarNombre(Nodo*& _lista,char *nombre1){
	  
    Nodo *actual =new Nodo();
    actual=_lista;
    actual->persona->nom=nombre1; 
}

void Nodo::modificarApellido(Nodo*& _lista,char *apellido1){
	  
    Nodo *actual =new Nodo();
    actual=_lista;
    actual->persona->apell=apellido1;   
}
void Nodo::modificarTeleCasa(Nodo*& _lista, int teleCasa1){
	Nodo *actual =new Nodo();
    actual=_lista;
    actual->persona->telefonoCasa=teleCasa1;
}
void Nodo::modificarCelular(Nodo*& _lista,int celular1){
	  Nodo *actual =new Nodo();
    actual=_lista;
    actual->persona->celular=celular1;
}
void Nodo::modificarCedula(Nodo*& _lista,int cedula1){
	 Nodo *actual =new Nodo();
    actual=_lista;
    actual->persona->cedula=cedula1;
}
void Nodo::modificarCumpleanios(Nodo*& _lista,int dia1,int mes1,int anio1){
	Nodo *actual =new Nodo();
    actual=_lista;
    actual->persona->cumpleDia=dia1;
    actual->persona->cumpleMes=mes1;
    actual->persona->cumpleAnio=anio1;
}
void Nodo::modificarCorreo(Nodo*& _lista,char *correo1){
	Nodo *actual =new Nodo();
    actual=_lista;
    actual->persona->correo=correo1;
}

void Nodo::modificarDireccion(Nodo*& _lista,char *direccion1){
	 Nodo *actual =new Nodo();
    actual=_lista;
    actual->persona->direccion=direccion1;
}

void Nodo::modificarAniversario(Nodo*& _lista,int dia1,int mes1,int anio1){
	 Nodo *actual =new Nodo();
    actual=_lista;
    actual->persona->aniverDia=dia1;
    actual->persona->aniverMes=mes1;
    actual->persona->aniverAnio=anio1;
}
void Nodo::modificarNota(Nodo*& _lista,char *nota1){
	 Nodo *actual =new Nodo();
    actual=_lista;
    actual->persona->nota=nota1;
}

#endif // NODO_H
