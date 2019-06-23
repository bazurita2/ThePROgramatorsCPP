#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include "Cubo.h"
#define dim 20



int main()

{

	cout<<"\n\n\t\t\t\t\tUniversidad de las Fuerzas Armadas ESPE"<<endl;
	cout<<"\n\n\t\t\Tema: Cubo magico."<<endl;
	cout<<"\n\n\t\t\Autores: Camilo Jimenez, Bryan Zurita,Sebastian Landazuri G."<<endl;
	cout<<"\n\t Fecha de creacion: 03-05-2019";
	cout<<"\n\t Fecha de presentacion: 05-05-2019 ";
	cout<<"\n\n\n\n\n"<<endl;
	system("PAUSE");
	system("cls");
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
