#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

#include "Gnome.h"
#define dim 100

using namespace std;

int main(){
    int *vector;
    int auxiliar;
    unsigned t0,t1;
    vector=(int*)malloc(dim*sizeof(int));
    t0=clock();
	Gnome gnome;
    gnome.ask(vector);
    for(int p=0;p<dim;p++){
        gnome.gnomeSort(vector,p,auxiliar);
    }
    t1=clock();
    cout<<endl;
    cout<<"Mostrar vector ordenado: "<<endl;
    for(int i=0;i<dim;i++){
	    cout<<" ["<<*(vector+i)<<"]";
    }
    

    printf("\nEl tiempo de ejecucion es de: %f ms",((float)t1-t0)/CLOCKS_PER_SEC);

    return 0;
}
