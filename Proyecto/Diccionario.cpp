#include <Diccionario.h>

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
