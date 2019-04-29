#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <ctime>

#define dim 100

using namespace std;

class Gnome{

    public:
        int getPosition();
        int getAuxiliar();
        void setPosition(int);
        void setAuxiliar(int);

        void ask(int *);
        void gnomeSort(int *,int,int);
        int random();

};

void Gnome::ask(int *vector){
	srand(time(NULL)); 
     for(int i=0;i<dim;i++){
	 *(vector+i)= random();
    }
    cout<<"Mostrar vector desordenado: "<<endl;
     for(int i=0;i<dim;i++){
	 cout<<" ["<<*(vector+i)<<"]";
    }
}


void Gnome::gnomeSort(int *vector,int position,int auxiliar){
    if(position>0 && *(vector+(position)) > *(vector+(position-1))){
                return;
            }else{
                if(position>0&& *(vector+position)< *(vector+(position-1))){
                      auxiliar = *(vector+(position-1));
                      *(vector+(position- 1))= *(vector+position);
                      *(vector+position) = auxiliar;
                      auxiliar=0;
                      gnomeSort(vector,position-1,auxiliar);

                }
        }
}

int Gnome::random(){
	return rand()%(100-1);
}


