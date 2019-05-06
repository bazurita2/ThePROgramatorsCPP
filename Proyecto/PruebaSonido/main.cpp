#include <conio.h>
#include <stdio.h>
#include <string.h>
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <windows.h>

using namespace std;






void lectura(){
     string txt;
     ifstream mostrarArchivo;
     mostrarArchivo.open("diccionario.txt",ios::out);

    while(!mostrarArchivo.eof()){
        getline(mostrarArchivo,txt);
        cout<<txt<<endl;
    }
     mostrarArchivo.close();
}




void buscar(){
   fstream archivo;
    string linea1,linea2,linea3;
    int res=0;
     char *busca;
     char *wav;
     char *unir;
    
    busca=(char*)malloc(20*sizeof(char));
   wav=(char*)malloc(20*sizeof(char));
 	unir=(char*)malloc(20*sizeof(char));
    

    
    cout<<"Digite la palabra a buscar: ";
    cin>>busca;
	
     wav = ".wav";
    strcpy(unir,busca);
    strcat(unir,wav);
	
	cout<<PlaySound((LPCSTR)unir,NULL,SND_FILENAME|SND_ASYNC)<<endl;
    
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
    



    int op;

    do{
        cout<<"Digite una opcion"<<endl;
        cout<<" 1) leer"<<endl;
        cout<<" 2) buscar"<<endl;
        cout<<" 3) Salir"<<endl;

        cin>>op;
        system("cls");
    switch(op){
        case 1: lectura();
        break;
        case 2: buscar();
        system("pause");
        break;

    }

    }while(op!=3);

return 0;

}




