#include <stdio.h>
#include <stdlib.h>
#include "Vector.h"

clock_t tiempo_inicio, tiempo_final;	
double segundos;

int main()
{
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
