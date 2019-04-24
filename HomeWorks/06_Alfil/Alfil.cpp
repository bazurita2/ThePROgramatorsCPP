#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "Alfil.h"

using namespace std;

int main(){
    Alfil alfil =Alfil();
    alfil.pedirUbicacion();
    alfil.solucion();
    cout<<"\n\tEl alfil se puede mover de la siguiente forma:\n"<<endl;
    alfil.mostrar();
    system("pause");
    return 0;
}
