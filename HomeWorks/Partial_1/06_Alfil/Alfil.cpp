#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "Alfil.h"

using namespace std;

int main(){
	cout<<"\n\n\t\t\t\t\tUniversidad de las Fuerzas Armadas ESPE"<<endl;
	cout<<"\n\n\t\t\Tema: Juego de Alfil."<<endl;
	cout<<"\n\n\t\t\Autores: Camilo Jimenez, Bryan Zurita,Sebastian Landazuri G."<<endl;
	cout<<"\n\t Fecha de creacion: 04-05-2019";
	cout<<"\n\t Fecha de presentacion: 07-05-2019";
	cout<<"\n\n\n\n\n"<<endl;
    Alfil alfil =Alfil();
    alfil.pedirUbicacion();
    alfil.solucion();
    cout<<"\n\tEl alfil se puede mover de la siguiente forma:\n"<<endl;
    alfil.mostrar();
    system("pause");
    return 0;
}
