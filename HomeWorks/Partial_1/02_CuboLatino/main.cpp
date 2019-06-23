#include <iostream>
#include "MatrizClass.h"


 int pedirDimension(){
	cout<<"\n\n\t\t\t\t\tUniversidad de las Fuerzas Armadas ESPE"<<endl;
	cout<<"\n\n\t\t\Tema: Cubo latino."<<endl;
	cout<<"\n\n\t\t\Autores: Camilo Jimenez, Bryan Zurita,Sebastian Landazuri G."<<endl;
	cout<<"\n\t Fecha de creacion: 03-05-2019";
	cout<<"\n\t Fecha de presentacion:05-05-2019 ";
	cout<<"\n\n\n\n\n"<<endl;
	
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




