#include <stdio.h>

class Vector{
    public:
        void qs(int*,int,int);
        void quicksort(int*,int);
    private:
    	int* list;
};

void Vector::qs(int* lista,int limite_izq,int limite_der){
	    int izq,der,temporal,pivote;
	    izq=limite_izq;
	    der = limite_der;
	    pivote =  *(lista+((izq+der)/2));
	    do{
	        while(*(lista+izq)<pivote && izq<limite_der)izq++;
	        while(pivote<*(lista+der) && der > limite_izq)der--;
	        if(izq <=der){
	            temporal= *(lista+izq);
	           *(lista+izq)=*(lista+der);
	           *(lista+der)=temporal;
	            izq++;
	            der--;
	        }
	    }while(izq<=der);
	    if(limite_izq<der){qs(lista,limite_izq,der);}
	    if(limite_der>izq){qs(lista,izq,limite_der);}
	}