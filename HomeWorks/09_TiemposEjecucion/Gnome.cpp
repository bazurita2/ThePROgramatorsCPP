#include <iostream>
#include <stdlib.h>
#include <time.h>

#include "Gnome.h"
#define dim 5

using namespace std;

clock_t tiempo_inicio, tiempo_final;	
double segundos;

int main(){
    int *vector;
    int auxiliar;
    vector=(int*)malloc(dim*sizeof(int));
    Gnome gnome;
    gnome.ask(vector);
    tiempo_inicio = clock();
    for(int p=0;p<dim;p++){
        gnome.gnomeSort(vector,p,auxiliar);
    }
    tiempo_final = clock();
    cout<<endl;
    cout<<"Mostrar vector ordenado: "<<endl;
    for(int i=0;i<dim;i++){
	    cout<<" ["<<*(vector+i)<<"]";
    }
    segundos = (double)( tiempo_final- tiempo_inicio)/CLOCKS_PER_SEC;
	printf("\nEl tiempo de ejecucion es de: %f ms",segundos);    
    free(vector);

    return 0;
}
