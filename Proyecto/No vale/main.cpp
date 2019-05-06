#include <conio.h>
#include <fstream>
#include <stdio.h>
#include <string>
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <time.h>

#include "Diccionario.h"

using namespace std;


class Archivo{
    public:
        Archivo();
        void lectura();
        void aniadir(Diccionario);
        void buscar();
};

Archivo::Archivo(){

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
    ofstream agregarTxtAux;
    ofstream agregarTxtLog;
    fflush(stdin);
    agregarTxt.open("diccionario.txt",ios::app);
    agregarTxt<<"Palabra: "<<di.agregarPalabra()<<endl;
    agregarTxt<<"Definicion: "<<di.agregarDefinicion()<<endl;
	agregarTxt.close();
	agregarTxtAux.open("diccionarioPalabras.txt",ios::app);
	agregarTxtAux<<di.agregarPalabra()<<endl;
    agregarTxtAux<<di.agregarDefinicion()<<endl;
	agregarTxtAux.close();
	agregarTxtLog.open("log.txt",ios::app);
	time_t tiempoAhora;
	time(&tiempoAhora);
	agregarTxtLog<<"Se busco la palabra: "<<di.agregarPalabra()<<" en la fecha: "<<ctime(&tiempoAhora)<<endl;
	agregarTxtLog.close();
}

void Archivo::buscar(){
    fstream archivo;
    string busca,linea1,linea2,linea3;
    int res=0;

    cout<<"Digite la palabra a buscar: ";
    cin>>busca;

    if(!archivo.is_open()){
        archivo.open("diccionario.txt",ios::in);
    }
    while(getline(archivo,linea1)){
        if(linea1.find(busca)!=string::npos){
            cout<<linea1<<endl;
            getline(archivo,linea2);
            cout<<linea2<<endl;
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
        break;

    }

    }while(op!=4);

return 0;

}
