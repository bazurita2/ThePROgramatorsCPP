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


