#include <stdio.h>
#include <stdlib.h>
#include "Vector.h"


int main()
{
		int ingreso;	
		printf("Ingrese el numero de elementos para ingresar: ");
		scanf("%d",&ingreso);
		system("cls");
		Vector vector=Vector();
		vector.ordenar(ingreso);
	    return 0;

}
