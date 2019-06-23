#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#define N 8

using namespace std;

class Alfil{
    private:
        bool **validar;
        char **tablero;
        int m;
        int n;	
    public:
        Alfil(){
        validar=new bool *[N];
		tablero=new char *[N];
		for(int i=0;i<N;i++){
        validar[i]=new bool[N];
        tablero[i]=new char[N];
        for (int j=0;j<N;j++){
            *(*(validar +i)+j)=false;
            *(*(tablero +i)+j)='.';
			}
		}
		};
        void mostrar();
        void pedirUbicacion();
        void llenarDiagonalAb(int aux1, int aux2);
        void llenarDiagonalAbS(int aux1,int aux2);
        void llenarDiagonalSupS(int aux1, int aux2);
        void llenarDiagonalSupA(int aux1, int aux2);
        void solucion();
        int getM();
        int getN();
};


void Alfil::pedirUbicacion(){
	do{
		cout<<"\n\tIngrese la ubicacion en x del alfil: ";
		cin>>m;
	}while(m<1 || m>8);
    cout<<endl;
    m--;
    do{
		cout<<"\tIngrese la ubicacion en y del alfil: ";
        cin>>n;
	}while(n<1 || n>8);
    cout<<endl;
    n--;
    *(*(tablero+n)+m)='A';
}

void Alfil::llenarDiagonalAb(int aux1, int aux2){
    aux1++;
    aux2--;
    if(aux1==N || aux2<0){
    }
    else{
        *(*(tablero+aux1)+aux2)='M';
        llenarDiagonalAb(aux1,aux2);
    }
}

void Alfil::llenarDiagonalAbS(int aux1, int aux2){
    aux1--;
    aux2++;

    if(aux1<0 || aux2==N){
    }
    else{
        *(*(tablero+aux1)+aux2)='M';
        llenarDiagonalAbS(aux1,aux2);
    }
}

void Alfil::llenarDiagonalSupS(int aux1, int aux2){
    aux1++;
    aux2++;
    if(aux1==N || aux2==N){
    }
    else{
        *(*(tablero+aux1)+aux2)='M';
        llenarDiagonalSupS(aux1,aux2);
    }
}

void Alfil::llenarDiagonalSupA(int aux1, int aux2){
    aux1--;
    aux2--;

    if(aux1<0 || aux2<0){
    }
    else{
        *(*(tablero+aux1)+aux2)='M';
        llenarDiagonalSupA(aux1,aux2);
    }
}

void Alfil::solucion(){
    llenarDiagonalAb(n,m);
    llenarDiagonalAbS(n,m);
    llenarDiagonalSupA(n,m);
    llenarDiagonalSupS(n,m);
}

void Alfil::mostrar(){

	for(int i = 0; i < N;i++){
		cout<<"\t";
		for(int j=0;j<N;j++){
			
			cout<<*(*(tablero+i)+j)<<" ";

		}
        cout<<endl;
	}
	cout<<endl;
}


int Alfil::getM(){
    return m;
}
int Alfil::getN(){
    return n;
}
