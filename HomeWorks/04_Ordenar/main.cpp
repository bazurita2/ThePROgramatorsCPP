#include <stdio.h>
#include <stdlib.h>
#include "Vector.h"

int main()
{
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

}
