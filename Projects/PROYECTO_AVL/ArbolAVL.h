//UNIVERSIDAD DE LAS FUERZAS ARMADAS "ESPE"
//ESTRUCTURA DE DATOS
//VICTOR JIMENEZ, SEBASTIAN LANDAZURI, BRYAN ZURITA
//19/07/2019


#include<iostream>
#include<conio.h>
#include <stdlib.h>
#include<math.h>
#include <fstream>
#include<string.h>
#include <sstream>
#include <graphics.h>
#include "Nodo.h"
#include<stdio.h>
#include <windows.h>
using namespace std;
Nodo *raiz;

class ArbolAVL{
    public:
           int max(int , int );
           int bandera=0;
           int altura( Nodo *);
           Nodo* nuevo_nodo(int );
           void imprimir(Nodo *, int );
           Nodo* RotacionDerecha( Nodo *);
           Nodo* RotacionIzquierda( Nodo *);
           int Balancear( Nodo *);
           Nodo* Insertar( Nodo* , int );
           Nodo * minimoValorNodo( Nodo* );
           Nodo* eliminarNodo( Nodo* , int );
           void buscar(int);
           void intercambiarNodos(Nodo * );
           void borrarHojas();
           void Dibujar(Nodo *, int , int , int , int );
        ArbolAVL()
        {
            raiz = NULL;
        }
};
 /**
* /brief buscar	
*
* Recorre el arbol por sus lados hasta encontrar el dato deseado, en caso de no encontrarlo o estar vacio mostrara su respectivo mensaje
* @param int dato
*/
void ArbolAVL::buscar(int dato)
{
     Nodo *temp = raiz,*padre = raiz;
    if(temp==NULL)
        cout<<"\nEl arbol AVL esta vacio\n"<<endl;
    else
    {
        while(temp!=NULL && temp->dato!=dato)
        {
            padre=temp;
            if(temp->dato<dato)
            {
                temp=temp->derecha;
            }
            else
            {
                temp=temp->izquierda;
            }
        }
    }
    
    if(temp==NULL)
        cout<<"Este elemento no se encunetra en el arbol!";
    else
        {cout<<"\nElemento "<<dato<<" encontrado en el arbol";
        cout<<"\nSu altura es: "<<temp->altura;
        }
        
}
 /**
* /brief intercambiarNodos	
*
* Cuando el arbol esta desvalanceado, intercambia el nodo correspondiente ya sea por la derecha o por izquierda
* @param Nodo *p
*/
void ArbolAVL::intercambiarNodos(Nodo * p)

{
     if(!p) return;
     intercambiarNodos(p->izquierda);
     intercambiarNodos(p->derecha);
     Nodo * temp=p->izquierda;
     p->izquierda=p->derecha;
     p->derecha=temp;
     
}
 /**
* /brief destruirNodo	
*
* Una vez que se balancea el arbol se debe eliminar el nodo que fue movido
* @param Nodo *p
*/
void destruirNodo(Nodo *p)

{
     if(!p) return;
     destruirNodo(p->izquierda);
     destruirNodo(p->derecha);
     delete p;
}
/**
* /brief eliminar	
*
* Mediante la creacion de Nodos auxiliares, elimina el valor del dato que este contenido en el Nodo
* @param Nodo *p
*/
void eliminar(Nodo *p)
{    Nodo* lc=p->izquierda;
     if(lc&&(lc->izquierda||lc->derecha)) eliminar(lc);
     else
     { delete lc;
       p->izquierda=NULL;
     }
     Nodo* rc=p->derecha;
     if(rc&&(rc->izquierda||rc->derecha)) eliminar(rc);
     else
     { delete rc;
       p->derecha=NULL;
     }
}
 /**
* /brief borrarHojas	
*
* En el caso que se desee eliminar un nodo, se verifica si es hoja, si esto cumple la eliminacion es directa 
*/
void ArbolAVL::borrarHojas()

{
     if(!raiz) return;
     if(raiz->izquierda || raiz->derecha) eliminar(raiz);
     else
     destruirNodo(raiz);
}

/**
* /brief max	
*
* Compara los valores de los nodos, retornando el mayor de ellos
* @param int a
* @param int b
* @return (a > b)? a : b;
*/
int ArbolAVL::max(int a, int b)
{
    return (a > b)? a : b;
}
 
