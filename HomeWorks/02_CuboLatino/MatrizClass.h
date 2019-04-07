#ifndef MATRIZCLASS_H_INCLUDED
#define MATRIZCLASS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

class Matriz{
    private:
    	int n;
    	int **matriz;
    public:
        Matriz();
        int **getMatriz();
        void setMatriz(int **matriz);
        void llenar(int n,int **matriz);
        void imprimir(int n,int **matriz);
        bool comprobarCuadrado(int n,int **matriz);
};

Matriz::Matriz(){

}

bool Matriz::comprobarCuadrado(int n,int **matriz){
    int numero=0;
    int suma1[n];
    int suma2[n];
    bool comprob=true;
    numero = (n*(n*n+1))/2;
    printf("\nLa suma de la fila y columna debe ser: %d\n",numero);
    for(int i=0;i<n;i++){
    		suma1[i]=0;
    }
    for(int i=0;i<n;i++){
    		suma2[i]=0;
    }

	for(int i=0;i<n;i++){
    	for (int j=0;j<n;j++){
    		suma1[i]+=(*(*(matriz+i)+j));
		}
		if(suma1[i] == numero){
		}else{
        	comprob=false;
		}
    }

    printf("\n");

    for(int i=0;i<n;i++){
    	for (int j=0;j<n;j++){
    		suma2[i]+=(*(*(matriz+j)+i));
		}
		if(suma1[i] == numero){
		}else{
        	comprob=false;
		}
    }


    return comprob;
}

void Matriz::imprimir(int n,int **matriz){
    for(int i=0;i<n;i++){
    	for (int j=0;j<n;j++){
    		printf("\t%d\t",*(*(matriz+i)+j));
		}
		printf("\n");
    }
}

void Matriz::llenar(int n,int **matriz){

    for(int i=0;i<n;i++){
    	for (int j=0;j<n;j++){
    		printf("\tIngrese el valor [%d][%d]:",i+1,j+1);
		    scanf("%d",&(*(*(matriz+i)+j)));
		}
    }
    printf("\n");
}

int **Matriz::getMatriz(){
    return matriz;
}

void Matriz::setMatriz(int **matriz){
    matriz = matriz;
}

#endif
