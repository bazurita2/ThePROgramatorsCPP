#include <iostream>
#include "MatrizClass.h"


 int pedirDimension(){
     int n;

   do{
    cout<<"\tIngrese el tamaño del cuadrado latino: ";
    cin>>n;
   }while(n<2||(n%2==0));
        return n;
}

int main(){
    CuadradoL cuadrado = CuadradoL();

    cuadrado.setCuadradoLDimension(pedirDimension());
    cuadrado.imprimir(cuadrado);

    return 0;
}