/**
* /brief altura	
*
* Verifica si el arbol esta vacio retorna 0, caso contrario retornara la altura del arbol
* @param Nodo *N
* @return 0 || return N->altura
*/
int ArbolAVL::altura( Nodo *N)
{
    if (N == NULL)
        return 0;
    return N->altura;
}
/**
* /brief Dibujar	
*
* Mediante el uso de las funciones de la libreria graphics.h, se procede a graficar de forma dinamica, se aplica recursividad para recorrer los dos lados del arbol 
* @param Nodo *Arbol
* @param int a
* @param int b
* @param int c
* @param int d
*/
void ArbolAVL::Dibujar(Nodo *Arbol, int a, int b, int c, int d){
  string value;
ofstream agregarTxt;
agregarTxt.open("AVL.txt",ios::app); 
  if (Arbol != NULL){
    value = to_string(Arbol->dato);
    char value2[value.length() +1];
    strcpy(value2, value.c_str());
    circle(300 + a, 75 + b, 14);
    agregarTxt<<circle(300 + a, 75 + b, 14);

    setcolor(YELLOW);
    outtextxy(292 + a, 68 + b, value2);
    agregarTxt<<outtextxy(292 + a, 68 + b, value2);
    setcolor(WHITE);
     if (d == 1){
      line(300 + a + pow(2, c + 1), b + 14, 300 + a, 61 + b);
      agregarTxt<<line(300 + a + pow(2, c + 1), b + 14, 300 + a, 61 + b);
  	}
    else if (d == 2){
      line(300 + a - pow(2, c + 1), b + 14, 300 + a, 61 + b);
      agregarTxt<<line(300 + a - pow(2, c + 1), b + 14, 300 + a, 61 + b);
  	}
    Dibujar(Arbol->izquierda, a - pow(2, c) - pow(2, d - 4), b + 75, c - 1, 1);
    Dibujar(Arbol->derecha, a + pow(2, c) + pow(2, d - 4), b + 75, c - 1, 2);
  }
agregarTxt.close();
}
 
/**
* /brief nuevo_nodo	
*
* Reserva espacio de memoria, crea un nodo con sus lados nulos
* @param int dato
* @return nodo
*/
 Nodo* ArbolAVL::nuevo_nodo(int dato){
    Nodo *nodo = (class Nodo*) malloc(sizeof(class Nodo));
    nodo->dato   = dato;
    nodo->izquierda   = NULL;
    nodo->derecha  = NULL;
    nodo->altura = 1;  
    return(nodo);
}
 
  /**
* /brief RotacionDerecha	
*
* Si el arbol esta desbalanceado en su lado izquierdo, se procede a balancear a su derecha
* @param class Nodo *y
* @return x
*/
 Nodo* ArbolAVL::RotacionDerecha(class Nodo *y)
{
     Nodo *x = y->izquierda;
     Nodo *T2 = x->derecha;

    x->derecha = y;
    y->izquierda = T2;
  
    y->altura = max(altura(y->izquierda), altura(y->derecha))+1;
    x->altura = max(altura(x->izquierda), altura(x->derecha))+1;

    return x;
}
 
 /**
* /brief RotacionIzquierda	
*
* Si el arbol esta desbalanceado en su lado derecho, se procede a balancear a su izquierda
* @param Nodo *x
* @return y
*/
 Nodo* ArbolAVL::RotacionIzquierda( Nodo *x)
{
    class Nodo *y = x->derecha;
    class Nodo *T2 = y->izquierda;

    y->izquierda = x;
    x->derecha = T2;

    x->altura = max(altura(x->izquierda), altura(x->derecha))+1;
    y->altura = max(altura(y->izquierda), altura(y->derecha))+1;

    return y;
}
 
