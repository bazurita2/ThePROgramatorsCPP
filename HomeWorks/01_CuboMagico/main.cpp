#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include "Cubo.h"
#define dim 20 

void Cubo::setMatriz(int** valor)
{
	Cubo::matriz=valor;
}

int **Cubo::getMatriz()
{
	return matriz;
}

void Cubo::proceder(int n)
{  
	int key,i,j,k,r;
	
    if(n%2!=0)
	{
      	*(*(Cubo::matriz+0)+(n-1)/2)=1;
        key=2;
        i=0;
        j=(n-1)/2;
        
      while(key <= n*n)
	  {
		k=i-1;
		r=j-1;
		if(k<0) 
			k=n-1;
		if(r<0)
		    r=n-1;
		if(*(*(Cubo::matriz+k)+r)!=0) 
			i=(i+1)%n;
		else 
		{
	 	   i=k;
	       j=r; 
		}
		*(*(Cubo::matriz+i)+j)=key;
		key++;
      }
      
   }
   else 
   {
   	  printf("ERROR: La dimension no es impar\n");
   	  exit(1);
   }

}

void Cubo::visualizar(int n)
{  
    int i,j;
   for(i=0;i<n;i++)
   {
     for(j=0;j<n;j++)
     {
      	 printf("%-3d" ,*(*(Cubo::matriz+j)+i));
     }
    printf("\n");
   }
}

void Cubo::inicializar(int n)
{  
   int i,j;
   for(i=0;i<n;i++)
   {
   		for(j=0;j<n;j++)
   		{
   		  *(*(Cubo::matriz+j)+i)=0;
	    }
   }
}

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
   printf("Digite un valor que sea de preferencia impar: ");
   scanf("%d",&num);
   printf("Cubo magico:\n\n");
   c.setMatriz(cubo);
   c.inicializar(num);
   c.proceder(num);
   c.visualizar(num);
   free(cubo);
   return 0;
}
