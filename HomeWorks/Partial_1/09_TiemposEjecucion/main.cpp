#include <stdio.h>
#include <stdlib.h>
#include "Vector.h"

clock_t tiempo_inicio, tiempo_final;	
double segundos;

int main()
{		cout<<"\n\n\t\t\t\t\tUniversidad de las Fuerzas Armadas ESPE"<<endl;
	cout<<"\n\n\t\t\Tema: Metodo de ordenamiento."<<endl;
	cout<<"\n\n\t\t\Autores: Camilo Jimenez, Bryan Zurita,Sebastian Landazuri G."<<endl;
	cout<<"\n\t Fecha de creacion: 08-05-2019";
	cout<<"\n\t Fecha de presentacion: 10-05-2019";
	cout<<"\n\n\n\n\n"<<endl;
		int ingreso;	
		printf("Ingrese el numero de elementos para ingresar: ");
		scanf("%d",&ingreso);
		system("cls");
		Vector vector=Vector();
		tiempo_inicio = clock();
		vector.ordenar(ingreso);
		tiempo_final = clock();
		segundos = (double)( tiempo_final- tiempo_inicio)/CLOCKS_PER_SEC;
		printf("\nEl tiempo de ejecucion es de: %f.2 ms",segundos); 		
	    return 0;

}
