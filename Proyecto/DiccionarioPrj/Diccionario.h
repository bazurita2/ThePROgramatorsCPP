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


