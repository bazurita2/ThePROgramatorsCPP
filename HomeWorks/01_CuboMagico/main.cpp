#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include "Cubo.h"
#define dim 20



int main()
{
	Cubo c=Cubo();
    int** cubo;
	int num;
    cubo = (int **)malloc(dim*sizeof(int*));
  	for(int i=0;i<dim;i++)
  	{
  	    *(cubo+i) = (int *)malloc(dim*sizeof(int));
	}

   system("cls");

   do{
   printf("Digite un valor impar: ");
   scanf("%d",&num);
   }while(num<=1||(num%2==0));

   c.setN(num);
   printf("Cubo magico:\n\n");
   c.setMatriz(cubo);
   c.inicializar(c);
   c.proceder(c);
   c.visualizar(c);
   free(c.getMatriz());
   return 0;
}
