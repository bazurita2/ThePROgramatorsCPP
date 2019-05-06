//UNIVERSIDAD DE LAS FUERZAS ARMADAS "ESPE"
//ESTRUCTURA DE DATOS
//AUTORES: BRYAN ZURITA, VICTOR JIMENEZ, SEBASTIAN LANDAZURI
//FECHA: 6/5/2019

#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class Diccionario
{

private:
       string palabra;
       string definicion;

   public:
    Diccionario();
    string agregarPalabra();
    string agregarDefinicion();

};

Diccionario::Diccionario(){

}

string Diccionario::agregarPalabra(){

    cout<<"Ingrese la palabra: ";
    getline(cin,palabra);

    return palabra;
}


string Diccionario::agregarDefinicion(){
    cout<<"Ingrese su definicion: ";
    getline(cin,definicion);

    return definicion;

}


