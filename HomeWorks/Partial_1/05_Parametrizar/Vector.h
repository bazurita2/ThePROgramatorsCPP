#include <stdio.h>
#include <stdlib.h>

class Vector{
    public:
        void qs(int*,int,int);
        void quicksort(int*,int);
        void ordenar(int);
        Vector();
    private:
    	int* list;
};

Vector::Vector()
{
	
}

void Vector::ordenar(int n)
{
		int* array;
		array=(int*)malloc(n*sizeof(int));
		int temp;
	    
	    printf("Usted ingreso %d valores para reservar y analizar\n",n);
	    
	    for (int i=0; i<n; i++) 
		{
	        printf("Ingrese el valor [%i]: ",i);
	        scanf("%i",&temp);
	        *(array+i)=temp;
	        printf("\n");
	        system("cls");
	    }
	    
	    printf("Lista Desordenada \n");
	    for (int i=0; i<n; i++) 
		{
	        printf("[%d]",*(array+i));
	    }
	    
        printf("\n");
        Vector::quicksort(array,n);
		free(array);

}

void Vector::qs(int* lista,int limite_izq,int limite_der){
	    int izq,der,temp,pivote;
	    izq=limite_izq;
	    der = limite_der;
	    
	    pivote = *(lista+((izq+der)/2));
	    do
		{
	        while(*(lista+izq)<pivote && izq<limite_der)
				izq++;
	        while(pivote<*(lista+der) && der>limite_izq)
				der--;
	        if(izq <=der)
			{
	            temp= *(lista+izq);
	           *(lista+izq)=*(lista+der);
	           *(lista+der)=temp;
	            izq++;
	            der--;
	        }
	    }while(izq<=der);
	    
	    if(limite_izq<der)
		{
			qs(lista,limite_izq,der);
		}
	    if(limite_der>izq)
		{
			qs(lista,izq,limite_der);
		}
	}

void Vector::quicksort(int* lista,int n){
	    qs(lista,0,n-1);
	    
	    printf("Lista Ordenada \n");
	    for (int i=0; i<n; i++) 
		{
	        printf("[%d]",*(lista+i));
	        if(i<n-1)
            	printf(",");
    	}
}
