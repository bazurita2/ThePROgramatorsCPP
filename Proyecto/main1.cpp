#include <conio.h>
#include <fstream>
#include <stdio.h>
#include <string>
#include <fstream>
#include <iostream>
#include "Diccionario.h"
#include <stdlib.h>
#include <windows.h>

using namespace std;


class Archivo{

    public:
        Archivo();
        void lectura();
        void aniadir(Diccionario);
        void buscar();
	void sonido(char *);
};

Archivo::Archivo(){

}

void Archivo::sonido(char *palabra){
	char *soundfile;
	soundfile=(char*)malloc(20*sizeof(char));
	soundfile=palabra;
	cout<<PlaySound((LPCSTR)soundfile,NULL,SND_FILENAME|SND_ASYNC)<<endl;
	
}

void Archivo::lectura(){
     string txt;
     ifstream mostrarArchivo;
     mostrarArchivo.open("diccionario.txt",ios::out);

    while(!mostrarArchivo.eof()){
        getline(mostrarArchivo,txt);
        cout<<txt<<endl;
    }
     mostrarArchivo.close();
}


void Archivo::aniadir(Diccionario di){
    ofstream agregarTxt;

    fflush(stdin);
    agregarTxt.open("diccionario.txt",ios::app);
    agregarTxt<<"\n\tPalabra: "<<di.agregarPalabra()<<endl;
    agregarTxt<<"\tDefinicion: "<<di.agregarDefinicion()<<endl;
        agregarTxt.close();
}

void Archivo::buscar(){
    fstream archivo;
    string linea1,linea2,linea3;
    int res=0;
    char *busca;
    char *wav;
    char *unir;
    
    busca=(char*)malloc(20*sizeof(char));
    wav=(char*)malloc(20*sizeof(char));
    unir=(char*)malloc(20*sizeof(char));
    
    wav=".wav";
    
    cout<<"Digite la palabra a buscar: ";
    cin>>busca;

    
    strcpy(unir,busca);
    strcat(unir,wav);
    
	sonido(unir);
	
  
    if(!archivo.is_open()){
        archivo.open("diccionario.txt",ios::in);
    }
 
    while(getline(archivo,linea1)){
        if(linea1.find(busca)!=string::npos){
            cout<<linea1<<endl;
            getline(archivo,linea2);
            res=1;
        }
    }
    if(res==0){
        cout<<"Palabra no encontrada"<<endl;
    }
}

int main(){
    Archivo arch = Archivo();
    Diccionario di = Diccionario();


    int op;

    do{
        cout<<"Digite una opcion"<<endl;
        cout<<" 1) agregar"<<endl;
        cout<<" 2) leer"<<endl;
        cout<<" 3) buscar"<<endl;
        cout<<" 4) Salir"<<endl;

        cin>>op;
        system("cls");
    switch(op){
        case 1: arch.aniadir(di);
        break;
        case 2: arch.lectura();
        break;
        case 3: arch.buscar();
		system("pause");
        break;

    }

    }while(op!=4);

return 0;

}