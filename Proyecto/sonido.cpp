#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <fstream>
using namespace std;

char sonido(char *palabra){
	char *soundfile;
	soundfile=(char*)malloc(20*sizeof(char));
	soundfile=palabra;
	cout<<PlaySound((LPCSTR)soundfile,NULL,SND_FILENAME|SND_ASYNC)<<endl;
	
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
	
	
	buscar();
	system("pause");

	
	return 0;
	
	
}
