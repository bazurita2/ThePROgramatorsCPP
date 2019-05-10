#include <stdio.h>
#include <stdlib.h>
#include "Vector.h"


int main()
{	
		cout<<"\n\n\t\t\t\t\tUniversidad de las Fuerzas Armadas ESPE"<<endl;
	cout<<"\n\n\t\t\Tema: Metodo de ordenamiento, parametrizado y recursivo."<<endl;
	cout<<"\n\n\t\t\Autores: Camilo Jimenez, Bryan Zurita,Sebastian Landazuri G."<<endl;
	cout<<"\n\t Fecha de creacion: 04-05-2019";
	cout<<"\n\t Fecha de presentacion: 05-05-2019";
	cout<<"\n\n\n\n\n"<<endl;
		int ingreso;	
		printf("Ingrese el numero de elementos para ingresar: ");
		scanf("%d",&ingreso);
		system("cls");
		Vector vector=Vector();
		vector.ordenar(ingreso);
	    return 0;

}
