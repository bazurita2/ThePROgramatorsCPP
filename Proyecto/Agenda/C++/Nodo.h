#ifndef NODO_H
#define NODO_H
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "Contacto.h"

using namespace std;
class Nodo
{
    private:
        Contacto *contacto;
        Nodo *siguiente;
        Nodo *anterior;
    public:
        Nodo();
        void setNodo(Nodo *);
        Nodo* getNodo();
        bool validarNodo(Nodo *,Nodo *);
        int tamanioNodo(Nodo *);
        void insertarInicio(Nodo *&,Nodo *&,long int, long int, string,string);
        void mostrarLista(Nodo *);
        void eliminarPersonaNodo(Nodo *&,Nodo *&,int);
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

void Nodo::insertarInicio(Nodo *&inicio,Nodo *&ultimo,long int teleCasa,long int celu,string nomb,string apell){
    Nodo *nuevo=new Nodo();
    contacto = (Contacto*)malloc(sizeof(Contacto));
    contacto->nombre = nomb;
    contacto->apellido = apell;
    contacto->celular= celu;
    contacto->telefonoCasa=teleCasa;
    nuevo->contacto= contacto;
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
        cout<<"\nNombre: "<<lista->contacto->nombre;
        cout<<"\nApellido: "<<lista->contacto->apellido;
        cout<<"\nCelular: "<<lista->contacto->celular;
        cout<<"\nTelefono casa: "<<lista->contacto->telefonoCasa;
        cout<<"\n---------------------------------";
        lista = lista->siguiente;
            }
        }
    }

/*
bool Nodo::verificarCedulaRegistro(Nodo *&inicio,int cedula){
    while(inicio!=NULL){
        if(inicio->persona->ced == cedula){
            return true;
        }
    }
    return false;
}

void Nodo::eliminarPersonaNodo(Nodo *&inicio,Nodo *&ultimo,int cedula){
    Nodo *actual = new Nodo();
    actual = inicio;
    Nodo *nodo_anterior= new Nodo();
    nodo_anterior=NULL;
    bool encontrado =false;
    if(inicio!=NULL){
        while(actual!=NULL && encontrado != true){
            if(actual->persona->ced == cedula){
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

*/
#endif // NODO_H