/**
* /brief Balancear
*
* Realiza la resta de alturas de su lado izquierdo menos su lado derecho, para comprobar si esta balanceado
* @param Nodo *N
* @return altura(N->izquierda) - altura(N->derecha);
*/
int ArbolAVL::Balancear( Nodo *N)
{
    if (N == NULL)
        return 0;
    return altura(N->izquierda) - altura(N->derecha);
}
 /**
* /brief Insertar
*
* Verifica si el arbol esta vacio, en ese caso lo inserta como raiz, caso contrario compara si es menor o mayor de la raiz, para ponerlo a su derecha o izquierda, llamando a la funcion balancear una vez insertado
* @param Nodo *nodo
* @param int dato
* @return nodo
*/
 Nodo* ArbolAVL::Insertar( Nodo* nodo, int dato)
{
   
    if (nodo == NULL)
        return(nuevo_nodo(dato));
    if (dato < nodo->dato)
        nodo->izquierda  = Insertar(nodo->izquierda, dato);
    else
        nodo->derecha = Insertar(nodo->derecha, dato);
    nodo->altura = max(altura(nodo->izquierda), altura(nodo->derecha)) + 1;

    int balance = Balancear(nodo);

    if (balance > 1 && dato < nodo->izquierda->dato)
        return RotacionDerecha(nodo);

    if (balance < -1 && dato > nodo->derecha->dato)
        return RotacionIzquierda(nodo);
        
    if (balance > 1 && dato > nodo->izquierda->dato)
    {
        nodo->izquierda =  RotacionIzquierda(nodo->izquierda);
        return RotacionDerecha(nodo);
    }
    if (balance < -1 && dato < nodo->derecha->dato)
    {
        nodo->derecha = RotacionDerecha(nodo->derecha);
        return RotacionIzquierda(nodo);
    }
  
    return nodo;
}
/**
* /brief minimoValorNodo
*
* Instancia de un Nodo, recorre el lado izquierdo hasta encontrar el valor menor
* @param Nodo *nodo
* @return aux
*/
 Nodo * ArbolAVL::minimoValorNodo( Nodo* nodo)
{
     class Nodo* aux = nodo;
  
    while (aux->izquierda != NULL)
        aux = aux->izquierda;
    return aux;
}
 /**
* /brief eliminarNodo
*
* Verifica si la raiz esta vacia, si no lo es recorre su lao izquierdo en caso de que sea menor, o lado derecho en caso de que sea mayor hasta encontrar el nodo
* Cuando ha sido encontrado se verifica si es hoja o subraiz, elimina el nodo y procede hacer el balanceo
* @param Nodo *N
* @return altura(N->izquierda) - altura(N->derecha);
*/
 Nodo* ArbolAVL::eliminarNodo( Nodo* raiz, int dato)
{
  
    if (raiz == NULL)
        return raiz;

    if ( dato < raiz->dato )
        raiz->izquierda = eliminarNodo(raiz->izquierda, dato);

    else if( dato > raiz->dato )
        raiz->derecha = eliminarNodo(raiz->derecha, dato);

    else
    {   
        if( (raiz->izquierda == NULL) || (raiz->derecha == NULL) )
        {    Nodo *temp = raiz->izquierda ? raiz->izquierda : raiz->derecha;
            bandera=1;
      
            if(temp == NULL)
            {       
                temp = raiz;
                raiz = NULL;
                bandera=1;
            }
            else 
             {*raiz = *temp;bandera=1;}
        free(temp);
        }
        else
        {   
             Nodo* temp = minimoValorNodo(raiz->derecha);

            raiz->dato = temp->dato;

            raiz->derecha = eliminarNodo(raiz->derecha, temp->dato);
        }
    }

    if (raiz == NULL)
      return raiz;

    raiz->altura = max(altura(raiz->izquierda), altura(raiz->derecha)) + 1;

    int balance = Balancear(raiz);

    if (balance > 1 && Balancear(raiz->izquierda) >= 0)
        return RotacionDerecha(raiz);

    if (balance > 1 && Balancear(raiz->izquierda) < 0)
    {
        raiz->izquierda =  RotacionIzquierda(raiz->izquierda);
        return RotacionDerecha(raiz);
    }

    if (balance < -1 && Balancear(raiz->derecha) <= 0)
        return RotacionIzquierda(raiz);

    if (balance < -1 && Balancear(raiz->derecha) > 0)
    {
        raiz->derecha = RotacionDerecha(raiz->derecha);
        return RotacionIzquierda(raiz);
    }
    return raiz;
}




