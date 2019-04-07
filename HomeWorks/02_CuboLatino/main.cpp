#include <stdio.h>
#include <stdlib.h>
#include "MatrizClass.h"


int main(){
	int n;
	printf("Recuerde que la dimension del cuadrado debe de ser > o = que 3\n\n");
	printf("Ingrese el rango de la matriz: ");
	scanf("%d",&n);
	printf("\n");

    int **p_matriz;
    p_matriz = (int**)malloc(n*sizeof(int));
    for(int i=0;i<n;i++){
    	p_matriz[i]=(int *)malloc(n*sizeof(int));
    }

    Matriz matriz = Matriz();
    matriz.llenar(n,p_matriz);
    matriz.imprimir(n,p_matriz);
    if(matriz.comprobarCuadrado(n,p_matriz) == true){
    	printf("Si es una cuadrado magico!!!!\n\n");
    	printf("Gracias por usar este programa!!!\n");
    	free(p_matriz);
	}else{
		printf("Error NO es un cuadrado magico...\n");
		free(p_matriz);
		exit(1);
	}

    return 0;
}

