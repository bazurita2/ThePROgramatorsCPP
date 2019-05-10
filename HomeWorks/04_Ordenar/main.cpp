#include <stdio.h>
#include <stdlib.h>
#include "Vector.h"

int main()
{	
		cout<<"\n\n\t\t\t\t\tUniversidad de las Fuerzas Armadas ESPE"<<endl;
	cout<<"\n\n\t\t\Tema: Metodo de ordenamiento."<<endl;
	cout<<"\n\n\t\t\Autores: Camilo Jimenez, Bryan Zurita,Sebastian Landazuri G."<<endl;
	cout<<"\n\t Fecha de creacion: 04-05-2019";
	cout<<"\n\t Fecha de presentacion: 05-05-2019";
	cout<<"\n\n\n\n\n"<<endl;
	
		int* array;
		array=(int*)malloc(5*sizeof(int));
		int temp;
	    
	    for (int i=0; i<5; i++) 
		{
	        printf("Ingrese el valor %i: ",i);
	        scanf("%i",&temp);
	        *(array+i)=temp;
	        printf("\n");
	        system("cls");
	    }

	    printf("Lista Desordenada \n");
	    for (int i=0; i<5; i++) 
		{
	        printf("[%d]",*(array+i));
	    }
            printf("\n");
	    Vector vector=Vector();
	    vector.quicksort(array,5);
		free(array);	
	    return 0;

}
